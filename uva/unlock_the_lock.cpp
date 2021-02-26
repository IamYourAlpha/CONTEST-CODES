#include<bits/stdc++.h>
using namespace std;

typedef struct {
      int val;
      int step;
} node;

node current,now;

int u,l,b;
int visited[100000];
int but[100000];


int bfs() {
      memset(visited,0,sizeof(visited));
      queue<node>q;
      current.val = u;
      current.step = 0;
      q.push(current);
      visited[current.val]=1;
      while(!q.empty()) {
            current =  q.front();
            q.pop();
            if(current.val==l) return current.step;
            for(int i=0; i<b; i++) {
                  int demo = current.val + but[i];
                  if(demo>=10000)
                        demo -=10000;
                  if(!visited[demo]) {
                        now.val = demo;
                        now.step = current.step + 1;
                        q.push(now);
                        visited[demo]=1;
                  }
            }
      }
       while(!q.empty()) q.pop();
      return -1;
}





int main() {
   //freopen("input.txt","r",stdin);
      int k=0;

      while(scanf("%d %d %d",&u,&l,&b)!=EOF) {
            if(u+l+b==0) return 0;
            for(int i=0; i<b; i++) {
                  scanf("%d",&but[i]);
            }
            int ans = bfs();
            if(ans==-1) printf("Case %d: Permanently Locked\n",++k);
            else printf("Case %d: %d\n",++k,ans);

      }
      return 0;
}

