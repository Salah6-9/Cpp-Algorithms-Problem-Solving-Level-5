#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

void PrintArrayInfo(clsDynamicArray<int> &dynamicArray, const string &message)
{
    cout << "\n============================================================\n";
    cout << message << "\n";
    cout << "Array Size : " << dynamicArray.Size() << "\n";
    cout << "Array Items: ";
    dynamicArray.PrintList();
}

int main()
{
    clsDynamicArray<int> myDynamicArray(10);

    myDynamicArray.SetItem(0, 10);
    myDynamicArray.SetItem(1, 20);
    myDynamicArray.SetItem(2, 30);
    myDynamicArray.SetItem(3, 40);
    myDynamicArray.SetItem(4, 50);
    myDynamicArray.SetItem(5, 60);

    cout << "Is Empty? " << myDynamicArray.IsEmpty() << "\n";
    PrintArrayInfo(myDynamicArray, "Initial array:");

    myDynamicArray.Resize(15);
    PrintArrayInfo(myDynamicArray, "After Resize(15):");

    myDynamicArray.Resize(5);
    PrintArrayInfo(myDynamicArray, "After Resize(5):");

    myDynamicArray.Reverse();
    PrintArrayInfo(myDynamicArray, "After Reverse():");

    int index = 1;
    int *item = myDynamicArray.GetItem(index);

    if (item != nullptr)
    {
        cout << "\nItem at index " << index << " = " << *item << "\n";
    }
    else
    {
        cout << "\nInvalid index: " << index << "\n";
    }

    myDynamicArray.DeleteAt(index);
    PrintArrayInfo(myDynamicArray, "After DeleteAt(1):");

    myDynamicArray.DeletFirstItem();
    PrintArrayInfo(myDynamicArray, "After DeletFirstItem():");

    myDynamicArray.DeletLastItem();
    PrintArrayInfo(myDynamicArray, "After DeletLastItem():");

    // Current size is 2 here, so index 1 is valid.
    index = 1;

    if (myDynamicArray.InsertAt(index, 45))
    {
        PrintArrayInfo(myDynamicArray, "After InsertAt(1, 45):");
    }
    else
    {
        cout << "\nInsertAt failed: invalid index.\n";
    }

    if (myDynamicArray.InsertAfter(index, 35))
    {
        PrintArrayInfo(myDynamicArray, "After InsetAfter(1, 35):");
    }
    else
    {
        cout << "\nInsetAfter failed: invalid index.\n";
    }

    if (myDynamicArray.InsertBefore(index, 25))
    {
        PrintArrayInfo(myDynamicArray, "After InsetBefore(1, 25):");
    }
    else
    {
        cout << "\nInsetBefore failed: invalid index.\n";
    }

    myDynamicArray.InsertAtBeginning(5);

        PrintArrayInfo(myDynamicArray, "After InsetAtBeginning(5):");

    if (myDynamicArray.InsertAtEnd(100))
    {
        PrintArrayInfo(myDynamicArray, "After InsetAtEnd(100):");
    }

    myDynamicArray.Clear();
    PrintArrayInfo(myDynamicArray, "After Clear():");

    return 0;
}