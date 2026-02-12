#include "list.h"
#include <stdexcept>

List::List() : head(nullptr), tail(nullptr) {}

List::~List() {
	while (!isEmpty()) {
		removeFront();
	}
}

void List::insertFront(const std::string& value) {
	Node* newNode = new Node(value);

	if(isEmpty()) {
		head = tail = newNode;
	} else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void List::insertBack(const std::string& value) {
	Node* newNode = new Node(value);

	if(isEmpty()) {
		head = tail = newNode;
	} else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}

std::string List::removeFront() {
	if(isEmpty()) {
		throw std::runtime_error("Cannot removeFront on empty list");
	}	

	Node* temp = head;
	std::string value = temp->data;

	if(head == tail) {
		head = tail = nullptr;
	} else {
		head = head->next;
		head->prev = nullptr;
	}

	delete temp;
	size--;
	return value;
}

std::string List::removeBack() {
	if(isEmpty()) {
		throw std::runtime_error("Cannot removeBack on empty list");
	}

	Node* temp = tail;
	std::string value = temp->data;

	if(head == tail) {
		// only one node
		head = tail = nullptr;
	} else {
		tail = tail->prev;
		tail->next = nullptr;
	}

	delete temp;
	size--;
	return value;
}

bool List::isEmpty() const {
	return size == 0;
}

int List::getSize() const {
	return size;
}

