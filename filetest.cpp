using namespace std;
#include<bits/stdc++.h>



int main() {

    string name[1000];
    int age[100];
    string sex[100];
    ifstream f1;
    f1.open("test.txt");
    for(int i=0; i<3;  i++) {
        f1 >> name[i] ;
        f1 >> age[i];
        f1 >> sex[i];
    }
    for(int i=0; i<3; i++) cout << name[i] << " " << age[i] << " " << sex[i] << endl;
    return 0;

}
