#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector <pii> vpi;

int indx,n;
vpi input;
int graph[100][100],wt[100];

void dfs(int f) {
    for(int s=1; s<=indx; s++) {
        if(graph[f][s]) {
            graph[f][s]--;
            graph[s][f]--;
            dfs(s);
            input.push_back(make_pair(f,s));
            //cout << f << " " << s << endl;
        }
    }
    // cout << " " << endl << endl;
    return;
}

int main() {
    freopen("input.txt","r",stdin);
    int tc;
    int kase = 0;
    cin >> tc;


    while(tc--) {
        bool NotEuler = false;
        memset(graph,0,sizeof(graph));
        memset(wt,0,sizeof(wt));
        input.clear();
        //  input.assign(0,1000);
        indx = -11;
        cin >> n;
        for(int i=0; i<n; i++) {
            int u,v;
            cin >> u >> v;
            graph[u][v]++;
            graph[v][u]++;
            wt[u]++;
            wt[v]++;
            indx = max(indx,max(u,v));
        }
        for(int i=1; i<=indx; i++) {
            if(wt[i]&1) {
                NotEuler = true;
                break;
            }
        }
        //  cout << indx << endl;
        cout << "Case #" << ++kase << endl;
        if(!NotEuler) {
            dfs(indx);
            // cout <<  " intel inside" << endl;
            if(input.size()!=n || ( input[0].second != input[input.size()-1].first) ) {
                cout << "some beads may be lost" << endl;
            } else {
                for(int ii = input.size()-1; ii >=0; ii--)
                    cout << input[ii].first << " " << input[ii].second << endl;
            }
        } else cout << "some beads may be lost" << endl;
        if(tc) cout << endl;




    }
    return 0;
}
