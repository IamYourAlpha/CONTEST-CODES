#include<stdio.h>
#include<vector>
#include<set>
#include<string.h>
#include<stdlib.h>
using namespace std;
vector<int>viii;
set<int>ans;

int main() {
    int n,make;
    int ans_=0;
    bool visited[100000+10];
    bool flag=true;
    memset(visited,false,sizeof(visited));
    visited[0]=true;
    scanf("%d %d",&n,&make);
    set<int>::iterator it;
    if(make==1){
            for(int i=1;i<=n;i++){ printf("%d ",i); }return 0;}
    for(int i=make; i>=1; i--) viii.push_back(i);
    ans.insert(1);
    visited[1]=true;
    int c=0;
    for(int i=0;; i++) {
        if(c==make) {
            c=0;
            flag=!flag;
        }
        if(flag) {
            printf("%d",*it);
                  it=ans.end();
            ans_= *it+viii[c];
            flag=!flag;
        } else {
            it=ans.end();
            ans_=abs( *it-viii[c]);
            flag=!flag;
        }
        if(!visited[ans_] && ans_<=n ) {
            ans.insert(ans_);;
            visited[ans_]=true;
            c++;
        } //else { c++; flag=!flag; }
        if(ans.size()==n) break;
    }
    for(it=ans.begin(); it!=ans.end(); it++) printf("%d ",*it);

    return 0;
}
