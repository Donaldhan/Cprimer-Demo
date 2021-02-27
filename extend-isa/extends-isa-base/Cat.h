
/*
 * @ClassName: Cat
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-26 16:55
*/


#ifndef CPRIMER_DEMO_CAT_H
#define CPRIMER_DEMO_CAT_H

#include "Animals.h"
class Cat : public Animals{
private:
    string animalTypeDesc;
public:
//    Cat();
    Cat(string nm, const char * nickNM, int ag);
    /**
     *
     */
    ~Cat() override;
    void show() const override;
    void move() const ;
    /**
     * 赋值构造
     * @param animals
     * @return
     */
//    Cat & operator=(const Cat & cat);
};


#endif CPRIMER_DEMO_CAT_H
