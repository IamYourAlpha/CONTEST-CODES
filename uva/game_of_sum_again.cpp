#include<bits/stdc++.h>
using namespace std;

int memo[1000][1000];
int input[1000];
int presum[1000];
int n;
void reset() {
    memset(memo,numeric_limits<int>::min(),sizeof(memo));
    // memset(arr,0,sizeof(arr));
    memset(presum,0,sizeof(presum));
    memset(input,0,sizeof(input));

}

int getSum(int s_,int f_) {
//cout << (presum[f_] - presum[s_]) + presum[s_]  <<endl;
    return (presum[f_] - presum[s_]) + input[s_] ;

}


int dp(int f,int b) {

    if(f>b) return 0;
    else if(memo[f][b]!=numeric_limits<int>::min()) return memo[f][b];
    else {
        int ans = numeric_limits<int>::min();
        for(int pos = f; pos<=b; pos++) {
            ans = max(ans,getSum(f,pos) - dp(pos+1,b) ) ;
        }
        for(int pos = b; pos>=f; pos--) {
            ans = max(ans,getSum(pos,b) - dp(f,pos-1) );
        }
        return (memo[f][b] = ans);
    }
}


int main() {
    freopen("in.txt","r",stdin);


    while(scanf("%d",&n)==1) {
        if(n==0) break;
        reset();
        int demo;
        cin >>demo;
        input[0] = demo;
        presum[0] = demo;
        for(int i=1; i<n; i++) {
            scanf("%d",&input[i]);
            presum[i] = presum[i-1] + input[i];
        }
       // for(int i=0; i<n; i++)  cout <<  " elements  of positon " << i << "  : " << presum[i] << endl;
        cout << dp(0,n-1) << endl;
        //cout << anss << endl;


    }
    return 0;
}
