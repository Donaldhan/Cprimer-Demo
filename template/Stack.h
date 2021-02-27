
/*
 * @ClassName: Stack
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-27 14:36
*/


#ifndef CPRIMER_DEMO_STACK_H
#define CPRIMER_DEMO_STACK_H

#include <vector>
using namespace std;

template <class T>
/**
 *
 * @tparam T
 */
class Stack {
private:
    vector<T> elems;     // 元素

public:
    void push(T const&);  // 入栈
    void pop();               // 出栈
    T top() const;            // 返回栈顶元素
    bool empty() const{       // 如果为空则返回真。
        return elems.empty();
    }
};

#endif CPRIMER_DEMO_STACK_H
