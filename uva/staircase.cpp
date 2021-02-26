
#include <stdio.h>

long ways [7500];
void count ()
{

    int coin [] = { 50, 25, 10, 5, 1 };

    ways [0] = 1;

    for ( int i = 0; i < 5; i++ ) {
        for ( int j = coin [i]; j < 100; j++ ){
            ways [j] += ways [j - coin [i]];
            printf("%d\n",ways[j]);}
    }
}

int main ()
{
    count ();
    int n;
    while ( scanf ("%d", &n) != EOF )
        printf("%ld\n", ways [n]);

    return 0;

}
