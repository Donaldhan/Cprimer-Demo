
/*
 * @ClassName: BoostMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-04 17:25
*/
#include <boost/algorithm/string.hpp>
#include <locale>
#include <iostream>
#include <clocale>
#include <boost/regex.hpp>
#include <boost/tokenizer.hpp>
int main(){
    std::string s = "Boris Schäling";
    std::cout << boost::algorithm::to_upper_copy(s) << std::endl;

    std::string sr = "Boris Schäling";
    boost::regex expr("\\w+\\s\\w+");
    std::cout << boost::regex_match(sr, expr) << std::endl;

    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    std::string st = "Boost C++ libraries";
    tokenizer tok(st);
    for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
        std::cout << *it << std::endl;
}

