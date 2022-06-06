#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::string;
using std::list;

class HashTable
{
private:
	/* Defines the number of buckets the table will have */
	int numberOfBuckets;

	/* The actual table */
	list<string>* table;

public:
	/* Forbid the parameterless constructor */
	HashTable() = delete;
	
	/* Forbid the copy constructor */
	HashTable(const HashTable& ht) = delete;

	/* Parameterized constructor */
	HashTable(int numberOfBuckets) : numberOfBuckets(numberOfBuckets)
	{
		/* Allocate memory for the table */
		table = new list<string>[numberOfBuckets];

		/* Set the size of the table */
		this->numberOfBuckets = numberOfBuckets;

		cout << "Table constructed!\n";
	}

	/* Destructor used to free the allocated memory */
	~HashTable()
	{
		delete[]table;
		cout << "Table destructed!\n";
	}

	/* ----------------------------------------------- */

	/* Add a new element to the table */
	void AddElement(int key, const string& value)
	{
		/* Calculate the index in the table based on the given key */
		// Not really a hash function
		int calcBucket = key % this->numberOfBuckets;

		/* Insert the value in the table */
		table[calcBucket].push_back(value);
	}

	/* Print the whole table */
	void PrintTable()
	{
		for (int i = 0; i < this->numberOfBuckets; i++) 
		{
			cout << "| Bucket " << i << " | ";
			for (string current : table[i]) {
				cout << "-> | " << current << " | ";
			}
			cout << endl;
		}
	}

	/* Should I make the hash function static? */
	// static int HashFunction(key)
};

/*
 *	TODO:
 *		1) Implement the list manually
 *		2) Possibly create a hash function
 *		3) Possibly set a template types for the keys and values
 */

#endif // !HASHTABLE_H

