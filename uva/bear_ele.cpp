#include<stdio.h>
#include<algorithm>
using namespace std;

int a[6];

int main() {

    for(int i=0; i<6; i++) scanf("%d",&a[i]);
    sort(a,a+6);
    if( (a[0]==a[1] && a[1]==a[2] && a[2]==a[3])) {
        if(a[4]==a[5]) {
            printf("Elephant\n");
            return 0;
        } else {
            printf("Bear\n");
            return 0;
        }
    }

    else if( (a[2]==a[3] && a[3]==a[4] && a[4]==a[5])) {
        if(a[0]==a[1]) {
            printf("Elephant\n");
            return 0;
        } else  {
            printf("Bear\n");
            return 0;
        }
    }

    else if( (a[1]==a[2] && a[2]==a[3] && a[3]==a[4])) {
        if(a[0]==a[5]) {
            printf("Elephant\n");
            return 0;
        } else  {
            printf("Bear\n");
            return 0;
        }
    } else printf("Alien\n");
    return 0;
}
