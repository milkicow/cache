# LFU_cache
My implementing the LFU cache eviction scheme O(1). Also there is "perfect_cache" to see difference between LFU and ideal model that knows the future.

## GoogleTest

To use gtests you need to clone in dir test dir from googletest.git:

```
cd test
git clone https://github.com/google/googletest.git -b release-1.12.0
```

## Compiling 

To compile each of the cache you need to use сmake in the directory tmp:

``` 
mkdir tmp
сmake ..
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
LFU_cache: ( in dir tmp )
```
cd LFU_cache
./lfu
```
Perfect_cache: ( in dir tmp )

```
cd perfect_cache
./perfect
```
Also you can do:

```
make install DESTDIR=<path to install folder>
```
to collect all binary files in one folder

## Test the program: 
In dir tmp:

```
cd test
./tests < ../../test/test.txt
```
