#include <stdio.h>
#include <string.h>

#define MAX 100

void encrypt(char message[], int keyMatrix[3][3], int size) {
    int i, j, k, messageVector[3] = {0}, cipherMatrix[3] = {0};
    int len = strlen(message);
    int idx = 0;

    printf("Encrypted message: ");
    for (i = 0; i < len; ) {
        // Reset messageVector
        for (j = 0; j < size; j++) {
            messageVector[j] = 0;
        }
        
        // Fill messageVector, skipping spaces
        for (j = 0; j < size && i < len; ) {
            if (message[i] != ' ') {
                messageVector[j] = message[i] - 'A';
                j++;
            }
            i++;
        }

        // Encrypt using the key matrix
        for (j = 0; j < size; j++) {
            cipherMatrix[j] = 0;
            for (k = 0; k < size; k++) {
                cipherMatrix[j] += keyMatrix[j][k] * messageVector[k];
            }
            cipherMatrix[j] = cipherMatrix[j] % 26;
        }

        // Print the ciphered text
        for (j = 0; j < size; j++) {
            printf("%c", cipherMatrix[j] + 'A');
        }
    }
    printf("\n");
}

int main() {
    char message[MAX];
    int keyMatrix[3][3], size, i, j;

    printf("Enter the size of the key matrix (2 or 3): ");
    scanf("%d", &size);

    if (size != 2 && size != 3) {
        printf("Invalid key size. Only 2x2 and 3x3 key matrices are supported.\n");
        return 1;
    }

    printf("Enter the elements of the %dx%d key matrix:\n", size, size);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &keyMatrix[i][j]);
        }
    }

    printf("Enter the message to be encrypted (uppercase letters and spaces only): ");
    scanf(" %[^\n]s", message);

    // Pad the message with 'X' if necessary
    int len = strlen(message);
    int nonSpaceCount = 0;

    // Count non-space characters
    for (i = 0; i < len; i++) {
        if (message[i] != ' ') {
            nonSpaceCount++;
        }
    }

    while (nonSpaceCount % size != 0) {
        message[len] = 'X';
        len++;
        nonSpaceCount++;
    }
    message[len] = '\0';

    encrypt(message, keyMatrix, size);

    return 0;
}
