
/*
 * @ClassName: MutexConditionMain
 * @Description:
 * condition_variable:
 *
 * 需要#include<condition_variable>，该头文件中包含了条件变量相关的类，其中包括std::condition_variable类
 *
 * wait(locker) :
 * wait函数需要传入一个std::mutex（一般会传入std::unique_lock对象）,即上述的locker。
 * wait函数会自动调用 locker.unlock() 释放锁（因为需要释放锁，所以要传入mutex）并阻塞当前线程，
 * 本线程释放锁使得其他的线程得以继续竞争锁。一旦当前线程获得notify(通常是另外某个线程调用 notify_* 唤醒了当前线程)，
 * wait() 函数此时再自动调用 locker.lock()上锁。
 * cond.notify_one(): 随机唤醒一个等待的线程
 * cond.notify_all(): 唤醒所有等待的线程
 *
 * @Author:  Ravitn
 * @Date: 2021-03-05 13:57
*/

/*
生产者消费者问题
*/
#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include<Windows.h>
#include <chrono>
using namespace std;

deque<int> q;
mutex mu;
condition_variable condition;
int c = 0;//缓冲区的产品个数
void producer() {
    int data1;
    while (1) {//通过外层循环，能保证生产不停止
        if(c < 3) {//限流
            {
                data1 = rand();
                unique_lock<mutex> locker(mu);//锁
                q.push_front(data1);
                cout << "producer存了" << data1 << endl;
                condition.notify_one();  // 通知取
                ++c;
            }
            this_thread::sleep_for(std::chrono::seconds(1));
//            Sleep(500);
        }
    }
}

void consumer() {
    //data用来覆盖存放取的数据
    int data2;
    while (1) {
        {
            unique_lock<mutex> locker(mu);
            while(q.empty())
                //wait()阻塞前先会解锁,解锁后生产者才能获得锁来放产品到缓冲区；生产者notify后，将不再阻塞，且自动又获得了锁。
                condition.wait(locker);
            data2 = q.back();//取的第一步
            q.pop_back();//取的第二步
            cout << "consumer取了" << data2<<endl;
            --c;
        }
        this_thread::sleep_for(std::chrono::milliseconds (1500));
//        Sleep(1500);
    }
}
int main() {
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}
