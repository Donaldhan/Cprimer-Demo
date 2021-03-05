
/*
 * @ClassName: MutexSimpleMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-05 11:07
*/
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;//实例化m对象，不要理解为定义变量
void proc1(int a)
{
    m.lock();
    cout << "proc1函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 1 << endl;
    m.unlock();
}
void proc2(int a)
{
    m.lock();
    cout << "proc2函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 2 << endl;
    m.unlock();
}
/*
 * 不推荐实直接去调用成员函数lock()，因为如果忘记unlock()，将导致锁无法释放，
 * 使用lock_guard或者unique_lock则能避免忘记解锁带来的问题。
 */
int main()
{
    int a = 0;
    thread t1(proc1, std::ref(a));
    thread t2(proc2, std::ref(a));
    t1.join();
    t2.join();
}

