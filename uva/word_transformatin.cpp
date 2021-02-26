#include<bits/stdc++.h>
using namespace std;

typedef struct {
    string str;
    int stp;
} node;

queue<node>q;
int ii;
string src,dst;
node current,nw;
int visited[300];
string cont[300];


bool ok(string s,string p) {
    if(s.length()!=p.length()) return false;
    int c=0;
    for(int i=0; i<s.length(); i++)
        if(s[i]!=p[i]) c++;
    // cout << c <<endl;
    if( c==1) return true;
    else return false;
}

int bfs() {
    current.str = src;
    current.stp = 0;
    q.push(current);
    while(!q.empty()) {
        current = q.front();
        q.pop();
        if( current.str == dst  ) return current.stp;
        for(int i=0; i<ii; i++) {
            if(!visited[i] ) {
                if(  ok(current.str,cont[i])) {
                    nw.str = cont[i];
                    nw.stp = current.stp+1;
                    q.push(nw);
                    visited[i]=1;
                }
            }
        }
    }
    return 0;
}

int main() {
    freopen("input.txt","r",stdin);
    int tc;
    stringstream ss(stringstream::in|stringstream::out);
    cin >> tc;
    bool ok = false;
    while(tc--) {
        for(int i=0; i<250; i++) cont[i].clear();
        ii=0;
        if(ok) printf("\n");
        ok = true;
        ii=0;
        string demo;
        while(cin>>demo) {
            if(demo=="*") break;
            cont[ii]=demo;
            ii++;
        }
        for(int i=0; i<250; i++) visited[ i ] = 0;
        string c;
        getline(cin,c);
        while (getline(cin,c)) {
            if(c=="") break;
            ss.clear();
            ss<<c;
            ss>>src;
            ss>>dst;
            int ans = bfs();
            // if(src.length()!=dst.length()) ans = 0;
            cout << src << " " << dst << " " <<  ans <<endl;
            while(!q.empty()) q.pop();
            for(int i=0; i<250; i++) visited[i] = false;

        }
    }
    return 0;
}
