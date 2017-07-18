using namespace std;
#include<bits/stdc++.h>

int n,tq;
struct ML {
    string P;
    int L,A,B,Pr;
} node[100];

bool done[10000];

bool comp(ML a,ML b) {
    return  a.A < b.A;
}

void adjust_burst_time(int now,int before) {
    node[before].B = node[before].B - abs(node[now].A - sum);
    if(node[before].B<=0) done[before] = true;
    if(
}

void solve() {
    bool F = true;
    int Prev = -1;
    int sum = 0;
    for(int i=0; i<n; i=(i+1)%n {

     if(F) {
            cout << sum << " " << node[i].P << " ";
            F = ~F;
            Prev = i;
            continue;
        }
    if(Prev != -1 && node[i].Pr < node[Prev].Pr && node[i].L == 1){
    adjust_burst_time(i,prev);
    sum += node[i].A;
    int now = i;
    next = (now+1)%n;
       while(node[now].Pr < node[next].Pr && node[next].L ==1){
          cout << sum << " " << node[now].P << " ";
          adjust_burst_time(next,next-1);
              next = (next + 1)%n;
          }
    }
}

int main() {
    freopen("in.txt","r",stdin);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> node[i].P;
        cin >> node[i].B;
        cin >> node[i].L;
        cin >> node[i].A;
        cin >> node[i].Pr;
    }
    sort(node,node+n,comp);
    solve();
//   for(int i=0; i<n; i++) cout << node[i].P << endl;
    return 0;
}
