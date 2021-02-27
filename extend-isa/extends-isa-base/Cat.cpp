
/*
 * @ClassName: Cat
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-26 16:55
*/

#include <iostream>
#include "Cat.h"

//Cat::Cat() {
//    animalTypeDesc = "";
//}

Cat::Cat(string nm, const char *nickNM, int ag) : Animals(nm, nickNM, ag) {
    animalTypeDesc = "cat";
    setAnimalsType(CAT);
    cout << "Cat create " << getName() << "\n";
}
/**
 * 销毁时，回调用父类析构函数
 */
Cat::~Cat() {
    cout << "Cat destory " << getName() << "\n";
}

void Cat::show() const {
    Animals::show();
    std::cout << "animalTypeDesc:" << animalTypeDesc << "\n";
    std::cout << "name:" << getName() << " age:" << getAge()  <<" animalsType:" << getAnimalsType()<< "\n";

}
/**
 * TOOD
 * 需要验证是否赋值
 * @param dog
 * @return
 */
/*Cat & Cat::operator=(const Cat &cat) {
    animalTypeDesc = cat.animalTypeDesc;
    return *this;
}*/

void Cat::move() const {
    std::cout << "Cat move" << "\n";
}