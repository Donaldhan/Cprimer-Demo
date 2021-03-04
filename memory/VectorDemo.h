
/*
 * @ClassName: VectorDemo
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-03-04 11:24
*/


#ifndef CPRIMER_DEMO_VECTORDEMO_H
#define CPRIMER_DEMO_VECTORDEMO_H

#include <memory>
#include <string>

namespace nstl {
    class VectorDemo {
    public:
        VectorDemo() : elements(nullptr), first_free(nullptr), cap(nullptr) {
        }
        VectorDemo(const VectorDemo&);
        VectorDemo& operator= (const VectorDemo&);
        ~VectorDemo();
        void push_back(const std::string&);
        size_t size() const {
            return first_free - elements;
        }
        size_t capacity() const {
            return cap - elements;
        }
        std::string* begin() const {
            return elements;
        }
        std::string* end() const {
            return first_free;
        }
    private:
        static std::allocator<std::string> alloc;
        void chk_n_alloc() {
            if (size() == capacity()) {
                reallocate();
            }
        }
        /**
         *
         * @return
         */
        std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
        /**
         *
         */
        void free();
        /**
         *
         */
        void reallocate();
        std::string* elements;
        std::string* first_free;
        std::string* cap;
    };
}
#endif CPRIMER_DEMO_VECTORDEMO_H
