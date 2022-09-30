#include "cache.hpp"
#include "perfect_cache.hpp"

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

int LFU()
{
   
    int size = 0, number_of_pages = 0;
    std::cin >> size >> number_of_pages;

    lfu::cache<page_t> cache(size);

    int hits = 0;
    for (int i = 0; i < number_of_pages; i++)
    {
        int page_number = 0;
        std::cin >> page_number;
        if (cache.lookup_update(page_number, slow_get_page)) hits++;
    }

    return hits;
}

int perfect()
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