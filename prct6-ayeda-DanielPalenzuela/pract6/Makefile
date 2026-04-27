CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
TARGET := tdatree
SRCS := main.cc nif.cc ab.cc abe.cc abb.cc
OBJS := $(SRCS:.cc=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc nif.h nodo_b.h ab.h abe.h abb.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean