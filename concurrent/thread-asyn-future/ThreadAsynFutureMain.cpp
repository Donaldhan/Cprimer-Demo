
/*
 * @ClassName: ThreadAsynFutureMain
 * @Description:
 * async与future：
 * std::async是一个函数模板，用来启动一个异步任务，它返回一个std::future类模板对象，future对象起到了占位的作用（记住这点就可以了），
 占位是什么意思？就是说该变量现在无值，但将来会有值（好比你挤公交瞧见空了个座位
 ，刚准备坐下去就被旁边的小伙给拦住了：“这个座位有人了”，你反驳道：”这不是空着吗？“，小伙：”等会人就来了“）,
 刚实例化的future是没有储存值的，但在调用std::future对象的get()成员函数时，
 主线程会被阻塞直到异步线程执行结束，并把返回结果传递给std::future，即通过FutureObject.get()获取函数返回值。
 *
 *shared_future
 *
 std::future与std::shard_future的用途都是为了占位，但是两者有些许差别。std::future的get()成员函数是转移数据所有权;
 std::shared_future的get()成员函数是复制数据。
 因此： future对象的get()只能调用一次；无法实现多个线程等待同一个异步线程，一旦其中一个线程获取了异步线程的返回值，
 其他线程就无法再次获取。 std::shared_future对象的get()可以调用多次；
 可以实现多个线程等待同一个异步线程，每个线程都可以获取异步线程的返回值。
 *
 * @Author:  Ravitn
 * @Date: 2021-03-05 14:10
*/
#include <iostream>
#include <thread>
#include <mutex>
#include<future>
#include<Windows.h>
using namespace std;
double t1(const double a, const double b)
{
    double c = a + b;
    Sleep(3000);//假设t1函数是个复杂的计算过程，需要消耗3秒
    return c;
}
void waitShareFuture(const shared_future<double>& shareFuture){
    cout << "waitShareFuture theadId:"<< this_thread::get_id() << endl;
    double result = shareFuture.get();
    cout << "theadId:"<< this_thread::get_id() << " shareFuture value:" <<result <<  endl;

}
int main()
{
    double a = 2.3;
    double b = 6.7;
    future<double> fu = async(t1, a, b);//创建异步线程线程，并将线程的执行结果用fu占位；
    cout << "正在进行计算" << endl;
    cout << "计算结果马上就准备好，请您耐心等待" << endl;
    cout << "计算结果：" << fu.get() << endl;//阻塞主线程，直至异步线程return
    //cout << "计算结果：" << fu.get() << endl; //取消该语句注释后运行会报错，因为future对象的get()方法只能调用一次。
    shared_future<double> sharedFuture = async(t1, 1.0,2.0);
    thread t2(waitShareFuture,sharedFuture);
    thread t3(waitShareFuture,sharedFuture);
    t2.join();
    /*
     * Thread::joinable是C++ std::thread中的内置函数。它是一个观察器函数，表示它观察状态，然后返回相应的输出并检查线程对象是否可连接。
     * 如果线程对象标识/表示执行中的活动线程，则称该线程对象是可连接的。
     * 在以下情况下，线程不可联接：
     * 1. 它是默认构造的
     * 2. 如果其成员join或detach中的任何一个已被调用
     * 3. 它已移至其他地方
     */
    //joinable
    //检查线程是否可被 join。
    if(t2.joinable()){
        cout << " t2 can joinable" << endl;
    }
    else{
        cout << " t2 can not  joinable"<< endl;
    }
    if(t3.joinable()){
        cout << " t3 can joinable"<< endl;
    }
    else{
        cout << " t3 can not  joinable"<< endl;
    }
    t3.join();
}


