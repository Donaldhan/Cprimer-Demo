
/*
 * @ClassName: ConcurrentQueueMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-05 14:53
*/
#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include "ConcurrentQueue.h"
#include <boost/lockfree/queue.hpp>
//#include <functional>

boost::lockfree::queue<int> queue;
using namespace std;
void writer(ConcurrentQueue<int>& concurrentQueue , int start, int size) {
    for(int i = start; i< start+size ; i++){
        concurrentQueue.push(i);
    }
}
void waitRead(ConcurrentQueue<int>& concurrentQueue ) {
    while(true){
        std::shared_ptr<int> sharedPtr = concurrentQueue.wait_and_pop();
        cout << "waitRead:" << sharedPtr;
    }
}
void tryRead(ConcurrentQueue<int>& concurrentQueue ) {
    while(true){
        std::shared_ptr<int> sharedPtr = concurrentQueue.try_pop();
        if(nullptr != sharedPtr){
            cout << "tryRead:" << sharedPtr;
        }
    }
}
int main() {
    vector<thread> vc;
    ConcurrentQueue<int> cq;
    vc.emplace_back(thread(waitRead,std::ref(cq)));
    vc.emplace_back(thread(tryRead,std::ref(cq)));
    vc.emplace_back(thread(writer,std::ref(cq), 0, 10));
    vc.emplace_back(thread(writer,std::ref(cq), 10, 10));
    for(int i =0; i< vc.size(); i++){
        vc[i].join();
    }
//    for_each(vc.begin(), vc.end(), [&](thread t){t.join();});
}

