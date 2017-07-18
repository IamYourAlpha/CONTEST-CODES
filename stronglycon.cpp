using namespace std;
#include<iostream>
#include<stdio.h>
#include<string.h>
int n,m;
bool visited[100][100];
bool graph[100][100][4];

bool valid(int x,int y) {
  if(x>=0 && y>=0  && x<n && y<m) return true;
  return false;
}

void dfs(int x,int y) {
  if(!valid(x,y)) return;
  if(visited[x][y]) return;
  visited[x][y]=true;
  if(graph[x][y][0]) dfs(x,y+1);
  if(graph[x][y][1]) dfs(x,y-1);
  if(graph[x][y][2]) dfs(x+1,y);
  if(graph[x][y][3]) dfs(x-1,y);
}

int main() {
  string h;
  string v;
  cin>>n>>m;
  cin>>h>>v;
  memset(graph,false,sizeof(graph));
  memset(visited,false,sizeof(visited));
  for(int j=0; j<n; j++) {
    if(h[j]=='>')
      for(int i=0; i<m; i++) {
        if(valid(i,i+1)) graph[i][i+1][0]=true;
      }
    if(h[j]=='<') {
      for(int i=m-1; i>=0; i--)
        if(valid(i,i-1)) graph[i][i-1][1]=true;
    }
  }
  for(int j=0; j<m; j++) {
    if(v[j]=='^') {
      for(int i=n-1; i>=0; i--)
        if(valid(i+1,i)) graph[i+1][i][2]=true;
    }
    if(v[j]=='v') {
      for(int i=0; i<m; i++)
        if(valid(i-1,i)) graph[i-1][i][3]=true;
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(!visited[i][j])
        dfs(i,j);
    }
  }
  int ans=0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(visited[i][j])
        ans++;
    }
  }
  cout<<ans<<endl;
  if(ans==n*m) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
