#include<bits/stdc++.h>
using namespace std;

map <int,string>mp[1000];
int main(){
   mp [0][1] = "intisar";
   mp [1][1] = "boy";
   mp [2][2] = "ok";
   for(size_t i=0; i<3; i++) cout << mp [i][i] << endl;
   return 0;
}
