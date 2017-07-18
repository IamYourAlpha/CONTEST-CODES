#include<stdio.h>

int max_index;
int min_index;
int max_=-999999;
int min_=999999;
int main() {
    int a[3];
    int sum=0;
    int count_one=0;
    for(int i=0; i<3; i++)
        scanf("%d",&a[i]);
    if(a[0]+a[1]+a[2]==3) {
        printf("3");
        return 0;
    }
    for(int i=0; i<3; i++) {
        if(a[i]==1)count_one++;
    }
    for(int i=0; i<3; i++) {
        if(a[i]>max_) {
            max_=a[i];
            max_index=i;
        }
        if(a[i]<min_ && a[i]!=1 ) {
            min_=a[i];
            min_index=i;
        }

    }

    if(count_one==1) {
        if(a[1]==1) {
            printf("%d",(count_one+min_)*a[max_index]);
            return 0;
        }  if(a[0]==1) {
            printf("%d",(1+a[1])*a[2]);
            return 0;
        } if(a[2]==1) {
            printf("%d",(1+a[1])*a[0]);
            return 0;
        }
    }

        if(count_one==2){
            if( (a[0]==1 && a[1]==1) || ( a[1]==1 && a[2]==1) ) {
                printf("%d",2*max_);
               // printf("here");
                return 0;
            }
            else printf("%d",a[0]+a[1]+a[2]);
        }
            else  printf("%d",a[0]*a[1]*a[2]);

//    printf("%d",sum);
        return 0;
    }
