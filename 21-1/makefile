CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = p1
OBJS = main.o list.o queue.o

$(TARGET) : $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	
main.o: main.cpp queue.h list.h
	$(CXX) $(CXXFLAGS) -c main.cpp

list.o: list.cpp list.h
	$(CXX) $(CXXFLAGS) -c list.cpp

queue.o: queue.cpp queue.h list.h
	$(CXX) $(CXXFLAGS) -c queue.cpp

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
