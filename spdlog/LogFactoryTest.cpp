
/*
 * @ClassName: LogFactoryTest
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-02 20:29
*/
#include "LogFactory.h"
int main(){
    auto log = LogFactory().getLogger("LogFactoryTest");
    log->info("Test spdlog output:name:{}, age:{}", "jack", 23);
    log->flush();
}
