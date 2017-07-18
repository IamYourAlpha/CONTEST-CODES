#include<bits/stdc++.h>
using namespace std;


int ans[100000];
int arr[100000];
int visited[100000];

vector<int>v;

int main() {
      freopen("input.txt","r",stdin);
      int i=0;
      int demo;
      while(scanf("%d",&demo)!=EOF) {
            arr[i++]=demo;
      }
      for(int j=0; j<=i; j++) ans [j] = 1;
      // cout << i << endl;
      for(int ii=1; ii<i; ii++) {
            for(int jj=0; jj<ii; jj++) {
                  if(arr[ii] > arr[jj] &&  ans[ii]<ans[jj]+1)
                        ans[ii] = ans[jj] + 1;

            }
      }
      int  max_ = INT_MIN;
      for(int ii=0; ii<i; ii++)  if(ans[ii]>max_)  max_= ans[ii];
      for(int ii=0; ii<i; ii++) {
            if(ans[ii]!=ans[ii+1] && !visited[ans[ii]] ) {
                  v.push_back(arr[ii]);
                  visited[ans[ii]]=1;
            }
      }
      cout << max_ << endl;
      cout << "-"  <<   endl;
      if(v.size()==0) v.push_back(arr[0]);
      for(int i=0; i<v.size(); i++) cout << v[i] << endl;
      v.clear();
      memset(ans,0,sizeof(ans));
      memset(visited,0,sizeof(visited));


      // for(int j=0;j<i;j++) cout<< arr[j] << endl;
      return 0;

}
