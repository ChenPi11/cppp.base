#ifndef _INC_CPPP_MEMORY_HPP_
#define _INC_CPPP_MEMORY_HPP_
#include "mincpppdef.h"
#include <memory.h>
namespace cppp{namespace base
{
	namespace charset
	{
		extern "C"
		{
			extern int convert(const char* from,const char* to,bool strict,
				size_t buf_size_,
				const char* in,size_t inlen,
				char** out,size_t& outlen);
			extern const char* locale_charset();
		}
    }
}} // namespace cppp::base::memory

#endif