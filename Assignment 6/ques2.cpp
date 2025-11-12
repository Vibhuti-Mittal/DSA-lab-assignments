#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val = 0, Node* n = NULL) {
        data = val;
        next = n;
    }
};

// Function to insert node at end of Circular Linked List
Node* insertAtEndCLL(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        newNode->next = newNode; // circular link to itself
        head = newNode;
        return head;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

// Function to display all nodes (repeating head value at end)
void displayCLLWithHeadRepeat(Node* head) {
    if (head == NULL) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "Circular Linked List: ";

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << head->data << endl; // repeat head node value at end
}

int main() {
    Node* head = NULL;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertAtEndCLL(head, val);
    }

    cout << "\nOutput: ";
    displayCLLWithHeadRepeat(head);

    return 0;
}
