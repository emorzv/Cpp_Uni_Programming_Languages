#ifndef CUSTOM_SCOPED_LOCK_H
#define CUSTOM_SCOPED_LOCK_H

using std::cout;
using std::endl;
using std::string;

template <typename T>
class CustomScopedArray
{
private:
	T* arr;
	int size;

public:
	/* Constructors to acquire the resources */
	CustomScopedArray() = delete;

	CustomScopedArray(int size)
	{
		/* Out of bounds check */
		if (size < 0) { exit(1); }

		this->size = size;
		arr = new T[size];
		cout << "Custom array constructed\n";
	}

	/* Array functionality */
	T& SetAt(int index)
	{
		/* Out of bounds check */
		if ((index >= this->size) || (index < 0))
		{
			exit(1);
		}

		return arr[index];
	}

	T GetAt(int index)
	{
		/* Out of bounds check */
		if ((index >= this->size) || (index < 0))
		{
			exit(1);
		}

		return arr[index];
	}

	int GetSize()
	{
		return this->size;
	}

	/* Destructors to release the previously acquired resources */
	~CustomScopedArray()
	{
		delete[]arr;
		cout << "Custom array destructed\n";
	}
};

#endif
