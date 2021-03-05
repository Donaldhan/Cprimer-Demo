
/*
 * @ClassName: AtomicOperatorMain
 * @Description: atomic<int>支持++和--的原子操作。
 * @Author:  Ravitn
 * @Date: 2021-03-05 16:11
*/


#include <iostream>
#include <cassert>
#include <atomic>
#include <vector>
#include <unistd.h>
#include <thread>
#include <sstream>
#include <chrono>

std::atomic<int> foo(0);
std::atomic_flag lock = ATOMIC_FLAG_INIT;

void add_foo()
{
    while (1)
    {
        foo++;
        // foo = foo + 1;
        while (lock.test_and_set());
        std::cout <<"add: " << foo << std::endl;
        lock.clear();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//        usleep(1000);
    }
}

void sub_foo()
{
    while (1)
    {
        foo--;
        // foo = foo - 1;
        while (lock.test_and_set());
        std::cout << "sub: " << foo << std::endl;
        lock.clear();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//        usleep(1000);
    }
}
int main()
{
    std::thread th2 = std::thread(add_foo);
    std::thread th1 = std::thread(sub_foo);
    th1.join();
    th2.join();
    return 0;
}