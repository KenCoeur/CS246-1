#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/******************************************************
 * Data Structure: Linked List
 * Description: It is a collection of linked nodes.
 ******************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"
#include "Iterator.h"

namespace ds 
{
    /**************************************************
     * Typically all linked list data structure 
     * implementation contain the methods listed in 
     * the following interface.
     *************************************************/
    template <class T>
    class LinkedListInterface 
    {
    public:
        virtual void InsertFirst(const T&) = 0;
        virtual void InsertLast(const T&) = 0;
        virtual bool InsertAt(int,const T&) = 0;
        virtual void RemoveFirst() = 0;
        virtual void RemoveLast() = 0;        
        virtual void Remove(const T&) = 0;
        virtual T& First() = 0;
        virtual const T& First() const = 0;
        virtual T& Last() = 0;
        virtual const T& Last() const = 0;
        virtual int IndexOf(const T&) const = 0;
        virtual bool Contains(const T&) const = 0;
        virtual bool IsEmpty() const = 0;
        virtual int Size() const = 0;
        virtual T& operator[](int) = 0;
        virtual const T& operator[](int) const = 0;
    };

    namespace sn
    {
        //Singly Linked Node Implementation
        template <class T>
        class LinkedList : public LinkedListInterface<T> 
        {
        private:
            Node<T>* head;
            Node<T>* tail;
            int size;

            Node<T>* Get(int idx)
            {
                if(idx < 0 || idx >= size)
                {
                    return NULL;
                }
                else if(idx == size - 1)
                {
                    return tail;
                }

                Node<T>* tmp = head;

                for(int i = 0;i < idx;i += 1)
                {
                    tmp = tmp->GetLink();
                } 
                return tmp;
            }

        public:
            LinkedList() : head(NULL), tail(NULL), size(0) {}

            LinkedList(const LinkedList<T>& obj)
            {
                size = obj.size;
                head = Copy(obj.head);
                tail = head;
                
                if(tail != NULL)
                {
                    while(tail->GetLink() != NULL)
                    {
                        tail = tail->GetLink();
                    }
                }
            }

            LinkedList<T>& operator=(const LinkedList<T>& rhs)
            {
                if(this != &rhs)
                {
                    size = rhs.size;
                    Clear(head);
                    head = Copy(rhs.head);
                    tail = head;
                    
                    if(tail != NULL)
                    {
                        while(tail->GetLink() != NULL)
                        {
                            tail = tail->GetLink();
                        }
                    }
                }
                return *this;
            }

            ~LinkedList() 
            {
                Clear(head);
                tail = NULL;
            }

            void InsertFirst(const T& value)
            {
                if(head == NULL)
                {
                    head = new Node<T>(value);
                    tail = head;
                }
                else
                {
                    Node<T>* tmp = new Node<T>(value);
                    tmp->SetLink(head);
                    head = tmp;
                }
                size += 1;
            }

            void InsertLast(const T& value)
            {
                if(head == NULL)
                {
                    head = new Node<T>(value);
                    tail = head;
                }
                else
                {
                    tail->SetLink(new Node<T>(value));
                    tail = tail->GetLink();
                }
                size += 1;
            }

            bool InsertAt(int idx,const T& value)
            {
                if(idx < 0 || idx >= size)
                {
                    return false;
                }
                else if(idx == 0)
                {
                    InsertFirst(value);
                }
                else if(idx == size - 1)
                {
                    InsertLast(value);
                }
                else 
                {
                    Node<T>* prev = Get(idx - 1);
                    Node<T>* tmp = new Node<T>(value);
                    tmp->SetLink(prev->GetLink());
                    prev->SetLink(tmp);
                }
                return true;
            }

            void RemoveFirst() 
            {
                if(head != NULL)
                {
                    if(head == tail)
                    {
                        delete head;
                        head = NULL;
                        tail = NULL;
                    }
                    else 
                    {
                        Node<T>* tmp = head;
                        head = head->GetLink();
                        delete tmp;
                        tmp = NULL;
                    }
                    size -= 1;
                }
            }

            void RemoveLast() 
            {
                if(head != NULL)
                {
                    if(head == tail)
                    {
                        delete head;
                        head = NULL;
                        tail = NULL;
                    }
                    else 
                    {
                        Node<T>* tmp = head;

                        while(tmp->GetLink() != tail)
                        {
                            tmp = tmp->GetLink();
                        }
                        tmp->SetLink(NULL);
                        delete tail;
                        tail = tmp;
                    }
                    size -= 1;
                }
            }

            void Remove(const T& value)
            {
                if(head != NULL)
                {
                    if(head == tail && head->GetData() == value)
                    {
                        delete head;
                        head = NULL;
                        tail = NULL;
                        size -= 1;
                    }
                    else
                    {
                        Node<T>* tmp = head;
                        Node<T>* prv = NULL;

                        while(tmp != NULL && tmp->GetData() != value)
                        {
                            prv = tmp;
                            tmp = tmp->GetLink();
                        }

                        if(tmp != NULL && prv != NULL)
                        {
                            if (tmp == tail)
                            {
                                tail = prv;
                            }

                            prv->SetLink(tmp->GetLink());
                            delete tmp;
                            tmp = NULL;
                            size -= 1;
                        }
                    }
                }
            }

            T& First() 
            {
                if(head == NULL)
                {
                    throw "Out of Bound";
                }
                return head->GetData();
            }

            const T& First() const 
            {
                if(head == NULL)
                {
                    throw "Out of Bound";
                }
                return head->GetData();
            }

            T& Last() 
            {
                if(tail == NULL)
                {
                    throw "Out of Bound";
                }
                return tail->GetData();
            }

            const T& Last() const 
            {
                if(tail == NULL)
                {
                    throw "Out of Bound";
                }
                return tail->GetData();
            }

            int IndexOf(const T& value) const
            {
                int idx = 0;
                Node<T>* tmp = head;

                while(tmp != NULL && tmp->GetData() != value)
                {
                    tmp = tmp->GetLink();
                    idx += 1;
                }
                return (tmp == NULL)?(-1):(idx);
            }

            bool Contains(const T& value) const
            {
                Node<T>* tmp = head;

                while(tmp != NULL && tmp->GetData() != value)
                {
                    tmp = tmp->GetLink();
                }
                return (tmp != NULL);
            }

            bool IsEmpty() const
            {
                return (head == NULL);
            }

            int Size() const
            {
                return size;
            }

		    T& operator[](int idx)
		    {
			    if(idx >= 0 && idx < size)
			    {
				    Node<T>* tmp = head;
				    for(int i = 0;i < idx;i += 1)
				    {
					    tmp = tmp->GetLink();
				    }

				    return tmp->GetData();
			    }
			    throw "Out of Bound";
		    }

		    const T& operator[](int idx) const
		    {
			    if(idx >= 0 && idx < size)
			    {
				    Node<T>* tmp = head;
				    for(int i = 0;i < idx;i += 1)
				    {
					    tmp = tmp->GetLink();
				    }

				    return tmp->GetData();
			    }
			    throw "Out of Bound";
		    }

            Iterator<T>* ToIterator() const 
            {
                return new Iterator<T>(head);
            }

            std::string ToString() const 
            {
                std::stringstream out;
                out << "{";
                
                for(Node<T>* i = head;i != NULL;i = i->GetLink())
			    {
				    out << i->GetData();
				
				    if(i->GetLink() != NULL)
				    {
					    out << ",";
				    }
			    }
			    out << "}";
			    return out.str();
            }

            friend std::ostream& operator<<(std::ostream& out,const LinkedList<T>& obj)
            {
                out << obj.ToString();
                return out;
            }
        };
    }
}

#endif