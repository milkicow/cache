#include <iostream>
#include <list>
#include <unordered_map>

struct page {
    int index; // page index: 1, 2, ... n 
    int sz; // page size
    char *data; // page data
};

template <typename T, typename KeyT = int>
struct cache_t 
{
    size_t sz_; 
    cache_t(size_t sz) : sz_(sz) {};
    std::list<T> cache_;

    using ListIt = typename std::list<T>::iterator; 
    std::unordered_map<KeyT, ListIt> hash_;

    bool full() const;

    template <typename F>
    bool lookup_update(KeyT key, F slow_get_page); 
};


template <typename T, typename KeyT = int, typename F>
bool lookup_update(KeyT key, F slow_get_page) 
{
    using ListIt = typename std::list<T>::iterator; 
    std::unordered_map<KeyT, ListIt> hash_;
    
    auto hit = hash_.find(key);
    if (hit == hash_.end())  // not found
    {
        if (full()) 
        {
            hash_.erase(cache_.back().id); // cleanup least recently used
            cache_.pop_back();
        }
        cache_.push_front(slow_get_page(key)); // fallback to slow method
        hash_[key] = cache_.begin();
        return false;
    }
    auto eltit = hit->second;
    if (eltit != cache_.begin())
    {
        cache_.splice(cache_.begin(), cache_, eltit, std::next(eltit)); 
    }
    return true;
}

template <typename KeyT = int>
int slow_get_page(int key)
{
    return key;
}

int main()
{   
    int m = 0;
    std::cin >> m;
    cache_t<int> c{m};


    return 0;
}
