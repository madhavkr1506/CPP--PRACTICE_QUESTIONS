#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        // parameterised constructor
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList {
    public:
        Node* head;
        LinkedList() {
            this->head = NULL;
        }

        // INSERTION FUNCTIONS

        void append(int data) {
            Node* newNode = new Node(data);
            // LL is empty, this is the first Node getting created
            if(this->head == NULL) {
                this->head = newNode;
                return;
            }
            // go to the end of the LL, and add the Node at the end.
            Node* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        void addAtStart(int data) {
            Node* newNode = new Node(data);
            if(this->head == NULL) {
                this->head = newNode;
                return;
            }
            Node* oldHead = head;
            this->head = newNode;
            this->head->next = oldHead;
        }

        void insertAfter(int data1, int data2) {
            if(this->head == NULL) {
                Node* newNode = new Node(data2);
                cout << "List is Empty! Adding " << data2 << " at the start." << endl;
                this->head = newNode;
                return;
            }
            // search for data1
            Node* temp = head;
            while(temp->data != data1 && temp->next != NULL)
                temp = temp->next;
            // data1 is not in the LL ?
            if(temp->data != data1) {
                cout << data1 << " does not exist in the LinkedList. Aborting insertion." << endl;;
                return;
            }
            // data1 found, adding a data2 after data1
            Node* newNode = new Node(data2);
            newNode->next = temp->next;
            temp->next = newNode;
        }

        // DELETION FUNCTIONS

        void deleteFromStart() {
            if(this->head == NULL) {
                cout << "List is Empty! Aborting the deletion." << endl;
                return;
            }
            // if there is only one Node
            if(this->head->next == NULL) {
                delete(head);
                this->head = NULL;
                return;
            }
            Node* temp = this->head;
            this->head = head->next;
            delete(temp);
        }

        void deleteFromEnd() {
            if(this->head == NULL) {
                cout << "List is Empty! Aborting the deletion." << endl;
                return;
            }
            // if there is only one Node
            if(this->head->next == NULL) {
                delete(head);
                this->head = NULL;
                return;
            }
            Node* temp = this->head;
            while(temp->next->next != NULL)
                temp = temp->next;
            delete(temp->next);
            temp->next = NULL;
        }

        void deleteKey(int data) {
            if(this->head == NULL) {
                cout << "List is Empty! Aborting the deletion." << endl;
                return;
            }
            // search for the data in the LL
            Node* slow = this->head;
            Node* temp = this->head;
            while(temp->data != data && temp->next != NULL) {
                slow = temp;
                temp = temp->next;
            }
            // data is not in the LL ?
            if(temp->data != data) {
                cout << data << " does not exist in the LinkedList. Aborting deletion." << endl;;
                return;
            }
            slow->next = temp->next;
            delete(temp);
        }

        // Q1:- deleteElement(index);    |   EASY

        // PRINT STATEMENTS

        void printList() {
            Node* temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        // Q2:- printReverse();         | Prints the elements from the Singly LL in reverse
        void printListReverse(Node* head) {
            // base case
            if(head == NULL) return;
            // adding each Node to the stack of the compiler
            printListReverse(head->next);
            cout << head->data << " ";
        }
};

int main() {
    LinkedList list = LinkedList();         // head = NULL;

    list.deleteFromEnd();
    list.deleteFromStart();

    list.insertAfter(10, 1000);
    list.printList();                       //  1000

    list.append(100);
    list.append(200);
    list.append(300);
    list.append(400);
    list.append(500);
    list.printList();                       // 1000 100 200 300 400 500

    list.addAtStart(50);
    list.printList();                       // 50 1000 100 200 300 400 500

    list.insertAfter(2000, 600);            // Error Message | Not Found
    list.printList();

    list.insertAfter(200, 250);
    list.printList();                       // 50 1000 100 200 250 300 400 500

    list.deleteFromStart();
    list.printList();                       // 1000 100 200 250 300 400 500

    list.deleteFromEnd();
    list.printList();                       // 1000 100 200 250 300 400

    list.deleteKey(2000);                   // Error Message | Not Found

    list.deleteKey(200);
    list.printList();                       // 1000 100 250 300 400

    // list.deleteElement(0)                // 100 250 300 400

    // list.printReverse();                 // 400 300 250 100
    list.printListReverse(list.head);
    cout << endl;
}