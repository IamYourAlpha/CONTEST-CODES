#include<bits/stdc++.h>
using namespace std;

int memo[1000][1000];
int arr[1000];
int presum[1000];

void reset() {
    memset(memo,-999,sizeof(memo));
   // memset(arr,0,sizeof(arr));
    memset(presum,0,sizeof(presum));

}

int getSum(int s_,int f_) {
//cout << (presum[f_] - presum[s_]) + presum[s_]  <<endl;
    return (presum[f_] - presum[s_]) + arr[s_] ;


}


int dp(int f,int b) {

    if(f>b) return 0;
    else if(memo[f][b]!=-999) return memo[f][b];
    else {
    int ans = -999;
        for(int pos = f; pos<=b; pos++)
            ans = max(ans,getSum(f,pos) - dp(pos+1,b) ) ;
        for(int pos = b; pos>=f; pos--)
            ans = max(ans,getSum(pos,b) - dp(f,pos-1) ) ;
        return (memo[f][b] = ans);

    }
}


int main() {
    freopen("in.txt","r",stdin);


    int n;
    while(scanf("%d",&n) && n) {
        reset();
        scanf("%d",&arr[0]);
        presum[0] = arr[0];
        for(int i=1; i<n; i++) {
            scanf("%d",&arr[i]);
            presum[i] = presum[i-1] + arr[i];
        }
        int anss = dp(0,n-1);
	   cout << anss << endl;


    }
    return 0;
}
