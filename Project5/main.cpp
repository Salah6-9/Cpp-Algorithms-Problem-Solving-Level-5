//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
#include "clsMyQueueArr.h"

using namespace std;

int main()
{
    clsMyQueueArr<int> myQueue;

    for (int value : {10, 20, 30, 40, 50})
        myQueue.push(value);

    cout << "Queue:\n";
    myQueue.Print();

    cout << "\nQueue size : " << myQueue.Size()
         << "\nQueue front: " << myQueue.front()
         << "\nQueue back : " << myQueue.back() << '\n';

    myQueue.pop();
    cout << "\nQueue after pop():\n";
    myQueue.Print();

    // Extension #1: Get an item by its zero-based index.
    constexpr int itemIndex = 1;
    int* item = myQueue.GetItem(itemIndex);
    if (item != nullptr)
        cout << "\nItem at index " << itemIndex << ": " << *item << '\n';
    else
        cout << "\nItem at index " << itemIndex << " was not found.\n";

    // Extension #2
    myQueue.Reverse();
    cout << "\nQueue after Reverse():\n";
    myQueue.Print();

    // Extension #3
    if (myQueue.UpdateItem(2, 600))
        cout << "\n\nQueue after updating index 2 to 600:\n";
    else
        cout << "\n\nCould not update index 2.\n";
    myQueue.Print();

    // Extension #4
    if (myQueue.InsertAfter(2, 800))
        cout << "\n\nQueue after inserting 800 after index 2:\n";
    else
        cout << "\n\nCould not insert after index 2.\n";
    myQueue.Print();

    // Extension #5
    myQueue.InsertAtFront(1000);
    cout << "\n\nQueue after inserting 1000 at the front:\n";
    myQueue.Print();

    // Extension #6
    myQueue.InsertAtBack(2000);
    cout << "\n\nQueue after inserting 2000 at the back:\n";
    myQueue.Print();

    // Extension #7
    myQueue.Clear();
    cout << "\n\nQueue after Clear():\n";
    myQueue.Print();

    return 0;
}
