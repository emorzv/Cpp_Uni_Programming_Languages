#include "HashTable.h"

int main()
{
	HashTable hashTable(5);

	/* Populate the table */
	hashTable.AddElement(1, "emo");
	hashTable.AddElement(2, "rizov");
	hashTable.AddElement(3, "VMware");
	hashTable.AddElement(1, "dopamine");
	hashTable.AddElement(4, "adrenaline");
	hashTable.AddElement(1, "neuroscience");
	hashTable.AddElement(5, "quantum entanglement");

	// Print the state of the hash table
	hashTable.PrintTable();

	return 0;
}