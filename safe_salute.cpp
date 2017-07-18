#include<stdio.h>

long long a[500][500];

void pascal(){
   	a[1][1] = 1;
	a[1][0] = 1;
    a[0][0]=1;
	for (int i = 2; i <= 450; i++) {
		a[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}

}


int main(){
    int n;
    bool ok=0;
    pascal();
    while(scanf("%d",&n)!=EOF){
            if(ok!=0) printf("\n");
            printf("%d\n",a[2*n][n]-a[2*n][n+1]);
            ok=1;
    }
    return 0;
}
