#include<bits/stdc++.h>
using namespace std;

int main() {

      int n;
      int arr[2000];
      string str;
      scanf("%d",&n);
      cin>>str;
      for(int i=0; i<str.length(); i++) arr[i]= str[i]-'0';
      sort(arr,arr+n);
      for(int i=0; i<n; i++) cout<<abs(arr[0]-arr[i]);
}
