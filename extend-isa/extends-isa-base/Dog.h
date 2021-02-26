
/*
 * @ClassName: Dog
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-26 16:55
*/


#ifndef CPRIMER_DEMO_DOG_H
#define CPRIMER_DEMO_DOG_H

#include "Animals.h"
class Dog : public Animals{
private:
    string animalTypeDesc;
public:
    Dog();
    Dog(string nm, const char * nickNM, int ag);
    /**
     *
     */
    ~Dog() override;
    void show() const override;
    /**
     * 赋值构造
     * @param animals
     * @return
     */
    Dog & operator=(const Dog & dog);
};


#endif CPRIMER_DEMO_DOG_H
