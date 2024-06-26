#include <math.h>
#include <stdio.h>

long long int power(long long int a, long long int b, long long int P) {
    if (b == 1)
        return a % P;
    else
        return ((long long int)pow(a, b) % P);
}

int main() {
    long long int P, G, x, a, y, b, ka, kb;

    printf("Enter the value of P (Prime Number): ");
    scanf("%lld", &P);

    printf("Enter the value of G (A generator of P): ");
    scanf("%lld", &G);

    printf("Enter the value of a private key for Alice: ");
    scanf("%lld", &a);

    printf("Enter the value of a private key for Bob: ");
    scanf("%lld", &b);

    x = power(G, a, P);
    y = power(G, b, P);

    ka = power(y, a, P);
    kb = power(x, b, P);

    printf("Secret key for Alice is : %lld\n", ka);
    printf("Secret key for Bob is : %lld\n", kb);

    return 0;
}
