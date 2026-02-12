#include "queue.h"

Queue::Queue() {}

Queue::~Queue() {}

void Queue::enqueue(const std::string& value) {
	list.insertBack(value);
}

std::string Queue::dequeue() {
	return list.removeFront();
}

bool Queue::isQueueEmpty() const {
	return list.isEmpty();
}
