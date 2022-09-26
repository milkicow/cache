#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <vector>
#include <chrono>

#include <stdio.h>

#define __OUT__ stderr

#define PRINT(str)     do{ fprintf(__OUT__, "%s\n", #str                                                              );   }while(0)
#define PRINT_LINE     do{ fprintf(__OUT__, "I'm at %s at line %d in %s\n", __PRETTY_FUNCTION__, __LINE__, __FILE__   );   }while(0)
#define PRINT_(str)    do{ fprintf(__OUT__, "[%s:%d] %s\n",                 __PRETTY_FUNCTION__, __LINE__, #str       );   }while(0)
#define PRINT_PTR(ptr) do{ fprintf(__OUT__, "[%s:%d] pointer %s at %p\n",   __PRETTY_FUNCTION__, __LINE__, #ptr,  ptr );   }while(0)
#define PRINT_C(char)  do{ fprintf(__OUT__, "[%s:%d] %s = %c  \n",          __PRETTY_FUNCTION__, __LINE__, #char, char);   }while(0)
#define PRINT_S(str)   do{ fprintf(__OUT__, "[%s:%d] %s = %s  \n",          __PRETTY_FUNCTION__, __LINE__, #str,  str );   }while(0)
#define PRINT_UL(num)  do{ fprintf(__OUT__, "[%s:%d] %s = %lu \n",          __PRETTY_FUNCTION__, __LINE__, #num,  num );   }while(0)
#define PRINT_D(num)   do{ fprintf(__OUT__, "[%s:%d] %s = %d  \n",          __PRETTY_FUNCTION__, __LINE__, #num,  num );   }while(0)
#define PRINT_X(num)   do{ fprintf(__OUT__, "[%s:%d] %s = %x  \n",          __PRETTY_FUNCTION__, __LINE__, #num,  num );   }while(0)
#define PRINT_SM(s, n) do{ fprintf(__OUT__, "[%s:%d] %s = %.*s\n",          __PRETTY_FUNCTION__, __LINE__, #s,    n, s);   }while(0)

struct page_t
{
    int id;
    page_t() : page_t(0) {}
    page_t(int num) : id(num) {}
};

page_t slow_get_page(int key)
{
    return page_t(key);
}

namespace perfect_cache{

template <typename T, typename KeyT = int>

class caches
{
    std::vector<KeyT> stream;
    std::vector<std::pair<T, KeyT>> cache;

    typename std::vector<KeyT>::iterator vector_it = stream.begin();

    size_t capacity;

public:
    caches(size_t size, std::vector<KeyT> keys) : capacity(size), stream(keys) {}

    template <typename F> 
    bool lookup_update(F slow_get_page);

    auto find_last_occur()
    {   
        auto erase = cache.begin();
        auto pos   = stream.begin();

        for (auto cache_it = cache.begin(); cache_it != cache.end(); cache_it = std::next(cache_it))
        {
            auto candidate = vector_it;

            for (auto stream_it = vector_it; stream_it != stream.end(); stream_it = std::next(stream_it))
            {   
                if (*stream_it == cache_it->second) {
                    candidate = stream_it;
                    break;
                }
                candidate = stream.end();
            }

            if (candidate > pos) {
                pos = candidate;
                erase = cache_it;
            }
        }

        return erase;
    }


    auto find_cache(KeyT key)
    {
        for (auto cache_it = cache.begin(); cache_it != cache.end(); cache_it = std::next(cache_it))
        {
            if(cache_it -> second == key) return cache_it;
        }

        return cache.end();
    }

    bool full() const { return cache.size() == capacity; }


};

template <typename T, typename KeyT>
template <typename F>
bool caches<T, KeyT>::lookup_update(F slow_get_page)
{   
    auto key = *vector_it++;
    auto hit = find_cache(key);

    if(hit == cache.end())
    {
        if(full())
        {   

            auto res = find_last_occur();
            cache.erase(res);
        }

        cache.push_back(std::pair(slow_get_page(key), key)); 

        return false;
    }

    return true;
}
};
