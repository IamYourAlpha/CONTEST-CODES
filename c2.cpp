//
//       Filename:  c2.cpp
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

#define Red 1
#define Green 2
#define blue 3



int main() {
    int n;
    char arr[10000];
    while(scanf("%d",&n)!=EOF) {
        cin >> arr;
        char demo;
        demo = arr[0];
        int ans = 0;
        for(int i=1; i<n; i++) {
            if(arr[i]==demo) ans++;
            demo = arr[i];
        }
        cout << ans << endl;
    }
    return 0;
}
