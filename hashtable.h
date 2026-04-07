#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <list>
#include <memory>
#include <ostream>

class Record {
public:
	virtual ~Record() = default;
	virtual int         getID()	const = 0;
	virtual std::string getLine()	const = 0;
	virtual std::unique_ptr<Record> clone() const = 0;
};

class DataRecord : public Record {
public:
	explicit DataRecord(int id, const std::string& line);

	int 		getID()		const override;
	std::string 	getLine()	const override;
	std::unique_ptr<Record> clone() const override;

private:
	int		id_;
	std::string     line_;
};

class HashTable {
public:
	explicit HashTable(std::size_t capacity = 100);

	void insert(const Record& rec);

	bool erase(int key);

	std::unique_ptr<Record> search(int key) const;

	void clear();

	void save() const;

	std::size_t size()	const noexcept;
	std::size_t capacity()	const noexcept;

private:
	const Record* find(int key) const;

	std::size_t hash(int key) const noexcept;

	std::vector<std::list<std::unique_ptr<Record>>> table_;
	std::size_t m_;
	std::size_t size_ = 0;
};

#endif
