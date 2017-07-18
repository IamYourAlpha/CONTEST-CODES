#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int main()
{
    int n,num,sum=0;


    while(cin>>n && n)
    {
        priority_queue<int,vector<int>,greater<int> >mypq;
        for(int i=0; i<n; i++)
        {
            cin>>num;
            mypq.push(num);
        }
        if(n==1)
        {
            cout<<num;
            continue;
        }
        sum=0;
        while(mypq.size()>1)
        {
            num = mypq.top();
            mypq.pop();
            num+=mypq.top();
            mypq.pop();
            sum+=num;
            mypq.push(num);
        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}
