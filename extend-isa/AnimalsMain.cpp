
/*
 * @ClassName: AnimalsMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-26 16:54
*/
#include <iostream>
#include <cstring>
#include "extends-isa-base/Animals.h"
#include "extends-isa-base/Cat.h"
#include "extends-isa-base/Dog.h"

void test();

void testPointer();

void testPointerX();

/**
 *
 * @return
 */
int main() {
//     test();
//    testPointer();
     testPointerX();
}

/**
 *
 */
void test() {
   /* Animals animals;
    animals.show();
    std::cout << "==============\n";
    Dog dog;
    dog.show();
    std::cout << "==============\n";
    Cat cat;
    cat.show();
    std::cout << "==============\n";
    string dogNickName = "jack-nb";
    dog = Dog("jack-dog", dogNickName.c_str(), 2);
    dog.show();
    dog.move();
    std::cout << "==============\n";
    string catNickName = "mark-nb";
    cat = Cat("mark-cat", catNickName.c_str(), 1);
    cat.show();
    cat.move();
    std::cout << "==============\n";
    animals = dog;
    animals.show();
    std::cout << "==============\n";
    animals = cat;
    animals.show();
    std::cout << "==============\n";
    string anmNickName = "animals-nb";
    animals = Animals("andy-animals", anmNickName.c_str(), 3);
    animals.show();;*/
}

/**
 *
 */
void testPointer() {
   /* Animals *animals;
    Dog dog;
    dog.show();
    std::cout << "==============\n";
    Cat cat;
    cat.show();
    std::cout << "==============\n";
    string dogNickName = "jack-nb";
    dog = Dog("jack-dog", dogNickName.c_str(), 2);
    dog.show();
    dog.move();
    std::cout << "==============\n";
    string catNickName = "mark-nb";
    cat = Cat("mark-cat", catNickName.c_str(), 1);
    cat.show();
    cat.move();
    std::cout << "==============\n";
    animals = &dog;
    animals->show();
    std::cout << "==============\n";
    animals = &cat;
    animals->show();
    delete animals;
    std::cout << "==============\n";*/
}

/**
 *
 */
void testPointerX() {
    Animals *animals;
    string dogNickName = "jack-nb";
    Dog dog = Dog("jack-dog", dogNickName.c_str(), 2);
    dog.show();
    dog.move();
    std::cout << "==============\n";
    string catNickName = "mark-nb";
    Cat cat = Cat("mark-cat", catNickName.c_str(), 1);
    cat.show();
    cat.move();
    std::cout << "==============\n";
    animals = &dog;
    animals->show();
    std::cout << "==============\n";
    animals = &cat;
    animals->show();
    std::cout << "==============\n";
    delete animals;
    std::cout << "==============\n";
}