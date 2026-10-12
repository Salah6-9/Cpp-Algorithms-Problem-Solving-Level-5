#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
public:
    class Node
    {
    public:
        T Value;
        Node *Next;
        Node *Prev;
    };

    Node *head = nullptr;

protected:
    int _Size = 0;

private:
    Node *_CreateNode(T value)
    {
        Node *newNode = new Node();
        newNode->Value = value;
        newNode->Next = nullptr;
        newNode->Prev = nullptr;

        return newNode;
    }

public:
    clsDblLinkedList()
    {
        head = nullptr;
        _Size = 0;
    }

    void InsertAtBeginning(T Value)
    {
        Node *newNode = _CreateNode(Value);
        newNode->Prev = nullptr;
        newNode->Next = head;

        if (head != nullptr)
        {
            head->Prev = newNode;
        }
        head = newNode;
        _Size++;
    }

    void PrintList()
    {
        Node *Current = head;
        while (Current != nullptr)
        {
            cout << Current->Value << " ";
            Current = Current->Next;
        }
        cout << "\n";
    }

    Node *Find(T Value)
    {
        Node *Current = head;
        while (Current != nullptr)
        {
            if (Current->Value == Value)
                return Current;
            Current = Current->Next;
        }
        return nullptr;
    }

    void InsertAfter(Node *NodeAfter, T Value)
    {
        if (NodeAfter == nullptr)
            return;

        Node *newNode = _CreateNode(Value);
        newNode->Next = NodeAfter->Next;
        newNode->Prev = NodeAfter;

        if (NodeAfter->Next != nullptr)
        {
            NodeAfter->Next->Prev = newNode;
        }
        NodeAfter->Next = newNode;
        _Size++;
    }

    void InsertAtEnd(T Value)
    {
        Node *newNode = _CreateNode(Value);
        newNode->Next = nullptr;
        if (head == nullptr)
        {
            newNode->Prev = nullptr;
            head = newNode;
            _Size++;
            return;
        }

        Node *Current = head;
        while (Current->Next != nullptr)
        {
            Current = Current->Next;
        }
        newNode->Prev = Current;
        Current->Next = newNode;
        _Size++;
    }

    void DeleteNode(Node *DeletedNode)
    {
        if (DeletedNode == nullptr || head == nullptr)
            return;

        if (head == DeletedNode)
        {
            head = DeletedNode->Next;
            if (head != nullptr)
                head->Prev = nullptr;

            delete DeletedNode;
            _Size--;
            return;
        }

        if (DeletedNode->Next != nullptr)
        {
            DeletedNode->Prev->Next = DeletedNode->Next;
            DeletedNode->Next->Prev = DeletedNode->Prev;
        }
        else
        {
            DeletedNode->Prev->Next = nullptr;
        }
        delete DeletedNode;
        _Size--;
    }

    void DeleteFirstNode()
    {
        if (head == nullptr)
            return;

        Node *Temp = head;
        head = head->Next;
        if (head != nullptr)
            head->Prev = nullptr;

        delete Temp;
        _Size--;
    }

    void DeleteLastNode()
    {
        if (head == nullptr)
            return;

        if (head->Next == nullptr)
        {
            delete head;
            head = nullptr;
            _Size--;
            return;
        }

        Node *Current = head;
        while (Current->Next != nullptr)
        {
            Current = Current->Next;
        }
        Current->Prev->Next = nullptr;

        delete Current;
        _Size--;
    }

    int size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return _Size == 0;
    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }
    Node *LastNode()
    {
        if (head == nullptr)
            return nullptr;
        if (head->Next == nullptr)
            return head;

        Node *Current = head;

        while (Current->Next != nullptr)
        {
            Current = Current->Next;
        }
        return Current;
    }
    void Reverse()
    {
        Node *Current = head;
        Node *Temp = nullptr;

        while (Current != nullptr)
        {
            Temp = Current->Prev;
            Current->Prev = Current->Next;
            Current->Next = Temp;
            Current = Current->Prev;
        }

        if (Temp != nullptr)
        {
            head = Temp->Prev;
        }
    }

    Node *GetNode(int index)
    {
        int counter = 0;
        if (index > _Size - 1 || index < 0)
            return nullptr;

        Node *Current = head;
        while (Current != nullptr && (Current->Next != nullptr))
        {
            if (counter == index)
                break;

            Current = Current->Next;
            counter++;
        }
        return Current;
    }

    T *GetItem(int index)
    {
        Node *ItemNode = GetNode(index);
        if (ItemNode == nullptr)
            return nullptr; // if the index is invalid
        else
            return &ItemNode->Value; // return Adress Of Value
    }

    bool UpdateValue(int index, T Value)
    {
        T *value = GetItem(index);
        if (value == nullptr)
            return false;

        *value = Value;
        return true;
    }

    bool InsertAfterIndex(int index, T Value)
    {
        Node * NodeAfter = GetNode(index);
        if(NodeAfter == nullptr)
            return false;

        InsertAfter(NodeAfter,Value);
        return true;
    }
};
