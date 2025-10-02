#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstddef>
#include <utility>

template<typename T>
class linkedlist
{
    private:
        struct node
        {
            T value;
            node* next;
            node(const T& val):value(val),next(nullptr){}
        };

        node* head;
        node* tail;
        size_t length;
    public:
        linkedlist():head(nullptr),tail(nullptr),length(0){}
        ~linkedlist(){ clear();}

        class iterator
        {
            node* ptr;
            public:
                iterator(node* p):ptr(p){}
                T& operator*(){ return ptr->value;}
                iterator& operator++(){ptr=ptr->next; return *this;}
                iterator operator++(int){ iterator temp=*this;ptr=ptr->next;return temp;}
                bool operator==(const iterator& other) const { return ptr == other.ptr; }
                bool operator!=(const iterator& other) const { return ptr != other.ptr; }

        };

        bool empty() const { return head==nullptr; }
        size_t size() const { return length; }
        iterator begin(){ return iterator(head);}
        iterator end(){ return iterator(nullptr);}

        void clear()
        {
            while(head)
            {
                node* temp=head;
                head=head->next;
                delete temp;
            }
            tail=nullptr;
            length=0;
        }

        void push_back(const T &value)
        {
            node* nnode=new node(value);
            if(!head)
            {
                head=tail=nnode;
            }
            else{
                tail->next=nnode;
                tail=nnode;
            }
            ++length;
        }

        void push_front(const T &value)
        {
            node* nnode=new node(value);
            if(!head)
            {
                head=tail=nnode;
            }
            else{
                nnode->next=head;
                head=nnode;
            }
            ++length;
        }

        iterator find(const T& value)
        {
            node* curr=head;
            while(curr)
            {
                if(curr->value==value) return iterator(curr);
                curr=curr->next;
            }
            return end();
        }

        void reverse()
        {
            node* prev=nullptr;
            node* curr=head;
            tail=head;
            while(curr)
            {
                node* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            head=prev;
        }

        bool erase(const T& value)
        {
            if(!head) return false;
            bool removed=false;
            while(head && head->value==value)
            {
                node* temp=head;
                head=head->next;
                delete temp;
                --length;
                removed=true;
            }

            if(!head)
            {
                tail=nullptr;
                return removed;
            }

            node* curr=head;
            while(curr->next)
            {
                if(curr->next->value==value)
                {
                    node* temp=curr->next;
                    curr->next=curr->next->next;
                    if(temp==tail) tail=curr;
                    delete temp;
                    --length;
                    removed=true;
                }
                else
                {
                    curr=curr->next;
                }
            }
            return removed;
        }

        void sort()
        {
            head=mergesort(head);
            tail=head;
            while(tail && tail->next) tail=tail->next;
        }
        
        private:
            node* mergesort(node* head)
            {
                if(!head || !head->next) return head;
                node* slow=head;
                node* fast=slow->next;
                while(fast && fast->next)
                {
                    slow=slow->next;
                    fast=fast->next->next;
                }
                node* mid=slow->next;
                slow->next=nullptr;
                node* left=mergesort(head);
                node* right=mergesort(mid);

                return merge(left,right);
            }

            node* merge(node* left,node* right)
            {
                node dummy(T{});
                node* curr=&dummy;
                while(left&& right)
                {
                    if(left->value<right->value)
                    {
                        curr->next=left;
                        left=left->next;
                    }
                    else{
                        curr->next=right;
                        right=right->next;
                    }
                    curr=curr->next;
                }
                curr->next=(left)?left:right;
                return dummy.next;
            }
};

#endif