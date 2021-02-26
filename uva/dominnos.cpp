#include<bits/stdc++.h>
using  namespace std;

//typedef vector<vector<int>> vii;

int n,k;

void DFS(int node,const vector< vector<int> > &domino,vector<int> &visited,vector<int> &TopSort) {
    visited[node] =  true;

    for(int i=0; i<domino[node].size(); i++) {
        int temp = domino[node][i];
        if(!visited[temp]) DFS(temp,domino,visited,TopSort);
    }
    TopSort.push_back(node);
}

int main() {
  // freopen("input.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d%d",&n,&k);
        vector < vector<int> > domino(n+1);
        vector< int > visited(n+1,false);
        vector<int> TopSort;
        for(int i=0; i<k; i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            domino[u].push_back(v);
        }
        for(int i=1; i<=n; ++i) {
            if(!visited[i])
                DFS(i,domino,visited,TopSort);
        }
        reverse(TopSort.begin(),TopSort.end());
        int ans = 0;
        visited.assign(n+1,false);
        /*debug*/
        //  for(int i=0;i<TopSort.size();i++) cout << "node : " << TopSort[i] << endl;

        for(int i=0; i<n; i++) {
            int demo = TopSort[i];
            if(!visited[demo]) {
                DFS(demo,domino,visited,TopSort);
                ++ans;
            }
        }
        cout << ans << endl;
        TopSort.clear();
    }
    return 0;
}



