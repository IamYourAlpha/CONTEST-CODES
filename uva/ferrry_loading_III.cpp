#include<bits/stdc++.h>
using namespace std;


queue<int>q[2];
int Arrived[100000];
int deparpted[100000];


int main() {
    freopen("input.txt","r",stdin);
    int tc;
    cin >> tc;

    while(tc--) {
     memset(deparpted,0,sizeof(deparpted));
     // memset(deparpted,0,sizeof(Arrived));
        int t,m,n;
        cin >> n >> t >> m;
        for(int i=0; i<m; i++) {
            int time;
            string str;
            cin >> time >> str;
            if(str=="left") {
                q[0].push(i);
                Arrived[i] = time;
            } else {
                q[1].push(i);
                Arrived[i] = time;
            }
        }
        int NowAt = 0;
        int NowTime = 0;
        while(!q[0].empty()  || !q[1].empty()) {
            int next = q[0].empty() ? Arrived[q[1].front()] :
                       q[1].empty() ? Arrived[q[0].front()] :
                       min(Arrived[q[0].front()],Arrived[q[1].front()]);
             NowTime = max(NowTime,next);
            int cnt = 0;
            while(cnt<n && !q[NowAt].empty() && Arrived[q[NowAt].front()]<=NowTime) {
                deparpted[q[NowAt].front()] = NowTime + t;
                q[NowAt].pop();
                cnt++;
            }
            NowAt = !NowAt;
            NowTime = NowTime + t;
        }
        for(int i=0; i<m; i++) cout << deparpted[i] << endl;
        if(tc) cout << endl;
    }
    return 0;
}



