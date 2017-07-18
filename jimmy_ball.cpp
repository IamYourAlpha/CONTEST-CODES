#include<stdio.h>
#define MAX 1000010
long long dp[MAX+10];
int main() {
	int tc=0;
	long long N;
	dp [ 6 ]=1;
	for(int i=1; i<=3; i++)
		for(int j=6; j<MAX; j++)			dp [ j+i ]+=dp [ j ];
			while(scanf("%lld",&N)) {
                    if(N==0) return 0;
					printf("Case %d: %lld\n",++tc,dp[N]);
					}
	return 0;
	}


