#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

int n;
int A[1000+100];
int memo[100][100];


int dp(int start,int endd) {
    if(endd-start==1) return  memo[start][endd]=0;

    if(memo[start][endd]!=-1) return memo[start][endd];

    int ans= 1<<30;
    for(int i=start+1; i<endd; i++) {
    ans= min(   (A[endd]-A[start]) + dp(start,i) +dp(i,endd), ans) ;
    //printf("%d\n",ans);
    }
    return memo[start][endd]=ans;
}



int main() {

int num;
    while( scanf("%d",&n)!=EOF ) {
            if(n==0) return 0;
        scanf("%d",&num);
        A[0]=0;
        for(int i=1; i<=num; i++) scanf("%d",&A[i]);
        A[num+1]=n;
        memset(memo,-1,sizeof(memo));;
        printf("The minimum cutting is %d.\n",dp(0,num+1));
     //   printf(" min :%d ",1<<30);
    }
    return 0;
}
