#include <cpppbase/cpppcharset.hpp>
#include <iconv.h>
#include <libcharset.h>
#include <iostream>
#include <vector>
extern "C"
{
    int cppp::base::charset::convert(const char *from, const char *to, bool strict, size_t buf_size_, const char *in, size_t inlen, char **out, size_t &outlen)
    {
        outlen = 0;
        iconv_t iconv_ = ::iconv_open(to, from);
        if (iconv_ == (iconv_t)(-1))
        {
            return errno;
        }
        bool ignore_error_ = !strict;
        std::vector<char> in_buf(in, in+inlen);
        char* src_ptr = &in_buf[0];
        size_t src_size = inlen;
        char* buf = new char[buf_size_] {};
        std::vector<char> dst;
        while (0 < src_size) {
            char* dst_ptr = buf;
            size_t dst_size = buf_size_;
            size_t res = ::iconv(iconv_, (const char**)&src_ptr, &src_size, &dst_ptr, &dst_size);
            if (res == (size_t)-1) {
                if (errno == E2BIG) {
                    // ignore this error
                }
                else if (ignore_error_) {
                    // skip character
                    ++src_ptr;
                    --src_size;
                }
                else
                {
                    int le = errno;
                    if (le == EINVAL)
                    {
                        le = EILSEQ;
                    }
                    ::iconv_close(iconv_);
                    delete[] buf;
                    return le;
                }
            }
            for (size_t i = 0; i < buf_size_ - dst_size; i++)
            {
                dst.push_back(buf[i]);
                outlen++;
            }
        }
        ::iconv_close(iconv_);
        char* pout = new char[dst.size() + sizeof(char)] {};
        for (size_t i = 0; i < dst.size(); i++)
        {
            pout[i] = buf[i];
        }
        *out = pout;
        return 0;
    }
    const char* cppp::base::charset::locale_charset()
    {
        return locale_charset();
    }
}