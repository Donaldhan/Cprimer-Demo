
/*
 * @ClassName: UniqueLockMain
 * @Description:
 *
 * std::unique_lock类似于lock_guard,只是std::unique_lock用法更加丰富，同时支持std::lock_guard()的原有功能。
 * 使用std::lock_guard后不能手动lock()与手动unlock();
 * 使用std::unique_lock后可以手动lock()与手动unlock();
 * std::unique_lock的第二个参数，除了可以是adopt_lock,还可以是try_to_lock与defer_lock;
 * try_to_lock: 尝试去锁定，得保证锁处于unlock的状态,然后尝试现在能不能获得锁；尝试用mutx的lock()去锁定这个mutex，
 * 但如果没有锁定成功，会立即返回，不会阻塞在那里，并继续往下执行；
 * defer_lock: 始化了一个没有加锁的mutex;
 *
 * std::unique_lock所有权的转移
 *
 * 注意，这里的转移指的是std::unique_lock对象间的转移；
 * std::mutex对象的所有权不需要手动转移给std::unique_lock ,
 * std::unique_lock对象实例化后会直接接管std::mutex。
 * mutex m;
 * {
    unique_lock<mutex> g2(m,defer_lock);
    unique_lock<mutex> g3(move(g2));//所有权转移，此时由g3来管理互斥量m
    g3.lock();
    g3.unlock();
    g3.lock();
    }
 * @Author:  Ravitn
 * @Date: 2021-03-05 11:31
*/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;
void proc1(int a)
{
    unique_lock<mutex> g1(m, defer_lock);//始化了一个没有加锁的mutex
    cout << "proc1 lock before, defer lock" << endl;
    //手动加锁，注意，不是m.lock();注意，不是m.lock(),m已经被g1接管了;
    g1.lock();
    cout << "proc1函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 1 << endl;
    g1.unlock();//临时解锁
    cout << "临时解锁"  << endl;
    g1.lock();
    cout << "proc1 lock again" << endl;
}//自动解锁
/*
 * 使用try_to_lock要小心，因为try_to_lock尝试锁失败后不会阻塞线程，而是继续往下执行程序，
 * 因此，需要使用if-else语句来判断是否锁成功,只有锁成功后才能去执行互斥代码段。
 * 而且需要注意的是，因为try_to_lock尝试锁失败后代码继续往下执行了，因此该语句不会再次去尝试锁。
 */
void proc2(int a)
{
    unique_lock<mutex> g2(m,try_to_lock);//尝试加锁一次，但如果没有锁定成功，会立即返回，不会阻塞在那里，且不会再次尝试锁操作。
    if(g2.owns_lock()){//锁成功
        cout << "proc2函数正在改写a" << endl;
        cout << "原始a为" << a << endl;
        cout << "现在a为" << a + 2 << endl;
    }else{//锁失败则执行这段语句
        cout <<"proc2 lock fail"<<endl;
    }
}//自动解锁

int main()
{
    int a = 0;
    thread t1(proc1, a);
    thread t2(proc2, a);
    t1.join();
    t2.join();
    return 0;
}
