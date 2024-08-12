#include <stdio.h>

// Function to find d such that (e * d) % phi = 1
long long int findD(long long int e, long long int phi) {
    long long int d;
    for (d = 1; d < phi; d++) {
        if ((e * d) % phi == 1) {
            return d;
        }
    }
    return -1; // Indicates no valid d found
}

long long int power(long long int base, long long int exp, long long int modulus) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2 != 0) result = (result * base) % modulus;
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
    d = findD(e, phi);

    if (d == -1) {
        printf("No valid d found.\n");
        return 1;
    }

    printf("The value of d is: %lld\n", d);

    printf("Enter plaintext: ");
    scanf("%lld", &plaintext);

    ciphertext = power(plaintext, e, n);
    printf("Encrypted message: %lld\n", ciphertext);

    decryptedtext = power(ciphertext, d, n);
    printf("Decrypted message: %lld\n", decryptedtext);

    return 0;
}
