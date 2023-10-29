#include <stdio.h>

int main() {
    printf("Zweierpotenz bis: \n");
    int myNum;
    scanf("%d", &myNum);
    zweierpotenz(myNum);

    printf("END");
}

int zweierpotenz(int n) {
    int m = 0;
    int p = 1;
    //int n = 10; //Beispiel

    while(m <= n) {
        printf("2^%d ist %d \n", m, p); //%d = Platzhalter
        m = m + 1;
        p = p * 2;
    }
}

// clang –Wall –std=c11 zweierpotenz.c –o zweierpotenz
// Ausgabe dann mit ./ zweierpotenz