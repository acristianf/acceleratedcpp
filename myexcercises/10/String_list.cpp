#include <iostream>
#include "String_list.h"

using namespace std;

void String_list::print_list() const
{
    Node* temp = this->head;

    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->str << " ";
        temp = temp->next;
    }
}

void String_list::insert(string new_str)
{
    Node* new_node = new Node(new_str);

    if (this->head == NULL)
    {
        this->head = new_node;
        return;
    }

    Node* temp = this->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    new_node->prev = temp;
    temp->next = new_node;
}

void String_list::insert_front(string new_str)
{
    if (head == NULL) {
        head = new Node(new_str);
        return;
    }
    Node* temp = head;
    head = new Node(new_str);
    head->next = temp;
}
