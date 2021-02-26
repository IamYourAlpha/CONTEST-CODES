/*** rise from zero -fall from INFINITY*****/

using namespace std;
#include<bits/stdc++.h>


typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
// Input macros

int arr[10];

void prepos() {
     arr[0]=1;
     arr[1]=6;
     arr[2]=1;
     arr[3]=2;
     arr[4]=2;
     arr[5]=3;
     arr[6]=1;
     arr[7]=4;
     arr[8]=0;
     arr[9]=1;
}




int main() {

     prepos();
     int input;
     scanf("%d",&input);
     int demo=input;
     int first = input%10;
     input/=10;
     int second = input%10;
   //  printf("%d %d\n",first,second);
     printf("%d",(arr[first]+1)*(arr[second]+1));
}

