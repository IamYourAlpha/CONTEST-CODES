#include<bits/stdc++.h>
using namespace std;

int e[1000];
int c[1000];
int dp[1000][1000];


int main() {
   freopen("in.txt","r",stdin);
    int tc;
    int m,s;
    cin >> tc;
    while(tc--) {
        cin >> m >> s;
        for(int i=0; i<1000; i++)
            for(int j=0; j<1000; j++) dp[i][j] = INT_MAX;

        for(int i=0; i<m; i++) cin >> e[i] >> c[i];
        dp[0][0] = 0;
        for(int k=0; k<m; k++) {
            for(int i=e[k]; i<=s; i++) {
                for(int j=c[k] ; j<=s; j++) {
                    if(dp[i-e[k]][j-c[k]]!=INT_MAX)
                    dp[i][j] = min(dp[i-e[k]][j-c[k]]+1,dp[i][j]);
                }
            }
        }
         int ans = INT_MAX;

        for(int i=0; i<=s; i++) {
            for(int j=0; j<=s; j++) {
                if(i*i + j*j == s*s && dp[i][j] != INT_MAX)
                    ans = min(ans,dp[i][j]);
            }
        }
        if(ans==INT_MAX) cout <<  "not possible" << endl;
        else
        cout << ans << endl;
    }
    return 0;

}

