
/*
 * @ClassName: ConcurrentQueue
 * @Description:
 * 问题：为什么模板类的.cpp 与.h文件不能分开
    1.
    在某些编译器中是可以分开，但是在很多的编译器中是不可以分开的。
    虽然某些编译器在模板这种情况下做了支持可以将函数的实现和声明的分开，但是个人认为这并不是一个很好的做法。
    2.
    我们都知道，在编译的时候，并不对模板本身进行编译。它就像一个未装填任何东西的空箱子，是不需要搬到可执行文件这辆卡车上的。
    但当有一个确定的类型被装进了模板的这个箱子中时候，编译器就非常确定了该实例占用的空间大小等（即箱子的重量等）信息，
     这时候编译器才会将该模板按照一定的方式进行展开编译实现。
    3.
    这样看来，模板的整个声明与实现，其实完全都是一个声明，因为没有确定的数据类型，所以在实例之前，
     编译器无法知道该模板应以什么样的方式去编译。这样理解起来，那么模板类所有的信息，理应都放在头文件中。
    4.
    对于某些编译器对这种分离的支持，实在是会误导我们对模板类的理解。
    5.
    有些巧妙的方法是，在头文件最后面包含cpp文件。还有些是直接在使用的时候包含cpp文件。
     其实都是告诉编译器，这只是一个头文件的声明而已，没有实现过程。
     * @Author:  Ravitn
 * @Date: 2021-03-06 15:18
*/


#ifndef CPRIMER_DEMO_CONCURRENTQUEUE_H
#define CPRIMER_DEMO_CONCURRENTQUEUE_H

#include <mutex>
#include <memory>
#include <condition_variable>

template<typename T>
class ConcurrentQueue
{
private:
    struct node
    {
        std::shared_ptr<T> data;
        std::unique_ptr<node> next;
    };

    std::mutex head_mutex;
    std::unique_ptr<node> head;
    std::mutex tail_mutex;
    node* tail;
    std::condition_variable data_cond;
    /**
     *
     * @return
     */
    std::unique_ptr<node> pop_head()
    {
        std::unique_ptr<node> const old_head=std::move(head);
        head=std::move(old_head->next);
        return old_head;
    }
    /**
     *
     * @return
     */
    node* get_tail()
    {
        std::lock_guard<std::mutex> tail_lock(tail_mutex);
        return tail;
    }
    /**
     *
     * @return
     */
    std::unique_ptr<node> try_pop_head()
    {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if(head.get()==get_tail())
        {
            return std::unique_ptr<node>();
        }
        return pop_head();
    }
    /**
     *
     * @param value
     * @return
     */
    std::unique_ptr<node> try_pop_head(T& value)
    {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if(head.get()==get_tail())
        {
            return std::unique_ptr<node>();
        }
        value=std::move(*head->data);
        return pop_head();
    }
    /**
     *
     * @return
     */
    std::unique_lock<std::mutex> wait_for_data()
    {
        std::unique_lock<std::mutex> head_lock(head_mutex);
        data_cond.wait(head_lock,[&]{return head!=get_tail();});
        return std::move(head_lock);
    }
    /**
     *
     * @return
     */
    std::unique_ptr<node> wait_pop_head()
    {
        std::unique_lock<std::mutex> head_lock(wait_for_data());
        return pop_head();
    }
    /**
     *
     * @param value
     * @return
     */
    std::unique_ptr<node> wait_pop_head(T& value)
    {
        std::unique_lock<std::mutex> head_lock(wait_for_data());
        value=std::move(*head->data);
        return pop_head();
    }
public:
    ConcurrentQueue():
            head(new node),tail(head.get())
    {}
    /**
     *禁止默认拷贝行为
     * @param other
     */
    ConcurrentQueue(const ConcurrentQueue& other)=delete;
    /**
     * 禁止默认赋值行为
     * @param other
     * @return
     */
    ConcurrentQueue& operator=(const ConcurrentQueue& other)=delete;
    /**
     *
     * @param new_value
     */
    void push(T new_value)
    {
        std::shared_ptr<T> new_data(
                std::make_shared<T>(std::move(new_value)));
        std::unique_ptr<node> p(new node);
        {
            std::lock_guard<std::mutex> tail_lock(tail_mutex);
            tail->data=new_data;
            node* const new_tail=p.get();
            tail->next=std::move(p);
            tail=new_tail;
        }
        data_cond.notify_one();
    }

    /**
     *
     * @return
     */
    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_ptr<node> const old_head=wait_pop_head();
        return old_head->data;
    }
    /**
     *
     * @param value
     */
    void wait_and_pop(T& value)
    {
        std::unique_ptr<node> const old_head=wait_pop_head(value);
    }
    /**
     *
     * @return
     */
    std::shared_ptr<T> try_pop()
    {
        std::unique_ptr<node> const old_head=try_pop_head();
        return old_head?old_head->data:std::shared_ptr<T>();
    }
    /**
     *
     * @param value
     * @return
     */
    bool try_pop(T& value)
    {
        std::unique_ptr<node> const old_head=try_pop_head(value);
        return old_head;
    }
    /**
     *
     */
    void empty()
    {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        return (head==get_tail());
    }
};


#endif CPRIMER_DEMO_CONCURRENTQUEUE_H
