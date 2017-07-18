using namespace std;
#include<bits/stdc++.h>

int main() {
    int n,t;
    scanf("%d %d",&n,&t);
    int start = 1;
    for(int i=1; i<n; i++) start*=10;
    int  end_ = start*10 -1;
    bool f = false;
   // cout << start <<  endl  << end_ << endl;
    for(int i=start; i<=end_; i++) {
        if(i%t==0) {
            cout << i << endl;
            f = true;
            break;
        }
    }
    if(!f) cout << -1 << endl;
    return 0;
}
