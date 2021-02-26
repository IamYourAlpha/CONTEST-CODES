#include <stdio.h>
using namespace std;

int m, board[100020];
char text[100020];

void preprocess() {
    int i = 0, j = -1;
    board[0] = -1;
    while (i < m) {
        while (j >= 0 && text[m - i - 1] != text[m - j - 1]) // search for reversed input in original
            j = board[j]; // to find the start index of matching then print chars before this index
        i++;                  // in reserved order
        j++;
        board[i] = j;
    }
}

int kmp() {
    int i = 0, j = 0;
    while (i < m) {
        while (j >= 0 && text[i] != text[m - j - 1])
            j = board[j];
        i++;
        j++;
    }
    return i - j;
}

void get() {
    while (1) {
        text[0] = 0;
        scanf("%s", text);
        m = 0;
        while (text[m]) {
            m++;
        }
        if (m == 0)
            break;
        preprocess();
        int index = kmp();
        printf("%s", text);
        for (int i = index - 1; i >= 0; i--)
            printf("%c", text[i]);
        printf("\n");
        printf("%d\n",index-1);

    }
}

int main() {
    get();
    return 0;
}
