#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Node
{
public:
	string value;
	Node* next;
};

class List
{
private:
	Node* head;
	int size;

public:
	List()
	{
		/* Set the head to NULL, indicating that the list is empty */
		this->head = NULL;
		this->size = 0;

		cout << "List constructed!\n";
	}

	~List()
	{
		Node* holder;
		/* Traverse the whole list. Delete node by node */
		while (NULL != head)
		{
			/* Save the next node */
			holder = this->head->next;

			/* Delete the current node */
			delete this->head;

			/* Set the next node to be the current */
			this->head = holder;
		}

		cout << "List destructed!\n";
	}

	// -------------------------------------------------------

	void Append(const string& newValue)
	{
		/* Create the new node that's to be appended */
		Node* newNode = new Node();

		/* Set the new node's data */
		newNode->value = newValue;
		/* The new node's next has to be null since we append at the end */
		newNode->next = NULL;

		/* Check if the list is empty. If so, head points to the newly created node */
		if (NULL == this->head)
		{
			this->head = newNode;
			return;
		}

		/* Else - traverse till the end of the list and append */
		Node* temp = this->head;

		while (NULL != temp->next)
		{
			temp = temp->next;
		}

		/* Append */
		temp->next = newNode;

		/* Increment the size */
		this->size += 1;
	}

	int GetSize() const
	{
		return this->size;
	}

	void PrintList()
	{
		Node* temp = this->head;

		while (NULL != temp)
		{
			cout << "| " << temp->value << " | -> ";
			
			temp = temp->next;
		}

		cout << endl;
	}
};

#endif // SINGLYLINKEDLIST_H
