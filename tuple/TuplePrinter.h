
/*
 * @ClassName: TuplePrinter
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-03 10:29
*/


#ifndef CPRIMER_DEMO_TUPLEPRINTER_H
#define CPRIMER_DEMO_TUPLEPRINTER_H
#include <string>
template<class Tuple, std::size_t N>
struct TuplePrinter {
    static void print(const Tuple& t)
    {
        TuplePrinter<Tuple, N - 1>::print(t);
        std::cout << ", " << std::get<N - 1>(t);
    }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1>{
    static void print(const Tuple& t)
    {
        std::cout << std::get<0>(t);
    }
};

template<class... Args>
void printTuple(const std::tuple<Args...>& t)
{
    std::cout << "(";
    TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
    std::cout << ")\n";
}
#endif CPRIMER_DEMO_TUPLEPRINTER_H
