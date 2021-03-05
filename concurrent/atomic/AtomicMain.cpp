
/*
 *
 * @ClassName: AtomicMain
 * @Description:
* 原子操作指“不可分割的操作”，也就是说这种操作状态要么是完成的，要么是没完成的，
 * 不存在“操作完成了一半”这种状况。互斥量的加锁一般是针对一个代码段，
 * 而原子操作针对的一般都是一个变量(操作变量时加锁防止他人干扰)。
 * std::atomic<>是一个模板类，使用该模板类实例化的对象，提供了一些保证原子性的成员函数来实现共享数据的常用操作。
 * 提到std::atomic<>，你脑海里就想到一点就可以了：std::atomic<>用来定义一个自动加锁解锁的共享变量（“定义”“变量”用词在这里是不准确的，
 * 但是更加贴切它的实际功能），供多个线程访问而不发生冲突。
 *
 * std::atomic<>对象提供了常见的原子操作（通过调用成员函数实现对数据的原子操作）：
 * store是原子写操作，load是原子读操作。exchange是于两个数值进行交换的原子操作。
 * 即使使用了std::atomic<>，也要注意执行的操作是否支持原子性，也就是说，你不要觉得用的是具有原子性的变量（准确说是对象）就可以为所欲为了，
 * 你对它进行的运算不支持原子性的话，也不能实现其原子效果。一般针对++，–，+=，-=，&=，|=，^=是支持的，
 * 这些原子操作是通过在std::atomic<>对象内部进行运算符重载实现的。
 *
 *
 *  std::atomic对int, char, bool等数据结构进行原子性封装，
 *  在多线程环境中，对std::atomic对象的访问不会造成竞争-冒险。利用std::atomic可实现数据结构的无锁设计。
 *
 *
 *
 * @Author:  Ravitn
 * @Date: 2021-03-05 14:13
*/


#include <iostream>
#include <atomic>
#include <atomic>
#include <vector>
#include <thread>
#include <sstream>

std::atomic<bool> ready(false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void count1m(int i)
{
    while (!ready);
    for (int i=0; i<1000000; i++);
    if (!winner.test_and_set())
        std::cout << "winner: " << i << std::endl;
}

int main()
{
    std::vector<std::thread> ths;
    for (int i=0; i<20; i++)
        ths.push_back(std::thread(count1m, i));
    /**
     *  /// Enumeration for memory_order
  typedef enum memory_order
    {
      memory_order_relaxed,
      memory_order_consume,
      memory_order_acquire,
      memory_order_release,
      memory_order_acq_rel,
      memory_order_seq_cst
    } memory_order;
     *
     */
//    ready.compare_exchange_strong(&ready, bool,std::memory_order::memory_order_acquire);
//ready.exchange()
//ready.compare_exchange_weak()
//ready.is_lock_free()
//ready.load()
//ready.store()
    ready = true;
    for (int i=0; i<20; i++)
        ths[i].join();

//    std::atomic<bool> b;
//    bool x=b.load(std::memory_order_acquire);
//    b.store(true);
//    x=b.exchange(false,std::memory_order_acq_rel);//更改为false并返回原来的值


   /* compare_exchange_weak/strong函数是保证在比较和交换执行下原子化,
    但是此函数可能与expected值相等的情形下atomic的T值没有替换为val，
    这时atomic值未变且返回false，
    compare_exchange_weak可能失败，特别是线程数多于CPU核心数时compare-exchange这个指令序列可能CPU不能保证原子化*/
//    bool expected=false;
//    extern atomic<bool> b; // set somewhere else
//    while(!b.compare_exchange_weak(expected,true) && !expected);
    return 0;
}