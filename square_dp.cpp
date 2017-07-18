using namespace std;
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
int m;
int arr[1000];
int memo[100][100];
int dp(int i,int sum,int c){
if( i>=m){
        if(sum%4==0 && sum>=4 && c>=4)
        return 1;
        else return 0;
}
if(c>=4){
        if(sum%4==0) return 1;
}
if(memo[i][sum]!=-1) return memo[i][sum];
int ans1=0;
int ans2=0;
 ans1=dp(i+1,sum+arr[i],c+1);
ans2= dp(i+1,sum,c);
 return memo[i][sum] = ans1+ans2;
// return memo[i][sum];
}



int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        bool flag=false;
        scanf("%d",&m);
        for(int i=0; i<m; i++)
            scanf("%d",&arr[i]);
            memset(memo,-1,sizeof(memo));
           cout<< dp(0,0,0)<<endl;
    }
    return 0;
}
