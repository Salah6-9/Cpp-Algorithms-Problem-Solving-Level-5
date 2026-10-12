
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{

    clsDblLinkedList<int> MydblLinkedList;
    if (MydblLinkedList.IsEmpty())
        cout << "\nThe list is empty\n";
    else
        cout << "\nThe list is not empty\n";

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    clsDblLinkedList<int>::Node *N1 = MydblLinkedList.Find(2);

    if (N1 != NULL)
        cout << "\nNode with value 2 is Found :-)\n";
    else
        cout << "\nNode Is not found :-(\n";

    MydblLinkedList.InsertAfter(N1, 500);
    cout << "\nAfter Inserting 500 after 2:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAtEnd(700);
    cout << "\nAfter Inserting 700 at end:\n";
    MydblLinkedList.PrintList();

    clsDblLinkedList<int>::Node *N2 = MydblLinkedList.Find(4);
    MydblLinkedList.DeleteNode(N2);
    cout << "\nAfter Deleting 4:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.DeleteFirstNode();
    cout << "\nAfter Deleting First Node:\n";
    MydblLinkedList.PrintList();

    cout << "\nAfter Deleting Last Node:\n";
    MydblLinkedList.DeleteLastNode();
    MydblLinkedList.PrintList();

    cout << "\nSize of the list : " << MydblLinkedList.size() << endl;

    if (MydblLinkedList.IsEmpty())
    {

        cout << "\nThe list is empty\n";
    }
    else
    {
        cout << "\nThe list is not empty\n";
    }

    cout << "\nBefor Revers:\n";
    MydblLinkedList.PrintList();
    cout << "\nAfter Revers:\n";
    MydblLinkedList.Reverse();
    MydblLinkedList.PrintList();

    clsDblLinkedList<int>::Node *N3 = MydblLinkedList.GetNode(0);
    if (N3 != nullptr)
        cout << "\nValue of Node In Index Num 0 is " << N3->Value << endl;

    int *item = MydblLinkedList.GetItem(-5);
    if (item != nullptr)
        cout << "\nValue: " << *item << endl;
    else
        cout << "\nInvalid index.\n";


    MydblLinkedList.UpdateValue(0,1000);
    cout << "\nAfter Update:\n";
    MydblLinkedList.PrintList();    
    
    if(MydblLinkedList.InsertAfterIndex(0,2000)) 
    {
        cout << "\nList After Insert After Index 0 :\n";
        MydblLinkedList.PrintList();
    }else {
        cout <<"\nInserting Index Failed";
    }

    MydblLinkedList.Clear();

    if (MydblLinkedList.IsEmpty())
        cout << "\nThe list is empty\n";
    else
        cout << "\nThe list is not empty\n";
}