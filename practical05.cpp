
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert a node at the end
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }

        cout << value << " inserted successfully.\n";
    }

    // Delete a node from the beginning
    void deleteNode() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << temp->data << " deleted successfully.\n";

        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        delete temp;
    }

    // Display in forward direction
    void displayForward() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Forward: ";

        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Display in reverse direction
    void displayReverse() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        cout << "Reverse: ";

        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        cout << "NULL\n";
    }

    // Free allocated memory
    ~DoublyLinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value;

    do {
        cout << "\n--- Doubly Linked List ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Delete from Beginning\n";
        cout << "3. Display Forward\n";
        cout << "4. Display Reverse\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insert(value);
                break;

            case 2:
                list.deleteNode();
                break;

            case 3:
                list.displayForward();
                break;

            case 4:
                list.displayReverse();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
