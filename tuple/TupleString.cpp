
/*
 * @ClassName: TupleStrings
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-03 10:58
*/


#include "TupleString.h"
#include <cstring>

//template<class Tuple, std::size_t N>
//TupleString::tuple2String(const Tuple& t, std::string result)
//    {
//        TupleString<Tuple, N - 1>::tuple2String(t, result);
//        result = std::strcat(result,std::get<N - 1>(t));
//    }
//
//template<class Tuple>
//TupleString::tuple2String(const Tuple& t, std::string result)
//    {
//        result = strcat(result,std::get<0>(t));
//    }

/**
 *
 * @tparam Args
 * @param t
 * @return
 */
//template<class... Args>
//const std::string tupleToString(const std::tuple<Args...>& t)
//{
//    std::string result = "";
//    result = std::strcat(result "(")
//    TupleString<decltype(t), sizeof...(Args)>::tuple2String(t, result);
//    result = std::strcat(result, ")");
//    return result;
//}