#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() { root = NULL; }

    Node* insert(Node* node, int val) {
        if (node == NULL)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        else
            cout << "Duplicate value " << val << " not inserted\n";

        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    Node* findMin(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (node == NULL) return node;

        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    void deleteValue(int val) {
        root = deleteNode(root, val);
    }

    int maxDepth(Node* node) {
        if (node == NULL) return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }

    int maxDepth() {
        return maxDepth(root);
    }

    int minDepth(Node* node) {
        if (node == NULL) return 0;

        if (node->left == NULL && node->right == NULL)
            return 1;

        if (node->left == NULL)
            return 1 + minDepth(node->right);

        if (node->right == NULL)
            return 1 + minDepth(node->left);

        return 1 + min(minDepth(node->left), minDepth(node->right));
    }

    int minDepth() {
        return minDepth(root);
    }
    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal: ";
    tree.inorder();

    tree.deleteValue(20);
    cout << "After deleting 20: ";
    tree.inorder();

    cout << "Maximum depth: " << tree.maxDepth() << endl;
    cout << "Minimum depth: " << tree.minDepth() << endl;

    return 0;
}
