
/*
 * @ClassName: Dog
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-26 16:55
*/

#include <iostream>
#include "Dog.h"
/*
Dog::Dog() {
  animalTypeDesc = "";
}
*/

Dog::Dog(string nm, const char *nickNM, int ag) : Animals(nm, nickNM, ag) {
    animalTypeDesc = "dog";
    setAnimalsType(DOG);
    cout << "Dog create " << getName() << "\n";
}
/**
 * 销毁时，回调用父类析构函数
 */
Dog::~Dog() {
    cout << "Dog destory " << getName() << "\n";
}

void Dog::show() const {
//    Animals::show();
    std::cout << "animalTypeDesc:" << animalTypeDesc << "\n";
    std::cout << "name:" << getName() <<" age:" << getAge() <<" animalsType:" << getAnimalsType()<< "\n";
}

/**
 * TOOD
 * 需要验证是否赋值
 * @param dog
 * @return
 */
/*Dog & Dog::operator=(const Dog &dog) {
    animalTypeDesc = dog.animalTypeDesc;
    return *this;
}*/

void Dog::move() const {
    std::cout << "Dog move" << "\n";
}

