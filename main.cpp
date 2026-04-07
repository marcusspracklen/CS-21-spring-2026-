#include "hashtable.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <memory>


void printMenu() {
	std::cout << "(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? ";
}



static std::unique_ptr<DataRecord> parseLine(const std::string& line) {
	if (line.empty()) return nullptr;
	std::istringstream ss(line);
	int id;
	if (!(ss >> id)) return nullptr;
	return std::make_unique<DataRecord>(id, line);
}


int main() {
	constexpr std::size_t TABLE_SIZE = 178000;
	HashTable ht(TABLE_SIZE);

	int choice = 0;
	while (true) {
		printMenu();
		if (!(std::cin >> choice)) break;
		std::cin.ignore();

		// 1: Load from file
		if (choice == 1) {
			std::string filename;
			std::cout << "read hash table - filename? ";
			std::getline(std::cin, filename);

			std::ifstream fin(filename);
			if (!fin) {
				std::cout << " ERROR: cannot open \"" << filename << "\"\n";
			} else {
				std::string line;
				int loaded = 0;
				while (std::getline(fin, line)) {
					if (line.empty()) continue;
					auto rec = parseLine(line);
					if (rec) { ht.insert(*rec); ++loaded; }
				}
				std::cout << "Loaded " << loaded << " record(s) from \"" << filename << "\"\n"; 
			}
		// 2: Insert from keyboard
		} else if (choice == 2) {
			std::cout << "input new record: ";
			std::string line;
			std::getline(std::cin, line);
			auto rec = parseLine(line);
			if (rec) {
				ht.insert(*rec);
			} else {
				std::cout << "ERROR: invalid record format.\n";
			}
		// 3: Delete by key
		} else if (choice == 3) {
			std::cout << " delete record - key? ";
			int key; 
			std::cin >> key; 
			std::cin.ignore();

			auto found = ht.search(key);
			if (found) {
				std::cout << "Delete: " << found->getLine() << '\n';
				ht.erase(key);
			} else {
				std::cout << "Delete not found: " << key << '\n';
			}
		// 4: Search by key
		} else if (choice == 4) {
			std::cout << "Search for record - key? ";
			int key;
			std::cin >> key;
			std::cin.ignore();

			auto found = ht.search(key);
			if (found) {
				std::cout << "Found: " << found->getLine() << '\n';
			} else {
				std::cout << "Search not found: " << key << '\n';
			}
		// 5: clear	
		} else if (choice == 5) {
			std::cout << "clearing hash table.\n";
			ht.clear();
		// 6: Save to file
		} else if (choice == 6) {
			std::string filename;
			std::cout << "write hash table - filename? ";
			std::getline(std::cin, filename);

			std::ofstream fout(filename);
			if (!fout) {
				std::cout << "ERROR: cannot open \"" << filename << "\" for writing.\n";
			} else {
				ht.save();
				std::cout << "Saved " << ht.size() << " record(s) to \"" << filename << "\"\n";
			}
		// 7: Quit
		} else if (choice == 7) {
			break;
		} else {
			std::cout << "Unkown command. Please enter 1-7.\n";
		}
	}

	return 0;
}
