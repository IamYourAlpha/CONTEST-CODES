#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[100][100],n;


    while(scanf("%d",&n)==1) {
        memset(a,0,sizeof(a));

        for(int i=0; i<n ; i++) {
            for(int j=0; j<n ; j++) {
                cin >> a[i][j];
                a[i][j+n] = a[i+n][j] = a[i+n][j+n] = a[i][j];
                if(i>0) a[i][j] += a[i-1][j];
                if(j>0) a[i][j] += a[i][j-1];
               // if(i>0 && j>0) a[i][j] -= a[i-1][j-1];
            }
        }

        for(int i=0; i<n ; i++) {
            for(int j=0; j<n; j++) {
                cout << a[i][j] << " " ;
            }
            cout << endl;
        }
        return 0;
    }
}
