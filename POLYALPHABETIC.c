#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereCipher(char message[], char key[], char result[], int encrypt) {
    int msgLen = strlen(message);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < msgLen; i++) {
        if (isalpha(message[i])) {
            char base;
            char shift = tolower(key[j % keyLen]) - 'a';
            if (islower(message[i])) {
                base = 'a';
            } else {
                base = 'A';
            }
            if (encrypt) {
                result[i] = ((message[i] - base + shift) % 26) + base;
            } else {
                result[i] = ((message[i] - base - shift + 26) % 26) + base;
            }
            j++;
        } else {
            result[i] = message[i];
        }
    }
    result[msgLen] = '\0';
}

int main() {
    char message[1000], key[100], encryptedMessage[1000], decryptedMessage[1000];

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove the newline character from input

    printf("Enter the encryption key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove the newline character from input

    // Encrypt the message
    vigenereCipher(message, key, encryptedMessage, 1);
    printf("Encrypted Message: %s\n", encryptedMessage);

    // Decrypt the encrypted message
    vigenereCipher(encryptedMessage, key, decryptedMessage, 0);
    printf("Decrypted Message: %s\n", decryptedMessage);

    return 0;
}
