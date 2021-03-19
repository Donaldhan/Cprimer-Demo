cmake_minimum_required(VERSION 3.17)

# 自己的项目名称
project(Tutorial VERSION 1.3.8)

# 版本号.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 3)
set (Tutorial_VERSION_PATCH 8)

# xx是你创建项目的时候使用的C++标准
set(CMAKE_CXX_STANDARD 11)

#   cmake start
# 将构建目录添加到 include 的搜索路径中以便找到
# TutorialConfig.h 文件
include_directories("${PROJECT_BINARY_DIR}")

# 配置一个头文件将一些 CMake 设置传入到源代码中
# 以 TutorialConfig.h.in 为模版，替换相关变量
# 以生成 TutorialConfig.h
configure_file ("${PROJECT_SOURCE_DIR}/cmake/TutorialConfig.h.in" "${PROJECT_BINARY_DIR}/cmake/TutorialConfig.h")


add_executable(tutorial tutorial/TutorialMain.cpp)