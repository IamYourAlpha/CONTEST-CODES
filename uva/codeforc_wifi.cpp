using namespace std;
#include<stdio.h>
#include<iostream>
#include<string>
 int a[100][100];
int main() {

   string s1,s2;

    int query=0;
    int plus=0;
    int plus1=0;
    int minus=0;
    int minus1=0;
    cin>>s1>>s2;
    a[0][0]=1;
    a[1][1] = 1;
    a[1][0] = 1;

    for (int i = 2; i <= 20; i++) {
        a[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    for(int i=0; i<s1.length(); i++) {
        if(s1[i]=='+') ++plus;
        else if (s1[i]=='-') ++minus;
    }
    //cout<<plus<<endl;
    //cout<<minus<<endl;
    for(int i=0; i<s2.length(); i++) {
        if(s2[i]=='?') ++query;
         else if(s2[i]=='+') ++plus1;
        else if(s2[i]=='-') ++minus1;
    }
    //cout<<plus1<<endl;
    //cout<<minus1<<endl;
    int n = query;
    int p= plus- plus1;
    int neg= minus- minus;
    //cout<<query<<" "<<p<<" "<<neg<<endl;
     if(p<0 || neg<<0)  printf("0.000000000000");
     else{
 double ans=(double)(a[n][p])/(1<<n);
    printf("%.12lf",ans);
     }
    return 0;
}
