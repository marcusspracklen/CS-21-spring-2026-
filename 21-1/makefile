CXX	 = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

TARGET	 = p2
SRCS	 = main.cpp intMinHeap.cpp
OBJS	 = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp intMinHeap.h
	$(CXX) $(CXXFLAGS) -c $<

intMinHeap.o: intMinHeap.cpp intMinHeap.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
