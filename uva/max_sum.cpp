using namespace std;
#include<stdio.h>
#include<iostream>
#include<algorithm>
//#define MAX(a,b) int(a)>int (b) ? (a):(b)

int sum[100*100];
int grid[100+10][100+10];
int n;

void init() {
    for(int i=0; i<100*100; i++) sum[i]=0;
}

int main() {
    while(scanf("%d",&n)!=EOF) {
        int ans_=-2147483647;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&grid[i][j]);

        for(int i=0; i<n; i++) {
            init();
            for(int j=i; j<n; j++) {
                int max_=-2147483647;
                int temp_=0;
                for(int k=0; k<n; k++) {
                    sum[k]+=grid[j][k];
                    temp_+=sum[k];
                   // printf("%d \n",temp_);
                    max_=max(max_,temp_);
                    if(temp_<0)
                        temp_=0;
                }
                ans_ = max(ans_,max_);
                if(max_>0) ans_+=max_;
            }
        }
        printf("%d\n",ans_);
    }
    return 0;
}
