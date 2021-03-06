/*
 * @ClassName: LogFactory
 * @Description:
 * @Author:  Ravitn
 * @Date: 2021-03-02 20:17
*/


#ifndef CPRIMER_DEMO_LOGFACTORY_H
#define CPRIMER_DEMO_LOGFACTORY_H

#include <string>
#include "spdlog.h"

class LogFactory {
public:
    /**
     *
     * @param logName
     * @return
     */
     static std::shared_ptr<spdlog::logger> getLogger(const std::string logName);
     /**
      *
      * @param logName
      * @return
      */
     static std::shared_ptr<spdlog::logger> logger(const std::string logName);
};


#endif CPRIMER_DEMO_LOGFACTORY_H
