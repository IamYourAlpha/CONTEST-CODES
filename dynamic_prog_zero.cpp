using namespace std;
#include<bits/stdc++.h>
int n;
int memo[1000];

int dp(int number) {

    int ans;
    if(number == 1) return 1;
    if(memo[number]!=-1) return memo[number];

     ans = 1 + dp(number-1);
     if(number%2==0)  ans =  min(ans,1+dp(number/2));
     if(number%5==0)  ans =  min(ans,1+dp(number/5));
    memo[number] = ans;
        return ans;
}


int main() {
    scanf("%d",&n);
    memset(memo,-1,sizeof(memo));
    memo[0] = 0;
    int ans = dp(n);
    printf("%d",ans);
    return 0;
}
