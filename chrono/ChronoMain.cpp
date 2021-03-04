
/*
 * @ClassName: ChronoMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-04 20:57
*/

#include <iostream>
#include <chrono>
# include "LoggerFactory.h"

using namespace std::chrono;

int main() {
    auto log = LoggerFactory::getLogger("ChronoMain");
    milliseconds foo(1000); // 1 second
    foo *= 60;

    std::cout << "duration (in periods): ";
    std::cout << foo.count() << " milliseconds.\n";

    std::cout << "duration (in seconds): ";
    std::cout << foo.count() * milliseconds::period::num / milliseconds::period::den;
    std::cout << " seconds.\n";
//     std::chrono::milliseconds is an instatiation of std::chrono::duration:
    seconds s(1);
    log->info("seconds:{}",s.count());
    minutes m(1);
    log->info("seconds:{}",m.count());
    hours h(1);
    log->info("hours:{}",h.count());
    std::cout << "time_point============" << "\n";
    // "start" and "end"'s type is std::chrono::time_point
    time_point<system_clock> start = system_clock::now();
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    time_point<system_clock> end = system_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time:" << elapsed.count() << "s\n";

    std::cout << "ctime,to_time_t, gmtime ============" << "\n";
    auto t = std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(t);
    std::string stt = std::ctime(&tt);
    std::cout << "ctime:"<< stt<< "\n" ;

    std::tm* now = std::gmtime(&tt);
    printf("%4d年%02d月%02d日 %02d:%02d:%02d\n",
           now->tm_year+1900, now->tm_mon+1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
    std::cout << "duration_cast============" << "\n";
    auto t1 = system_clock::now();
    std::this_thread::sleep_for(seconds(1));
    auto t2 = system_clock::now();

    // floating-point duration: no duration_cast needed
    duration<double, std::milli> fp_ms = t2 - t1;

    // integral duration: requires duration_cast
    auto int_ms = duration_cast<milliseconds>(fp_ms);

    // converting integral duration to integral duration of shorter divisible time unit: no duration_cast needed
    duration<long, std::micro> int_usec = int_ms;

    std::cout << "took " << fp_ms.count() << " ms, "
              << "or " << int_ms.count() << " whole milliseconds "
              << "(which is " << int_usec.count() << " whole microseconds)" << std::endl;

    std::cout << "now============" << "\n";
    // now 表示当前时间到时钟原点的毫秒数
    time_point<system_clock> nowx = system_clock::now();
    auto elapsedx = duration_cast<std::chrono::hours>(nowx.time_since_epoch());
    std::cout << elapsedx.count() << " 小时" << std::endl;
    std::cout << nowx.time_since_epoch().count() << " 毫秒"<< std::endl;

    std::cout << "time_point_cast============" << "\n";
    //time_point 想要进行精度转换，则使用 std::chrono::time_point_cast
    auto t1x = system_clock::now();
    auto t2x = time_point_cast<seconds>(t1x);
    std::cout << t1x.time_since_epoch().count() << " 毫秒" << std::endl;
    std::cout << t2x.time_since_epoch().count() << " 秒" << std::endl;
}

