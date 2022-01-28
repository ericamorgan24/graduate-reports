/*
Purpose:
  A Property template entity class used to hold records with a specified value
Attributes:
  value: the value of type T that that all records have
  elements: a collection of Record*
Functions:
  Property(T):
    purpose: constructor for a Property object
    input: none
    output: a Property object
  T getValue():
    purpose: to get the value that all records in this collection have
    input: none
    output: value or type T
  int getSize():
    purpose: to get the number of elements in the collections
    input: none
    output: an int
  Property& operator+=(Record*):
    purpose: to add a Record* to the collection
    input: a Record* for the new record
    output: a Property& for the object itself that called the function
  Record* operator[](int):
    purpose: to retrieve the record at the specified index
    input: an int for the index
    output: a Record* for the record at the specified index
*/
#include <iostream>
using namespace std;
#include <vector>
#include "Record.h"


template <class T>
class Property
{
  public:
  	Property(T);
  	T getValue();
  	int getSize();
  	Property& operator+=(Record*);
  	Record* operator[](int);
  private:
  	T 			 		      value;
  	vector<Record*> 	elements;
  	
};



template <class T>
Property<T>::Property(T t)
 : value(t)
{

}



template <class T>
T Property<T>::getValue()
{
  return value;
}



template <class T>
int Property<T>::getSize()
{
  return elements.size();
}



template <class T>
Property<T>& Property<T>::operator+=(Record* r)
{
  elements.push_back(r);
  return *this;
}



template <class T>
Record* Property<T>::operator[](int i)
{
  if (i < 0 || i >= elements.size()) {
    cout << "ERROR:  invalid index" << endl; //review error handling/using view class???
    exit(1);
  }

  return elements[i];
}