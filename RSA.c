#include <stdio.h>

long long int gcd(long long int a, long long int b) {
    while (b) {
        long long int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long int modInverse(long long int e, long long int phi) {
    long long int t, q, x0 = 0, x1 = 1, m0 = phi;
    if (phi == 1) return 0;
    while (e > 1) {
        q = e / phi;
        t = phi;
        phi = e % phi;
        e = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    return x1 < 0 ? x1 + m0 : x1;
}

long long int power(long long int base, long long int exp, long long int modulus) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp /= 2;
    }
    return result;
}
int main() {
    long long int p, q, e, n, phi, d, plaintext, ciphertext, decryptedtext;
    
    printf("Enter p: ");
    scanf("%lld", &p);
    printf("Enter q: ");
    scanf("%lld", &q);
    printf("Enter e: ");
    scanf("%lld", &e);
    
    n = p * q;
    phi = (p - 1) * (q - 1);
    d = modInverse(e, phi);

    printf("Enter plaintext: ");
    scanf("%lld", &plaintext);

    ciphertext = power(plaintext, e, n);
    printf("Encrypted message: %lld\n", ciphertext);

    decryptedtext = power(ciphertext, d, n);
    printf("Decrypted message: %lld\n", decryptedtext);

    return 0;
}
