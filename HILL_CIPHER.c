#include <stdio.h>
#include <string.h>

#define MAX 100

void encrypt(char message[], int keyMatrix[3][3], int size) {
    int i, j, k, messageVector[3] = {0}, cipherMatrix[3] = {0};
    int len = strlen(message);
    
    printf("Encrypted message: ");
    for (i = 0; i < len; i += size) {
        for (j = 0; j < size; j++) {
            messageVector[j] = message[i + j] - 'A';
        }

        for (j = 0; j < size; j++) {
            cipherMatrix[j] = 0;
            for (k = 0; k < size; k++) {
                cipherMatrix[j] += keyMatrix[j][k] * messageVector[k];
            }
            cipherMatrix[j] = cipherMatrix[j] % 26;
        }

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

    printf("Enter the message to be encrypted (uppercase letters only): ");
    scanf("%s", message);

    // Pad the message with 'X' if necessary
    int len = strlen(message);
    while (len % size != 0) {
        message[len] = 'X';
        len++;
    }
    message[len] = '\0';

    encrypt(message, keyMatrix, size);

    return 0;
}
