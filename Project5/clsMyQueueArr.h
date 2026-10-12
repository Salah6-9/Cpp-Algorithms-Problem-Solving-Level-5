#pragma once

#include <iostream>
#include "../Project4/clsDynamicArray.h"

using namespace std;
template <class T>

class clsMyQueueArr
{

protected:
	clsDynamicArray<T> _MyList;

public:
	void push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}

	void pop()
	{
		_MyList.DeletFirstItem();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return *_MyList.GetItem(0);
	}

	T back()
	{
		return *_MyList.GetItem(Size() - 1);
	}
	// extantion 1

	T *GetItem(int index)
	{
		return _MyList.GetItem(index);
	}

	void Reverse ()
	{

		_MyList.Reverse();
	}

	bool UpdateItem(int index, T value)
	{
		return _MyList.UpdateItem(index, value);
	}

	bool InsertAfterIndex(int index, T value)
	{

		return _MyList.InsertAfter(index, value);
	}
	bool InsertAfter(int index, T value)
	{

		return _MyList.InsertAfter(index, value);
	}

	void  InsertAtFront(T value)
	{

		return _MyList.InsertAtBeginning(value);
	}
	bool InsertAtBack(T value)
	{

		return _MyList.InsertAtEnd(value);
	}

	void Clear (){
		_MyList.Clear();
	}
};
