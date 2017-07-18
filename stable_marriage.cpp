using namespace std;
#include<bits/stdc++.h>

/*input macros */

#define SNUM(N)  scanf("%d",&N);
#define SCHAR(N) scanf("%c",&N);
#define MAX 10000

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
typedef vector <int> VI;
typedef vector < vector <int> > VVI;

int IN;
int Couple;
//int MT[ 2*MAX ][ MAX ];
int M[ MAX ];
int Asyn[ 2*MAX ];

int MT[2*4][4] = { {7, 5, 6, 4},
    {5, 4, 6, 7},
    {4, 5, 6, 7},
    {4, 5, 6, 7},
    {0, 1, 2, 3},
    {0, 1, 2, 3},
    {0, 1, 2, 3},
    {0, 1, 2, 3},
};


bool Strong(int m,int m1) {
    for(int i=0; i<4; i++) {
        if(M[i]==m) return true;
        if(M[i]==m1) return false;
    }
}




void Solve() {
    Couple = IN;

    while(Couple>0) {
        int m ;

        for(m=0; m<4; m++) if(M[m] == false) break;

        for(int k=0; k<4 && M[m]==false; k++) {
            int W = MT[m][k];
            if(Asyn[abs(W-4) ]==-1) {
                Asyn[abs(W-4)] = m;
                M[m] = true;
                Couple--;
            } else {
                int m1 = Asyn[abs(W-4)];
                if(Strong(m,m1)==false) {
                    Asyn[abs(W-4)] = m;
                    M[m1] = false;
                    M[m] = true;
                }
            }
        }
    }

    for(int i=0 ; i<4 ; i++)  printf("%d \t  %d\n",Asyn[i] , i+4);

    return ;
}




int main() {


    memset(M,false,sizeof(M));
    memset(Asyn,-1,sizeof(Asyn));
    Solve();
    return 0;
}
