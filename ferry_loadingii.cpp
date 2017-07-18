#include<bits/stdc++.h>
using namespace std;

queue<int> l;
queue<int> r;
int n,m,demo;
char str[100];
int t;


int main() {
      int tc;
      scanf("%d",&tc);
      while(tc--) {
            scanf("%d %d %d",&n,&t,&m);
            for(int i=0; i<m; i++) {
                  scanf("%d",&demo);
                  cin>>str;
                  strcmp(str,"left")==0 ? l.push(demo) : r.push(demo);
            }
            while(!l.empty() || !r.empty()){




      }
      return 0;
}
