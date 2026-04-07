CXX	 = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET	 = p5
OBJS	 = main.o hashtable.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp hashtable.h
	$(CXX) $(CXXFLAGS) -c main.cpp

hashtable.o: hashtable.cpp hashtable.h
	$(CXX) $(CXXFLAGS) -c hashtable.cpp

clean:
	rm -f $(TARGET) $(OBJS)
