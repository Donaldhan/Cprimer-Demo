
/*
 * @ClassName: LogFactory
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-02 20:17
*/


#include "LogFactory.h"

/**
 *
 * @param logName
 * @return
 */
std::shared_ptr<spdlog::logger> LogFactory::getLogger(const std::string logName) {
    spdlog::set_async_mode(4096);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e][%n][%t][%l] %v");
    //创建控制台对象指针
    auto console_log = spdlog::stdout_logger_mt("console");
    //创建文件对象指针
    auto file_log = spdlog::rotating_logger_mt("file", "cprimer.log", 100 * 1024, 2);
    //将以上两种日志对象 sink 组合在一起
    spdlog::sinks_init_list sink_list = { console_log->sinks().front(), file_log->sinks().front() };
    //创建一个新的日志对象，以上面两个日志对象作为初始化参数，即实现了同时输出 console 和 file
    return spdlog::create(logName, sink_list);
}
/**
 *
 * @param logName
 * @return
 */
std::shared_ptr<spdlog::logger> LogFactory::logger(const std::string logName) {
    spdlog::set_async_mode(4096);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e][%n][%t][%l] %v");
    //创建控制台对象指针
    auto console_log = spdlog::stdout_logger_mt("console");
    //创建文件对象指针
    auto file_log = spdlog::rotating_logger_mt("file", "cprimer.log", 100 * 1024, 2);
    //将以上两种日志对象 sink 组合在一起
    spdlog::sinks_init_list sink_list = { console_log->sinks().front(), file_log->sinks().front() };
    //创建一个新的日志对象，以上面两个日志对象作为初始化参数，即实现了同时输出 console 和 file
    return spdlog::create(logName, sink_list);
}
