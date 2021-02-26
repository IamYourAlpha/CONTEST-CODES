#include<bits/stdc++.h>
using namespace std;

char mobile[100][100];

void pre() {
      char demo='a';
      mobile[1][1]='.';
      mobile[1][2]=',';
      mobile[1][3]='?';
      mobile[1][4]='"';
      mobile[0][1]=' ';
      for(int i=1; i<=3; i++) {mobile[2][i] = demo;  demo++;}  demo='d';
      for(int i=1; i<=3; i++) {mobile[3][i] = demo;  demo++;} demo='g';
      for(int i=1; i<=3; i++) {mobile[4][i] = demo;  demo++;} demo='j';
      for(int i=1; i<=3; i++)  {mobile[5][i] = demo; demo++;} demo='m';
      for(int i=1; i<=3; i++) {mobile[6][i] = demo;  demo++;} demo='p';
      for(int i=1; i<=4; i++) {mobile[7][i] = demo;  demo++;} demo='t';
      for(int i=1; i<=3; i++) {mobile[8][i] = demo;  demo++;} demo='w';
      for(int i=1; i<=5; i++) {mobile[9][i] = demo;  demo++;}

}
int main() {
      int tc;
      pre();
      int key[1000];
      int num[1000];
    scanf("%d",&tc);
      while(tc--) {
            int n;
            scanf("%d",&n);
            for(int i=0; i<n; i++) scanf("%d",&key[i]);
            for(int i=0; i<n; i++) scanf("%d",&num[i]);
            for(int i=0; i<n; i++) cout<<mobile[ key[i] ][ num[i] ];
            printf("\n");
      }
      return 0;

}
