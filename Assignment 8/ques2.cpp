#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insertBST(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if (!root) return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* target) {
    if (!target) return nullptr;

    if (target->right)
        return findMin(target->right);

    Node* successor = nullptr;
    while (root) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (target->data > root->data) {
            root = root->right;
        }
        else break;
    }
    return successor;
}

Node* inorderPredecessor(Node* root, Node* target) {
    if (!target) return nullptr;

    if (target->left)
        return findMax(target->left);

    Node* predecessor = nullptr;
    while (root) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else if (target->data < root->data) {
            root = root->left;
        }
        else break;
    }
    return predecessor;
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of nodes to insert: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insertBST(root, val);
    }

    int key;
    cout << "\nEnter key to search: ";
    cin >> key;

    Node* rec = searchRecursive(root, key);
    Node* nonrec = searchNonRecursive(root, key);

    cout << "\nRecursive Search: ";
    if (rec) cout << "Found\n";
    else cout << "Not Found\n";

    cout << "Non-Recursive Search: ";
    if (nonrec) cout << "Found\n";
    else cout << "Not Found\n";

    Node* mn = findMin(root);
    if (mn) cout << "\nMinimum element: " << mn->data << endl;

    Node* mx = findMax(root);
    if (mx) cout << "Maximum element: " << mx->data << endl;

    if (rec) {
        Node* suc = inorderSuccessor(root, rec);
        cout << "Inorder Successor of " << key << ": ";
        if (suc) cout << suc->data << endl;
        else cout << "None\n";
    }

    if (rec) {
        Node* pre = inorderPredecessor(root, rec);
        cout << "Inorder Predecessor of " << key << ": ";
        if (pre) cout << pre->data << endl;
        else cout << "None\n";
    }

    return 0;
}
