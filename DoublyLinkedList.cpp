#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

class DoublyLinkedList {
    public:
        Node* head; Node* tail;
        DoublyLinkedList() {
            this->head = NULL;
            this->tail = NULL;
        }

        // INSERTION OPERATIONS

        void append(int data) {
            Node* newNode = new Node(data);
            if(this->head == NULL) {
                this->head = newNode;
                this->tail = newNode;
                return;
            }
            Node* temp = this->head;
            while(temp->next != NULL)
                temp = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            this->tail = newNode;
        }

        // DISPLAY OPERATION

        void print() {
            Node* temp = this->head;
            while(temp != tail) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << tail->data << endl;
        }

        void printReverse() {
            Node* temp = this->tail;
            while(temp != head) {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << head->data << endl;
        }
};

int main() {
    DoublyLinkedList list = DoublyLinkedList();             // head = NULL | tail = NULL
    list.append(100);
    list.append(200);
    list.append(300);
    list.append(400);
    list.append(500);
    list.print();                                           // 100 200 300 400 500
    list.printReverse();                                    // 500 400 300 200 100

    return 0;
}