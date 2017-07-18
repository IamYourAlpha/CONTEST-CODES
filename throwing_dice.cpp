using namespace std;
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
typedef unsigned long long ull;
ull memo[50][300];
ull n,x;
unsigned long long dp(ull n,ull s)
{
    if(n==0)
    {
        if(s >=x)
            return 1;
        else return 0;
    }
    if(memo[n][s]!=-1) return memo[n][s];
    ull ans=0;
    for(int i=1; i<=6; i++)
    {
        ans+=dp(n-1,s+i);
    }
    return memo[n][s]=ans;
}
ull gCd(ull n,ull s)
{
    if(s==0)  return n;
    else gCd(s,n%s);
}

int main()
{
    ull tok;
    while(cin>>n>>x && (n|x))
    {
        ull space,event;

        memset(memo,-1,sizeof(memo));
        space = pow(6.0,n);
        event = dp(n,0);
        tok = gCd(space,event);
       // cout<<tok<<endl;
        if( (event/tok)==0) cout<<"0"<<endl;
        else if( (space/tok)==1) cout<<event/tok<<endl;
        else cout<<event/tok<<"/"<<space/tok<<endl;
    }
    return 0;
}
