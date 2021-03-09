
/*
 * @ClassName: AtomicFetch
 * @Description:
 * 在现代 CPU 体系结构下提供了 CPU 指令级的原子操作，
 * 因此在 C++11 中多线程下共享变量的读写这一问题上，
 * 还引入了 std::atomic 模板，使得我们实例化一个原子类型，将一个 原子类型读写操作从一组指令，最小化到单个 CPU 指令
 * @Author:  Ravitn
 * @Date: 2021-03-05 16:23
*/
#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> count = {0};

int main() {
    std::cout << std::boolalpha <<":" << count.is_lock_free() << std::endl;
    std::thread t1([](){
        count.fetch_add(1);
//        count.fetch_sub(1);
        std::cout << "threadId:" << std::this_thread::get_id()<< " count:" << count << "\n";
    });
    std::thread t2([](){
        count++;        // 等价于 fetch_add
        std::cout << "threadId:" << std::this_thread::get_id()<< " count:" << count << "\n";
        count += 1;     // 等价于 fetch_add
        std::cout << "threadId:" << std::this_thread::get_id()<< " count:" << count << "\n";
    });
    t1.join();
    t2.join();
    std::cout << "final:" <<  count << std::endl;
    return 0;
}

