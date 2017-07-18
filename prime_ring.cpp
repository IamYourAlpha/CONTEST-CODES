#include<bits/stdc++.h>
using namespace std;

int n;
bool prime[1000];
int ok[1000] =  {1};
bool seen[1000];
void seive() {
    memset(prime,true,sizeof(prime));
    prime[1] = false;
    prime[0] = false;
    prime[2] = true;
    for(int i=4; i<1000; i+=2) prime[i] = false;
    for(int i=3; i*i<1000; i++) {
        if(prime[i]) {
            for(int j=i+i; j<1000; j+=i)
                prime[j] =false;
        }
    }
   // for(int i=0;i<100;i++) if(prime[i]) cout << i <<  endl;
}


void back_track(int len) {
    if(len == n) {
   // cout << "H" << endl;
      if(!prime[ok[n-1]+1] ) return ;
        cout << "1";
        for(int i=1; i<n; i++) cout << " " <<  ok[i];
        cout << endl;
        return ;
    }
    for(int k=2; k<=n; k++) {
        if(seen[k]) continue;
        if(prime[k+ok[len-1]] ) {
            ok[len] = k;
            seen[k] = true;
            back_track(len+1);
            seen[k] = false;
        }
    }
    return ;
}



int main() {
    seive();
    int k = 0;
    while(scanf("%d",&n)!=EOF) {
     if(k) cout << endl;
        memset(seen,false,sizeof(seen));
       cout<< "Case "<<++k << ":"<<endl;
        back_track(1);
    }
    return 0;
}



