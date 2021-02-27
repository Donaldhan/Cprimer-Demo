# x.x是自身需要的Clion版本
# cmake_minimum_required(VERSION <specify CMake version here>)

# 自己的项目名称
project(Cprimer_Demo)

# xx是你创建项目的时候使用的C++标准
set(CMAKE_CXX_STANDARD 11)


# “+”要更改成你想给这个结局方案的名称（这个可自定义），“*”是该主项目下的源文件名称
# “+”与“*”之间有空格。
# 如果想在主项目中添加文件，则在这里添加，如果在子文件夹中，则在子项目中添加

add_executable(Cprimer_Demo main.cpp)
# add_executable(Cprimer_Demo 6/good_printmain.cpp)
# add_library(test_library STATIC 7/Sales_data.cpp)
add_executable(Cprimer_Add_Item 7/add_item.cpp 7/Sales_data.h 7/Sales_data.cpp extend-isa/extends-isa-base/Animals.h)

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

# 模板
add_executable(Cprimer_Collection collections/CollectionsMain.cpp)
# 这里需要将子项目导入
# “-”是你创建的子项目的名称
# ADD_SUBDIRECTORY(-)

# 将该子项目下包含的内容反馈回主项目中
# include_directories(.)

# 这里的“+”和“-”是你想创建的子项目的配置器名称，注意“+”和“-”……不能与现有任何一个名称相同，“*”和“/”是子项目内源文件名称
# “+”与“*”指尖以及“-”与“/”之间都有空格
# add_executable(+ *.cpp)
# add_executable(- /.cpp)