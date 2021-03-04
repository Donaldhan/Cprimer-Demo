
/*
 * @ClassName: CastMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-04 14:30
*/
#include <iostream>
#include "LoggerFactory.h"
#include <cstring>

using namespace std;

class A {
public:
    A() {};
    int i;
    int j;

    A(int n) : i(n), j(n) {}
};

class Base {
public:
    virtual void fun() {
        cout << "Base" << "\n";
    }
};

class Derived : public Base {
public:
    void fun() { cout << "Derived" << "\n"; }

    void funx() { cout << "funx XX" << "\n"; }

    string name = "ravitn";
};

int main() {
    auto log = LoggerFactory::getLogger("CastMain");
    /*用法：static_cast < type-id > ( expression )，
     *
     * 在上行转换中，static_cast和dynamic_cast效果是一样的，而且都比较安全，
     * 因为向上转换的对象一般是指向子类对象的子类类型指针；而在下行转换中，
     * 由于可以定义就不同了指向子类对象的父类类型指针，同时static_cast只在编译时进行类型检查，
     * 而dynamic_cast是运行时类型检查，则需要视情况而定
     *
     * 上行：指向子类型；（子类型可以指向子类型，父类型可以指向子类型）
     * 下行：执行父类型；（子类型可以指向子类型，父类型可以指向父类型，子类型不可以指向父类型）
     *
     * static_cast 主要用于基本原始类型的转换, 比如int，char；
     * dynamic_cast主要用于含继承关系的对象指针转换；
     */
    A a;
    int n;
    char *p = "New Dragon Inn";

    n = static_cast <int> (3.14);  // n 的值变为 3
    log->info("n:{}", n);
//    n = static_cast <int> (a);     // 调用 a.operator int，n 的值变为 1
    log->info("n:{}", n);
//    p = static_cast <char*> (a);   // 调用 a.operator char*，p 的值变为 NULL
    log->info("p:{}", p);
//    n = static_cast <int> (p);     // 编译错误，static_cast不能将指针转换成整型
    log->info("n:{}", n);
//    p = static_cast <char*> (n);   // 编译错误，static_cast 不能将整型转换成指针
    log->info("p:{}", p);
    /*
     * 上行转换， 都可以
     */
    Base *Pb = new Derived();
    Derived *pd1 = static_cast<Derived *>(Pb);
    pd1->fun();
    Derived *pd2 = dynamic_cast<Derived *>(Pb);
    pd2->fun();
    /*
     * 不允许 , 下行转换
     * static_cast转换在编译时不会报错，也可以返回一个子类对象指针（假想）
     * dynamic_cast由于具有运行时类型检查功能，它能检查P的类型，不合理的，返回NULL。
     */
    Base *Pa = new Base;
    Derived *pd3 = static_cast<Derived *>(Pa);
    pd3->fun();
    //下行转换（基类---->派生类）由于没有动态类型检查，所以是不安全的
    pd3->funx();
    log->info("name:{}", pd3->name);
    Derived *pd4 = dynamic_cast<Derived *>(Pa);//NULL
//    pd4->fun();
// RTTI全名叫run time type identification，在运行时进行类型检查/辨认
//TypeID 解决
    if(  typeid(*pd3)  ==   typeid(Derived)  )
    {
        log->info("typeid name:{}", pd3->name);
    }else{
        log->info("typeid name:null");
    }
    //dynamic_cast 解决
    if(  nullptr != dynamic_cast<Derived*>(Pa)  ){
        log->info("dynamic_cast name:{}", pd3->name);
    }
    else{
        log->info("dynamic_cast name:null");
    }
    /*
     * reinterpret_cast
        reinterpret_cast 用于进行各种不同类型的指针之间、不同类型的引用之间以及指针和能容纳指针的整数类型之间的转换。
        转换时，执行的是逐个比特复制的操作。
        1.使用场景：
        不到万不得已，不用使用这个转换符，高危操作；
        2.使用特点：　　
        　　a、reinterpret_cast是从底层对数据进行重新解释，依赖具体的平台，可移植性差；
        　　b、reinterpret_cast可以将整型转换为指针，也可以把指针转换为数组；
        　　c、reinterpret_cast可以在指针和引用里进行肆无忌惮的转换；
     */
// pa逐个比特拷贝到u
    unsigned int u = reinterpret_cast<unsigned int>(Pa);
    /*
     * const_cast
     * const_cast 运算符仅用于进行去除 const 属性的转换，它也是四个强制类型转换运算符中唯一能够去除 const 属性的运算符。
     * 1.使用场景：
     * a、常量指针转换为非常量指针，并且仍然指向原来的对象
     * b、常量引用被转换为非常量引用，并且仍然指向原来的对象
     *
     * 2.使用特点：
     * a、cosnt_cast是四种类型转换符中唯一可以对常量进行操作的转换符
     * b、去除常量性是一个危险的动作，尽量避免使用。
     */
    const string s = "Inception";
    string &ps = const_cast <string &> (s);
    log->info("string const_cast ps:{}", ps);
    string *ps1 = const_cast <string *> (&s);  // &s 的类型是 const string*
    log->info("string const_cast ps1:{}", *ps1);
};

