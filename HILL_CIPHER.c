#include <stdio.h>
#include <string.h>
#include <math.h>

#define M 10

int det(int a, int b, int c, int d) { 
    return a * d - b * c; 
}

int inv(int a, int m) {
    for (int i = 1; i < m; i++)
        if ((a * i) % m == 1)
            return i;
    return -1;
}

void enc(char m[], int k[][M], int s) {
    int l = strlen(m), p = ceil(l / (float) s) * s, a[p], e[p], i, j, t;
    for (i = 0; i < l; i++) 
        a[i] = m[i] - 'A';
    for (; i < p; i++) 
        a[i] = 23;
    for (i = 0; i < p; i += s) {
        for (j = 0; j < s; j++) {
            t = 0;
            for (int x = 0; x < s; x++) 
                t += k[j][x] * a[i + x]; 
            e[i + j] = t % 26;
        }
    }
    printf("Encrypted message: ");
    for (i = 0; i < p; i++) 
        printf("%c", (char) (e[i] + 'A'));
    printf("\n");
}

int main() {
    int s, k[M][M], i, j;
    char m[1000];
    printf("Enter key size (max 10): ");
    scanf("%d", &s);
    printf("Enter key matrix elements:\n");
    for (i = 0; i < s; i++) {
        for (j = 0; j < s; j++) {
            scanf("%d", &k[i][j]);
        }
    }
    if (det(k[0][0], k[0][1], k[1][0], k[1][1]) == 0) {
        printf("Key matrix is not invertible. Please enter a valid key matrix.\n");
        return 1;
    }
    printf("Enter message to encrypt (uppercase only): ");
    scanf("%s", m);
    enc(m, k, s);
    return 0;
}
