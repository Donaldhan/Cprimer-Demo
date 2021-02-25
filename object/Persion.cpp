
/*
 * @ClassName: Persion
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-25 14:13
*/

#include <iostream>
#include <cstring>
#include "Persion.h"

using namespace std;

Persion::Persion(const string &ln, const char *fn) {
    lname = ln;
    strcpy(fname, fn);
}

void Persion::show() const {
    //new
    cout << "lastName:" << lname << " firstName:" << fname << "\n";

}

void Persion::formalShow() const {
    cout << "firstName:" << fname << " lastName:" << lname << "\n";
}

Persion::~Persion() {
//    delete
    cout <<  fname <<  " is dead \n";
}

const string &Persion::getLname() const {
    return lname;
}

void Persion::setLname(const string &lname) {
    Persion::lname = lname;
}

const char *Persion::getFname() const {
    return fname;
}
