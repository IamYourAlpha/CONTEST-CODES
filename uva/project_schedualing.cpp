#include<bits/stdc++.h>
using namespace std;
char demo;
char buf[1000];
char tasks[1000];
int cost[1000],num;
int memo[1000];
vector < vector<int> > graph(1000);

void reset() {
    for(int i=0; i<100; i++) {
        graph[i].clear();
        cost[i] = -1;
        memo[i] = -1;
    }
}

int dp(int node) {
    int f=0;
    if(memo[node]!=-1) return memo[node];
    for(int i=0; i<graph[node].size(); i++) {
        int pie = graph[node][i];
        f = max(f,cost[pie] + dp(pie));
    }
    return (memo[node] = f);
}

int main() {
  //  freopen("input.txt","r",stdin);
    int tc;
    int ans;
    cin >> tc;
    getchar();
    getchar();
    while(tc--) {`
        reset();
        while(gets(buf) && strlen(buf)) {
            tasks[0] = '\0';
            sscanf(buf,"%c %d %s", &demo, &num, tasks);
            int node = demo - 'A';
            cost[node] = num;
            // cout << node << endl;
            for(int j=0; j<strlen(tasks); j++) {
                int node1 = tasks[j] - 'A';
                graph[node1].push_back(node);
            }
        }
        ans = INT_MIN;
        for(int i=0; i<26; i++)
            if(cost[i]!=-1)
                ans = max(ans,cost[i] + dp(i));
        cout << ans << endl;
       if(tc)  cout << endl;
        //     cout <<"out put count :  " <<   ++k << " "  << endl;
    }
    return 0;
}
