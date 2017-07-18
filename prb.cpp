#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;


int a;
int b;
int A[100+7];
int B[100+7];
int memo[100][100];
/*
int dp(int i,int j) {
    int ans;
    if(i>a) return 0;
    if(j>b) return 0;
    if( (A[i]-B[j])==1 || (A[i]-B[j])==0) return 1+dp(i+1,j+1);
    if(memo[i][j]!=-1) return memo[i][j];
    else {
    memo[i+1][j]+= dp(i+1,j);
    memo[i][j+1]+=max(dp(i,j+1),memo[i+1][j]);
    memo[i+1][j+1]+=max( dp(i+1,j+1), memo[i+1][j+1]);
    ans=memo[i][j];
    }
    return ans;
}
*/

bool visited_a[1000];
bool visited_b[1000];
int main() {

    int C=0;
    int i,j;
    int ans=-99999;
    scanf("%d",&a);
    for(int i=0; i<a; i++) scanf("%d",&A[i]);
    sort(A,A+a);
    scanf("%d",&b);
    for(int i=0; i<b; i++)  scanf("%d",&B[i]);
    sort(B,B+b);
 memset(memo,false,sizeof(visited_b));
    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
            if(abs(A[i]-B[j])<=1 && !visited_b[j]) {
                C++;
                visited_b[j]=true;
                break;
            }
        }
    }
    printf("%d\n",C);
    return 0;
}
