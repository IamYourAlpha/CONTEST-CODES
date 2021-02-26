#include<bits/stdc++.h>
using namespace std;

int coin[10000];
int n;

int main() {
//freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i=0; i<n; i++) cin >> coin[i];
        sort(coin,coin+n);
        int sum = coin[0];
        if(n<=2) cout << n << endl;
        else {
            int ans = 2;
            for(int i=1; i<n-1; i++) {
                if(sum<coin[i] && (sum+coin[i])<coin[i+1]) {
                    sum+=coin[i];
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
