//
// Created by Ravitn on 2021/2/24.
//
#include <iostream>
#include <cstring>
#include "golf.h"

using namespace std;

/**
 *
 * @param g
 * @param name
 * @param hc
 */
void setgolf(golf & g, const char * name, int hc){
    g.handicap = hc;
    int i =0;
    for(; i < Len && *(name+i) != '\0'; i++){
        g.fullname[i] = *(name + i);
    }
    if( i< Len -1){
        g.fullname[i] = '\0';
       /* while(i< Len){
            g.fullname[i] = '\0';
            i++;
        }*/
    }

}
/**
 *
 * @param g
 * @return
 */
int setgolf(golf & g){
//    string name;
    cout << "please input golf name:";
    cin >> g.fullname;
    int handicap;
    cout << "please input golf handicap(int):";
    cin >> g.handicap;
    if(strlen(g.fullname) >0){
        return 1;
    } else{
        return 0;
    }
}
/**
 *
 * @param g
 * @param hc
 */
void  handicap(golf & g, int hc){
    g.handicap = hc;

}
/**
 *
 * @param g
 */
void showgolf(const golf & g){
  cout << "golf name:" << g.fullname << " and handicap:" << g.handicap << "\n";
}