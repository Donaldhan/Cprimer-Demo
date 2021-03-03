
/*
 * @ClassName: BaseMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-03 15:17
*/
#include "LoggerFactory.h"
int main(){
    auto log = LoggerFactory::getLogger("BaseMain");
    size_t i = 0;
    for(;i< 2;i++) {
        log->info("size_t:{}", i);
    }



}


