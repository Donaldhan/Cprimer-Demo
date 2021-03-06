
/*
 * @ClassName: ReadWriteLockMain
 * @Description:
 * STL 和 Boost 都提供了 shared_mutex 来解决「读者-写者」问题。shared_mutex 这个名字并不十分贴切，不如 pthread 直呼「读写锁」。
 * 所谓「读写锁」，就是同时可以被多个读者拥有，但是只能被一个写者拥有的锁。
 * 而所谓「多个读者、单个写者」，并非指程序中只有一个写者（线程），而是说不能有多个写者同时去写。
 * @Author:  Ravitn
 * @Date: 2021-03-05 14:57
*/
#include <atomic>
#include <mutex>
//#include <shared_mutex>
#include <thread>
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/locks.hpp>
#include <iostream>
#include <vector>

class Counter {
private:
    mutable boost::shared_mutex mutex_;
    std::size_t value_;
public:
    Counter() : value_(0) {
    }

    // Multiple threads/readers can read the counter's value at the same time.
    std::size_t Get() const {
        boost::shared_lock<boost::shared_mutex> lock(mutex_);
        return value_;
    }

    // Only one thread/writer can increment/write the counter's value.
    void Increase() {
        // You can also use lock_guard here.
        boost::unique_lock<boost::shared_mutex> lock(mutex_);
        value_++;
    }

    // Only one thread/writer can reset/write the counter's value.
    void Reset() {
        std::unique_lock<boost::shared_mutex> lock(mutex_);
        value_ = 0;
    }
};

std::mutex g_io_mutex;

void Worker(Counter& counter) {
    for (int i = 0; i < 3; ++i) {
        counter.Increase();
        std::size_t value = counter.Get();
        std::lock_guard<std::mutex> lock(g_io_mutex);
        std::cout <<"thread id:" << std::this_thread::get_id() << ", vaule:" << value << std::endl;
    }
}
int main(){
    const std::size_t SIZE = 2;
    Counter counter;
    std::vector<std::thread> v;
    v.reserve(SIZE);
    v.emplace_back(std::thread(Worker, std::ref(counter)));
    v.emplace_back(&Worker, std::ref(counter));
    for (std::thread& t : v) {
        t.join();
    }
}
