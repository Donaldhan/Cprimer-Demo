
/*
 * @ClassName: Pointer
 * @Description:
 *
 * 我们大多数场景下用到的应该都是 unique_ptr。
unique_ptr 代表的是专属所有权，即由 unique_ptr 管理的内存，只能被一个对象持有。
所以，unique_ptr 不支持复制和赋值

 unique_ptr 代表的是专属所有权，如果想要把一个 unique_ptr 的内存交给另外一个 unique_ptr 对象管理。
 只能使用 std::move 转移当前对象的所有权。转移之后，当前对象不再持有此内存，新的对象将获得专属所有权。

 std::shared_ptr 是通过指针保持对象共享所有权的智能指针。多个 shared_ptr 对象可占有同一对象。下列情况之一出现时销毁对象并解分配其内存：

最后剩下的占有对象的 shared_ptr 被销毁；
最后剩下的占有对象的 shared_ptr 被通过 operator= 或 reset() 赋值为另一指针。


 std::weak_ptr 的另一用法是打断 std::shared_ptr 所管理的对象组成的环状引用。若这种环被孤立（例如无指向环中的外部共享指针），
 则 shared_ptr 引用计数无法抵达零，而内存被泄露。能令环中的指针之一为弱指针以避免此情况。

 auto_ptr可以复制和赋值，存在指针对象被悬空，内存泄漏

 *
 *
 * @Author:  Ravitn
 * @Date: 2021-03-03 16:15
*/
#include <cstring>
#include <memory>
#include "LoggerFactory.h"

using namespace std;
class Persion{
private:
    string name;
public:
    Persion(string nm)
    {name = nm;}
    const string getName(){
        return name;
    }
    ~Persion()
    {
        // 忘记 delete w
    }

};
int main() {
    auto log = LoggerFactory::getLogger("pointerMain");
    string name = "ravitn";
    unique_ptr<string> unique_ptr1(&name);
    // 编译错误,unique_ptr 不支持复制和赋值
//    auto name1 = unique_ptr1;
//只能使用 std::move 转移当前对象的所有权。转移之后，当前对象不再持有此内存，新的对象将获得专属所有权。
    auto name1 = move(unique_ptr1);
    log->info("move after unique_ptr1 is null:{}" , unique_ptr1 == nullptr);
    log->info("move after name1 is null:{}" , name1 == nullptr);
    log->info("move after name1:{}",name1->c_str());
    shared_ptr<Persion> sharedPtrPersion = make_shared<Persion>("ravitn");
    shared_ptr<Persion> sharedPtrP1 = sharedPtrPersion;
    log->info("shared_ptr is same:{}" , sharedPtrPersion == sharedPtrP1);
    log->info("sharedPtrPersion name :{}",sharedPtrPersion->getName());
    log->info("sharedPtrP1 name :{}",sharedPtrP1->getName());
    log->info("sharedPtrPersion userCount :{}",sharedPtrPersion.use_count());
    log->info("sharedPtrP1 userCount :{}",sharedPtrP1.use_count());
    auto  sharedPtrP2 = move(sharedPtrP1);
    log->info("after move is same:{}", sharedPtrP1 == nullptr);
    log->info("after move sharedPtrPersion userCount :{}",sharedPtrPersion.use_count());
    log->info("after move sharedPtrP1 userCount :{}",sharedPtrP1.use_count());
    log->info("after move sharedPtrP2 userCount :{}",sharedPtrP2.use_count());
    log->info("after move is same:{}",sharedPtrPersion == sharedPtrP2);
    log->info("sharedPtrPersion name :{}",sharedPtrPersion->getName());
    //nullptr
//    log->info("sharedPtrP1 name :{}",sharedPtrP1->getName());
    log->info("sharedPtrP2 name :{}",sharedPtrP2->getName());
    auto_ptr<Persion> autoPtr(new Persion("123"));
    auto_ptr<Persion> autoPtr1(new Persion("456"));
    //会导致autoPtr1执行的指针对象悬空，内存泄漏
    autoPtr1 = autoPtr;
    log->info("auto_ptr persion name :{}",autoPtr1->getName());
    log->info("auto_ptr persion autoPtr is null :{}",autoPtr.get() == nullptr);
    log->info("auto_ptr persion autoPtr1 is null :{}",autoPtr1.get() == nullptr);
    log->info("after move sharedPtrP2 userCount :{}",sharedPtrP2.use_count());
    weak_ptr<Persion> weakPtr = sharedPtrP2;
    log->info("after move sharedPtrP2 userCount :{}",sharedPtrP2.use_count());
    log->info("weakPtr userCount :{}", weakPtr.use_count());
}
