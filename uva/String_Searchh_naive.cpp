using namespace std;
#include<bits/stdc++.h>

int main() {

    string input,pat;
    int index1,index2,tot = 0;
    bool f = false;
    cin >> input >> pat;
    for(int i=0; i<input.length(); i++) {
        index1 = i;
        index2 = 0;
        tot = 0;
        f = false;
        while(input[index1] == pat[index2]) {
         tot++;
            index1++;
            index2++;
            if(tot == pat.length()-1){ f = true; break;}
        }
        if(f) break;
    }
    if(f) cout << " found the pattern" << endl;
    else cout << " not found" << endl;
    return 0;
}
