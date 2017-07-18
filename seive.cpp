//
//       Filename:  c3.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  07/23/2015 08:01:33 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Tony (),
//   Organization:
//
// =====================================================================================












using namespace std;
#include<cstring>
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
//#define sintll(a)   scanf("%lld",&a)
//#define pintll(a)   printf("%lld",a)
//#define sint2(a,b)  scanf("%d%d",&a,&b)


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

/****************** templates***********************/

typedef struct {
    int step;
    int Pnumbers;
} node;

queue<node>q;
node cur,nw;
bool visited[50000];
bool prime[1000000];
int d,s;

int getNextPrime(int start) {
    for(int i=start+1; i<10000; i++)
        if(prime[i] && !visited[i]) return i;
}
bool ok(int a,int b) {
    int ans = 0;
    int m=0;
    int n=0;
    int r1[100];
    int r2[100];
    while(a>0) {
         r1[m++] = a%10;
         r2[n++] = b%10;
        a/=10;
        b/=10;
    }
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++) if(r1[i]!=r2[j]) ans++;
        if(ans>1) return false;
        else return true;
}



int bfs(int s,int d) {
    memset(visited,false,sizeof(false));
    cur.Pnumbers = s;
    cur.step = 0;
    //visited[cur.Pnumbers] = true;
    q.push(cur);
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if( cur.Pnumbers == d  ) return cur.step;
        int next = cur.Pnumbers;
        int prevPrime = next;
        for(int i=1000; i<10000; i++) {

            //  cout << " k " << endl;
            if(!visited[i] && ok(i,prevPrime)) {
                //cout << i << endl;
                nw.Pnumbers = i;
                nw.step = cur.step+1;
                q.push(nw);
                visited[i]=true;
                prevPrime = i;
            }
        }
    }
    return 0;
}




void seive() {
    mem(prime,true);
    prime[0]=prime[1]=false;
    prime[2]=true;
    for(int i=4; i<10000; i+=2) prime[i]=false;
    for(int i=3; i*i<10000; i++) {
        if(prime[i])
            for(int j=i+i; j<10000; j+=i)
                prime[j]=false;

    }
//repo(i,10)  if(!prime[i]) cout<<i<<endl;
}




int main() {
    seive();
    freopen("input.txt","r",stdin);

    int tc;
    cin >> tc;
    while(tc--) {
        cin >> s >> d;
        int ans = bfs(s,d);
        cout << ans << endl;

    }
    return 0;
}

