#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;


#define N 1000000

using namespace std;

int parent [N];
int rank_ [N];
int findParent (int p) {
    if ( parent [p] == p ) return p;
    return parent [p] = findParent(parent [p]);
}

void union_(int x,int y) {
    int a;
    int b;
    a= findParent(x);
    b= findParent(y);
    if(rank_[a]>rank_[b]) {
        parent[b]=a;
    }
        else if(rank_[a]==rank_[b]) {
            rank_[b]++;
            parent[a]=b;
        }
    }

int main () {
    int testCases;
    scanf ("%d", &testCases);
    bool blank = false;

    while ( testCases-- ) {

        for ( int i = 0; i < N; i++ ){ parent [i] = i; rank_[i]=0;}

        int numberOfComputers;
        scanf ("%d", &numberOfComputers);
        getchar ();

        char command;
        int computeri, computerj;
        int successfulCnt = 0, unsuccessfulCnt = 0;

        while ( (command = getchar ()) && isalpha (command) ) {

            scanf ("%d %d", &computeri, &computerj);
            getchar ();

            int p = findParent(computeri);
            int q = findParent(computerj);

            if ( command == 'c' ) {
                union_(p,q);

            } else {
                if ( p == q ) successfulCnt++;
                else unsuccessfulCnt++;
            }
        }

        if ( blank ) printf ("\n");
        blank = true;
        printf ("%d,%d\n", successfulCnt, unsuccessfulCnt);

    }

    return 0;

}
