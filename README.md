# LFU_cache
My implementing the LFU cache eviction scheme O(1). Also there is "perfect_cache" to see difference between LFU and ideal model that knows the future.

## Compiling 

To compile each of the cache you need to use make:

``` 
make 
```

To compile each of the cache you need to make "cache" or "perfect_cache":

```
make cache
```
```
make perfect_cache
```

## Run the program:
LFU_cache:
```
./cache < out.txt
```
Perfect_cache:

```
./perfect_cache < out.txt
```
You can find the test for 100 hundreds values in file out.txt
