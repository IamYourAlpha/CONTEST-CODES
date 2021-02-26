using namespace std;
#include<bits/stdc++.h>
#define MX 600
int n;
int ans;
int parent [MX];
int visited [MX];
vector <int> graph [MX];

void dfs(int s,int e,int level) {
    visited [ s ] = true;
    parent [ level ] = s;
    if( s == e ) {
        ans = level;
        return;
    }
    for(int i=0; i<graph [ s ].size(); i++) {
        int node = graph [ s ][ i ];
        if(!visited [ node ])
            dfs(node,e,level+1);
        if(ans != -1) return;
    }
}

int main() {
   // freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF && n!=0) {
        for(int i =0; i<n-1; i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            graph [ u ].push_back(v);
            graph [ v ].push_back(u);
        }
        int q;
        scanf("%d",&q);
        for(int i=0; i<q; i++) {
            memset(visited,false,sizeof(visited));
            memset(parent,0,sizeof(parent));
            int s,e;
            cin >> s >> e;
            ans = -1;
            dfs(s,e,0);
            if(ans%2==0) printf("The fleas meet at %d.\n",parent [ ans/2 ]);
            else {
                int a = parent [ ans/2 ];
                int b = parent [ ans/2 + 1 ];
                if(a<=b) printf("The fleas jump forever between %d and %d.\n",a,b);
                else  printf("The fleas jump forever between %d and %d.\n",b,a);
            }
        }
       for(int i=0; i<600; i++) graph[i].clear();
    }
    return 0;
}
