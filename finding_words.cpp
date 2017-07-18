#include<bits/stdc++.h>
using namespace std;

int main() {
   freopen("in.txt","r",stdin);
   string in;
   string out = "";
   int newline = 0;
   while(getline(cin,in)) {
      int len = in.length();
      if(in=="#") return 0;
      for(int i=0; i<len; i++) {
         if(isspace(in[i])) {
            cout << out;
            if(newline)
               cout << endl;
            cout << in[i];
            out = "";
            newline = 0;
         } else if(isalpha(in[i])) {
            out = out + in[i];
         } else {
            if(in[i]=='-') {
               if(out.length()>0 && i==len-1) {
                  newline = 1;
               }
            } else {
               cout << out;
               out = "";
               if(newline) cout << endl;
               newline = 0;
            }
         }
      }
      if(newline==0) {
         cout << out;
         out = "";
      }
   cout << endl;
}
return 0;
}
