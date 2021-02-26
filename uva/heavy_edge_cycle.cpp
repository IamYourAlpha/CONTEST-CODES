using namespace std;
#include<bits/stdc++.h>
typedef long long ll;

struct S {
    ll u;
    ll v;
    ll val;
} edges[25000+100];

ll n,m;
ll rank_[1600];
ll marked[1600];
ll parent[1600];
bool comp(S x, S y) {
    if(x.val < y.val) return true;
    else return false;

}

void init() {
    for(int i=0; i<1500; i++) {
        rank_[i]=0;
        parent[i] = i;
    }
}

int find_(int node) {
    if(parent[node]==node) return node;
    else return parent[node] =  find_(parent[node]);
}


bool union_(int node1,int node2) {
    if(find_(node1)==find_(node2)) return false;
    else parent[find_(node1)] = find_(node2);
    return true;
}

int main() {
    freopen("input.txt","r",stdin);
    while(scanf("%lld %lld",&n,&m)==2) {
        if(n+m==0) return 0;
        init();
        for(ll i=0; i<m; i++) {
            ll uu;
            ll vv;
            ll vaal;
            scanf("%lld %lld %lld",&uu,&vv,&vaal);
            edges[i].u = uu;
            edges[i].v = vv;
            edges[i].val = vaal;
        }
        sort(edges,edges+m,comp);
       // for(int i=0;i<m;i++) cout << edges[i].val << "  ";
        // cout  << endl;
        memset(marked,false,sizeof(marked));
        for(ll i=0; i<m; i++) {
            if(union_(edges[i].u,edges[i].v)) {
                marked[ i ] = true;
        //       cout <<" running" <<  edges[i].val << endl;
            }
        }
        vector < ll > ans;
        for(ll i=0; i<m; i++) if(!marked[i]) ans.push_back(edges[i].val);
        if(ans.size()>0) {
            cout << ans[0];
            for(int i=1; i<ans.size(); i++) printf(" %lld",ans[i]);
            cout << endl;
        } else printf("forest\n");
        ans.clear();
    }

    return 0;
}
