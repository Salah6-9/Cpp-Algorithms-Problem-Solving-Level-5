#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsMyQueue
{
protected:
    class Node
    {
    public:
        T Value;
        Node *Next;
    };

    int _Size = 0;
    Node *_front;
    Node *_back;

private:
    Node *_CreateNode(T value)
    {
        Node *N = new Node();
        N->Value = value;
        N->Next = nullptr;
        return N;
    }

public:
    clsMyQueue()
    {
        _Size = 0;
        _front = nullptr;
        _back = nullptr;
    }

    void push(T value)
    {
        Node *newNode = _CreateNode(value);
        if (_back == nullptr && _front == nullptr)
        {
            _back = newNode;
            _front = newNode;
        }
        else
        {
            _back->Next = newNode;
            _back = newNode;
        }
        _Size++;
    }

    void pop()
    {
        
        if (_front == nullptr)
            return;
        Node *temp = _front;
        if (_back == _front)
        {
            
            delete temp;
            _front = nullptr;
            _back = nullptr;
            _Size = 0;
        }
        else
        {

            _front = _front->Next;
            delete temp;
            _Size--;
        }
    }
    void Print(){
        Node *current = _front;
        while (current != nullptr)
        {
            cout << current->Value << " ";
            current = current->Next;

        }
        
    }
    int Size(){
        return _Size;
    }

    T front()
    {
        if(_front != nullptr)
            return _front->Value;

        return T{};
    }
    T back()
    {
        if (_back != nullptr)
            return _back->Value;

        return T{};
    }
};

