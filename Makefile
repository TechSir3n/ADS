.PHONY: all clean

CXX = g++
CXXFLAGS = -g -Wall  -Wextra  -std=c++11
LIBS = -lgtest -lgtest_main -lpthread

all: 

test: test.o 
    $(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

test.o: test.cpp
    $(CXX) $(CXXFLAGS) -c $<

formatting: 
    find . -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;
    
.PHONY: clean
clean:
    rm -f test test.o