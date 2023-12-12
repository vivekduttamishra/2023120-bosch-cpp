#pragma once
#include <string>
#include "index_error.h"
#include "empty_error.h"

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
        LinkedList& Append(int value)
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
            return *this;
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


        int & operator[](int index)
        {
            auto ptr=Locate(index);
            return ptr->data;
        }

        int operator[](int index) const
        {
            return Locate(index)->data;
        }

        void Set(int index,int value)
        {
           Locate(index)->data=value;
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
            if(size()==0)
                throw EmptyError("LinkedList is emtpy");

            if(index<0 || index>=size())
                throw IndexError("Index out of range",index);

            auto ptr=first;
            for(auto i=0;i<index;i++)
                ptr=ptr->next;

            return ptr;
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

        LinkedList operator+(const LinkedList& rhs) const
        {
            LinkedList result;
            for(auto ptr=first;ptr;ptr=ptr->next)
                result.Append(ptr->data);

            for(auto ptr=rhs.first;ptr;ptr=ptr->next)
                result.Append(ptr->data);

            return result;
        }

        ostream & operator<<(ostream &out)
        {
            if(first==nullptr)
                return out<<"LinkedList(empty)";
            
            out<<"LinkedList( ";

            for(auto ptr=first;ptr;ptr=ptr->next)
                out<<ptr->data<<" ";

            return out<<")";
        }

        LinkedList & operator<<(int value)
        {
            Append(value);
            return *this;
        }


    };



    inline ostream & operator<<(ostream &out, const LinkedList &list)
    {
        if(list.size()==0)
            return out<<"LinkedList(empty)";

        out<<"LinkedList( ";
        for(auto i=0;i<list.size();i++)
            out<<list[i]<<" ";

        return out<<")";
    }

}


