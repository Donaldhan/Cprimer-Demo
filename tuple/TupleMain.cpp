
/*
 * @ClassName: TupleMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-02 17:16
*/
#include <tuple>
#include <iostream>
#include <cstring>
#include "LoggerFactory.h"
#include "TupleUtil.h"
#include "TuplePrinter.h"
//#include "TupleString.h"
#include "json.hpp"
using json = nlohmann::json;
int main() {

    //tp的类型实际是std::tuple<int&,std::string&, int&>
    auto log = LoggerFactory::getLogger("TupleMain");
    std::tuple<int, std::string, float> t1(10, "Test", 3.14);
//    json json1 = t1;
//    log->info("tuple_cat :{}", tupleToString(t1));
    printTuple(t1);
    int n = 7;
//    tuple_cat连接多个tupe
    auto t2 = std::tuple_cat(t1, std::make_pair("Foo", "bar"), t1, std::tie(n));
    n = 10;
//    log->info("tuple_cat :{}", tupleToString(t2));
    printTuple(t2);
//     std::cout << t2 << "\n";
    //通过std::tie解包tuple, 通过tie解包后，tp中三d个值会自动赋值给三个变量。
    int x, y;
    std::string a;
    std::tie(x, a, y) = t1;
    log->info("std::tie result x:{},a:{},y:{}", x, a, y);
    auto t3 = std::make_tuple("jack", "ma", 35);
    log->info("make_tuple second name:{}, first name:{}, age:{}", std::get<0>(t3), std::get<1>(t3), std::get<2>(t3));
}

