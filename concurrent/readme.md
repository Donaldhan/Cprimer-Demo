并发编程
# 
[C++11多线程并发基础入门教程](https://zhuanlan.zhihu.com/p/194198073)   


# Reactor
[Reactor线程模型](https://zhuanlan.zhihu.com/p/69341619)    


#  C++ 11 右值引用
C++ 会把 即将离开作用域的 非引用类型的 返回值当成 右值（参考 [sec|值类别 vs 变量类型]），
对返回的对象进行 [sec|移动语义] 移动构造（语言标准）；
如果编译器允许 [sec|拷贝省略] 拷贝省略，还可以省略这一步的构造，
直接把 ret 存放到返回值的内存里（编译器优化）。  

[一次性搞定右值，右值引用（&&），和move语义](https://juejin.cn/post/6844903497075294216) 
[深入浅出 C++ 11 右值引用](https://zhuanlan.zhihu.com/p/107445960) 