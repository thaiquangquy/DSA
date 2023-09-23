#pragma once
#include <iostream>

// template <typename T>
// class LinkedList
// {
//     public:
//     LinkedList<T>();
//     LinkedList<T>(const LinkedList<T>& obj);
//     virtual ~LinkedList<T>();

//     private:
//     int length;
//     T* pList;
// };

void NodeTest()
{
    Node<int>* pHead = new Node<int>(1);

    Node<int>* pSec = new Node<int>(2);
    pHead->pNext = pSec;

    Node<int>* pThird = new Node<int>(3);
    pSec->pNext = pThird;

    Node<int>* pTemp = pHead;
    while (pTemp != NULL)
    {
        std::cout << pTemp->data << std::endl;
        pTemp = pTemp->pNext;
    }
}

template <typename T>
class Node
{
    public:
    Node();
    Node(T data);
    virtual ~Node();
    
    T data;
    Node* pNext;
};

template <typename T>
Node<T>::Node() :
pNext(nullptr)
{

}

template <typename T>
Node<T>::Node(T data) :
data(data),
pNext(nullptr)
{

}

template <typename T>
Node<T>::~Node()
{

}