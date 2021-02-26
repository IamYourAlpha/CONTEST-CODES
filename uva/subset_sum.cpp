//
//       Filename:  c3.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  07/23/2015 08:01:33 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Tony (),
//   Organization:
//
// =====================================================================================

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll target,n;
ll in[100];

int dp(ll index,ll sum) {
    if(index>n-1) {
     if(sum==target) return 1;
     else return 0;
     }
  //   if(ST[index]) return  memo[index];
     if(sum==target) return 1;
    return  dp(index+1,sum+in[index]) + dp(index+1,sum);
}


int main() {
   // freopen("input.txt","r",stdin);
    while(scanf("%lld %lld",&n,&target)==2) {
        for(int i=0; i<n; i++)
            cin >> in[i];
        int ans = dp(0,in[0]);
        if(ans>0)
        cout << ans-1 << endl;
        else cout << "0" << endl;

    }
    return 0;
}

