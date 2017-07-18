// =====================================================================================
//
//       Filename:  BPM.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  02/15/2016 09:02:10 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  INTISAR (),
//   Organization:
//
// =====================================================================================


using namespace std;
#include<bits/stdc++.h>

#define _MAX_ 500

int A,J;
vector<int> Grid[_MAX_];
int Job[_MAX_];
bool seen[_MAX_];

bool  BPM(int node) {
    for(int i = 0; i <Grid[node].size(); i++) {
        int u = Grid[node][i];
        if( !seen[ u ] ) {
            seen[ u ] = true;
            if( Job[u] < 0 || BPM( Job[u] ) )
                Job[u] = node;
            return true;
        }
    }
    return false;
}


int main() {
    wihile( scanf("%d %d",&A,&J) != EOF ) {
        int n;
        for(int i = 0; i < A; i++) {
            scanf("%d",&n);
            for(int j = 0; j < n; j++) {
                int T;
                scanf("%d",&T);
                Grid[i].push_back(T);
            }
        }
        int tot = 0;
        memset( Job,-1,sizeof(Job) );
        for(int i = 0; i < A; i++) {
            memset( seen,false,sizeof(seen) );
            if( BPM(i) ) tot++;
        }
        printf("Maximum matching is :  %d ",tot);
    }
    return 0;
}

