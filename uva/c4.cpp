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

int main() {
    int tc;
    int n,m;
    cin >> tc;
    while(tc--) {
     int ans = 0;
        cin >> n >> m;
        m--;
        for(int i=0; i<n; i++) {
            ans+=  m;
            m--;
        }
        cout << ans << endl;
    }
    return 0;
}


