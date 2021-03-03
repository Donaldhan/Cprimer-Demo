
/*
 * @ClassName: TupleUtil
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-03 9:51
*/


#ifndef CPRIMER_DEMO_TUPLEUTIL_H
#define CPRIMER_DEMO_TUPLEUTIL_H
#include <tuple>
/**
 *
 * @tparam Args
 * @param tp
 * @return
 */
template<class... Args>
const std::string tupleToString(const std::tuple<Args...> &tp);
/**
 *
 * @tparam Args
 * @param tp
 * @param size
 * @return
 */
template<class... Args, std::size_t size>
const std::string tupleToString(const std::tuple<Args...> &tp);
#endif CPRIMER_DEMO_TUPLEUTIL_H
