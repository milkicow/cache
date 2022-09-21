#include "header.hpp"

int main()
{   
    int size = 0, number_of_page = 0;
    std::cin >> size >> number_of_page;
    using namespace std::chrono;
    using fseconds = duration<float>;

    lfu::cache<lfu::page_t> cache(size);

    int hits = 0;
    auto start = system_clock::now();
    for (int i = 0; i < number_of_page; i++)
    {
        int page_number = 0;
        std::cin >> page_number;
        if (cache.lookup_update(page_number, lfu::slow_get_page)) hits++;
    }

    auto time = system_clock::now() - start;
    std::cout << "runtime " << duration_cast<fseconds>(time).count() << "c\n";

    std::cout << hits << '\n';
}