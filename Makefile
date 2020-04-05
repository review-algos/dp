cc = g++ 
srcs = $(wildcard *.cpp)
proms = $(srcs:%.cpp=%)
objs = $(srcs:%.cpp=%.o)
cflags = -g -Wall -std=c++11

all: $(proms)

.secondary: $(objs)

.phony: all clean

%: %.o
	$(cc) $(cflags) $< -o $@

%.o: %.cpp
	$(cc) $(cflags) -c $< -o $@

clean:
	rm -rf $(objs) $(proms)
