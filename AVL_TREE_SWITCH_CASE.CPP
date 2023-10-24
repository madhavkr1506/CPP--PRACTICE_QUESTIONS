#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(TreeNode* node) {
    if (node == nullptr) return 0;
    return node->height;
}

void updateHeight(TreeNode* node) {
    if (node == nullptr) return;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

TreeNode* leftRotate(TreeNode* y) {
    TreeNode* x = y->right;
    TreeNode* T2 = x->left;
    x->left = y;
    y->right = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

TreeNode* rightRotate(TreeNode* x) {
    TreeNode* y = x->left;
    TreeNode* T2 = y->right;
    y->right = x;
    x->left = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

TreeNode* balance(TreeNode* node) {
    int balanceFactor = getHeight(node->left) - getHeight(node->right);

    if (balanceFactor > 1) {
        if (getHeight(node->left->left) >= getHeight(node->left->right))
            return rightRotate(node);
        else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balanceFactor < -1) {
        if (getHeight(node->right->right) >= getHeight(node->right->left))
            return leftRotate(node);
        else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        return root; // Duplicate keys are not allowed
    }

    updateHeight(root);
    return balance(root);
}

TreeNode* findMinNode(TreeNode* node) {
    if (node->left != nullptr)
        return findMinNode(node->left);
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            TreeNode* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            TreeNode* temp = findMinNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr) return root;

    updateHeight(root);
    return balance(root);
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;
    char operation;
    int key;

    while (true) {
        cout << "Enter 'I' to insert, 'D' to delete, 'T' to traverse, or 'Q' to quit: ";
        cin >> operation;

        switch (operation) {
            case 'I': // Insertion
                cout << "Enter key to insert: ";
                cin >> key;
                root = insert(root, key);
                break;

            case 'D': // Deletion
                cout << "Enter key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;

            case 'T': // Traversal
                cout << "In-order traversal of the AVL tree: ";
                inorderTraversal(root);
                cout << endl;
                break;

            case 'Q': // Quit
                return 0;

            default:
                cout << "Invalid operation. Please try again." << endl;
        }
    }

    return 0;
}
