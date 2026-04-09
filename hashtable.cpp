#include "hashtable.h"

#include <cmath>
#include <iostream>

// DataRecord implementation

DataRecord::DataRecord(int id, const std::string& line) : id_(id), line_(line) {}

int DataRecord::getID() const {
	return id_;
}

std::string DataRecord::getLine() const {
	return line_;
}

std::unique_ptr<Record> DataRecord::clone() const {
	return std::make_unique<DataRecord>(id_, line_);
}

// HashTable implementation

HashTable::HashTable(std::size_t capacity) : table_(capacity), m_(capacity) {}


void HashTable::insert(const Record& rec) {
	table_[hash(rec.getID())].push_back(rec.clone());
	++size_;
}

bool HashTable::erase(int key) {
	auto& chain = table_[hash(key)];
	for (auto it = chain.begin(); it != chain.end(); ++it) {
		if ((*it)->getID() == key) {
			chain.erase(it);
			--size_;
			return true;
		}
	}
	return false;
}

std::unique_ptr<Record> HashTable::search(int key) const {
	const Record* r = find(key);
	return r ? r->clone() : nullptr;
}

void HashTable::clear() {
	for (auto& chain : table_) chain.clear();
	size_ = 0;
}

<<<<<<< HEAD
void HashTable::save() const {
	for (const auto& chain : table_)
		for (const auto& rec : chain)
			std::cout << rec->getLine() << '\n';
}

=======
>>>>>>> 007a566 (working version with file writing)
std::size_t HashTable::size() const noexcept {
	return size_;
}

std::size_t HashTable::capacity() const noexcept {
	return m_;
}

const Record* HashTable::find(int key) const {
	for (const auto& rec : table_[hash(key)])
		if (rec->getID() == key) return rec.get();
	return nullptr;
}

std::size_t HashTable::hash(int key) const noexcept {
	constexpr double A = 0.6180339887498949;
	double frac = std::fmod(static_cast<double>(key) * A, 1.0);
	return static_cast<std::size_t>(m_ * frac);
}

std::string HashTable::toString() const {
	std::string result;
	for (const auto& chain : table_) {
		for (const auto& rec : chain) {
			result += rec->getLine() + '\n';
		}
	}
	return result;
}
