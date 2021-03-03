
/*
 * @ClassName: Lamdba
 * @Description:
 * [captures] (params) -> ret {Statments;}
 * [] 不截取任何变量
 * [&} 截取外部作用域中所有变量，并作为引用在函数体中使用
 * [=] 截取外部作用域中所有变量，并拷贝一份在函数体中使用
 * [=, &foo] 截取外部作用域中所有变量，并拷贝一份在函数体中使用，但是对foo变量使用引用
 * [bar]  截取bar变量并且拷贝一份在函数体重使用，同时不截取其他变量
 * [this] 截取当前类中的this指针。如果已经使用了&或者=就默认添加此选项。
 * @Author:  Ravitn
 * @Date: 2021-03-03 15:22
*/
#include <cstring>
#include <iostream>
#include <vector>
#include "LoggerFactory.h"

int main() {
    auto log = LoggerFactory::getLogger("LamdbaMain");

    auto func = [&]() { log->info("hello lamdba"); };
    func(); // now call the function

    auto funcx = []() -> int { return 1; };
    int a = funcx();
    std::cout << "funcx int adress 0:" << &a << "\n";
    log->info("no params funx result :{}", a);

    std::string name = "jack";
    std::cout << "name address 0:" << &name << "\n";
    const std::string &namePrix = "ravitn";
    auto funcxx = [=, &name](const std::string &prix) {
        std::cout << "funcx int adress 1:" << &a << "\n";
        std::cout << "name address 1:" << &name << "\n";
        return name.find(prix) != std::string::npos;
    };
    bool isFind = funcxx(namePrix);
    log->info("copy var funxx, isFind:{}", isFind);

    auto funcxxx = [name]() -> std::string {
        std::cout << "name address 2:" << &name << "\n";
        return name;
    };
    funcxxx();

    std::vector<int> v;
    v.push_back( 1 );
    v.push_back( 2 );
    for_each( v.begin(), v.end(), [&] (int val)
    {
        log->info("vector val:{}",val);
    });
}
