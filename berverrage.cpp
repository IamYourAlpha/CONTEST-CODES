using namespace std;
#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<stack>

int n;
int V;
int tc=0;
stack<int>st;
string OU[300];
string S;
vector<int>G[300];
map<string,int>mp;
bool visited[300];


void DFS(int node) {
    //cout<<"indfs"<<endl;
    visited[node]=true;
    vector<int>::iterator I;
    for(I=G[node].begin(); I!=G[node].end(); I++)
        if(!visited[*I])
            DFS(*I);
    st.push(node);
}

void SOL() {
    //cout<<"in"<<endl;
    for(int I=0; I<n; I++)
        visited[I]=false;
    for(int I=0; I<n; I++) {
        if(!visited[I])
            DFS(I);
    }
    cout<<"Case #"<<++tc<<": Dilbert should drink beverages in this order:";
    while(!st.empty()) {
        //   cout<<st.top();
        cout<<" "<<OU[st.top()];
        st.pop();
    }
    cout<<"."<<endl;
    cout<<endl;
}
int main() {
    //int tc=0;
    string ND1;
    string ND2;
    while(scanf("%d",&n)!=EOF) {
        mp.clear();
        for(int I=0; I<n; I++) {
            cin>>S;
            mp[S]=I;
            OU[I]=S;
        }
        scanf("%d",&V);
        for(int I=0; I<V; I++) {
            cin>>ND1>>ND2;
            G[mp[ND1]].push_back(mp[ND2]);
            //W_T[ND2]++;
        }
        SOL();
    }
    return 0;
}

