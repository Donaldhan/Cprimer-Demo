
/*
 * @ClassName: ExceptionMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-08 16:48
*/


#include <iostream>
#include <exception>
#include "LoggerFactory.h"

using namespace std;

struct MyException : public exception
{
    const char * what () const throw ()
    {
        return "C++ Exception";
    }
};

int main()
{
    auto log = LoggerFactory::getLogger("ExceptionMain");
    try
    {
        throw MyException();
    }
    catch(MyException& e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
//        std::cerr << e << std::endl;
//        log->error(e);
    }
    catch(std::exception& e)
    {
        //其他的错误
    }
}