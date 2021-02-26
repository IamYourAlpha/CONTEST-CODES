using namespace std;
#include<stdio.h>
#include<iostream>
#include<string.h>
int m,arr[25],visited[25];
long long sum;
int DP(int index,int c,long long make) {
	if(c==3) return 1;
	if(make==sum) {
		return  DP(0,c+1,0);
	}
	if(make>sum) return 0;
	// if(memo[index][make]!=-1) return memo[index][make];
	if(index>m-1) return 0;
	else {
		if(!visited[index] && arr[index]<=sum) {
			visited[index]=1;
			if(DP(index+1,c,make+arr[index]))
				return 1;
			visited[index]=0;
		}
	}
	if(DP(index+1,c,make))
		return 1;
}

int main() {
	int tc;
	long long tot;
	scanf("%d",&tc);
	while(tc--) {
		tot=0;
		memset(visited,0,sizeof(visited));
		// memset(memo,-1,sizeof(memo));
		bool flag=false;
		scanf("%d",&m);
		for(int i=0; i<m; i++) {
			scanf("%lld",&arr[i]);
			tot+=arr[i];
		}
		// cout<<tot/4<<endl;
		if(tot%4!=0 ||(tot/4)==0 ) printf("no\n");
		else if(tot%4==0) {
			sum=tot/4;
			if( DP(0,0,0) ) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
