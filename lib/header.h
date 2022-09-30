#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <vector>
#include <chrono>

#pragma once

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
