#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int tc;
int a[10000];
int n,k;
bool dp[10005][101];

int cal(int aa,int b) {
	if(aa<0) {
			aa = aa + (-aa / b + 1);
			}
	return aa%b;
	}


bool div(int mod_value,int index) {
	int check=0;
	if(index==n) {
			if(mod_value==0) return 1;
			else return 0;
			}
	else if(dp[index][mod_value]!=0) return dp[index][mod_value];
	check =check | div((mod_value+cal(-a[index],k))%k,index+1);
	check=check | div( (mod_value+cal(a[index],k))%k,index+1) ;
//	vi.push_back(mod_value);
	//vii.push_back(index);
	return dp[index][mod_value]=check;

	}

int main() {
	scanf("%d",&tc);
	while(tc--) {
			scanf("%d %d",&n,&k);
			for(int i=0; i<n; i++)
				scanf("%d",&a[i]);
			memset(dp,0,sizeof(dp));
			dp[n][0]=1;
			if(div(cal(a[0],k),1)==1) printf("Divisible\n");
			else printf("Not divisible\n");
			}
	return 0;
	}
