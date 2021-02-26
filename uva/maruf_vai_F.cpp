#include<bits/stdc++.h>
using namespace std;

string s1;
string demo;
int main() {
      int tc;
      cin >> tc;
      getchar();
      while(tc--) {
      char ch;
      while(true) {
                  scanf("%c",&ch);
                  if(isalpha(ch) && (ch>='A' && ch<='Z') ) {
                        s1+=ch;
                  }
                  if(ch=='\n') break;
            }
           cout<< s1 << endl;
      }
      return 0;
}
