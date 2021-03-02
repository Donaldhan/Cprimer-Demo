
/*
 * @ClassName: TupleMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-02 17:16
*/
#include <tuple>
#include <iostream>
#include <cstring>
#include "LogFactory.h"

template<class... Args>
const std::string tupleToString(const std::tuple<Args...> &tp);
template<class... Args>
const std::string tupleToString(const std::tuple<Args...> &tp, int size);
int main() {

    //tp的类型实际是std::tuple<int&,std::string&, int&>
    auto log = LogFactory().getLogger("TupleMain");
    std::tuple<int, std::string, float> t1(10, "Test", 3.14);
//    log->info("tuple_cat :", tupleToString(t1,3));
    int n = 7;
//    tuple_cat连接多个tupe
    auto t2 = std::tuple_cat(t1, std::make_pair("Foo", "bar"), t1, std::tie(n));
    n = 10;
//    log->info("tuple_cat :", tupleToString(t2,3+2+3+1));
    //通过std::tie解包tuple, 通过tie解包后，tp中三个值会自动赋值给三个变量。
    int x, y;
    std::string a;
    std::tie(x, a, y) = t1;
    log->info("std::tie result x:{},a:{},y:{}", x, a, y);
    auto t3 = std::make_tuple("jack", "ma", 35);
    log->info("make_tuple second name:{}, first name:{}, age:{}", std::get<0>(t3), std::get<1>(t3), std::get<2>(t3));
}

/**
 * 转换tuple为string
 * @tparam Args
 * @param tp
 * @return
 */
template<class... Args>
const std::string tupleToString(const std::tuple<Args...> &tp) {
//    int size  = std::tuple_size<decltype(tp)>::value;
    std::string result = "";
    /*int size = 0;
    for (int i = 0; i < size; i++) {
        result = std::strcat(result, std::get<i>(tp)+",");
    }
    if(!result.empty()){
        return result.substr(0, result.length()-1);
    }*/
    return result;
}
/**
 *
 * @tparam Args
 * @param tp
 * @param size
 * @return
 */
template<class... Args>
const std::string tupleToString(const std::tuple<Args...> &tp, int size){
    std::string result = "";
 /*   for (int i = 0; i < size; i++) {
        result = std::strcat(result, std::get<i>(tp)+",");
    }
    if(!result.empty()){
        return result.substr(0, result.length()-1);
    }*/
    return result;
}
