#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};


struct node* NewNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right= NULL;
}

int HeightTree(struct node* node) {
    if(node==NULL) return 0;
    else {
        return max( HeightTree(node->left) , HeightTree(node->right) ) + 1;
    }
}

int main() {

    struct node *root   =      NewNode(1);
    root->left          =      NewNode(2);
    root->right         =      NewNode(3);
    root->left->left    =      NewNode(4);
    root->left-> right  =      NewNode(5);
    root->right->left   =      NewNode(6);
    root->right->right  =      NewNode(7);

    root->left->left->left  = NewNode(8);
    root->left->left->right = NewNode(9);
    root->left->right->left = NewNode(10);

    printf("height of the tree is %d",HeightTree(root));
    return 0;
}
