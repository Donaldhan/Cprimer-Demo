
/*
 * @ClassName: AtomicMemoryReleaseAcquire
 * @Description:
 * 释放/获取模型：在此模型下，我们可以进一步加紧对不同线程间原子操作的顺序的限制，
 * 在释放 std::memory_order_release 和获取 std::memory_order_acquire 之间规定时序，即发生在释放操作之前的所有写操作，
 * 对其他线程的任何获取操作都是可见的，亦即发生顺序（happens-before）。
 * 可以看到，std::memory_order_release 确保了它之后的写行为不会发生在释放操作之前，是一个向前的屏障，
 * 而 std::memory_order_acquire 确保了它之前的写行为，不会发生在该获取操作之后，
 * 是一个向后的屏障。对于选项 std::memory_order_acq_rel 而言，则结合了这两者的特点，
 * 唯一确定了一个内存屏障，使得当前线程对内存的读写不会被重排到此操作的前后。
 *
 * @Author:  Ravitn
 * @Date: 2021-03-05 17:10
*/
#include <atomic>
#include <iostream>
#include <vector>
#include <thread>

int main() {
    std::vector<int> v;
    std::atomic<int> flag = {0};
    std::thread release([&]() {
        v.push_back(42);
        flag.store(1, std::memory_order_release);
    });
    /* compare_exchange_weak/strong函数是保证在比较和交换执行下原子化,
         但是此函数可能与expected值相等的情形下atomic的T值没有替换为val，
         这时atomic值未变且返回false，
         compare_exchange_weak可能失败，特别是线程数多于CPU核心数时compare-exchange这个指令序列可能CPU不能保证原子化
        //bool expected=false;
        //extern atomic<bool> b; // set somewhere else
        //while(!b.compare_exchange_weak(expected,true) && !expected);
*/
    /*在此例中我们使用了 compare_exchange_strong，它便是比较交换原语（Compare-and-swap primitive），
它有一个更弱的版本，即 compare_exchange_weak，它允许即便交换成功，也仍然返回 false 失败。
其原因是因为在某些平台上虚假故障导致的，具体而言，当 CPU 进行上下文切换时，
另一线程加载同一地址产生的不一致。除此之外，compare_exchange_strong 的性能可能稍差于 compare_exchange_weak，
但大部分情况下，compare_exchange_strong 应该被有限考虑。*/

    std::thread acqrel([&]() {
        int expected = 1; // must before compare_exchange_strong
//        store 变体？？？？
        while (!flag.compare_exchange_strong(expected, 2, std::memory_order_acq_rel)) {
//            expected = 1; // must after compare_exchange_strong
            std::cout <<"vflag has changed to 1, expected:" << expected << std::endl;
        }
        // flag has changed to 2
        std::cout <<"vflag has changed to 2, expected:" << expected << std::endl;
    });


    std::thread acquire([&]() {
        while (flag.load(std::memory_order_acquire) < 2);
        std::cout <<"v.at(0):" << v.at(0) << std::endl; // must be 42
    });
//    acqrel.join();
    release.join();
    //对于选项 std::memory_order_acq_rel 而言，则结合了这两者的特点，
    //唯一确定了一个内存屏障，使得当前线程对内存的读写不会被重排到此操作的前后。
    acqrel.join();
    acquire.join();
}

