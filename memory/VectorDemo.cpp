
/*
 * @ClassName: VectorDemo
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-04 11:24
*/


#include "VectorDemo.h"
using namespace nstl;

std::allocator<std::string> VectorDemo::alloc;

/**
 *
 * @param str
 */
VectorDemo::VectorDemo(const VectorDemo& str) {
    auto data = alloc_n_copy(str.begin(), str.end());
    elements = data.first;
    first_free = cap = data.second;
}

VectorDemo::~VectorDemo() {
    free();
}
/**
 *
 * @param str
 * @return
 */
VectorDemo& VectorDemo::operator= (const VectorDemo& str) {
    auto data = alloc_n_copy(str.begin(), str.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
/**
 *
 * @param str
 */
void VectorDemo::push_back(const std::string& str) {
    chk_n_alloc();
    alloc.construct(first_free++, str);
}
/**
 *
 * @param begin
 * @param end
 * @return
 */
std::pair<std::string*, std::string*> VectorDemo::alloc_n_copy(const std::string* begin, const std::string* end) {
    auto data = alloc.allocate(end - begin);
    //warning C4996: Call to 'std::uninitialized_copy' with parameters that may be unsafe
    return{ data, std::uninitialized_copy(begin, end, data) };
}
/**
 *
 */
void VectorDemo::free() {
    if (elements) {
        for (auto p = first_free; p != elements; ) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}
/**
 *
 */
void VectorDemo::reallocate() {
    auto capacity = size() ? 2 * size() : 1;
    auto data = alloc.allocate(capacity);
    auto databak = data;
    auto elembak = elements;
    for (size_t i = 0; i != size(); ++i) {
        //using std::move(string,don't copy construct)
        alloc.construct(databak++, std::move(*elembak++));
    }
    free(); //need elemets, no destructor string
    elements = data;
    first_free = databak;
    cap = elements + capacity;
}
