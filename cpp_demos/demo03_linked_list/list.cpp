#include <iostream>
using namespace std;
#include "linkedlist.h"


Node::Node(int data, Node *next,Node *previous)
{
        this->data=data;
        this->next=next;
        this->previous=previous;
}


void LinkedList::Show()
{
        for(Node *ptr=first;ptr!=nullptr;ptr=ptr->next)
            cout<<ptr->data<<" ";

        cout<<endl;
}

void LinkedList::Append(int value)
{
        Node *newNode =new Node(value);
        if (first==nullptr) 
        {
            first=newNode;
        }
        else
        {
            Node * ptr = first;
            while (ptr->next)
                ptr=ptr->next;

            ptr->next=newNode;
            newNode->previous=ptr;
        }
    
} 