#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <vector>
#define LOX printf("LINE№ = %d\n", __LINE__);

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

template <typename T, typename KeyT = int>
class Cache
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

    Cache(size_t size) : capacity(size) {}

    template <typename F> 
    bool lookup_update(KeyT key, F slow_get_page);

    bool full() const { return table.size() == capacity; }
};

template <typename T, typename KeyT>
template <typename F>
bool Cache<T, KeyT>::lookup_update(KeyT key, F slow_get_page)
{   
    //Parent = count_list.begin();
    auto lfu_node = count_list.begin();
    LOX
    if(table.find(key) == table.end())
    {   
        LOX
        if(full())
        {   
            LOX
            auto lfu_key = lfu_node -> second.back().key;
            table.erase(lfu_key);
            count_list.front().second.pop_back(); 
        }

        if (lfu_node -> first != 1)
        {   
            LOX
            count_list.push_front(std::pair(1, std::list<element> {}));
        }
        
        LOX
        element new_elem = { slow_get_page(key), count_list.begin(), key };
        count_list.front().second.push_front(new_elem);
        table[key] = (count_list.front().second.begin());

        return false;
    }

    LOX

    auto hit = table.find(key);
    LOX
    auto elem_it = hit -> second;
    LOX
    auto freq_it = elem_it -> parent;
    LOX
    auto next_freq_it = std::next(elem_it -> parent);
    LOX
    if(next_freq_it == count_list.end() || (next_freq_it -> first != ((freq_it -> first) + 1)))
    {   
        LOX
        count_list.insert(freq_it, std::pair(((freq_it -> first) + 1), std::list<element> {})); // может здесь проблема
        LOX
    }

    LOX
    auto &list = freq_it -> second;
    auto &next_list = next_freq_it -> second;
    LOX
    //next_list.splice(next_list.begin(), freq_it -> second, elem_it); // sick fault 
    next_list.splice(next_list.begin(), list, elem_it);
    LOX

    elem_it -> parent = next_freq_it;
    LOX
    if((freq_it -> second).empty())
    {   
        LOX
        count_list.erase(freq_it);
    }

    LOX
    return true;
}

int main()
{   
    int size = 0, number_of_page = 0;
    std::cin >> size >> number_of_page;

    Cache<page_t> cache(size);

    int hits = 0;
    for (int i = 0; i < number_of_page; i ++)
    {
        int page_number = 0;
        std::cin >> page_number;
        if (cache.lookup_update(page_number, slow_get_page)) hits++;
    }

    std::cout << hits << '\n';
}