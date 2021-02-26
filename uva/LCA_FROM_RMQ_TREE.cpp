// =====================================================================================
//
//       Filename:  LCA_FROM_RMQ_TREE.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  02/15/2016 12:55:44 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  INTISAR (),
//   Organization:
//
// =====================================================================================

using namespace std;
#include <bits/stdc++.h>
#define _MAX_ 500

int E [_MAX_], L [_MAX_], FS [_MAX_], ST [_MAX_],IND;

struct Node {
    int key;
    struct Node *left,*right;
};


/*  UTILITY METHOD TO CREATE A NEW NODE OF BINARY TREE WITH
 *  GIVEN KEY/VALUE/DATA   */
Node * newNode( int D ) {
    Node *temp = new node;
    temp->key = D;
    temp->left = temp->right = NULL;
    return temp;
}

/* RETURN LOGARITHM ____ BASE 2    */
int LOG2( int x ) {
    int tot = 0;
    while( !(x%2) ) {
        tot++;
        x = x/2;
    }
    return tot;
}


void Build_Tree(int i, int S, int E, int QS, int QE) {
    if( S == E ) ST [ i ] = S;
    else {
        int M = ( S + E )/2;
        Build_Tree(2*i + 1, S, M, QS, QE);
        Build_Tree(2*i + 2, M+1, E, QS, QE);
        if( L [ ST [ 2*i + 1 ] ] < L [ ST [ 2*i + 2 ] ] )
            ST [ i ] =  ST [ 2*i + 1 ];
        else
            ST [ i ] = ST [ 2*i + 2 ];
    }
}



int RMQ(int i, int S, int E, int QS, int QE) {
    /* IF [S,E] FALLS TOTALLY INSIDE THE GIVE [QS,QE]                                  */
    if( QS <= S && QE >= E )
        return ST [ i ];

    int M = ( S + E ) / 2;

    int Q1 = RMQ(2*i + 1, S,M,QS,QE);
    int Q2 = RMQ(2*i + 2, M+1,E,QS,QE);

    if( Q1 == -1 ) return Q2;
    else if( Q2 == -1) return Q1;
    return ( L [Q1] < L [Q2] ) ? Q1 : Q2;
}


void EulerTour(Node *root, int l) {
    /*   IF PASSED NODE EXISTS  */
    if( root ) {
        E [ IND ] = root->key; /*  INSERT IN ARRAY */
        L [ IND ] = l;
        IND++;
        /*  CHECK AND FILL THE FIRST SEEN ARRAY FS []   */
        if( FS [ root->key ] == -1 )
            FS [ root->key ] =( IND - 1 ) ;
        if( root->left ) {
            EulerTour( root->left, l + 1  );
            E [ IND ] = root->key;
            L [ IND ] = l;
            IND++;
        }
        if( root->right ) {
            EulerTour( root->right, l + 1 );
            E [ IND ] = root->key;
            L [ IND ] = l;
            IND++;
        }
    }
}

int LCA(Node *root, int u, int v) {
    memset(FS,-1,sizeof(FS));
    IND = 0;
    EulerTour(root,0);
    Build_Tree(0, 0, n-1);
    if( FS [ u ] >  FS [ v ] )  swap(u,v);
    int ANS = RMQ(0, 0, n-1, FS [ u ], FS [ v ] );
    return  E [ ANS ];
}

int main(){
return 0;
  }







