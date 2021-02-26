#include<bits/stdc++.h>
using namespace std;

long long p(long long n){
    if(n==0) return 1;
    else return n*p(n-1);
}

int main() {
      char str[100];
      int n;
      int tc;
      cin>>tc;
      while(tc--) {

            cin>>str;
            cin>>n;
      long long demo = p(strlen(str));
       demo = n%demo;
       cout<<demo<<endl;
            while(demo--) {
                  next_permutation(str,str+strlen(str));
            }
            cout<<str<<endl;
      }
      return 0;
}
