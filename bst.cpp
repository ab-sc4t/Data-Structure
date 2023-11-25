#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * left;
        Node * right;
        Node(int d){
            data = d;
            left = right = NULL; 
        }
};

Node * insert(Node * root, int d){
    if (root==NULL){
        Node * temp = new Node(d);
        return temp;
    }
    if (d>root->data){
        root->right = insert(root->right, d);
    }
    else{
        root->left = insert(root->left,d);
    }
    return root;
}

void insertValues(Node * &root){
    int data;
    cout << "Enter data: ";
    cin >> data;
    while(data!=-1){
        root = insert(root, data);
        cin >> data;
    }
}

int mini(Node * root){
    Node * temp = root;
    while(temp!=NULL){
        temp = temp->left;
    }
    int min = temp->data;
    return min;
}

class Node * deleteFromBst(Node * root, int val){
    if (root==NULL){
        return root;
    }
    if (root->data == val){
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL){
            Node * temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL){
            Node * temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right != NULL){
            int min = mini(root->right);
            root->data = min;
            root->right = deleteFromBst(root->right, min);
            return root;
        }
    }
    else if (root->data>val){
        root->left = deleteFromBst(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBst(root->right, val);
        return root;
    }
    return root;
}

void preOrder(Node * root){
    if (root!= NULL){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    Node * root = NULL;
    insertValues(root);
    cout << "Pre Order: ";
    preOrder(root);
    return 0;
}