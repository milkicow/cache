all:
	g++ cache.cpp -std=c++20 -o cache
	g++ perfect_cache.cpp -std=c++20 -o perfect_cache
cache: 
	g++	cache.cpp -std=c++20 -o cache
perfect_cache:
	g++ perfect_cache.cpp -std=c++20 -o perfect_cache
