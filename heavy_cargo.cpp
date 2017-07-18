using namespace std;
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define clr(a) memset(a,0,sizeof(a))


int city[500][500];
int ct,street;
map<string,int>mp;

void floyd_warshall()
{
    for(int k=1; k<=ct; k++)
        for(int i=1; i<=ct; i++)
            for(int j=1; j<=ct; j++)
             city[i][j]=max(city[i][j] , min(city[i][k],city[k][j]));


}
int main()
{
    string src,dst;
    int tc=0;
    string s1,s2;
    int index=0;
    int cost;
    while(cin>>ct>>street)
    {
        if(ct==0 && street==0) return 0;
        for(int i=0; i<street; i++)
        {
            cin>>s1>>s2>>cost;
            if(mp[s1]==0) mp[s1]=++index;
            if(mp[s2]==0) mp[s2]= ++index;
            city[mp[s1]][mp[s2]]=cost;
            city[mp[s2]][mp[s1]]=cost;
        }

        floyd_warshall();
        cin>>src>>dst;
        cout<<"Scenario #"<<++tc<<endl<<city[mp[src]][mp[dst]]<<" tons"<<endl<<endl;
        mp.clear();
        clr(city);
    }
    return 0;
}
