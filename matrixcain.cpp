using namespace std;
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<iostream>
int dp(int p[],int i,int j) {
    if(i==j)
        return 0;
    int k;
    int min= INT_MAX;
    int count;
    for(k=i; k<j; k++) {
        //cout<<p[i-1]<<" "<<p[k]<<" "<<p[j]<<endl;
        count=dp(p,i,k)+ dp(p,k+1,j)+ p[i-1]*p[k]*p[j];

        if(count<min) min=count;
    }
    return min;
}


int main() {
    int arr[]= {1,2,3,4};
    int n= sizeof(arr)/sizeof(arr[0]);
    printf("the minimum number of operations is %d",dp(arr,1,n-1));
    return 0;
}

