#include<bits/stdc++.h>

using namespace std;
int main(){
    string s,d,e;
    int n;
    stringstream ss(stringstream :: in | stringstream :: out);
    getline(cin,s);
    ss.clear();
    ss << s;
    ss >> d;
    ss >> n;
    cout << d << " " << n;
}
