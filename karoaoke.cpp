/* i am captain planet */
using namespace std;
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
/*
int dp(int index,int make){
    if(index==MU.size()) return 0;
    if(make<0 || make==0) return 0;
    if(make-MU[index]>0)
        return dp(index+1,make-MU[index]);
      else dp(index+1,make);
}
        */

    int main() {

        int n,T;
        int tc;
        int demo;
        int ans;
        vector<int>MU;
        cin>>tc;
        int k=0;
        while(tc--) {
                int c=0;
        int len=0;
            cin>>n>>T;
            for(int i=0; i<n; i++) {
                cin>>demo;
                MU.push_back(demo);
            }
            sort(MU.begin(),MU.end());
            if(T-MU[0]==1) printf("Case %d: 2 %d\n",++k,MU[0]+678);
            else {

        }
        return 0;
    }
