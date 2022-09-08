/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <string>
#include <iostream>
using namespace std;

/* Add a prototype for a helper function here if you need */


//Prints all values in linked list
void print(Node*& values)
{
  Node* temp = values;
  while (temp != NULL) 
  {
    std :: cout << temp->value << " ";
    temp = temp->next;
  }
}

//splits and prints into evens and odss
void split(Node*& in, Node*& odds, Node*& evens)
{
  Node* temp = in->next;
  
	//Checks if next value on input linked list is empty
  if(&temp->value == 0)
  {
		//Checks if even
    if(in->value % 2 == 0)
    {
      in->next = evens;
    }
		//Checks if odd
    if(in->value % 2 == 1)
    {
      in->next = odds;
    }
		//Calls print function to output both singly linked lists
    std::cout << "Print Odds: ";
    print(odds);
    std::cout << endl;
    std::cout << "Print Evens: ";
    print(evens);
    std::cout << endl;
		//Exists split
    return;
  }

	//Runs if next value next value Exists
	//Calls split recursively

	//Checks if even and adds to evens list
  if(in->value % 2 == 0)
  {
    in->next = evens;
    split(temp, odds, in);    
  }
	//Checks if odd adds to odds list
  else if(in->value % 2 == 1)
  {
    in->next = odds;
    split(temp, in, evens);
  }
}
