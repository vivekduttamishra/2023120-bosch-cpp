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
        Node *last=nullptr;
        int _size=0;

        Node * Locate(int index) const
        {
            if(Size()==0)
                throw EmptyError("LinkedList is emtpy");

            if(index<0 || index>=Size())
                throw IndexError("Index out of range",index);

            auto ptr=first;
            for(auto i=0;i<index;i++)
                ptr=ptr->next;

            return ptr;
        }

    public:
        LinkedList& Append(int value)
        {
            Node *newNode = new Node(value,nullptr,last);

            if (first == nullptr)
            {
                first = newNode;
            }
            else
            {
                last->next = newNode;
                
            }

            last=newNode;
            _size++;
            return *this;
        }

        
     

        LinkedList& Insert(int index, int value) 
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
            _size++;

            return *this;

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



        int Size() const
        {
            return _size;
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
            _size--;
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

        bool operator==(const LinkedList &rhs) const
        {
            if(Size()!=rhs.Size())
                return false;
            if(&rhs==this)
                return true;

            for(auto l1=first, l2=rhs.first; l1!=nullptr; l1=l1->next,l2=l2->next)
                if(l1->data!=l2->data)
                    return false;

            return true;
        }

    };

    inline ostream & operator<<(ostream &out, const LinkedList &list)
    {
        if(list.Size()==0)
            return out<<"LinkedList(empty)";

        out<<"LinkedList( ";
        for(auto i=0;i<list.Size();i++)
            out<<list[i]<<" ";

        return out<<")";
    }

    inline ostream & operator<<(ostream &out, const LinkedList *list)
    {
        return out<<*list;
    }
}


