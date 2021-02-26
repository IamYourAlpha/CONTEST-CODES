#include<bits/stdc++.h>
using namespace std;
char sample[1000];
char pat[1000];
int matched;

int match() {
    int j=0;
    matched = 0;
    for(int i=0; i<strlen(sample);) {
        if(sample[i]==pat[j]) {
            i++;
            j++;
            if(j==strlen(pat));
            return (i-j);
        } else {
            j=0;
            i++;
            matched=0;
        }
    }
    return -1;

}

int main() {

    scanf("%s",sample);
    scanf("%s",pat);
    int ans =  match();
    if(ans!=-1)
        cout << "matching starts at : " << ans  << endl;
    else cout << " no match" << endl;
    return 0;
}
