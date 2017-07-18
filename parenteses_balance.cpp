#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int memo[200][200];
int make,garment;
vector<int>viii[200];
int demo,model;
int max_=-1;
void dp(int index,int sum) {
    if(index==garment) {
        if(sum<=make && sum>max_)
            max_=sum;
            return ;
    }
    if(sum>make) return ;
    if(memo[index][sum]) return;
    memo[index][sum]=true;
    for(int i=0; i<viii[index].size(); i++)
        dp(index+1,sum+viii[index][i]);
}

void intit(){
    for(int i=0;i<200;i++) viii[i].clear();
    memset(memo,false,sizeof(memo));
}

int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--) {
            intit();
       // memset(memo,false,sizeof(memo));
        scanf("%d %d",&make,&garment);
        for(int i=0; i<garment; i++) {
            scanf("%d",&model);
            for(int j=0; j<model; j++) {
                scanf("%d",&demo);
                viii[i].push_back(demo);
            }
        }
        dp(0,0);
        if(max_<0) printf("no solution\n");
      else  printf("%d\n",max_);
      max_=-1;
    }
}
