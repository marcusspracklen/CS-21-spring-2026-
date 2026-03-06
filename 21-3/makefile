CXX	 = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET   = p3
SRCS	 = main.cpp quickSort.cpp
OBJS     = $(SRCS:.cpp=.o)

.PHONY: all clean

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp quickSort.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
