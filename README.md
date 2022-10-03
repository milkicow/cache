# LFU_cache
My implementing the LFU cache eviction scheme O(1). Also there is "perfect_cache" to see difference between LFU and ideal model that knows the future.

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

```
cd build/bin
```


LFU_cache: 
```
./lfu
```
Perfect_cache:

```
./perfect
```

## Test the program: 

Find binary in dir build/bin

```
cd build/bin
```

Run tests:

```
./tests
```
