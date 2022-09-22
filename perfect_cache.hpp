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

    // std::cout << "capacity = " << cache.size() << " \n";    
    // for(int i = 0; i != cache.size(); i++)
    // {
    //     std::cout << cache[i].second << " ";
    // }
    // std::cout << std::endl;



    if(hit == cache.end())
    {
        if(full())
        {   

            auto res = find_last_occur();
            // printf("elem %d will erase\n", res -> second);
            cache.erase(res);
        }

        cache.push_back(std::pair(slow_get_page(key), key)); 

        return false;
    }

    return true;
}
};


// template <typename T, typename KeyT = int>
// class caches
// {
//     size_t capacity;


//     std::vector<std::pair<page_t, KeyT>> keys;
//     std::vector<std::pair<page_t, KeyT>> cache;

//     using vector_it = typename std::vector<std::pair<page_t, KeyT>>::iterator;

//     vector_it cur_keys_it = keys.begin();

//     auto find_in_cache(KeyT key)
//     {
//         for(auto it = cache.begin(); it != cache.end(); std::next(it))
//         {
//             if(it -> second == key) return it;
//         }
//         return cache.end();
//     }

//     auto find_rep_occur(KeyT key)
//     {
//         for (auto it = cur_keys_it; it != keys.end(); std::next(it))
//         {
//             if(it -> second == key) return it;
//         }
//         return keys.end();
//     }

//     auto find_last_occur()
//     {   
//         auto max_distance = 0;
//         auto last_occur = cache.begin();

//         for(auto it = cache.begin(); it != cache.end(); std::next(it))
//         {
//             auto occur = find_rep_occur(it -> second);
//             auto distance = std::distance(cur_keys_it, occur);
//             if(distance > max_distance){
//                 max_distance = distance;
//                 last_occur = it;
//             }
//         }
//         return last_occur;
//     }

//     public:
//     caches(size_t size) : capacity(size), cur_keys_it(keys.begin()) {}

//     template <typename F> 
//     bool lookup_update(F slow_get_page);

//     bool full() const { return cache.size() == capacity; }
// };

// template <typename T, typename KeyT>
// template <typename F>
// bool caches<T, KeyT>::lookup_update(F slow_get_page)
// {   
//     auto key = (cur_keys_it++) -> second;

//     auto hit = find_in_cache(key);


//     if(hit == cache.end())
//     {
//         if(full())
//         {      
//             cache.erase(find_last_occur());
//         }

//         cache.push_back(std::pair(slow_get_page(key), key)); 

//         return false;
//     }

//     return true;

// }
// };


//seg fault кайффф