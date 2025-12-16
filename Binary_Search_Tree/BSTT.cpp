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

// Traversal methods
// Inorder, Preorder, Postorder
void inorder(Node* root) {
    // if (root == nullptr) {
    //     return;
    // }                               // this can also be used
    if(root != nullptr){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    
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

// Search in BST
Node* search(Node* root, int key, int &count) {
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->data == key) {
        cout<<"Number of comparisons made: "<<count<<endl;
        return root;
    }
    // Key is greater than root's key
    else if (key > root->data) {
        count++;
        return search(root->right, key, count);
    }
    else if (key < root->data) {
        count++;
        return search(root->left, key, count);
    }

}


// delete function can be added here
struct Node* deleteNode(struct Node* root, int key) {
    // Base Case
    if (root == nullptr) {
        return root;
    }
    // Recursive calls for ancestors of
    // node to be deleted
    else if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    
    }
    else{// if root->data ==key
        //found the node to be deleted
        if(root->left == NULL && root->right == NULL){
            // case 1: node to be deleted is leaf node
            delete root;
            return nullptr;
        }
        else if(root->left == NULL){
            // case 2: node to be deleted has only right child
            struct Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            // case 2: node to be deleted has only left child
            struct Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            // case 3: node to be deleted has both left and right child
            // find inorder successor (smallest in the right subtree)
            struct Node* temp = root->right;
            while(temp && temp->left != NULL){
                temp = temp->left;
            }
            // copy the inorder successor's content to this node
            root->data = temp->data;
            // delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }

    }

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


    // Search functionality can be tested here
    int count=0;
    int key=40;
    struct Node* result = search(root, key, count);
    if(result != nullptr){
        cout << "Element " << key << " found in the BST." << endl;
    }
    else{
        cout << "Element " << key << " not found in the BST." << endl;
    }
    cout<<"Number of comparisons made: "<<count<<endl;


    // Deletion functionality can be tested here
    int deleteKey = 20;
    root = deleteNode(root, deleteKey);
    cout << "Inorder traversal after deleting " << deleteKey << ": ";
    inorder(root);
    cout << endl;






    return 0;
}