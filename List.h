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
    void add(T*);//adds data to linked list
    T* get(int);//return at given index
    void cleanup();//delocates all data
    int getSize();//returns size

  private:
    Node* head;
    Node* tail;
    int size;
};

template <class T>
List<T>::List() : head(NULL), tail(NULL), size(0){}

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
int List<T>::getSize()
{
  return size;
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
  size++;
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
  size = 0;
}

#endif
