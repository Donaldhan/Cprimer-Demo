
/*
 * @ClassName: MemoryMain
 * @Description:
 * c++内存分配采用new/delete操作符，new表达式在分配适当内存后，自动运行合适的构造函数来初始化每个动态分配的类类型对象。
 * 不是所有需求都要求在分配内存后，立即对该内存的对象初始化！一些情况往往需求将内存的分配和对象的初始化（对象的构造）分离开
 *
 * 1.new基于每个对象分配内存的事实可能会对某些类强加不可接受的运行时开销，
 * 这样的类可能需要使用户级的类类型对象分配的能够更快一些。这样的类使用的通用策略是，
 * 预先分配用于创建对象的内存，需要时在预先分配的内存中构造每个新对象。
 *
 * 2.另外，一些类希望按最小尺寸为自己的数据成员分配需要的内存。例如，标准库中的vector类预先分配额外的内存以保存加入的附加元素，
 * 将新元素加入到这个保留容器中。将元素保持在连续的内存中的时候，预先分配的空间可以是vector能够高效的加入元素。
 *
 * 这些都需要将内存分配与对象构造分离，在预先分配的内存中构造对象很浪费，可能会创建从不使用的对象。
 * 更微妙的是，如果预先分配的内存必须构造，某些类就不能使用它。
 * 例如，考虑vector，它使用预先分配策略。如果必须构造预先分配的内存中的对象，
 * 就不能有基类型为没有默认构造函数的vector——vector没有办法知道怎样构造这些对象。
 *
 * operator new函数和operator delete表现功能与allocator类的allocate和deallocate成员类似，
 * 但他们有一个重要的不同点：operator new和operator delete函数是在void * 指针上操作，而不是在类型化的指针上操作。
 * allocate成员分配类型化的内存，所以使用它的程序可以不必计算以字节为典韦的所需的内存量，也可以避免进行强制类型转换。
 * 一般而言，allocator更为类型安全。
 *
 * @Author:  Ravitn
 * @Date: 2021-03-03 17:36
*/
#include <iostream>
#include <memory>
#include "LoggerFactory.h"
using namespace std;
class Test
{
public:
    Test()
    {
        std::cout << "Test Constructor"<< "\n";
    }
    ~Test()
    {
        std::cout << "Test DeConstructor"<< "\n";
    }

    Test(const Test &t)
    {
        std::cout << "Test Copy Constructor"<< "\n";
    }
};
int main(){
    auto log = LoggerFactory::getLogger("MemoryMain");
    allocator<Test> alloc;
    //申请三个单位的Test内存，未经初始化
    Test *pt = alloc.allocate(3);
    {
        //使用默认构造函数，构造对象（临时对象），，调用拷贝构造函数， 拷贝对象给相应的指针
        alloc.construct(pt, Test());
        std::cout << "===1" << "\n";
//        log->flush();
        alloc.construct(pt + 1, Test());
        std::cout << "===2"<< "\n";
        alloc.construct(pt + 2, Test());
    }
    std::cout << "destroy===0"<< "\n";
    alloc.destroy(pt);
    std::cout << "destroy===1"<< "\n";
    alloc.destroy(pt + 1);
    std::cout << "destroy===2"<< "\n";
    alloc.destroy(pt + 2);
    std::cout << "deallocate===3"<< "\n";
    alloc.deallocate(pt, 3);
    /*
     * allocator 底层默认使用operator new和operator delete， 创建时
     * 值分配未初始化的空间，如果初始化，则delete时，回调用相关的析构函数；
     */
    std::cout << "operator new[]==="<< "\n";
    Test * elements = static_cast<Test *> (operator new[](1 * sizeof(Test)));
    std::cout << "operator delete[]==="<< "\n";
    operator delete[](elements);
    std::cout << "operator new==="<< "\n";
    Test * singleElements = static_cast<Test *>(operator new(sizeof(Test)));
    std::cout << "operator delete==="<< "\n";
    operator delete(singleElements);
    /**
     * new, delete 分配删除时，回调用相关的对象的构造和析构函数，分配时会初始化相关对象
     */
    std::cout << "new[]==="<< "\n";
    Test * testArray = new Test[1];
    std::cout << "delete[]==="<< "\n";
    delete[] testArray;
    std::cout << "new==="<< "\n";
    Test *  singleTest = new Test();
    std::cout << "delete==="<< "\n";
    delete singleTest;



}

