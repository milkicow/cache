#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <vector>
#include <chrono>


namespace lfu{

template <typename T, typename KeyT = int>
class cache
{
    struct element;
    
    using Parent = typename std::list<std::pair<int, std::list<element>>>::iterator;
    using Iterator = typename std::list<element>::iterator;

    struct element
    {
        T page;
        Parent parent;
        KeyT key;
    };

    size_t capacity;

    std::unordered_map<KeyT, Iterator> table;
    std::list<std::pair<int, std::list<element>>> count_list;

    public:

    cache(size_t size) : capacity(size) {}

    template <typename F> 
    bool lookup_update(KeyT key, F slow_get_page);

    bool full() const { return table.size() == capacity; }
};

template <typename T, typename KeyT>
template <typename F>
bool cache<T, KeyT>::lookup_update(KeyT key, F slow_get_page)
{   
    //Parent = count_list.begin();
    auto lfu_node = count_list.begin();
    auto hit = table.find(key);
     
    if(hit == table.end())
    {   
         
        if(full())
        {   
             
            auto lfu_key = lfu_node -> second.back().key;
            table.erase(lfu_key);
            count_list.front().second.pop_back(); 
        }

        if (lfu_node -> first != 1)
        {   
            count_list.emplace_front(std::pair(1, std::list<element> {}));
        }
        
         
        element new_elem = { slow_get_page(key), count_list.begin(), key };
        count_list.front().second.push_front(new_elem);
        table[key] = (count_list.front().second.begin());

        return false;
    }

    
    auto elem_it = hit -> second;
    auto freq_it = elem_it -> parent;
    auto next_freq_it = std::next(elem_it -> parent);
     
    if(next_freq_it == count_list.end() || (next_freq_it -> first != ((freq_it -> first) + 1)))
    {   
        next_freq_it = count_list.insert(next_freq_it, std::pair(((freq_it -> first) + 1), std::list<element> {}));
         
    }

     
    auto &list = freq_it -> second;
    auto &next_list = next_freq_it -> second;
     
    next_list.splice(next_list.begin(), list, elem_it);
     
    elem_it -> parent = next_freq_it;
    if((freq_it -> second).empty())
    {   
        count_list.erase(freq_it);
    }

    return true;
}

};
