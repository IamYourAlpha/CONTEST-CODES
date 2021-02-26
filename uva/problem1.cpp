# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>

#define f(a,b,c,R) ((-a)*R*R)+(b*R)+c

using namespace std;

int  calc_tor(int a,int b,int c) {
    int demo;
    int max_demo= -(int)1e9;
    for(int r=0;; r++) {
        demo= f(a,b,c,r);
        if(demo>max_demo && demo>0) {
            max_demo=demo;
        } else if(demo<=0) break;
    }
    return max_demo;
}


int main() {
    int tc;
    int n;
    int gear[10000];
    int a[10000],b[10000],c[10000];
    int ans;
    int max_ans;
    int max_index;
    cin>>tc;
    int index;
    while(tc--) {
        //  vector<int>viii;
        //max_ans[0]=max_ans[1] =-999999;
        cin>>n;
        for(int i=0; i<10000; i++) gear[i]=0;
        for(int i=1; i<=n; i++)
           cin>>a[i]>>b[i]>>c[i];
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                gear[i]+= calc_tor(a[j],b[j],c[j]);
            }
        }
        int max__;
        int max_=-(int)1e9;
        for(int i=1; i<=n; i++){
                cout<<gear[i]<<endl;
            if(gear[i]>max_){
                max_=gear[i];
                max__=i;
            }
        }
        cout<<max__<<endl;
    }
    return 0;
}
