#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;
#include <cstdlib>

template <class T>
class List
{
  class Node 
  {
    public:
      T* data;
      Node*    next;
  };

  public:
    List();
    ~List();//delocates all nodes
    void add(T*);//adds book to linked list
    T* get(int);//return at given index
    void print() const;//prints linked list data
    void cleanup();//delocates all book

  private:
    Node* head;
    Node* tail;
};

template <class T>
List<T>::List() : head(NULL), tail(NULL){}

template <class T>
List<T>::~List()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

template <class T>
void List<T>::add(T* d)
{
  Node* tmpNode;

  tmpNode = new Node;
  tmpNode->data = d;
  tmpNode->next = NULL;

  //adding first element
  if (head == NULL){
    head = tmpNode;
    tail = tmpNode;
  }
  else{
    tail->next = tmpNode;
    tail = tmpNode;
  }
}

template <class T>
T* List<T>::get(int index){
  Node* currNode;
  currNode = head;
  int i =0;
  //Error checking
  if(index < 0){
    return NULL; 
  }

  //traverse untill index is reached
  //increment i 
  //break if i equals index
  while (currNode != NULL) {
    if( i == index){
      return currNode->data;
    }
      currNode = currNode->next;
      ++i;
  }
  //Get here is index not found
  return NULL; 
}

template <class T>
void List<T>::cleanup(){
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->data;
    currNode = nextNode;
  }
}


template <class T>
void List<T>::print() const
{
  Node* currNode = head;

  while (currNode != NULL) {
    cout<< *(currNode->data);
    currNode = currNode->next;
  }
}

#endif
