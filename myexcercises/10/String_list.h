#ifndef GUARD_string_list_h
#define GUARD_string_list_h

#include <cctype>
#include <cstddef>
#include <iterator>
#include <string>

struct Node {
    std::string str;
    Node* next;
    Node* prev;

    Node(): str(NULL), next(NULL), prev(NULL) {};
    Node(std::string s): str(s), next(NULL), prev(NULL) {};
};

class String_list
{
    private:
        Node* head;

    public:
        // constructors and destructors
        String_list(): head(NULL) {};
        ~String_list() { delete this->head; };

        void print_list() const;
        void insert(std::string new_str);
        void insert_front(std::string new_str);

        // iterators
        struct Iterator {
            using iterator_category = std::bidirectional_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = Node;
            using pointer = Node*;
            using reference = Node&;

            Iterator(pointer ptr): m_ptr(ptr) {};

            private:
                pointer m_ptr;
        };

        Iterator begin() { return head; };
        Iterator end() 
        {
            Node* end = head;
            while (end->next != NULL) {
                end = end->next;
            };
            return end;
        };
};

#endif
