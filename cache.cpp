#include "cache.hpp"

int main()
{   
    int size = 0, number_of_pages = 0;
    std::cin >> size >> number_of_pages;
    using namespace std::chrono;
    using fseconds = duration<float>;

    lfu::cache<page_t> cache(size);

    int hits = 0;
    auto start = system_clock::now();
    for (int i = 0; i < number_of_pages; i++)
    {
        int page_number = 0;
        std::cin >> page_number;
        if (cache.lookup_update(page_number, slow_get_page)) hits++;
    }

    auto time = system_clock::now() - start;
    std::cout << "runtime " << duration_cast<fseconds>(time).count() << "c\n";

    std::cout << hits << '\n';
}