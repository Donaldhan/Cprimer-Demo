
/*
 * @ClassName: BoostThreadPoolMain
 * @Description: linux 环境
 * @Author:  Ravitn
 * @Date: 2021-03-08 10:06
*/

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/move/move.hpp>
#include <iostream>
#include <unistd.h>

namespace asio = boost::asio;

int sleep_print(int seconds) {
    std::cout << "goint to sleep (" << seconds << ")" << std::endl;
    sleep(seconds);
    std::cout << "wake up (" << seconds << ")" << std::endl;
    return seconds*seconds;
}
//任务
typedef boost::packaged_task<int> task_t;
//任务指针
typedef boost::shared_ptr<task_t> ptask_t;

/**
 *
 * @param seconds
 * @param io_service
 * @param pending_data
 */
void push_job(int seconds, boost::asio::io_service& io_service, std::vector<boost::shared_future<int> >& pending_data) {
    ptask_t task = boost::make_shared<task_t>(boost::bind(&sleep_print, seconds));
    boost::shared_future<int> fut(task->get_future());
    pending_data.push_back(fut);
    io_service.post(boost::bind(&task_t::operator(), task));
}
/**
 *
 * @param seconds
 * @param io_service
 * @return
 */
boost::shared_future<int> push_job(int seconds, boost::asio::io_service& io_service) {
    ptask_t task = boost::make_shared<task_t>(boost::bind(&sleep_print, seconds));
    boost::shared_future<int> fut(task->get_future());
    io_service.post(boost::bind(&task_t::operator(), task));
    return fut;
}


int main() {

    boost::asio::io_service io_service;
    boost::thread_group threads;
    boost::asio::io_service::work work(io_service);
    for (int i = 0; i < boost::thread::hardware_concurrency() ; ++i)
    {
        threads.create_thread(boost::bind(&boost::asio::io_service::run,
                                          &io_service));
    }
    // vector of futures
    std::vector<boost::shared_future<int> > pending_data;

    sleep_print(2);
    push_job(3, io_service, pending_data);
    push_job(4, io_service, pending_data);

//	boost::thread task(boost::move(pt)); // launch task on a thread

    boost::wait_for_all(pending_data.begin(), pending_data.end());

    push_job(3, io_service, pending_data);
    push_job(4, io_service, pending_data);
    push_job(5, io_service, pending_data);
    boost::wait_for_all(pending_data.begin(), pending_data.end());
    boost::shared_future<int> sharedFuture = push_job(6,io_service );
    std::cout << "sharedFuture:" << sharedFuture.get() << std::endl;
}