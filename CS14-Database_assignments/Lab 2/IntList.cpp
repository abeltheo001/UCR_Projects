#include "IntList.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

IntList::IntList()
{
    head = NULL;
    tail = NULL;
}

IntList::~IntList()
{
    while (head != NULL && tail != NULL)
        pop_front();
}

void IntList::push_front(int value)
{
    IntNode* newNode = new IntNode(value);

    if (!empty())
    {
        head -> prev = newNode; 
        newNode -> next = head;
        head = newNode; 
    }
    else
    {
        head = newNode;
        tail = newNode;
    }


}

void IntList::pop_front()
{
    if (!empty())
    {
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL; 

        }
        else 
        {
            IntNode* newNode = head;
            head = head -> next;
            head -> prev = NULL;
            delete newNode; 
        }
    }

}

void IntList::push_back(int value)
{
IntNode* newNode = new IntNode(value);
    if (!empty())
    {
        
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
    else 
    {
        head = newNode;
        tail = newNode;
    }
    
}

void IntList::pop_back()
{
    if (!empty())
    {
        if (head == tail)
        {
            delete tail;
            tail = NULL;
            head = NULL;
        }
        else 
        {
            IntNode* temp = tail;
            tail = tail -> prev;
            tail -> next = NULL;
            delete temp;
        }
        
    }

}

bool IntList::empty() const
{
    if (head == NULL && tail == NULL)
    {
        return true; 
    }
    else
    {
        return false;
    }

}

ostream & operator<<(ostream &out, const IntList &rhs)
{

    for (IntNode* base = rhs.head; base != NULL; base = base -> next)
    {
        out << base -> data;
        if (base -> next != NULL)
        {
            cout << " ";
        }
    }
    return out; 
}

void IntList::printReverse() const
{
    IntNode *temp = tail;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> prev;
    }
    
}