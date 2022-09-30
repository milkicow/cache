#include "header.h"

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

        for (auto cache_it = cache.begin(); cache_it != cache.end(); ++cache_it)
        {
            auto candidate = vector_it;

            for (auto stream_it = vector_it; stream_it != stream.end(); ++stream_it)
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
        for (auto cache_it = cache.begin(); cache_it != cache.end(); ++cache_it)
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

int perfect_cache()
{
    int size = 0, number_of_pages = 0;
    std::cin >> size >> number_of_pages;


    std::vector<int> keys;

    int hits = 0;
    
    for (int i = 0; i < number_of_pages; i++)
    {   
        int page_number = 0;
        std::cin >> page_number;
        keys.push_back(page_number);
    }

    perfect_cache::caches<page_t> caches(size, keys);

    for (int i = 0; i < number_of_pages; i++)
    {   
        if (caches.lookup_update(slow_get_page)) hits++;
    }

    return hits;
}

};