#pragma once
#include <string>
#include "index_error.h"
#include "empty_error.h"
#include "null_pointer_exception.h"
#include "prime.h"

using namespace std;

namespace conceptarchitect::collections
{

    template<typename T>
    using Matcher= bool(*)(const T & value);

    template<typename T>
    class LinkedList;

    template<typename T>
    inline ostream &operator<<(ostream &out, const LinkedList<T> &list);

    template<typename T>
    inline ostream &operator<<(ostream &out, const LinkedList<T> *list);

    template<typename X>
    struct Node
    {

        X data;
        Node *next;
        Node *previous;

        Node(X data, Node *next = nullptr, Node *previous = nullptr)
        {
            this->data = data;
            this->next = next;
            this->previous = previous;
        }
    };

    template<class E>
    class LinkedListNodePointer
    {
        Node<E> *ptr;

    public:
        LinkedListNodePointer(Node<E> *ptr) : ptr(ptr) {}

        E operator*()
        {
            if (ptr)
                return ptr->data;
            else
                throw NullPointerException("Invalid Location");
        }

        E &operator->()
        {
            return ptr->data;
        }

        LinkedListNodePointer<E> &operator++()
        {
            if (ptr)
                ptr = ptr->next;

            return *this;
        }

        LinkedListNodePointer<E> &operator--()
        {
            if (ptr)
                ptr = ptr->previous;

            return *this;
        }

        bool operator==(const LinkedListNodePointer<E> &rhs) const
        {
            return ptr == rhs.ptr;
        }

        operator bool()
        {
            return ptr != nullptr;
        }
    };



    template<typename T>
    class LinkedList
    {

        Node<T> *first = nullptr;
        Node<T> *last = nullptr;
        int _size = 0;

        Node<T> *Locate(int index) const
        {
            if (Size() == 0)
                throw EmptyError("LinkedList is emtpy");

            if (index < 0 || index >= Size())
                throw IndexError("Index out of range", index);

            auto ptr = first;
            for (auto i = 0; i < index; i++)
                ptr = ptr->next;

            return ptr;
        }

        void AppendAll(){}
    public:

        LinkedList()
        {
        }

        LinkedList( initializer_list<T> values)
        {
            for(auto value : values)
                AppendOne(value);
        }

        LinkedList(const LinkedList<T> &rvalue)
        {
            // deep copy
            CopyAll(rvalue);
        }

        LinkedList &operator=(const LinkedList<T> &rvalue)
        {
            if (this == &rvalue)
                return *this;
            Clear();
            CopyAll(rvalue);
            return *this;
        }

    
        LinkedList(LinkedList<T> &&rvalue) // move constructor
        {
            // step #1 simple shallow copy
            first = rvalue.first;
            last = rvalue.last;
            _size = rvalue._size;

            // step #2 cancel the ownership of rvalue.
            rvalue.first = nullptr;
            rvalue.last = nullptr;
            rvalue._size = 0;
        }

        LinkedList<T> & operator=(LinkedList<T> &&rvalue) // move
        {
            // step #0 avoid self copy
            if (this == &rvalue)
                return *this;

            // Step#1 shallow copy reference
            first = rvalue.first;
            last = rvalue.last;
            _size = rvalue._size;

            // step #2 cancel the ownership of rvalue.
            rvalue.first = nullptr;
            rvalue.last = nullptr;
            rvalue._size = 0;

            return *this;
        }

        

        ~LinkedList()
        {
            Clear();
        }

        LinkedList<T> &CopyAll(const LinkedList<T> &other)
        {
            for (auto ptr = other.first; ptr; ptr = ptr->next)
                AppendOne(ptr->data);

            return *this;
        }

        LinkedList<T> &Clear()
        {
            auto ptr = first;
            while (ptr)
            {
                auto del = ptr;
                ptr = ptr->next;
                delete del;
            }

            first = last = nullptr;
            _size = 0;

            return *this;
        }

        LinkedList<T> & Append(initializer_list<T> values)
        {
            for(auto value : values)
                AppendOne(value);

            return *this;
        }

        template<typename ...Args>
        void AddAll(Args...args)
        {
            ((AppendOne(args)),...); 
        }

        template<typename ...Args>
        void AppendAll(T value, Args... args) //parameter pack
        {
            
            AppendOne(value);

            AppendAll( args...); // unpack parameter and call again.
            
        }



        

        LinkedList<T> &AppendOne(T value)
        {
            auto newNode = new Node<T>(value, nullptr, last);

            if (first == nullptr)
            {
                first = newNode;
            }
            else
            {
                last->next = newNode;
            }

            last = newNode;
            _size++;
            return *this;
        }

        LinkedList &Insert(int index, T value)
        {
            auto ptr = Locate(index);
            auto y = ptr->next;
            auto x = ptr->previous;

            auto newNode = new Node<T>(value, y, x);

            if (x)
                x->next = newNode;
            else
                first = newNode;

            y->previous = newNode;
            _size++;

            return *this;
        }

        T &operator[](int index)
        {
            auto ptr = Locate(index);
            return ptr->data;
        }

        T operator[](int index) const
        {
            return Locate(index)->data;
        }

      

        int Size() const
        {
            return _size;
        }

        T Remove(int index)
        {
            auto ptr = Locate(index);

            auto x = ptr->previous;
            auto y = ptr->next;

            if (x)
                x->next = y;
            else
                first = y;

            if (y)
                y->previous = x;

            auto value = ptr->data;

            delete ptr;
            _size--;
            return value;
        }

        LinkedList<T> &operator+(const LinkedList<T> &rhs) const
        {
            LinkedList *result = new LinkedList;
            for (auto ptr = first; ptr; ptr = ptr->next)
                result->Append(ptr->data);

            for (auto ptr = rhs.first; ptr; ptr = ptr->next)
                result->Append(ptr->data);

            return *result;
        }

        

        LinkedList<T> &operator<<(T value)
        {
            AppendOne(value);
            return *this;
        }

        bool operator==(const LinkedList<T> &rhs) const
        {
            if (Size() != rhs.Size())
                return false;
            if (&rhs == this)
                return true;

            for (auto l1 = first, l2 = rhs.first; l1 != nullptr; l1 = l1->next, l2 = l2->next)
                if (l1->data != l2->data)
                    return false;

            return true;
        }

       
        LinkedListNodePointer<T> begin()
        {
            return LinkedListNodePointer<T>(first);
        }

        LinkedListNodePointer<T> end()
        {
            return LinkedListNodePointer<T>(nullptr);
        }

        template<typename X>
        friend ostream &operator<<(ostream &out, const LinkedList<X> &list);

        template<typename Matcher>
        LinkedList<T> find(Matcher match)
        {
            LinkedList<T> result;

            for(auto ptr=first; ptr != nullptr; ptr = ptr->next)
                if( match(ptr->data))
                    result.Append(ptr->data);

            return result;
        }


    };

   

    template<typename T>
    inline ostream &operator<<(ostream &out, const LinkedList<T> &list)
    {
        if (list.Size() == 0)
            return out << "LinkedList(empty)";

        out << "LinkedList( ";
        for (auto ptr=list.first; ptr; ptr=ptr->next)
            out << ptr->data << " ";

        return out << ")";
    }

    template<typename T>
    inline ostream &operator<<(ostream &out, const LinkedList<T> *list)
    {
        return out << *list;
    }
}
