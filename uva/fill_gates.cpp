using namespace std;
#include<bits/stdc++.h>

map<int,char> mp;

pair <int,int> solve(string node){}


int main() {
    int q;
    string s;
    while(cin >> s) {
        cin >> q;
        for(int i=0; i<s.length(); i++) mp[i] = s[i];
        for(int i=0;i<q;i++) {
	string str;
	 cin >> str;
	 solve(s);
	 }
       // for(int i=0; i<s.length(); i++) cout << i <<" :" << s[i] << endl;
        return 0;
    }
    return 0;
}

