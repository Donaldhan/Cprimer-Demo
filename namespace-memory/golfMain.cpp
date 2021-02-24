//
// Created by Ravitn on 2021/2/24.
//
#include <iostream>
//#include <cstring>
#include "golf.h"
using namespace std;
/**
 *
 * @return
 */
int main(){
  golf andy;
  setgolf(andy);
  showgolf(andy);
  //TODO 如何读取字符
//  char * name = "ravitn";
  char * name = new char[5];
  cout << "input golf name size 4 char:";
  for(int i = 0; i< 4; i++){
      *(name + 1) = cin.get();
  }
  name[4] = '\0';
  cout << "input golf name end \n";
  cout << "input golf name:" << name << "\n";
//  string name = "ravitn";
  setgolf(andy, name , 2);
  showgolf(andy);
//  delete name;
}
