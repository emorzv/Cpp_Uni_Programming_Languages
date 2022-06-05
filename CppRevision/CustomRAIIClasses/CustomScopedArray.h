#ifndef CUSTOM_SCOPED_LOCK_H
#define CUSTOM_SCOPED_LOCK_H

class CustomScopedArray
{
private:
	int* arr;
	int size;

public:
	/* Constructors to acquire the resources */
	CustomScopedArray() = delete;
	CustomScopedArray(int size);

	/* Array functionality */
	int& SetAt(int index);
	int GetAt(int index);
	int GetSize();

	/* Destructors to release the previously acquired resources */
	~CustomScopedArray();
};

#endif
