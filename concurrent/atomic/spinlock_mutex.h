
/*
 * @ClassName: spinlock_mutex
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-05 16:18
*/


#ifndef CPRIMER_DEMO_SPINLOCK_MUTEX_H
#define CPRIMER_DEMO_SPINLOCK_MUTEX_H
/**
 *   采用class封装可以用于lock_guard或unique_lock，但是最好不要将此用于任何竞态条件下，这是一个busy loop！
 */
#include <atomic>
class spinlock_mutex
{
    std::atomic_flag flag;
public:
    spinlock_mutex():
            flag(ATOMIC_FLAG_INIT){}
    void lock()
    {
        while(flag.test_and_set(std::memory_order_acquire));
    }
    void unlock()
    {
        flag.clear(std::memory_order_release);
    }
};
#endif CPRIMER_DEMO_SPINLOCK_MUTEX_H
