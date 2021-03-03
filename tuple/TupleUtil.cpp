
/*
 * @ClassName: TupleUtil
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-03 9:51
*/


#include "TupleUtil.h"
#include <cstring>
/**
 * 转换tuple为string
 * @tparam Args
 * @param tp
 * @return
 */
template<class... Args>
const std::string tupleToString(const std::tuple<Args...> &tp) {
    std::size_t size  = std::tuple_size<decltype(tp)>::value;
    std::string result = "";
    for (int i = 0; i < size; i++) {
//        result = std::strcat(result, std::get<i>(tp)+",");
    }
    if(!result.empty()){
        return result.substr(0, result.length()-1);
    }
    return result;
}
/**
 *
 * @tparam Args
 * @param tp
 * @param size
 * @return
 */
template<class... Args, std::size_t size>
const std::string tupleToString(const std::tuple<Args...> &tp){
    std::string result = "";
       for (std::size_t i = 0; i < size; i++) {
//           result = std::strcat(result, std::get<i>(tp)+",");
       }
       if(!result.empty()){
           return result.substr(0, result.length()-1);
       }
    return result;
}
