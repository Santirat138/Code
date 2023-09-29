#include <bits/stdc++.h>
using namespace std;

class BST {
    int data;
    BST *left, *right;

public:
    BST();
    BST(int);
    BST* Insert(BST*, int);

    BST* Search(BST*, int);

    BST* Delete(BST*, int);
    void Inorder(BST*);
};
BST::BST()
        : data(0)
        , left(NULL)
        , right(NULL)
{
}
BST::BST(int value)
{
    data = value;
    left = right = NULL;
}
BST* BST::Insert(BST* root, int value)
{
    if (!root) { // if (root == NULL)
        return new BST(value);
    }
    if (value > root->data) {
        root->right = Insert(root->right, value);
    }
    else if (value < root->data) {
        root->left = Insert(root->left, value);
    }
    return root;
}

BST* BST::Search(BST* root, int value){
    if (!root){ // return NULL means NOT FOUND
        return root;
    }

    if (value == root->data){
        return root;
    }
    else if (value > root->data) {
        return Search(root->right, value);
    }
    else if (value < root->data) {
        return Search(root->left, value);
    }
}
void BST::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}


BST* BST::Delete(BST* root, int k)
{
    if (root == NULL)
        return root;
    if (k < root->data) {
        root->left = Delete(root->left, k);
        return root;
    }
    else if (k > root->data) {
        root->right = Delete(root->right, k);
        return root;
    }
    if (root->left == NULL) {
        BST* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        BST* temp = root->left;
        delete root;
        return temp;
    }
    else {

        BST* succParent = root;
        BST* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->data = succ->data;
        delete succ;
        return root;
    }
}

int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    b.Inorder(root); // Show from min to max
    cout << endl;

    b.Delete(root, 40);
    b.Inorder(root);
    cout << endl;

    b.Delete(root, 80);
    b.Inorder(root);
    cout << endl;

    b.Delete(root, 90);
    b.Inorder(root);
    cout << endl;
    return 0;
}