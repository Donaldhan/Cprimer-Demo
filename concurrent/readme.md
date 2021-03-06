并发编程
# guide
[C++11多线程并发基础入门教程](https://zhuanlan.zhihu.com/p/194198073)   


# Reactor
[Reactor线程模型](https://zhuanlan.zhihu.com/p/69341619)    

# 原子操作
[第 7 章 并行与并发](https://changkun.de/modern-cpp/zh-cn/07-thread/index.html#7-1-%E5%B9%B6%E8%A1%8C%E5%9F%BA%E7%A1%80)  
[C++11原子操作与无锁编程](https://zhuanlan.zhihu.com/p/24983412) 
[c++11 atomic的使用详解](https://www.yht7.com/news/134571)
[c++11 多线程（3）atomic 总结](https://www.jianshu.com/p/8c1bb012d5f8)  
[C++11 并发指南六( <atomic> 类型详解二 std::atomic )](https://www.cnblogs.com/haippy/p/3301408.html)  
[簡介 C++11 atomic 和 memory order](https://medium.com/fcamels-notes/%E7%B0%A1%E4%BB%8B-c-11-memory-model-b3f4ed81fea6)    
[c++ 11 的 std::atomic](https://juejin.cn/post/6844903460471570445)
[C++并发实战16: std::atomic原子操作](https://blog.csdn.net/liuxuejiang158blog/article/details/17413149)    
[c++并发编程3. CAS原语](https://zhuanlan.zhihu.com/p/56055215)    


# C++ 读锁和写锁  
[C++ 并发编程（七）：读写锁（Read-Write Lock）](https://segmentfault.com/a/1190000006941870)  



# 线程池
[C++ 线程池](https://wangpengcheng.github.io/2019/05/17/cplusplus_theadpool/) 


# 网络编程
[从零开始的C++网络编程](https://zhuanlan.zhihu.com/p/119085959)   
[C++ 网络编程初学者的开源项目 | 码云周刊第 41 期](https://blog.gitee.com/2018/03/23/weekly041/)  
[c++ 网络编程课设代码 网络编程入门教程 ---目录](https://www.cnblogs.com/DOMLX/p/9663167.html)   
[Linux 多线程服务端编程：使用 muduo C++ 网络库](https://chenshuo.com/book/) 


#  C++ 11 右值引用
C++ 会把 即将离开作用域的 非引用类型的 返回值当成 右值（参考 [sec|值类别 vs 变量类型]），
对返回的对象进行 [sec|移动语义] 移动构造（语言标准）；
如果编译器允许 [sec|拷贝省略] 拷贝省略，还可以省略这一步的构造，
直接把 ret 存放到返回值的内存里（编译器优化）。  

[一次性搞定右值，右值引用（&&），和move语义](https://juejin.cn/post/6844903497075294216)    
[深入浅出 C++ 11 右值引用](https://zhuanlan.zhihu.com/p/107445960) 