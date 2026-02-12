#include "queue.h"
#include <iostream>
#include <string>

int main() {
	Queue queue;
	std::string line;

	// REad all input lines until EOF
	while(std::getline(std::cin, line)) {
		queue.enqueue(line);
	}

	// Dequeue and print every other line
	bool print = true;
	while(!queue.isQueueEmpty()) {
		std::string line = queue.dequeue();
		if (print) {
			std::cout << line << std::endl;
		}
		print = !print;
	}

	return 0;
}
