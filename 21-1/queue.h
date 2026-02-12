#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"
#include <string>

class Queue {
private:
	List list;

public:
	Queue();
	~Queue();

	void enqueue(const std::string& value);
	std::string dequeue();
	bool isQueueEmpty() const;
};

#endif
