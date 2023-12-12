#pragma once
#include <string>
#include "index_error.h"
using namespace std;

namespace conceptarchitect::collections
{

    struct Node
    {

        int data;
        Node *next;
        Node *previous;
        Node(int data, Node *next = nullptr, Node *previous = nullptr)
        {
            this->data = data;
            this->next = next;
            this->previous = previous;
        }
    };

    class LinkedList
    {
        Node *first = nullptr;

    public:
        void Append(int value)
        {
            Node *newNode = new Node(value);
            if (first == nullptr)
            {
                first = newNode;
            }
            else
            {
                Node *ptr = first;
                while (ptr->next)
                    ptr = ptr->next;

                ptr->next = newNode;
                newNode->previous = ptr;
            }
        }
        
        void Show() const
        {
            for (Node *ptr = first; ptr != nullptr; ptr = ptr->next)
                cout << ptr->data << " ";

            cout << endl;
        }

        void Insert(int index, int value) 
        {
            auto ptr= Locate(index);
            Node *y= ptr->next;
            Node * x= ptr->previous;

            auto newNode= new Node(value,y,x);

            if(x)
                x->next=newNode;
            else
                first=newNode;

            y->previous=newNode;


        }




        int size() const
        {
            int c=0;
            for(auto ptr=first; ptr!=nullptr; ptr=ptr->next)
                c++;

            return c;
        }

        Node * Locate(int index) const
        {
            if(index<0 || index>=size())
                throw IndexError("Index out of range",index);

            auto ptr=first;
            for(auto i=0;i<index;i++)
                ptr=ptr->next;

            return ptr;
        }

        int Get(int index) const
        {
            // if(index<0 || index>=size())
            //     throw "Index out of range";

            // auto ptr=first;
            // for(auto i=0;i<index;i++)
            //     ptr=ptr->next;

            // return ptr->data;

            return Locate(index)->data;

        }

        void Set(int index,int value)
        {
            // if(index<0 || index>=size())
            //     throw "Index out of range";
            // auto ptr=first;
            // for(auto i=0;i<index;i++)
            //     ptr=ptr->next;

            // ptr->data=value;

            Locate(index)->data=value;
        }

        int Remove(int index)
        {
            auto ptr=Locate(index);

            auto x= ptr->previous;
            auto y= ptr->next;

            if(x)
                x->next=y;
            else
                first=y;

            if(y)
                y->previous=x;

            auto value=ptr->data;
            
            delete ptr;

            return value;
        }

    };
}
