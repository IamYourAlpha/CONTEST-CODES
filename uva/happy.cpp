using namespace std;
#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>

int main() {
    string SS[16];
    string SP[150];
    SS[0]="Happy";
    SS[1]="birthday";
    SS[2]="to";
    SS[3]="you";
    SS[4]="Happy";
    SS[5]="birthday";
    SS[6]="to";
    SS[7]="you";
    SS[8]="Happy";
    SS[9]="birthday";
    SS[10]="to";
    SS[11]="Rujia";
    SS[12]="Happy";
    SS[13]="birthday";
    SS[14]="to";
    SS[15]="you";
    int n;
    cin>>n;
    int c=0;
    bool flag=false;
    for(int i=0; i<n; i++)
        cin>>SP[i];
    while(!flag) {
        for(int j=0; j<16; j++) {
            if(c==n) {
                c=0;
                flag=true;
            }
            cout<<SP[c]<<": "<<SS[j]<<endl;
            c++;
        }
        if(flag) break;
    }
    return 0;
}


