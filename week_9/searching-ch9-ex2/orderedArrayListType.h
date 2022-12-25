#ifndef H_OrderedListType
#define H_OrderedListType

#include <iostream>
#include "arrayListType.h"

using namespace std;

template<class elemType>
class orderedArrayListType : public arrayListType<elemType>
{
public:
	void insertOrd(const elemType&);

	int binarySearch(const elemType& item) const;

	int recursiveBinarySearch(const elemType& item) const;

	orderedArrayListType(int size = 100);

private:
	int recBinarySearch(const elemType& item, int first, int last) const;
};

template<class elemType>
void orderedArrayListType<elemType>::insertOrd(const elemType& item)
{
	int first = 0;
	int last = this->length - 1;
	int mid;

	bool found = false;

	if (this->length == 0)   //list is empty
	{
		this->list[0] = item;
		this->length++;
	}
	else if (this->length == this->maxSize)
		cerr << "Cannot insert into a full list." << endl;
	else
	{
		while (first <= last && !found)
		{
			mid = (first + last) / 2;

			if (this->list[mid] == item)
				found = true;
			else if (this->list[mid] > item)
				last = mid - 1;
			else
				first = mid + 1;
		}//end while

		if (found)
			cerr << "The insert item is already in the list. "
			<< "Duplicates are not allowed.";
		else
		{
			if (this->list[mid] < item)
				mid++;

			this->insertAt(mid, item);
		}
	}
}//end insertOrd

template<class elemType>
int orderedArrayListType<elemType>::binarySearch
(const elemType& item) const
{
	int first = 0;
	int last = this->length - 1;
	int mid;

	bool found = false;

	while (first <= last && !found)
	{
		mid = (first + last) / 2;

		if (this->list[mid] == item)
			found = true;
		else if (this->list[mid] > item)
			last = mid - 1;
		else
			first = mid + 1;
	}

	if (found)
		return mid;
	else
		return -1;
}//end binarySearch


template<class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size)
	: arrayListType<elemType>(size)
{
}

template <class elemType>
int orderedArrayListType<elemType>::recursiveBinarySearch
(const elemType& item) const
{
	return recBinarySearch(item, 0, this->length - 1);
}

template <class elemType>
int orderedArrayListType<elemType>::recBinarySearch(const elemType& item,
	int first, int last) const
{
	int mid;

	if (first <= last)
	{
		mid = (first + last) / 2;

		if (this->list[mid] == item)
			return mid;
		else if (this->list[mid] > item)
			return recBinarySearch(item, first, mid - 1);
		else
			return recBinarySearch(item, mid + 1, last);
	}
	else
		return -1;
}

#endif