
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Insert a node at the end
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
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

        // Only one node
        if (head->next == head) {
            cout << temp->data << " deleted successfully.\n";
            delete temp;
            head = NULL;
            return;
        }

        Node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        cout << temp->data << " deleted successfully.\n";
        head = head->next;
        last->next = head;
        delete temp;
    }

    // Display the circular linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)\n";
    }

    // Free allocated memory
    ~CircularLinkedList() {
        if (head == NULL)
            return;

        Node* current = head->next;

        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        delete head;
        head = NULL;
    }
};

int main() {
    CircularLinkedList list;
    int choice, value;

    do {
        cout << "\n--- Circular Linked List ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete from Beginning\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
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
                list.display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
