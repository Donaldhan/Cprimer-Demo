
/*
 * @ClassName: PersionMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-25 14:47
*/
#include <iostream>
//#include <cstring>
#include "Persion.h"

using namespace std;

int main() {
    string lname;
    string fname;
    cout << "input first name:";
    cin >> lname;
    cout << "input last name:";
    cin >> fname;
    Persion rain = Persion(lname, fname.c_str());
    rain.show();
    rain.formalShow();
    Persion *mark =  new Persion();
    mark->show();
    mark->formalShow();
    delete mark;
}


