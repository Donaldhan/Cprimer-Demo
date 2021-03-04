//
// Created by Ravitn on 2021/2/24.
//
#include <iostream>
//#include <cstring>
#include "golf.h"

using namespace std;
//using namespace golfNameSpace;
/*
 * 在编程语言中，命名空间是一种特殊的作用域，它包含了处于该作用域中的所有标示符，
 * 而且其本身也是由标示符表示的。命名空间的使用目的是为了将逻辑相关的标示符限定在一起，
 * 组成相应的命名空间，可使整个系统更加模块化，最重要的是它可以防止命名冲突。
 * 就好比在两个函数或类中定义相同名字的对象一样，利用作用域标示符限定该对象是哪个类里定义的。
 * @return
 */
int main() {
    golfNameSpace::golf andy;
    setgolf(andy);
    showgolf(andy);
    //TODO 如何读取字符
//  char * name = "ravitn";
    char *name = new char[5];
    std::cout << "input golf name size 4 char:";
    for (int i = 0; i < 4; i++) {
        *(name + 1) = cin.get();
    }
    name[4] = '\0';
    cout << "input golf name end \n";
    cout << "input golf name:" << name << "\n";
//  string name = "ravitn";
    setgolf(andy, name, 2);
    showgolf(andy);
//  delete name;
}
