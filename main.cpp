#include <iostream>
#include <thread>
int main() {
    //
    std::cout << "Hello, World!" << std::endl;
    unsigned long const hardware_threads =
            std::thread::hardware_concurrency();
    std::cout << "hardware_threads：" <<hardware_threads;
    return 0;
}
