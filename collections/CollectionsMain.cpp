
/*
 * @ClassName: CollectionsMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-27 22:24
*/


#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
#include <iterator>
#include "LoggerFactory.h"
using namespace std;

int main()
{
    auto log = LoggerFactory::getLogger("CollectionsMain");


    // 创建一个向量存储 int
    vector<int> vec;
    int i;
    // 显示 vec 的原始大小
    log->info("vector size = :{}",vec.size());
    const int LEN = 3;
    // 推入 5 个值到向量中
    for(i = 0; i < LEN; i++){
        vec.push_back(i);
    }
    // 显示 vec 扩展后的大小
    log->info("extended vector size = {}",vec.size());
    // 访问向量中的 5 个值
    for(i = 0; i < LEN; i++){
        log->info("value of vec [{}] = {}",i, vec[i]);
    }
    // 使用迭代器 iterator 访问值
    vector<int>::iterator v = vec.begin();
    while( v != vec.end()) {
        log->info("nomral iterator value of v = {}", *v);
        v++;
    }
    vector<int>::reverse_iterator v1 = vec.rbegin();

    while( v1 != vec.rend()) {
        log->info("reverse_iterator value of v = ：{}", *v1 );
        v1++;
    }
    log->info("=======vector========");


    stack<int> stack;
    stack.push(1);
    stack.push(2);
    log->info("stack size:{}", stack.size());
    if(!stack.empty()){
        log->info("stack top:{}", stack.top());
        stack.pop();
        log->info("stack size:{}", to_string(stack.size()));
    }
    log->info("=======stack========");


    list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(3);
    list.insert(list.begin(),4);
    for_each(list.begin(), list.end(), [&] (int val)
    {
        log->info("list val:{}",val);
    });

    log->info("list back:{}",list.back());
    log->info("list front:{}",list.front());
    log->info("list size:{}",list.size());
    list.pop_back();
    log->info("list size:{}",list.size());
    list.pop_front();
    log->info("list size:{}",list.size());
    list.reverse();
    for_each(list.cbegin(), list.cend(), [&] (int val)
    {
        log->info("list cbegin , cend val:{}",val);
    });
    log->info("=======list========");


    queue<int> queue;
    queue.push(1);
    queue.push(2);
    if(!queue.empty()){
        log->info("queue front:{}", queue.front());
        queue.pop();
    }
    log->info("queue size:{}", queue.size());
    log->info("=======queue========");


    set<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(2);
    log->info("set key 2 count :{}",set.count(2));
    for_each(set.begin(), set.end(), [&] (int val)
    {
        log->info("set val:{}",val);
    });
    log->info("=======set========");

    multiset<int> multiset;
    multiset.insert(1);
    multiset.insert(2);
    multiset.insert(2);
    log->info("multiset key 2 count :{}",multiset.count(2));
    for_each(multiset.begin(), multiset.end(), [&] (int val)
    {
        log->info("multiset val:{}",val);
    });
    log->info("=======multiset========");


    map<int, string> map;
    map.insert({1,"jack"});
    map.insert(make_pair(2,"mark"));
    map.insert(make_pair(2,"mark"));
    log->info("map key 2 count:{}", map.count(2));
    for_each(map.begin(), map.end(), [&] (pair<int, string> pair)
    {
        log->info("map key:{}, value:{}",pair.first, pair.second);
    });
    log->info("=======map========");

    multimap<int, string> multimap;
    multimap.insert({1,"jack"});
    multimap.insert(make_pair(2,"mark"));
    multimap.insert(make_pair(2,"mark"));
    log->info("multimap key 2 count:{}", multimap.count(2));
    for_each(multimap.begin(), multimap.end(), [&] (pair<int, string> pair)
    {
        log->info("multimap key:{}, value:{}",pair.first, pair.second);
    });
    log->info("=======multimap========");
}