using namespace std;
#include<stdio.h>
#include<iostream>
#include<vector>
#define ll long long

ll max(ll a,ll b)
{
    return (a>b)? a:b;
}
ll max(ll a,ll b,ll c)
{
    return max(a, max(b,c) );
}

ll maxprod(ll n)
{
    if(n==0 || n==1)  return 0;
    int max_val= 0;
    for(int i=1; i<n; i++)
        max_val = max(max_val,i*(n-i),maxprod(n-i)*i);
    return max_val;
}
int main()
{
    ll n;
    cin>>n;
    cout<<"max product: "<<maxprod(n)<<endl;
    return 0;
}
