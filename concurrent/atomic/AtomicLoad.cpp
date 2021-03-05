
/*
 * @ClassName: AtomicLoad
 * @Description:
 * compare_exchange_strong可以保证当atomic不等于expected时返回false，不需要循环保护。
 * std::atomic_flag是lock free的，但是atomic<bool>不一定是lock free的，可以用atomic<T>::is_lock_free()判断。
 *
 * compare_exchange_weak/strong函数是保证在比较和交换执行下原子化,但是此函数可能与expected值相等的情形下atomic的T值没有替换为val，
 * 这时atomic值未变且返回false， compare_exchange_weak可能失败，
 * 特别是线程数多于CPU核心数时compare-exchange这个指令序列可能CPU不能保证原子化
 *
 * bool expected=false;
 * extern atomic<bool> b; // set somewhere else
 * while(!b.compare_exchange_weak(expected,true) && !expected);
 *
 *
 * @Author:  Ravitn
 * @Date: 2021-03-05 16:47
*/


#include <vector>
#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
std::vector<int> data;
std::atomic<bool> data_ready(false);
void reader_thread()
{
    while(!data_ready.load())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    std::cout<<"The answer="<<data[0]<<"\n";// 1
}
void writer_thread()
{
    data.push_back(42);//2  由于1和2处发生了data race，所以需要线程同步，可以使用mutex，此处使用atomic<bool>强制线程间有个顺序关系
    data_ready=true;
}
int main(){
  thread t1(reader_thread);
  thread t2(writer_thread);
  t1.join();
  t2.join();
}