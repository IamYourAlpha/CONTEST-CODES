using namespace std;
#include<bits/stdc++.h>

struct graph {
    int x,y,wt;
} edge[200000];

int n,m;
//typedef pair<int,int> pii;

int rnk[200000];
int p[200000];


bool comp(graph a,graph b) {
    if(a.wt<b.wt) return true;
     return false;
}

int fnd(int node) {
    if(p[node] == node) return node;
    else return p[node] = fnd(p[node]);
}

void link(int node2,int node1) {
    if(rnk[node1]>rnk[node2])
        p[node2] = node1;
    else {
        p[node1] = node2;
        if(rnk[node1] == rnk[node2])
        rnk[node2]++;
    }
}

int KrusKal() {
    int ans = 0;
    int taken = 0;
    sort(edge,edge+m,comp);
    for(int i=0; i<n ; i++) {
        int p = fnd(edge[i].x);
        int q = fnd(edge[i].y);
        if(p==q) continue;
        else  {
            ans+= edge[i].wt;
            taken++;
            if(taken==m-1) break;
            link(edge[i].x,edge[i].y);
        }
    }
     return ans;
}

int main() {
      freopen("input.txt","r",stdin);
    while(scanf("%d%d",&n,&m)==2 && (n+m)!=0) {
        for(int i=0; i<200000; i++) {
            rnk[i] = 0;
            p[i] = i;
        }
        int tot = 0;
        for(int i=0; i<m; i++) {
            cin >> edge[i].x >> edge[i].y >> edge[i].wt;
            tot+=edge[i].wt;
        }
        int anss = KrusKal();
        // cout << ans << endl;
        // cout << tot << endl;
        cout << tot - anss << endl;
     //   for(int i=0;i<m;i++) cout << edge[i].wt << endl;
    }
    return 0;
}
