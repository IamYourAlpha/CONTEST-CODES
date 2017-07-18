#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>viii;
bool visited[100];
int V[100];
int n,m;

int find_(int Si) {
    int ans;
    ans=Si;
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            ans=max(ans,V[i]);
        }
    }
    return ans;
}

void init() {
    for(int i=1; i<99; i++) visited[i]=false;
}


int main() {
    int n,m;
    int S;
    init();
    while(scanf("%d %d",&n,&m)!=EOF) {
        for(int i=1; i<=n; i++) scanf("%d",&V[i]);
        for(int i=1; i<=m; i++) {
                S=0;
            for(int j=i; j<=(n-m)+i; j++) {
                S+=V[i];
                visited[i]=true;
            }
            printf("%d ",S);
        int demo=find_(S);
            viii.push_back(demo);
            init();
        }
        printf("%d",viii.size());
    //sort(vii.begin(),vii.end());
    for(int i=0;i<viii.size();i++) printf(" %d ",viii[i]);
    }
    return 0;
}
