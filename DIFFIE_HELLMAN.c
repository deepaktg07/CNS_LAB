#include <math.h>
#include <stdio.h>

long long int power(long long int a, long long int b, long long int p) {
    if (b == 1)
        return a % p;
    else
        return ((long long int)pow(a, b) % p);
}

int main() {
    long long int p, g, x, a, y, b, ka, kb;

    printf("Enter the value of p (Prime Number): ");
    scanf("%lld", &p);

    printf("Enter the value of g (A generator of p): ");
    scanf("%lld", &g);

    printf("Enter the value of a private key for Alice: ");
    scanf("%lld", &a);

    printf("Enter the value of a private key for Bob: ");
    scanf("%lld", &b);

    x = power(g, a, p);
    y = power(g, b, p);

    ka = power(y, a, p);
    kb = power(x, b, p);

    printf("Secret key for Alice is : %lld\n", ka);
    printf("Secret key for Bob is : %lld\n", kb);

    return 0;
}
