
/*
 * @ClassName: MemorySingleThreadOrder
 * @Description:
 *
 * 宽松模型：
 * 在此模型下，单个线程内的原子操作都是顺序执行的，不允许指令重排，
 * 但不同线程间原子操作的顺序是任意的。类型通过 std::memory_order_relaxed 指定
 *
 * 单线程的原子操作顺序执行，其他操作不一定
 *
 * @Author:  Ravitn
 * @Date: 2021-03-05 17:09
*/
#include <atomic>
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

int main() {
    std::atomic<int> counter = {0};
    std::vector<std::thread> vt;
    for (int i = 0; i < 20; ++i) {
        vt.emplace_back([&]() {
            //添加返回当前值
            int now = counter.fetch_add(1, std::memory_order_relaxed);
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



