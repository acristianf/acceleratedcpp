#ifndef GUARD_List_h
#define GUARD_List_h

#include <cctype>
#include <iostream>
#include <memory>

template<class T>
class List
{
    struct Node;

    public:
        typedef T value_type;
        //typedef Node* iterator;
        //typedef const Node* const_iterator;
        typedef size_t size_type;

        List(): head(NULL), length(0) {};

        class iterator;
        class const_iterator;

        iterator insert(const value_type&);
        iterator insert(iterator, const value_type&);
        iterator insert(const_iterator, const value_type&);
        void push_back();
        void push_front();
        iterator erase(const_iterator);
        void clear();
        
        bool empty() const;
        size_type size() const { return length; };

        void display() const;

        iterator begin() { return head != NULL ? iterator(head) : NULL; }
        const_iterator begin() const { return head != NULL ? const_iterator(head) : NULL; }

        iterator end() { return iterator(NULL); }
        const_iterator end() const { return const_iterator(NULL); }

        class iterator
        {
            public:
                iterator() noexcept : current_node(NULL) {}
                iterator(const Node* n) noexcept : current_node(n) {}

                iterator& operator=(Node* n)
                {
                    current_node = n;
                    return *this;
                }

                // overloaded prefix operator
                iterator& operator++()
                {
                    if (current_node)
                        current_node = current_node->next;
                    return *this;
                }

                // overloaded postfix operator
                iterator operator++(int)
                {
                    if (current_node)
                        current_node = current_node->next;
                    return iterator(current_node);
                }

                bool operator!=(const iterator& it)
                {
                    return current_node != it.current_node;
                }

                value_type operator*()
                {
                    return current_node->value;
                }

            private:
                const Node* current_node;
        };

        class const_iterator
        {
            public:
                const_iterator() : current_node(NULL) {}
                const_iterator(Node* n) : current_node(n) {}

            private:
                const Node* current_node;
        };

    private:
        struct Node
        {
            value_type value;
            Node* next;
            Node() { value = NULL; next = NULL; }
            Node(value_type v) { value = v; next = NULL; }
        };


        Node* head;
        size_type length;
        std::allocator<Node> alloc;

        Node* create();
        void uncreate();

};

template<class T>
typename List<T>::iterator List<T>::insert(const value_type& v)
{
    Node* new_node = create();
    alloc.construct(new_node, Node(v));
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    ++length;
    return iterator(new_node);
}

// TODO: Finish this insert operation
template<class T>
typename List<T>::iterator List<T>::insert(iterator pos, const value_type& v)
{
    Node* new_node = create();
    alloc.construct(new_node, Node(v));
    if (pos != NULL)
    {
        Node* temp = pos;

        iterator it = pos;
        --it;

        it->next = new_node;
        new_node->next = temp;
        pos = new_node;
    }
    else
    {
        return iterator(NULL);
    }
    return iterator(new_node);
}


template<class T>
typename List<T>::Node* List<T>::create()
{
    return alloc.allocate(1);
}

template<class T>
void List<T>::clear()
{
    uncreate();
}

template<class T>
void List<T>::uncreate()
{
    Node* temp = head;
    Node* prev = head;
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        alloc.destroy(prev);
        alloc.deallocate(prev, 1);
    }
    head = NULL;
    length = 0;
}

template<class T>
void List<T>::display() const
{
    Node* temp = head;
    std::cout << "[";
    while (temp != NULL)
    {
        std::cout << " " << temp->value << " ";
        temp = temp->next;
    }
    std::cout << "]" << std::endl;
}

#endif
