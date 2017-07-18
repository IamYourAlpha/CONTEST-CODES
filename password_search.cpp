#include<bits/stdc++.h>
using namespace std;

map <string,int > mp;

int main() {
      string str;
      string demo;
      int n;
      while(cin>>n>>str) {
            for(int i=0; i<=str.length()-n; i++) {
                  demo = str.substr(i,n);
                  mp[demo]++;
            }
            int max_=-9999;
            for(  map < string,int > :: const_iterator  it=mp.begin(); it!=mp.end(); it++) {
                  if((it->second )>max_) {
                        max_=it->second;
                        demo = it->first;
                  }
            }
            cout << demo << endl;
            mp.clear();

      }
      return 0;
}
