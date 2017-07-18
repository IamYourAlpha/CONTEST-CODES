//
//       Filename:  c1.cpp
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
using namespace std;
#include<bits/stdc++.h>

int main() {
    freopen("input.txt","r",stdin);
    int n,k,demo,ans;
    int inp[1000];
    while(scanf("%d %d",&n,&k)!=EOF) {
        ans  = 0;
        for(int i=0; i<n; i++) {
            cin >> inp[i];
        }
        for(int i=0; i<n ; i++)
            if(inp[i]>=inp[k-1] && inp[i]>0) ans++;

        if(ans>0) cout << ans << endl;
        else  cout << "0" << endl;


    }
    return 0;
}
