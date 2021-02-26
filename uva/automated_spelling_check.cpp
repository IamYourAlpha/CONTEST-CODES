using namespace std;
#include<bits/stdc++.h>

char Dict[100][1000];
char input[1000];
bool check;
int Slen[1000];
set<string>st;


int main() {
 freopen("input.txt","r",stdin);
      int n;
    while(scanf("%d",&n)!=EOF) {
        while(getchar()!='\n') {
            for(int i=0; i<n; i++) {
                gets(Dict[i]);
                st.insert(Dict[i]);
                Slen[i] = strlen(Dict[i]);
            }
        }
        int m;
        scanf("%d",&m);
        while(getchar()!='\n') {

            for(int k=0; k<m; k++) {
                char demo[2000];
                gets(demo);
                if(st.find(demo)!=st.end()) {
                    printf("%s is correct\n",demo);
                    continue;
                }
                // check for the missing letter
                for(int i=0; i<n && !check ; i++) {
                    int len_ = strlen(Dict[i]);

                    if(len_-1 == strlen(demo)) {
                        check = false;
                        int index1_=0;
                        int index2_=0;
                        while(index1_<len_ && index2_<len_) {
                            if(Dict[i][index1_]==demo[index2_]) {
                                index1_++;
                                index2_++;
                            } else {
                                if(!check) {
                                    index1_++;
                                    check = true;
                                } else break;
                            }
                        }
                        if(!check)  {
                            index1_++;
                            check = true;
                        }
                        if(index1_==len_ && index2_== len_-1 && check==1) {
                            printf("%s is a misspelling of %s\n",demo,Dict[i]);
                            continue;
                        }
                    }
                    if(len_+1 == strlen(demo)) {
                        check = false;
                        int index1_=0;
                        int index2_=0;
                        int error = 0;
                        while(index1_<len_ && index2_<len_) {
                            if(Dict[i][index1_]==demo[index2_]) {
                                index1_++;
                                index2_++;
                            } else {
                                if(!check) {
                                    index1_++;
                                    error = 1;
                                } else break;
                            }
                        }
                        if(!check)  {
                            index2_++;
                            check = 1;
                        }
                        if(index1_==len_ && index2_== len_+1 && check==1) {
                            printf("%s is a misspelling of %s\n",demo,Dict[i]);
                            continue;
                        }
                    }
                    if(len_ = strlen(demo)) {
                        check = false;
                        int index1_=0;
                        int index2_=0;
                        int error = 0;
                        while(index1_<len_ && index2_<len_) {
                            if(Dict[i][index1_]==demo[index2_]) {
                                index1_++;
                                index2_++;
                            } else {
                                if(!check) {
                                    index1_++;
                                    error = 1;
                                } else break;
                            }
                        }
                        if(index1_==len_ && index2_== len_ && check==1) {
                            printf("%s is a misspelling of %s\n",demo,Dict[i]);
                            continue;
                        }
                    }

                    if(len_ = strlen(demo)) {
                        check = false;
                        int index1_=0;
                        int index2_=0;
                        int error = 0;
                        while(index1_<len_ && index2_<len_) {
                            if(Dict[i][index1_]==demo[index2_]) {
                                index1_++;
                                index2_++;
                            } else {
                                if(!check) {
                                    swap(demo[index1_],demo[index1_+1]);
                                    error = 1;
                                } else break;
                            }
                        }

                        if(index1_==len_ && index2_== len_ && check==1) {
                            printf("%s is a misspelling of %s\n",demo,Dict[i]);
                            break;
                        }
                    }
                    if(!check) printf("%s is unknown\n",demo);
                }
            }
        }
    }
    return 0;
}
