using namespace std;
#include<bits/stdc++.h>

int main() {
    int n;
    cin >> n;
    int tot = ceil (sqrt(n)) ;
    tot = tot*4;
    int c = 1;
    int i = 0;
    bool blank = true;
   // cout << tot*4 << endl;
    while(i<=n){
       //if(i == n) break;
        for(int j = 1; j<=2 ;j++) {
            if( blank && tot > n ) {
                cout << "Sheet " << i << ", front: " << "Blank, " << c << endl;
                tot--;
                c++;
                i++;
                blank = !blank;
            } else if( !blank &&  tot > n ) {
                cout << "Sheet " << i << ", back: " << c << ", " << "Blank" << endl;
                c++;
                tot--;
                i++;
                blank = !blank;
            } else if( blank &&  tot <= n)   {
                cout << "Sheet " << i << ", front: " << tot << ", " << c << endl;
                c++;
                tot--;
                i++;
                blank = !blank;
            } else if( !blank &&  tot <= n)   {
                cout << "Sheet " << i << ", back: " << c << ", " << tot << endl;
                c++;
                tot--;
                i++;
                blank = !blank;
            }
            }
    }
    return 0;
}
