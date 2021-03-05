
/*
 * @ClassName: LockGuradMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-05 11:17
*/
/*
 * 通过设定作用域，使得std::lock_guard在合适的地方被析构（在互斥量锁定到互斥量解锁之间的代码叫做临界区
 * （需要互斥访问共享资源的那段代码称为临界区），
 * 临界区范围应该尽可能的小，即lock互斥量后应该尽早unlock），
 * 通过使用{}来调整作用域范围，可使得互斥量m在合适的地方被解锁：
 */
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;//实例化m对象，不要理解为定义变量
void proc1(int a)
{
    lock_guard<mutex> g1(m);//用此语句替换了m.lock()；lock_guard传入一个参数时，该参数为互斥量，此时调用了lock_guard的构造函数，申请锁定m
    cout << "proc1函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 1 << endl;
}//此时不需要写m.unlock(),g1出了作用域被释放，自动调用析构函数，于是m被解锁

void proc2(int a)
{
    {
        lock_guard<mutex> g2(m);
        cout << "proc2函数正在改写a" << endl;
        cout << "原始a为" << a << endl;
        cout << "现在a为" << a + 2 << endl;
    }//通过使用{}来调整作用域范围，可使得m在合适的地方被解锁
    cout << "作用域外的内容3" << endl;
    cout << "作用域外的内容4" << endl;
    cout << "作用域外的内容5" << endl;
}
int main()
{
    int a = 0;
    thread t1(proc1, a);
    thread t2(proc2, a);
    t1.join();
    t2.join();
    return 0;
}
