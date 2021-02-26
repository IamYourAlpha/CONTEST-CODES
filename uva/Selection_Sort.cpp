using namespace std;
#include<bits/stdc++.h>

int main() {

    int a,b;
    bool found = false;
    int ans;
    cin >> a >> b;
    for(int i=1; i<=min(a,b); i++) {

        if(a%i==0 && b%i==0) ans = i, found = true;
    }
    if(!found) cout << 1 << endl;
    else cout << ans << endl;
    return 0;
}
