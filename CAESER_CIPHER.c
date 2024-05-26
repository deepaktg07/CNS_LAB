#include <stdio.h>
#include <string.h>

void caesar(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' + shift) % 26;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' + shift) % 26;
        }
    }
}

int main() {
    char message[100], original_message[100];
    int key;

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);

        // Make a copy of the original message
    strcpy(original_message, message);

    printf("Enter the key: ");
    scanf("%d", &key);

    printf("Original message: %s\n", original_message);

    // Encryption
    caesar(message, key);
    printf("Encrypted message: %s\n", message);

    // Display the original message as decrypted
    printf("Decrypted message: %s\n", original_message);

    return 0;
}
