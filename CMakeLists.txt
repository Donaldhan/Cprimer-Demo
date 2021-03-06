# x.x是自身需要的Clion版本
# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.17)

# 自己的项目名称
#project(Cprimer_Demo "1.0.0")
#project(Cprimer_Demo 1.0.0)
project(Cprimer_Demo VERSION 1.3.8)

# 版本号.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 3)
set (Tutorial_VERSION_PATCH 8)



# xx是你创建项目的时候使用的C++标准

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS$ {CMAKE_CXX_FLAGS} -std = c ++ 11)

#set(CMAKE_SYSTEM_NAME Windows)
#set(TOOLCHAIN_PATH D:\\mingw-w64\\mingw32)
#set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}\\bin\\gcc.exe)
#set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}\\bin\\g++.exe)
#set(CMAKE_WINDOWS_KITS_10_DIR "")

#cmake -G "MinGW Makefiles"

#当编译一个需要第三方库的项目时，需要知道：
#去哪找头文件（.h），-I（GCC）
#INCLUDE_DIRECTORIES()
#去哪找库文件（.so/.dll/.lib/.dylib/...），-L（GCC）
#LINK_DIRECTORIES()
#需要链接的库文件的名字：-l（GCC）
#LINK_LIBRARIES(库名称即可)
#添加头文件搜索路径
include_directories(include/spdlog)
include_directories(include/json)
include_directories(concurrent/queue)
#LogFactory
include_directories(spdlog)
#include_directories(E:\\blockchain\\c++\\boost_1_65_0)
include_directories(E:/blockchain/c++/boost_1_75_0)

# Logger
include_directories(logger)
#include_directories (${PROJECT_SOURCE_DIR}/logger)
#add_subdirectory (logger)



#include_directories(F:\\CPlus\\boost_1_75_0)
#include_directories(E:\\blockchain\\c++\\boost_1_75_0\\libs)

#添加库文件搜索路径
#link_directories(/usr/local/Cellar/boost/1.68.0_1/lib/)


#add_compile_options(-std=c++0x)



#target_include_directories(Cprimer_Demo PUBLIC "${PROJECT_BINARY_DIR}")

#   cmake start
# 将构建目录添加到 include 的搜索路径中以便找到
# TutorialConfig.h 文件
include_directories("${PROJECT_BINARY_DIR}")

# 配置一个头文件将一些 CMake 设置传入到源代码中
# 以 TutorialConfig.h.in 为模版，替换相关变量
# 以生成 TutorialConfig.h
configure_file ("${PROJECT_SOURCE_DIR}/cmake/TutorialConfig.h.in" "${PROJECT_BINARY_DIR}/cmake/TutorialConfig.h")

# “+”要更改成你想给这个结局方案的名称（这个可自定义），“*”是该主项目下的源文件名称
# “+”与“*”之间有空格。
# 如果想在主项目中添加文件，则在这里添加，如果在子文件夹中，则在子项目中添加
#include_directories(${WinSDK})
#target_link_libraries(tutorial ${WinSDK})
add_executable(tutorial tutorial/TutorialMain.cpp)
add_executable(Cprimer_Demo main.cpp)

# cmake demo end




# add_executable(Cprimer_Demo 6/good_printmain.cpp)
# add_library(test_library STATIC 7/Sales_data.cpp)
add_executable(Cprimer_Add_Item cplus/7/add_item.cpp cplus/7/Sales_data.h cplus/7/Sales_data.cpp extend-isa/extends-isa-base/Animals.h)

# 内存模型、命令空间
add_executable(namespace-memory namespace-memory/golf.h namespace-memory/golf.cpp namespace-memory/golfMain.cpp)

# 对象
add_executable(Cprimer_Object object/Persion.cpp object/Persion.h object/PersionMain.cpp)

# 操作符重载
add_executable(Cprimer_Operator operator/Score.cpp operator/Score.h operator/ScoreMain.cpp)

# 类继承
add_executable(Cprimer_Extends extend-isa/extends-isa-base/Animals.cpp extend-isa/AnimalsMain.cpp extend-isa/extends-isa-base/Cat.cpp extend-isa/extends-isa-base/Cat.h extend-isa/extends-isa-base/Dog.cpp extend-isa/extends-isa-base/Dog.h)

# 模板
add_executable(Cprimer_Template template/Stack.cpp template/Stack.h template/StackMain.cpp)

# 异常
add_executable(Cprimer_exception exception/ExceptionMain.cpp)

# C++Tuple元组的详细用法
add_executable(Cprimer_Tuple tuple/TupleMain.cpp tuple/TupleUtil.cpp tuple/TupleUtil.h tuple/TuplePrinter.h tuple/TupleString.cpp tuple/TupleString.h)

# spdlog
add_executable(Cprimer_spdlog spdlog/SpdLogMain.cpp spdlog/LogFactory.cpp spdlog/LogFactory.h spdlog/LogFactoryTest.cpp logger/LoggerFactory.h)
add_executable(LogFactory spdlog/LogFactoryTest.cpp spdlog/LogFactory.cpp spdlog/LogFactory.h)


# 集合
add_executable(Collection collections/CollectionsMain.cpp)




# 基础
add_executable(Base base/BaseMain.cpp)

# Lamdba
add_executable(Lamdba lambda/LamdbaMain.cpp)

# 智能指针
add_executable(pointer pointer/PointerMain.cpp)
add_executable(pointer-prior pointer/prior/PointerPriorMain.cpp)

# 内存分配与回收
add_executable(memory memory/MemoryMain.cpp memory/VectorDemo.cpp memory/VectorDemo.h)

# 强制类型转换
add_executable(cast cast/CastMain.cpp)

# 函数
add_executable(function function/FunctionMain.cpp)

# chrono 时间库
add_executable(chrono chrono/ChronoMain.cpp)

# Cpp-Concurrency-in-Action
## 线程管理
add_executable(Concurrency-thread_task concurrent/ThreadTasks.cpp)
add_executable(Concurrency-thread concurrent/thread-simple/ThreadSimpleMain.cpp)
add_executable(Concurrency-thread-asyn-future concurrent/thread-asyn-future/ThreadAsynFutureMain.cpp)


### 线程池
#TODO
add_executable(Concurrency-thread-pool concurrent/thead-pool/TheadPoolMain.cpp concurrent/thead-pool/SafeQueue.hpp concurrent/thead-pool/ThreadPool.h)



## 互斥量（共享数据管理）
add_executable(Concurrency-mutex concurrent/mutex/MutexMain.cpp)
add_executable(Concurrency-mutex-simple  concurrent/mutex-simple/MutexSimpleMain.cpp)
add_executable(Concurrency-mutex-lock-gurad   concurrent/mutex-lock-guard/LockGuradMain.cpp )
add_executable(Concurrency-mutex-lock-gurad-x concurrent/mutex-lock-guard/LockGuradMainWithAdoptLock.cpp)
add_executable(Concurrency-mutex-unique-lock concurrent/mutex-unique-lock/UniqueLockMain.cpp)
add_executable(Concurrency-mutex-condition concurrent/mutex-condition/MutexConditionMain.cpp)
add_executable(Concurrency-mutex-ReadWriteLock concurrent/mutex-read-write-lock/ReadWriteLockMain.cpp)

## 原子操作
add_executable(Concurrency-atomic concurrent/atomic/AtomicMain.cpp concurrent/atomic/spinlock_mutex.h )
add_executable(Concurrency-atomic-flag concurrent/atomic-flag/AtomicFlagMain.cpp)
add_executable(Concurrency-atomic-int concurrent/atomic/AtomicIntMain.cpp)
add_executable(Concurrency-atomic-operator concurrent/atomic-operator/AtomicOperatorMain.cpp)
add_executable(Concurrency-atomic-fetch concurrent/atomic/AtomicFetch.cpp)
add_executable(Concurrency-atomic-load concurrent/atomic/AtomicLoad.cpp concurrent/atomic/AtomicLoad.cpp)

### 内存顺序

# 宽松模型
add_executable(Concurrency-atomic-memory-single-thread-order concurrent/atomic-memory/AtomicMemorySingleThreadOrder.cpp)
# 释放/消费模型
add_executable(Concurrency-atomic-memory-release-consume concurrent/atomic-memory/AtomicMemoryReleaseConsume.cpp)
# 释放/获取模型
add_executable(Concurrency-atomic-memory-release-acquire concurrent/atomic-memory/AtomicMemoryReleaseAcquire.cpp)
# 顺序一致模型
add_executable(Concurrency-atomic-memory-order-consistent concurrent/atomic-memory/AtomicMemoryOrderConsistent.cpp)

## 并发队列
add_executable(Concurrency-queue concurrent/queue/ConcurrentQueueMain.cpp concurrent/queue/ConcurrentQueue.h  )


# 网络通信(nio aio,bio,epoll,reactor, 基于linux， window)
## bio
add_executable(network concurrent/network/NetworkMain.cpp)
add_executable(network-server-tcp concurrent/network/linux/bio/server/TcpSimpleServer.cpp)
add_executable(network-client-tcp concurrent/network/linux/bio/client/TcpSimpleClient.cpp)
add_executable(network-server-udp concurrent/network/linux/bio/client/UdpSimpleClient.cpp)
add_executable(network-client-udp concurrent/network/linux/bio/server/UdpSimpleServer.cpp)
add_executable(network-server-multiprocess concurrent/network/linux/bio/server/MultiProcessServer.cpp)
add_executable(network-client-multiprocess concurrent/network/linux/bio/client/MultiProcessClient.cpp)
add_executable(network-server-select concurrent/network/linux/select/server/SelectIOServer.cpp)
add_executable(network-client-select concurrent/network/linux/select/client/SelectIOClient.cpp)
add_executable(network-server-epoll concurrent/network/linux/epoll/server/EpollServer.cpp)
add_executable(network-client-epoll concurrent/network/linux/epoll/client/EpollClient.cpp)
add_executable(network-server-multiThread concurrent/network/linux/bio/server/MultiThreadServer.cpp)
add_executable(network-client-multiThread concurrent/network/linux/bio/client/MultiThreadClient.cpp)
add_executable(network-http concurrent/network/linux/http/HttpServer.cpp)
## nio





# boost
add_executable(Boost boost/BoostMain.cpp)
add_executable(Boost-date boost/boost-date/BoostDateMain.cpp)
add_executable(Boost-threadpool boost/boost-threadpool/BoostThreadPoolMain.cpp)
add_executable(Boost-collection boost/boost-collection/BoostCollectionMain.cpp)

# 这里需要将子项目导入
# “-”是你创建的子项目的名称
# ADD_SUBDIRECTORY(-)

# 将该子项目下包含的内容反馈回主项目中
# include_directories(.)

# 这里的“+”和“-”是你想创建的子项目的配置器名称，注意“+”和“-”……不能与现有任何一个名称相同，“*”和“/”是子项目内源文件名称
# “+”与“*”指尖以及“-”与“/”之间都有空格
# add_executable(+ *.cpp)
# add_executable(- /.cpp)

# 动态库
#target_link_libraries(test boost_thread-mt boost_system)
#target_link_libraries (Cprimer_Tuple Logger)