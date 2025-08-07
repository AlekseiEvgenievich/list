#include <cstddef>
#include <iostream>
class Node {
public:
         double data;
         Node* prev, * next;
 
public:
         Node(double data) {
                   this->data = data;
                   this->prev = this->next = NULL;
         }
};

class LinkedList {
public:
         Node* head, * tail;
 
public:
         LinkedList() {
                   this->head = this->tail = NULL;
         }
    Node* push_front(double data){
        Node* ptr = new Node(data);
        ptr->next = head;
        if (head!=NULL){
            head->prev = ptr;
        }
        if(tail == NULL){
            tail = ptr;
        }
        head = ptr;
        return ptr;
    }
    Node* push_back(double data){
        Node* ptr = new Node(data);
        ptr->prev = tail;
        if(tail!=NULL){
            tail->next = ptr;
        }
        if(head == NULL){
            head = ptr;
        }
        tail = ptr;
        return ptr;
    }
    void pop_front(){
        if (head == NULL) return;
        Node* ptr = head->next;
        if(ptr != NULL){
            ptr->prev = NULL;
        }
        else{
            tail = NULL;
        }
        delete head;
        head = ptr;
    }
    void pop_back(){
        if (tail == NULL) return;
        Node* ptr = tail->prev;
        if(ptr!=NULL){
            ptr->next = NULL;
        }
        else{
            head = NULL;
        }
        delete tail;
        tail = ptr;
    }
    Node* insert(int index, double data){
        Node* ptr = head;
        int n = 0;
        while(n!=index){
            if(ptr == NULL){
                break;
            }
            ptr = ptr->next;
            ++n;
        }
        if(ptr == NULL){
            return push_back(data);
        }
        if(ptr->prev == NULL){
            return push_front(data);
        }
        Node* ptr1 = new Node(data);
        ptr1->next = ptr;
        ptr1->prev = ptr->prev;

        ptr->prev->next = ptr1;
        ptr->prev = ptr1;
        return ptr1;
    }
    void erase(int index){
        Node* ptr = head;
        int n = 0;
        while(n!=index){
            if(ptr == NULL){
                break;
            }
            ptr = ptr->next;
            ++n;
        }
        if(ptr == NULL){
            return;
        }
        if (ptr->prev == NULL) {
            pop_front();
            return;
        }
         
        if (ptr->next == NULL) {
            pop_back();
            return;
        }
        
        Node* left = ptr->prev;
        Node* right = ptr->next;
        left->next = right;
        right->prev = left;
        delete ptr;
    }
};

int main()
{
         LinkedList lst;
         lst.push_back(1.0);
         lst.push_back(2.0);
         lst.push_back(3.0);
         lst.push_back(4.0);
         lst.erase(1);
        for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next)
                     std::cout << ptr->data << " ";
           std::cout << std::endl;
 
         return 0;
}
