#ifndef _INC_CPPP_MEMORY_HPP_
#define _INC_CPPP_MEMORY_HPP_
#include "mincpppdef.h"
#include <memory.h>
#include <stddef.h>

namespace cppp{namespace base{
    extern "C"
    {
        typedef unsigned short wchar;
        struct c_buffer_base
        {
            size_t length;
            char* buffer;
        };
        
        
        namespace memory
        {
            
        }
    }
}} // namespace cppp::base::memory

#endif