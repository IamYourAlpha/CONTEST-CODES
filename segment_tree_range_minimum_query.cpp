#include<bits/stdc++.h>
using namespace std;

#define MAX 10000
int n;
int input[MAX];
int Seg_Tree[MAX];


int RMQ(int low,int high,int ql,int qh,int pos) {
	if(ql<=low && qh>=high) return Seg_Tree[pos];

	if(ql>high || qh<low) return 9999999;
	int mid =  low + (high -low)/2;
	return min ( RMQ(low,mid,ql,qh,2*pos+1),RMQ(mid+1,high,ql,qh,2*pos+2) );
}

int Construct_Seg_Tree(int low,int high,int pos) {
	if(high==low) {
		Seg_Tree[pos] = input[low];
		return input[low];
	}
	int mid =  low + (high -low)/2;
	Seg_Tree[pos] = min ( Construct_Seg_Tree(low,mid,2*pos + 1),Construct_Seg_Tree(mid+1,high,2*pos + 2) ) ;
	return Seg_Tree[pos];
}

int main() {
	while(scanf("%d",&n)==1) {

		for(int i=0; i<n; i++) scanf("%d",&input[i]);

		Construct_Seg_Tree(0,n-1,0);

		printf("give the range as input \n");
		int qlow,qhigh;

		scanf("%d%d",&qlow,&qhigh);
		int ans = RMQ(0,n-1,qlow,qhigh,0);
		printf("%d",ans);
	}
	return 0;
}

