CXX=g++
CXXFLAGS= -std=c++17 -O3
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:  test_cache_lib

test_cache_lib: cache_lib.o test_cache_lib.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o.cc: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o test_cache_lib