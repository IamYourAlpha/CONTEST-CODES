using namespace std;
#include<bits/stdc++.h>

#define mAx(a,b) a > b ? a : b
typedef long long int ll;



ll arr[2000];
ll n;
ll memo[2000];
ll dp(int index) {
      ll sum=0;
      ll ret=0;
      if(index==n) return  0;
      if(memo[index]!=-1) return memo[index];
      if(arr[index]==0) ret =  dp(index+1);
      else {
            int i;
            for( i=1; i<=10 && (i+index)<=n; i++) {
                  sum = sum*10 + arr[index+i-1];
                  cout << sum << endl;
                  if(sum<=INT_MAX) ret = mAx (ret,sum+dp(index+i));
            }
      }
      return memo[index] = ret;
}

int main() {
   // freopen("input.txt","r",stdin);
      int tc;
      string str;
      cin >> tc;
      while(tc--) {
            cin >> str;
            n = str.length();
            memset(memo,-1,sizeof(memo));
            for(int i=0; i<str.length(); i++) arr[i]= str[i] -'0';
            cout << dp(0) <<endl;
      }
      return 0;
}
