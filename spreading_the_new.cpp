using namespace std;
#include<stdio.h>
#include<queue>
#include<string.h>
#include<string>
#include<iostream>
#include<vector>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000
#define LL long long

#define For(i, a, b) for( int i = (a); i < (b); i++ )
#define Fors(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fore(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Read(r) freopen(r, "r", stdin)
#define Write(w) freopen(w, "w", stdout)

int temp,demo,demo1;

vector<int>G[3000];
int p[3000];


void bfs(int node) {
       queue<int>q;
       p[node]=0;
       q.push(node);
       while(!q.empty()) {
              int demo_ = q.front();
              q.pop();
              Fors(i,G[demo_]) {
                     if(p[ G[ demo_ ][ i] ]==-1) {
                            p[ G[ demo_ ][ i ] ]=p[demo_]+1;
                            q.push(G[ demo_ ][ i ]);
                     }
              }
       }
}

void print_ans(int s) {
       int f[3000];
       int max_index;
       int max_=-1;
       memset(f,0,sizeof(f));
       for(int i=0; i<3000; i++) if(p[i]!=-1) {
                     f[p[i]]++;
              }
       for(int i=1; i<3000; i++) {
              if(f[ i ]>max_) {
                     max_=f[i];
                     max_index=i;
              }
       }
       if(G[s].size()==0) printf("0\n");
else printf("%d %d\n",f[max_index],max_index);
}



int main() {
       int tc;
       scanf("%d",&temp);
       for(int i=0; i<temp; i++) {
              scanf("%d",&demo);
              for(int j=0; j<demo; j++) {
                     scanf("%d",&demo1);
                     G[i].push_back(demo1);
              }
       }
       scanf("%d",&tc);
       int start;
       for(int i=0; i<tc; i++) {
              scanf("%d",&start);
              memset(p,-1,sizeof(p));
              bfs(start);
              print_ans(start);
       }
       return 0;
}


