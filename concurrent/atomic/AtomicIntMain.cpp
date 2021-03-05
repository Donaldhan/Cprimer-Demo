
/*
 * @ClassName: AtomicIntMain
 * @Description:
 * @Author:  Ravitn
 * @Date: 2021-03-05 15:59
*/
#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <sstream>

std::atomic<int> foo(0);

void set_foo(int x)
{
    foo = x;
    //memory_order_consume
//    foo.store(x, std::memory_order_acquire);
}

void print_foo()
{
    while (foo == 0)
    {
        /*
         * 其作用是当前线程“放弃”执行，让操作系统调度另一线程继续执行
         * 比如说你的线程需要等待某个操作完成，
         * 如果你直接用一个循环不断判断这个操作是否完成就会使得这个线程占满CPU时间，
         * 这会造成资源浪费。这时候你可以判断一次操作是否完成，
         * 如果没有完成就调用yield交出时间片，过一会儿再来判断是否完成，
         * 这样这个线程占用CPU时间会大大减少。
         */
        std::this_thread::yield();
    }
    std::cout << "x: " << foo << std::endl;
    //memory_order_relaxed
//    std::cout << "x: " << foo.load(std::memory_order_release) << std::endl;
}
int main()
{
    /*
     *set_foo用于设置atomic<int>对象的值，
     * print_foo用于打印atomic<int>对象的值。
     * std::atomic对象的值的读取和写入可使用load和store实现。
     */
    std::thread print_th(print_foo);
    std::thread set_th(set_foo, 10);
    print_th.join();
    set_th.join();
    return 0;
}

