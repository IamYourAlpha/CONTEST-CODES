#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
inline ll gcd(ll a,ll b) {
    ll t;
    while(b) {
        a=a%b;
        t=a;
        a=b;
        b=t;
    }
    return a;
}

int bamboo[100];

int main(){

//freopen("input.txt","r",stdin);
    int tc;
    cin >> tc;
    int n;
    while(tc--){
            scanf("%d",&n);
     bamboo[1]=1;
    bamboo[2]=1;
   for(int i=3;i<=15;i++) bamboo[i]=(i-1);
   int tot = 0;
   for(int i=1;i<=n;i++)  tot = tot + bamboo[i];
  // cout << tot << endl;
    cout << tot-(n-1) << endl;
    }
    return 0;
}


