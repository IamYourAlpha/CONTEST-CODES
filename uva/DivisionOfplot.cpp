using namespace std;
#include<bits/stdc++.h>

int main() {
    int k;
    int orx,ory;
     //freopen("test.txt","r",stdin);
    while(scanf("%d",&k)!=EOF) {
        if(k==0) return 0;
        scanf("%d%d",&orx,&ory);
        for(int i=0; i<k; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            if(orx == x || ory == y) printf("divisa\n");
            else {
                if(y > ory) {
                    if(x > orx) printf("NE\n");
                    else printf("NO\n");
                } else if(y<ory) {
                    if(x > orx) printf("SE\n");
                    else  printf("SO\n");
                }
            }
        }
    }
    return 0;
}
