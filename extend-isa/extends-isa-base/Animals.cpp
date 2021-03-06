
/*
 * @ClassName: Animalsx
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-26 16:22
*/

#include <iostream>
#include <cstring>
#include <utility>
#include "Animals.h"

Animals::Animals(string nm, const char *nickNM, int ag) {
    name = nm;
    int len = strlen(nickNM);
    nickName = new char[len+1];
    strcpy(nickName, nickNM);
    age = ag;
    cout << "Animals create " << getName() << "\n";
    std::cout << "Animals create name:" << name << " nickName: " << nickName <<" age:" << age <<" animalsType:" << animalsType<< "\n";
}


/*
Animals::Animals(const Animals & animals) {
    name = animals.name;
    nickName = animals.nickName;
    age = animals.age;
}
*/

Animals::~Animals(){
  delete nickName;
  cout << "Animals destory " << name << "\n";
}

void Animals::show() const {
   std::cout << "name:" << name << " nickName:" << nickName <<" age:" << age <<" animalsType:" << animalsType<< "\n";
}

/*Animals &  Animals::operator=(const Animals & animals) {
    if(this == &animals){
        return *this;
    }
     name = animals.name;
     nickName = animals.nickName;
     age = animals.age;
     animalsType = animals.animalsType;
    return *this;
}*/

const string Animals::getName() const {
    return name;
}

void Animals::setName(const string &name) {
    Animals::name = name;
}

int Animals::getAge() const {
    return age;
}

void Animals::setAge(int age) {
    Animals::age = age;
}

int Animals::getAnimalsType() const {
    return animalsType;
}

void Animals::setAnimalsType(int animalsType) {
    Animals::animalsType = animalsType;
}

