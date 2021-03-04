# x.x是自身需要的Clion版本
# cmake_minimum_required(VERSION <specify CMake version here>)

# 自己的项目名称
project(Cprimer_Demo)

# 版本号.
set (CPRIMER_DEMO_VERSION_MAJOR 1)
set (CPRIMER_DEMO_VERSION_MINOR 0)

# xx是你创建项目的时候使用的C++标准

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS$ {CMAKE_CXX_FLAGS} -std = c ++ 11)

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


# “+”要更改成你想给这个结局方案的名称（这个可自定义），“*”是该主项目下的源文件名称
# “+”与“*”之间有空格。
# 如果想在主项目中添加文件，则在这里添加，如果在子文件夹中，则在子项目中添加

add_executable(Cprimer_Demo main.cpp)
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

# C++Tuple元组的详细用法
add_executable(Cprimer_Tuple tuple/TupleMain.cpp tuple/TupleUtil.cpp tuple/TupleUtil.h tuple/TuplePrinter.h tuple/TupleString.cpp tuple/TupleString.h)

# spdlog
add_executable(Cprimer_spdlog spdlog/SpdLogMain.cpp spdlog/LogFactory.cpp spdlog/LogFactory.h spdlog/LogFactoryTest.cpp logger/LoggerFactory.h)
add_executable(Cprimer_LogFactory spdlog/LogFactoryTest.cpp spdlog/LogFactory.cpp spdlog/LogFactory.h)


# 集合
add_executable(Cprimer_Collection collections/CollectionsMain.cpp)

# 线程管理
add_executable(Cpp-Concurrency-in-Action_thread_task thread_task/ThreadTasks.cpp)

# 互斥量（共享数据管理）
add_executable(Cpp-Concurrency-in-Action_mutex  mutex/MutexMain.cpp )


# 基础
add_executable(Cprimer_Base base/BaseMain.cpp)

# Lamdba
add_executable(Cprimer_Lamdba lambda/LamdbaMain.cpp)

# 智能指针
add_executable(Cprimer_Pointer pointer/PointerMain.cpp)

# 内存分配与回收
add_executable(Cprimer_Memory memory/MemoryMain.cpp memory/VectorDemo.cpp memory/VectorDemo.h)

# 强制类型转换
add_executable(Cprimer_CAST cast/CastMain.cpp)

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