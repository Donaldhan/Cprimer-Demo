
/*
 * @ClassName: Persion
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-25 14:13
*/


#ifndef CPRIMER_DEMO_PERSION_H
#define CPRIMER_DEMO_PERSION_H


#include <cstring>
//#include <string>

using namespace std;

class Persion {
private:
    static const int LIMIT = 25;
    string lname; //
    char fname[LIMIT];
public:
    Persion() {
        lname = "unkonw";
        fname[0] = '\0';
    }

    const string &getLname() const;

    void setLname(const string &lname);

    const char *getFname() const;

    /**
     *
     * @param ln
     * @param fn
     */
    Persion(const string &ln, const char *fn = "Ravitn");
    /**
     *
     */
    ~ Persion();
    /**
     *
     */
    void show() const;
    /**
     *
     */
    void formalShow() const;



};


#endif CPRIMER_DEMO_PERSION_H
