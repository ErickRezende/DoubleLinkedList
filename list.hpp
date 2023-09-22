#pragma once 

#include <iostream>
using namespace std;

/*
    Autor: Erick Rezende
    Description: A double linked list implementation
    Date: 2023-09-21
*/

template<class T>
class Node {
public:
    T data;
    Node<T>* pPrevious;
    Node<T>* pNext;

    Node(T value = NULL, Node<T>* pPrevious = nullptr, Node<T>* pNext = nullptr): 
        pPrevious(pPrevious), pNext(pNext), data(value) {
    }
};

template<class T>
class List {
private:
    int listSize;
    Node<T>* pFirst;
    Node<T>* pLast;

public:
    List():
        listSize(0), pFirst(nullptr), pLast(nullptr){
    }

    void push(T value){
        Node<T>* newNode = new Node<T>(value, pLast);
        if(this->empty()){
            pFirst = pLast = newNode;
            listSize++;
            return;
        }
        pLast = pLast->pNext = newNode;

        listSize++;
    } 

    void push(T value, int index){
        this->push(value, atInPointer(index));
    } 

    void push(T value, Node<T>* newPos){
        Node<T>* newNode = new Node<T>(value);
        if(this->empty()){
            pFirst = pLast = newNode;
            listSize++;
            return;
        }

        newNode->pNext = newPos;

        newPos != pFirst ? newPos->pPrevious->pNext = newNode : pFirst = newNode;
        newPos != pLast  ? newPos->pNext->pPrevious = newNode : pLast->pPrevious = newNode;

        listSize++;
    } 

    void purge() {
        this->purge(pLast);
    }

    void purge(int index) {
        this->purge(atInPointer(index));
    }

    void purge(Node<T>* nodeToPurge) {
        nodeToPurge != pFirst ? nodeToPurge->pPrevious->pNext = nodeToPurge->pNext : pFirst = nodeToPurge->pNext;
        nodeToPurge != pLast  ? nodeToPurge->pNext->pPrevious = nodeToPurge->pPrevious : pLast = nodeToPurge->pPrevious;
    
        listSize--;
    }

    bool empty() {
        return pFirst == nullptr && pLast == nullptr;
    }

    Node<T>* atInPointer(int index) {
        Node<T>* newNode = pFirst;

        for (int i = 0; i < index; i++){
            newNode = newNode->pNext;
        }

        /*Node<T>* newNode = pLast;

        for (int i = index; i > 0; i--){
            newNode = newNode->pPrevious;
        }*/

        return newNode;
    }

    T at(int index) {
        return atInPointer(index)->data;
    }

    int size() {
        return this->listSize;
    }

    Node<T>* last() {
        return this->pLast;
    }

    Node<T>* first() {
        return this->pFirst;
    }


};