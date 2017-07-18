#include<bits/stdc++.h>
using namespace std;

char s1[1000];
char s2[100];
char s3[100];
int len;

void shift(char *ss1,char *ss2){

for(int i=0;i<len;i++)
     ss2[(i+1)%len]= ss1[i];
}


int main(){
cin>>s1;
len= strlen(s1);
shift(s1,s2);

for(int i=0;i<len;i++)
    cout<<s3[i];


}
