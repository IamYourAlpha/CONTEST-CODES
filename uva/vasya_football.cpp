
//headers
using namespace std;
#include<cstring>
#include<limits>
#include<limits.h>
#include<vector>
#include<map>
#include<iostream>
#include<math.h>
#include<queue>
#include<cstdlib>
#include<ctype.h>
#include<string>
#include<cstdio>
#include<algorithm>

/**********INPUT******/
#define sint(a)     scanf("%d",&a)
#define pint(a)     printf("%d",a)

#define MAX(a,b) (a > b) ? (a) : (b)
#define MIN(a,b) (a < b) ? (a) : (b)
#define MIN3(a,b,c) (a < b) ? (a < c ? a : c) : (b < c ? b : c)
#define MAX3(a,b,c) (a > b) ? (a > c ? a : c) : (b > c ? b : c)
#define mem(x,y) memset(x,y,sizeof(x));
#define pb push_back
#define pf pop_front()
#define N 1000000+7


/* loops****/
#define rep(a,n) for(int a=1;a<=n;a++)
#define repo(a,n) for(int a=0;a<n;a++)

#define PINF 2147483647
#define NINF -2147483647
#define Pi acos(-1.0)


struct team {
    char name[22];
    int minute;
    char ident;
    int Player;
    int yellow[1000];
} A[2];

bool printed[2][1000];

int main() {
    int n;
    int a;
    int p;
    char b, c;

    for(int i=0; i<2; i++) cin>>A[i].name;
    /*MC
    CSKA
    9
    28 a 3 y
    62 h 25 y
    66 h 42 y
    70 h 25 y
    77 a 4 y
    79 a 25 y
    82 h 42 r
    89 h 16 y
    90 a 13 r
    */
    scanf("%d",&n);

    memset(A[0].yellow,0,sizeof(A[0].yellow));
    memset(A[1].yellow,0,sizeof(A[1].yellow));
    memset(printed,false,sizeof(printed));

    for(int i=0; i<n; i++) {
        cin>>a>>b>>p>>c;

        if(b=='a') {
            A[1].minute=a;
            if(c=='y') {
                ++A[1].yellow[p];
                //cout<<A[1].yellow[p]<<endl;
                if(A[1].yellow[p]==2 && !printed[1][p]) {
                    cout<<A[1].name<<" "<<p<<" "<<A[1].minute<<endl;
                    printed[1][p]=true;
                }
            }

            else if(c=='r' && !printed[1][p]) {
                cout<<A[1].name<<" "<<p<<" "<<A[1].minute<<endl;
                printed[1][p]=true;
            }
        }

        else {
            A[0].minute=a;
            if(c=='y') {
                ++A[0].yellow[p];
                // cout<<A[0].yellow[p]<<endl;
                if(A[0].yellow[p]==2 && !printed[0][p]) {
                    cout<<A[0].name<<" "<<p<<" "<<A[0].minute<<endl;
                    printed[0][p]=true;
                }
            } else if(c=='r' && !printed[0][p])  {
                cout<<A[0].name<<" "<<p<<" "<<A[0].minute<<endl;
                printed[0][p]=true;
            }
        }
    }
    return 0;
}

