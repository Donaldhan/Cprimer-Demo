
/*
 * @ClassName: PointerPriorMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-09 10:30
*/


#include <iostream>
#include "LoggerFactory.h"

int main() {
    auto log = LoggerFactory::getLogger("PointerPriorMain");
    int a = 5;
    int *p = &a;
    int &rc = a;
    //++(*p)
    log->info("++*p:{}", ++*p);
    //*(++p)
    log->info("*++p:{}", *++p);
    //*(p++),
    log->info("*p++:{}", *p++);
    log->info("++rc:{}", ++rc);
    log->info("rc++:{}", rc++);

}