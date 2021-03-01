
/*
 * @ClassName: MutexMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-01 15:17
*/


#include <map>
#include <string>
#include <mutex>
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/locks.hpp>
/*
 *
 */
class dns_entry
{
private:
    std::string ip;
public:
     dns_entry(){
         ip = "";
     }
    dns_entry(std::string ipv){
       ip = ipv;
    }

    const std::string &getIp() const {
        return ip;
    }

    void setIp(const std::string &ip) {
        dns_entry::ip = ip;
    }
};
/*
 *
 */
class dns_cache
{
    std::map<std::string,dns_entry> entries;
    boost::shared_mutex entry_mutex;
public:
    dns_entry find_entry(std::string const& domain)
    {
        boost::shared_lock<boost::shared_mutex> lk(entry_mutex);
        std::map<std::string,dns_entry>::const_iterator const it=
                entries.find(domain);
        return (it==entries.end())? dns_entry() :it->second;
    }
    void update_or_add_entry(std::string const& domain,
                             dns_entry const& dns_details)
    {
        std::lock_guard<boost::shared_mutex> lk(entry_mutex);
        entries[domain]=dns_details;
    }
};
/*
 *
 * @return
 */
int main()
{}
