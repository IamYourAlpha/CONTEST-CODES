#include     <bits/stdc++.h>
using namespace std;

struct argus {
    int id;
    int p;
    int pp;
};

    bool comp(argus a,argus b) {
        if(a.p!=b.p)
            return a.p>b.p;
        return a.id>b.id;
    }

int main() {
   //freopen("input.txt","r",stdin);
    char str[1000];
    int n,m;
    argus now,tmp;

    priority_queue<argus,vector<argus>,comp >pq;
    while(!pq.empty()) pq.pop();

    while(scanf("%s",str)) {
        if(str[0]=='#') break;
        scanf("%d %d",&now.id,&now.p);
        now.pp = now.p;
        pq.push(now);
    }
    int k;
    scanf("%d",&k);

    for(int i=0; i<k; i++) {
        tmp = pq.top();
        pq.pop();
        cout << tmp.id << endl;
        tmp.p+= tmp.pp;
        pq.push(tmp);
    }
    return 0;
}


