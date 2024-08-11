#include <stdio.h>
#include <string.h>

#define MAX 100

void encrypt(char message[], int keyMatrix[2][2], int size) {
    int i, j, k, messageVector[2] = {0}, cipherMatrix[2] = {0};
    int len = strlen(message);
    
    printf("Encrypted message: ");
    for (i = 0; i < len; i += size) {
        for (j = 0; j < size; j++) {
            if (message[i + j] == ' ') {
                messageVector[j] = 0; // Handle spaces
            } else {
                messageVector[j] = message[i + j] - 'A';
            }
        }

        for (j = 0; j < size; j++) {
            cipherMatrix[j] = 0;
            for (k = 0; k < size; k++) {
                cipherMatrix[j] += keyMatrix[j][k] * messageVector[k];
            }
            cipherMatrix[j] = cipherMatrix[j] % 26;
        }

        for (j = 0; j < size; j++) {
            if (message[i + j] == ' ') {
                printf(" ");
            } else {
                printf("%c", cipherMatrix[j] + 'A');
            }
        }
    }
    printf("\n");
}

int main() {
    char message[MAX];
    int keyMatrix[2][2], size, i, j;

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

    printf("Enter the message to be encrypted (uppercase letters and spaces): ");
    scanf(" %[^\n]", message);  // Read entire line including spaces

    // Remove spaces and handle padding
    int len = strlen(message);
    char paddedMessage[MAX];
    int pos = 0;

    for (i = 0; i < len; i++) {
        if (message[i] != ' ') {
            paddedMessage[pos++] = message[i];
        }
    }
    
    while (pos % size != 0) {
        paddedMessage[pos++] = 'X';
    }
    paddedMessage[pos] = '\0';

    encrypt(paddedMessage, keyMatrix, size);

    return 0;
}
