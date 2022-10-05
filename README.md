# LFU_cache
My implementing the LFU cache eviction scheme O(1). Also there is "perfect_cache" to see difference between LFU and ideal model that knows the future.


## Requirements 

The following applications have to be installed:

1. CMake 3.2 version (or higher)
2. GTest
3. g++


## Compiling 

To compile each of the cache you need to use сmake in the directory build:

``` 
mkdir build
cd build
сmake ..
```

To compile all:
```
make all
```

To compile each of the cache you need to make "lfu" or "perfect":

```
make lfu
```
```
make perfect
```

To compile the test you need to make "tests":

```
make tests
```

## Run the program:

You can find all binaries in dir build/bin


LFU_cache: 
```
./build/lfu
```
Perfect_cache:

```
./build/perfect
```

## Test the program: 


Run tests:

```
./bin/tests
```
