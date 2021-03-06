
/*
 * @ClassName: EpollClient
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-09 14:58
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>

#define BUF_SIZE 100
#define EPOLL_SIZE 50
void error_handling(char *buf);

int main(int argc, const char * argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t adr_sz;
    int str_len, i;
    char buf[BUF_SIZE];

    //类似select的fd_set变量查看监视对象的状态变化，epoll_event结构体将发生变化的文件描述符单独集中到一起
    struct epoll_event *ep_events;
    struct epoll_event event;
    int epfd, event_cnt;

    if(argc != 2)
    {
        printf("Usage: %s <port> \n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1)
        error_handling("socket() error");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr *) &serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind() error");

    if(listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    //创建文件描述符的保存空间称为“epoll例程”
    epfd = epoll_create(EPOLL_SIZE);
    ep_events = malloc(sizeof(struct epoll_event) *EPOLL_SIZE);

    //添加读取事件的监视(注册事件)
    event.events = EPOLLIN;  //读取数据事件
    event.data.fd = serv_sock;
    epoll_ctl(epdf, EPOLL_CTL_ADD, serv_sock, &event);

    while (1)
    {
        //响应事件，返回发生事件的文件描述符数
        event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);  //传-1时，一直等待直到事件发生
        if(event_cnt == -1)
        {
            puts("epoll_wait() error");
            break;
        }

        //服务端套接字和客服端套接字
        for (i = 0; i < event_cnt; i++) {
            if(ep_events[i].data.fd == serv_sock)//服务端与客服端建立连接
            {
                adr_sz = sizeof(clnt_adr);
                clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &adr_sz);
                event.events = EPOLLIN;
                event.data.fd = clnt_sock;
                epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
                printf("connected client: %d \n", clnt_sock);
            }
            else  //连接之后传递数据
            {
                str_len = read(ep_events[i].data.fd, buf, BUF_SIZE);
                if(str_len == 0)
                {
                    //删除事件
                    epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
                    close(ep_events[i].data.fd);
                    printf("closed client: %d \n", ep_events[i].data.fd);
                }
                else
                {
                    write(ep_events[i].data.fd, buf, str_len);
                }
            }
        }
    }

    close(serv_sock);
    close(epfd);
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

