#ifndef LIST_H
#define LIST_H

#include <string>

class List {
	private:
		class Node {
		public:
			std::string data;
			Node* next;
			Node* prev;

			Node(const std::string& value) : data(value), next(nullptr), prev(nullptr) {}

		};

		Node* head;
		Node* tail;
		int size;

	public:
		List();
		~List();

		bool isEmpty() const;
		int getSize() const;

		void insertFront(const std::string& value);
		void insertBack(const std::string& value);

		std::string removeFront();
		std::string removeBack();
};

#endif
