#include<bits/stdc++.h>
using namespace std;


int main(){

freopen("input.txt","r",stdin);
    int arr[1000];
    int tc;
    int k=0;
    int demo;
    while(scanf("%d",&demo)!=EOF && demo!=-999999){
           arr[k++] = demo;
    }
    int now = 1;
    int max_far = INT_MIN;
    int max_now = INT_MIN;
    for(int i=0;i<k;i++){
            now =  now * arr[i];
            if(now>max_now)
            max_now = now;
            else now = 1;

            max_far = max(max_now,max_far);
    }
    cout << max_far << endl;



    return 0;
}
