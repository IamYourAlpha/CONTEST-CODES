using namespace std;
# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>


typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vector< vector<char> > > vvi;


//int positionx = {-1,+1,0,0,0,0};
//int positiony = {0,0,-1,+1,0,0};
//int positionz = {0,0,0,0,1,-1};
struct node {
    int key;
    struct node *left,*right;
};

struct node *NewNode(int element) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->key = element;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* pierce(struct node* node,int key) {
    if(node == NULL) return NewNode(key);
    if(key < node->key) node->left = pierce(node->left,key);
    else  node->right = pierce(node->right,key);
    return node;
}

int main() {
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    struct node *root = NULL;
    root = pierce(root,50);
    root = pierce(root, 50);
    pierce(root, 30);
    pierce(root, 20);
    pierce(root, 40);
    pierce(root, 70);
    pierce(root, 60);
    pierce(root, 80);
   // inorder(root);
    return 0;
}
