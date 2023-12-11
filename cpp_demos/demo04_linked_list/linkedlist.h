#pragma once
#include <exception>
#include <string>
using namespace std;

class IndexError
{
    string message;
    public:
    IndexError(string message="Invalid Index"):message(message){}
    string what() const { return message; }
};

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
    void Show()
    {
        for (Node *ptr = first; ptr != nullptr; ptr = ptr->next)
            cout << ptr->data << " ";

        cout << endl;
    }

    void Insert(int index, int value)
    {
        if(index==0)
        {
            if(first!=nullptr) // list is NOT empty
            {
                Node * newNode=new Node(value,first,nullptr);
                first->previous=newNode;
                first=newNode;    
            }
            else
                throw  IndexError("Can't Insert to Empty List. Use Append");
        }
        else
        {
            Node * y= first;
            for(int i=0; i<index && y; i++)
                y=y->next;

            if(y)
            {
                Node *x=y->previous;

                Node *newNode=new Node(value,y,x);

                x->next=newNode;
                y->previous=newNode;
            }
            else
            {
                //cout<<"invalid index"<<index<<endl;
                //throw  exception();
                throw IndexError("Invalid Index.");
            }

        }
    }


};