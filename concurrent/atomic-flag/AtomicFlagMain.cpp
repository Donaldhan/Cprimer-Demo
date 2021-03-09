
/*
 * @ClassName: AtomicFlagMain
 * @Description:
 * std::atomic_flag
 *
 * std::atomic_flag是一个原子的布尔类型，可支持两种原子操作：
 * test_and_set, 如果atomic_flag对象被设置，则返回true; 如果atomic_flag对象未被设置，则设置之，返回false
 * clear. 清楚atomic_flag对象
 * std::atomic_flag可用于多线程之间的同步操作，类似于linux中的信号量。使用atomic_flag可实现mutex.
 *
 * @Author:  Ravitn
 * @Date: 2021-03-05 15:23
*/
#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <sstream>

using namespace std;
std::atomic_flag lock = ATOMIC_FLAG_INIT;
std::stringstream stream;

void append_numer(int x)
{
    while (lock.test_and_set());//如果atomic_flag对象被设置，则返回true; 如果atomic_flag对象未被设置，则设置之，返回false
    stream << "thread#" << x << "id:" << this_thread::get_id() << endl;
    //清楚atomic_flag对象
    lock.clear();
}

int main()
{
    std::vector<std::thread> ths;
    for (int i=0; i<20; i++)
        ths.push_back(std::thread(append_numer, i));
    for (int i=0; i<20; i++)
        ths[i].join();
    std::cout << stream.str();
    return 0;
}
