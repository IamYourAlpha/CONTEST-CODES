#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, ans;
string s[1001];
bool b[1001], z;
void solve(){
     scanf("%d %d", &n, &m);
     for(i = 0 ; i < n ; i ++){
	cin >> s[i];
     }
     b[0] = !b[0];
     for(i = 0 ; i < m ; i ++){
     	 z = 0;
	 for(j = 0 ; j < n-1 ; j ++){
            if(!b[j+1])
	      if(s[j][i] > s[j+1][i]){
     	 	 z = true;
	 	 break;
     	      }
     	}
     	if(z) ans ++;
     	else {
     	    for(j = 0 ; j < n-1 ; j ++){
     	       if(!b[j+1])
		 if(s[j][i] < s[j+1][i]){
		   b[j+1] = true;
		 }
     	    }
     	}
     }
     printf("%d", ans);
}
int main(){
    solve();
}
