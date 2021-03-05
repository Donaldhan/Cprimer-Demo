
/*
 * @ClassName: AtomicMemoryReleaseConsume
 * @Description:
 *
 * 释放/消费模型：在此模型中，我们开始限制进程间的操作顺序，
 * 如果某个线程需要修改某个值，但另一个线程会对该值的某次操作产生依赖，即后者依赖前者。
 * 具体而言，线程 A 完成了三次对 x 的写操作，线程 B 仅依赖其中第三次 x 的写操作，
 * 与 x 的前两次写行为无关，则当 A 主动 x.release() 时候（即使用 std::memory_order_release），
 * 选项 std::memory_order_consume 能够确保 B 在调用 x.load() 时候观察到 A 中第三次对 x 的写操作。
 *
 * @Author:  Ravitn
 * @Date: 2021-03-05 17:09
*/
#include <atomic>
#include <iostream>
#include <vector>
#include <thread>
int main(){
    // 初始化为 nullptr 防止 consumer 线程从野指针进行读取
    std::atomic<int*> ptr(nullptr);
    int v;
    std::thread producer([&]() {
        int* p = new int(42);
        v = 1024;
        ptr.store(p, std::memory_order_release);
    });
    std::thread consumer([&]() {
        int* p;
        while(!(p = ptr.load(std::memory_order_consume)));

        std::cout << "p: " << *p << std::endl;
        std::cout << "v: " << v << std::endl;
    });
    producer.join();
    consumer.join();
}


