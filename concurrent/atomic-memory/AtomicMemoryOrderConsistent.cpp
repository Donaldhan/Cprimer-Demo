
/*
 * @ClassName: AtomicMemoryOrderConsistent
 * @Description:
 * 顺序一致模型：在此模型下，原子操作满足顺序一致性，进而可能对性能产生损耗。可显式的通过 std::memory_order_seq_cst 进行指定。
 * 这个例子与第一个宽松模型的例子本质上没有区别，仅仅只是将原子操作的内存顺序修改为了 memory_order_seq_cst，
 * 有兴趣的读者可以自行编写程序测量这两种不同内存顺序导致的性能差异。
 *
 * 单线程的原子操作顺序执行，同时其他操作也顺序执行
 * @Author:  Ravitn
 * @Date: 2021-03-05 17:10
*/
#include <atomic>
#include <iostream>
#include <vector>
#include <thread>

int main() {
    std::atomic<int> counter = {0};
    std::vector<std::thread> vt;
    for (int i = 0; i < 20; ++i) {
        vt.emplace_back([&]() {
            int now = counter.fetch_add(1, std::memory_order_seq_cst);
            std::cout << "current fetch_add:" << now << std::endl;
            //多线程共同访问
//            std::cout << "current fetch_add:" << counter << std::endl;
        });
    }
    for (auto &t : vt) {
        t.join();
    }
    std::cout << "current counter:" << counter << std::endl;
}
