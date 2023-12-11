#pragma once

struct Node
{

    int data;
    Node * next;
    Node * previous;
    Node(int data,Node *next=nullptr, Node *previous=nullptr);
    
};

class LinkedList
{
    Node * first=nullptr;

public:
   
    void Append(int value);
    void Show();
    
};