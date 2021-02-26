#include<bits/stdc++.h>
using namespace std;

vector<int> topo;
vector<vector<int> > grid(100);
vector<int>visited;

int costs[1000];

void dfs(int node) {
    if(visited[node]) return ;
    for(int i=0; i<grid[node].size(); i++) {
        if(!visited[grid[node][i]]) {
            visited[grid[node][i]] = true;
            dfs(visited[grid[node][i]]);
        }
    }
    topo.push_back(node);
}

int main() {
    int tc;
    scanf("%d",&tc);
    getchar();
    getchar();
    while(tc--) {
        char input[100];
        char before[1000];
        char task;
        int  tot;
        while( gets(input) && strlen(input)) {
            sscanf(input,"%c %d %s",&task,&tot,before);
            costs[task-'A'] = tot;
            for(int i=0; i<strlen(before); i++) {
                int temp = before[i]-'A';
                grid[task-'A'].push_back(temp);
                cout << task << tot << before;
            }

        }

    }
    return 0;
}



