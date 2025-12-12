#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int val) {
    Node* nn = new Node();
    nn->data = val;
    nn->left = nullptr;
    nn->right = nullptr;
    if (root == nullptr) {
        return nn;
    }
    else{
        if(val < root->data){
            root->left = insert(root->left, val);
        }
        else{
            root->right = insert(root->right, val);
        }
    }
    
    return root;
}
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;
    cout << "Preorder traversal of the BST: ";
    preorder(root);
    cout << endl;
    cout << "Postorder traversal of the BST: ";
    postorder(root);
    cout << endl;

    return 0;
}