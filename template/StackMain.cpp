
/*
 * @ClassName: StackMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-27 14:38
*/
#include <iostream>
#include <string>
#include "Stack.h"

/**
 *
 * CMakeFiles\Cprimer_Template.dir/objects.a(StackMain.cpp.obj): In function `main':
F:/github/Cprimer-Demo/template/StackMain.cpp:22: undefined reference to `Stack<int>::push(int const&)'
F:/github/Cprimer-Demo/template/StackMain.cpp:23: undefined reference to `Stack<int>::top() const'
F:/github/Cprimer-Demo/template/StackMain.cpp:25: undefined reference to `Stack<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::push(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
F:/github/Cprimer-Demo/template/StackMain.cpp:26: undefined reference to `Stack<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::top() const'
F:/github/Cprimer-Demo/template/StackMain.cpp:27: undefined reference to `Stack<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::pop()'
F:/github/Cprimer-Demo/template/StackMain.cpp:28: undefined reference to `Stack<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::pop()'
collect2.exe: error: ld returned 1 exit status
 * todo TEST
 * @return
 */
int main()
{
    try {
        Stack<int> intStack;  // int 类型的栈
        Stack<string> stringStack;    // string 类型的栈
        // 操作 int 类型的栈
        intStack.push(7);
        cout << intStack.top() <<endl;
        // 操作 string 类型的栈
        stringStack.push("hello");
        cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const& ex) {
        cerr << "Exception: " << ex.what() <<endl;
        return -1;
    }
}
