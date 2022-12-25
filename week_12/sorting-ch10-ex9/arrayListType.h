#ifndef H_arrayListType
#define H_arrayListType

#include <iostream>
#include <cassert>

using namespace std;

template <class elemType>
class arrayListType
{
public:
    const arrayListType<elemType>& operator=
        (const arrayListType<elemType>&);
    //Overloads the assignment operator
    bool isEmpty();
    //Function to determine whether the list is empty
    //Postcondition: Returns true if the list is empty; 
    //    otherwise, returns false.
    bool isFull();
    //Function to determine whether the list is full.
    //Postcondition: Returns true if the list is full; 
    //    otherwise, returns false.
    int listSize();
    //Function to determine the number of elements in the list
    //Postcondition: Returns the value of length.
    int maxListSize();
    //Function to determine the size of the list.
    //Postcondition: Returns the value of maxSize.
    void print() const;
    //Function to output the elements of the list
    //Postcondition: Elements of the list are output on the 
     //   standard output device.
    bool isItemAtEqual(int location, const elemType& item);
    //Function to determine whether the item is the same 
    //as the item in the list at the position specified by
    //Postcondition: Returns true if the list[location] 
    //    is the same as the item; otherwise, 
    //               returns false.
    void insertAt(int location, const elemType& insertItem);
    //Function to insert an item in the list at the 
    //position specified by location. The item to be inserted 
    //is passed as a parameter to the function.
    //Postcondition: Starting at location, the elements of the
    //    list are shifted down, list[location] = insertItem;,
    //    and length++;. If the list is full or location is
    //    out of range, an appropriate message is displayed.
    void insertEnd(const elemType& insertItem);
    //Function to insert an item at the end of the list. 
    //The parameter insertItem specifies the item to be inserted.
    //Postcondition: list[length] = insertItem; and length++;
    //    If the list is full, an appropriate message is 
    //    displayed.
    void removeAt(int location);
    //Function to remove the item from the list at the 
    //position specified by location 
    //Postcondition: The list element at list[location] is removed
    //    and length is decremented by 1. If location is out of 
    //    range,an appropriate message is displayed.
    void retrieveAt(int location, elemType& retItem);
    //Function to retrieve the element from the list at the  
    //position specified by location. 
    //Postcondition: retItem = list[location] 
    //    If location is out of range, an appropriate message is
    //    displayed.
    void replaceAt(int location, const elemType& repItem);
    //Function to replace the elements in the list at the 
    //position specified by location. The item to be replaced 
    //is specified by the parameter repItem.
    //Postcondition: list[location] = repItem 
    //    If location is out of range, an appropriate message is
    //    displayed.
    void clearList();
    //Function to remove all the elements from the list. 
    //After this operation, the size of the list is zero.
    //Postcondition: length = 0;
    int seqSearch(const elemType& item);
    //Function to search the list for a given item. 
    //Postcondition: If the item is found, returns the location 
    //    in the array where the item is found; otherwise,
    //    returns -1.
    void insert(const elemType& insertItem);
    //Function to insert the item specified by the parameter 
    //insertItem at the end of the list. However, first the
    //list is searched to see whether the item to be inserted 
    //is already in the list. 
    //Postcondition: list[length] = insertItem and length++
    //     If the item is already in the list or the list
    //     is full, an appropriate message is displayed.
    void remove(const elemType& removeItem);
    //Function to remove an item from the list. The parameter 
    //removeItem specifies the item to be removed.
    //Postcondition: If removeItem is found in the list,
    //      it is removed from the list and length is 
    //      decremented by one.

    arrayListType(int size = 100);
    //constructor
    //Creates an array of the size specified by the 
    //parameter size. The default array size is 100.
    //Postcondition: The list points to the array, length = 0, 
    //    and maxSize = size

    arrayListType(const arrayListType<elemType>& otherList);
    //copy constructor

    ~arrayListType();
    //destructor
    //Deallocates the memory occupied by the array.

    void selectionSort();
    void quickSort();
    void quickSortWithInsertionSort();
    void quickSortMedianPivot();
    void quickSortMedianWithInsertionSort();

protected:
    elemType* list;  //array to hold the list elements
    int length;      //to store the length of the list
    int maxSize;     //to store the maximum size of the list

    void swap(int first, int second);
    int minLocation(int first, int last);

    void recQuickSort(int first, int last);
    int partition(int first, int last);

    void recQuickSort20(int first, int last);
    void insertionSort20(int first, int last);

    void recQuickSortMedian(int first, int last);
    int partitionMedian(int first, int last);
    int medianLoc(int first, int middle, int last);

    void recQuickSortMedian20(int first, int last);
};

template<class elemType>
void arrayListType<elemType>::quickSort()
{
    recQuickSort(0, length - 1);
}

template<class elemType>
void arrayListType<elemType>::recQuickSort(int first, int last)
{
    int pivotLocation;

    if (first < last)
    {
        pivotLocation = partition(first, last);
        recQuickSort(first, pivotLocation - 1); //lower sublist recursive call
        recQuickSort(pivotLocation + 1, last);  //upper sublist recursive call
    }
}

template<class elemType>
int arrayListType<elemType>::partition(int first, int last)
{
    elemType pivot;

    int index, smallIndex;

    swap(first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }

    swap(first, smallIndex);

    return smallIndex;
}

template<class elemType>
void arrayListType<elemType>::quickSortWithInsertionSort()
{
    recQuickSort20(0, length - 1);
}

template<class elemType>
void arrayListType<elemType>::recQuickSort20(int first, int last)
{
    int pivotLocation;

    if (last - first > 20)
    {
        pivotLocation = partition(first, last);
        recQuickSort20(first, pivotLocation - 1);
        recQuickSort20(pivotLocation + 1, last);
    }
    else
        insertionSort20(first, last);
}


template<class elemType>
void arrayListType<elemType>::insertionSort20(int first, int last)
{
    int firstOutOfOrder, location;
    elemType temp;


    for (firstOutOfOrder = first + 1; firstOutOfOrder <= last;
        firstOutOfOrder++)
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            temp = list[firstOutOfOrder];
            location = firstOutOfOrder;

            do
            {
                list[location] = list[location - 1];
                location--;
            } while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
}

template<class elemType>
void arrayListType<elemType>::quickSortMedianPivot()
{
    recQuickSortMedian(0, length - 1);
}

template<class elemType>
void arrayListType<elemType>::recQuickSortMedian(int first, int last)
{
    int pivotLocation;

    if (first < last)
    {
        pivotLocation = partitionMedian(first, last);
        recQuickSortMedian(first, pivotLocation - 1);
        recQuickSortMedian(pivotLocation + 1, last);
    }
}

template<class elemType>
int arrayListType<elemType>::partitionMedian(int first, int last)
{
    elemType pivot;

    int index, smallIndex;

    swap(first, medianLoc(first, (first + last) / 2, last));

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }

    swap(first, smallIndex);

    return smallIndex;
}

template<class elemType>
int arrayListType<elemType>::medianLoc(int first,
    int middle, int last)
{
    if ((list[first] <= list[middle] && list[middle] <= list[last]) ||
        (list[first] >= list[middle] && list[middle] >= list[last]))
        return middle;
    else if ((list[middle] <= list[first] && list[first] <= list[last]) ||
        (list[middle] >= list[first] && list[first] >= list[last]))
        return first;
    else
        return last;
}

template<class elemType>
void arrayListType<elemType>::quickSortMedianWithInsertionSort()
{
    recQuickSortMedian20(0, length - 1);
}

template <class elemType>
void arrayListType<elemType>::recQuickSortMedian20(int first, int last)
{
    int pivotLocation;

    if (last - first > 20)
    {
        pivotLocation = partitionMedian(first, last);
        recQuickSortMedian20(first, pivotLocation - 1);
        recQuickSortMedian20(pivotLocation + 1, last);
    }
    else
        insertionSort20(first, last);
}

template <class elemType>
bool arrayListType<elemType>::isEmpty()
{
    return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull()
{
    return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize()
{
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize()
{
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";

    cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual
(int location, const elemType& item)
{
    return(list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt
(int location, const elemType& insertItem)
{
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted "
        << "is out of range" << endl;
    else
        if (length >= maxSize)  //list is full
            cerr << "Cannot insert in a full list" << endl;
        else
        {
            for (int i = length; i > location; i--)
                list[i] = list[i - 1];   //move the elements down

            list[location] = insertItem;  //insert the item at the 
                                          //specified position

            length++;     //increment the length
        }
} //end insertAt

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{

    if (length >= maxSize)  //the list is full
        cerr << "Cannot insert in a full list" << endl;
    else
    {
        list[length] = insertItem;   //insert the item at the end
        length++;   //increment the length
    }
} //end insertEnd

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed "
        << "is out of range" << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i + 1];

        length--;
    }
} //end removeAt

template <class elemType>
void arrayListType<elemType>::retrieveAt
(int location, elemType& retItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is "
        << "out of range." << endl;
    else
        retItem = list[location];
} //end retrieveAt


template <class elemType>
void arrayListType<elemType>::replaceAt
(int location, const elemType& repItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is "
        << "out of range." << endl;
    else
        list[location] = repItem;

} //end replaceAt

template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0;
} //end clearList

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item)
{
    int loc;
    bool found = false;

    for (loc = 0; loc < length; loc++)
        if (list[loc] == item)
        {
            found = true;
            break;
        }

    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
    int loc;

    if (length == 0)   //list is empty
        list[length++] = insertItem;    //insert the item and 
                                //increment the length
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        loc = seqSearch(insertItem);

        if (loc == -1)    //the item to be inserted 
                          //does not exist in the list
            list[length++] = insertItem;
        else
            cerr << "the item to be inserted is already in "
            << "the list. No duplicates are allowed." << endl;
    }
} //end insert

template<class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc;

    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
            << endl;
    }
} //end remove

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating "
            << "an array of size 100. " << endl;

        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0;

    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete[] list;
}


template <class elemType>
arrayListType<elemType>::arrayListType
(const arrayListType<elemType>& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize]; //create the array
    assert(list != NULL);         //terminate if unable to allocate
                                  //memory space

    for (int j = 0; j < length; j++)  //copy otherList
        list[j] = otherList.list[j];
} //end copy constructor

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
(const arrayListType<elemType>& otherList)
{
    if (this != &otherList)   //avoid self-assignment
    {
        delete[] list;
        maxSize = otherList.maxSize;
        length = otherList.length;

        list = new elemType[maxSize];  //create the array
        assert(list != NULL);   //if unable to allocate memory 
                                //space, terminate the program 
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }

    return *this;
}

template <class elemType>
void arrayListType<elemType>::selectionSort()
{
    int minIndex;

    for (int loc = 0; loc < length - 1; loc++)
    {
        minIndex = minLocation(loc, length - 1);
        swap(loc, minIndex);
    }
}

template <class elemType>
int arrayListType<elemType>::minLocation(int first, int last)
{
    int minIndex;

    minIndex = first;

    for (int loc = first + 1; loc <= last; loc++)
        if (list[loc] < list[minIndex])
            minIndex = loc;

    return minIndex;
} //end minLocation

template <class elemType>
void arrayListType<elemType>::swap(int first, int second)
{
    elemType temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}//end swap


#endif
