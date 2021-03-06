//
///*
// * @ClassName: ConcurrentQueue
// * @Description:
// * @Author:  Ravitn
// * @Date: 2021-03-06 15:18
//*/
//
//
//#include "ConcurrentQueue.h"
///**
// *
// * @tparam T
// * @param new_value
// */
//template<typename T>
//void ConcurrentQueue<T>::push(T new_value)
//{
//    std::shared_ptr<T> new_data(
//            std::make_shared<T>(std::move(new_value)));
//    std::unique_ptr<node> p(new node);
//    {
//        std::lock_guard<std::mutex> tail_lock(tail_mutex);
//        tail->data=new_data;
//        node* const new_tail=p.get();
//        tail->next=std::move(p);
//        tail=new_tail;
//    }
//    data_cond.notify_one();
//}
///**
// *
// * @tparam T
// * @return
// */
//template<typename T>
//std::shared_ptr<T> ConcurrentQueue<T>::try_pop()
//{
//    std::unique_ptr<node> const old_head=try_pop_head();
//    return old_head?old_head->data:std::shared_ptr<T>();
//}
///**
// *
// * @tparam T
// * @param value
// * @return
// */
//template<typename T>
//bool ConcurrentQueue<T>::try_pop(T& value)
//{
//    std::unique_ptr<node> const old_head=try_pop_head(value);
//    return old_head;
//}
///**
// *
// * @tparam T
// */
//template<typename T>
//void ConcurrentQueue<T>::empty()
//{
//    std::lock_guard<std::mutex> head_lock(head_mutex);
//    return (head==get_tail());
//}
///**
// *
// * @tparam T
// * @return
// */
//template<typename T>
//std::shared_ptr<T> ConcurrentQueue<T>::wait_and_pop()
//{
//    std::unique_ptr<node> const old_head=wait_pop_head();
//    return old_head->data;
//}
///**
// *
// * @tparam T
// * @param value
// */
//template<typename T>
//void ConcurrentQueue<T>::wait_and_pop(T& value)
//{
//    std::unique_ptr<node> const old_head=wait_pop_head(value);
//}