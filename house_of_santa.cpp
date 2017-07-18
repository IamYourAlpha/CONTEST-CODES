#include<bits/stdc++.h>
using namespace std;

int G[10][10];
bool visited[10][10];
int nodes[10];
int taken;
void back_track() {
//cout << taken << endl;
    if(taken==8) {
        for(int i=0 ; i<9 ; i++) {
            cout << nodes[i] ;
        }
        cout << endl;
    }
    //cout << "here" << endl;
    for(int i=1 ; i<=5 ; i++) {
        if(!visited[nodes[taken]][i] && G[nodes[taken]][i]==1) {
            visited[i][nodes[taken]] = true;
            visited[nodes[taken]][i] = true;
            nodes[++taken] = i ;
            //cout << "i: " << i << endl;
            back_track();
            taken--;
            visited[i][nodes[taken]] = false;
            visited[nodes[taken]][i] = false;
        }
    }
}



int main() {

    for(int i =0; i<=5; i++)
        for(int j=0; j<=5; j++){ G[i][j] = 0; visited[i][j] = false;}
    G[ 1 ][ 2 ] = 1;
    G[ 2 ][ 1 ] = 1;
    G[ 1 ][ 5 ] = 1;
    G[ 5 ][ 1 ] = 1;
    G[ 2 ][ 5 ] = 1;
    G[ 5 ][ 2 ] = 1;
    G[ 3 ][ 1 ] = 1;
    G[ 1 ][ 3 ] = 1;
    G[ 3 ][ 2 ] = 1;
    G[ 2 ][ 3 ] = 1;
    G[ 4 ][ 3 ] = 1;
    G[ 5 ][ 3 ] = 1;
    G[ 5 ][ 4 ] = 1;
    G[ 3 ][ 4 ] = 1;
    G[ 3 ][ 5 ] = 1;
    G[ 4 ][ 5 ] = 1;
    taken = 0 ;
    nodes[0] = 1;
    back_track();

    return 0;
}


