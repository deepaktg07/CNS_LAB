#include <stdio.h>
#include <string.h>

void encrypt(char pt[], char key[], char ct[]) {
    int i;
    for(i = 0; i < strlen(pt); i++) {
        if(pt[i] == ' ')
            ct[i] = ' ';
        else
            ct[i] = key[pt[i] - 'A'];
    }
    ct[i] = '\0';
}

void decrypt(char ct[], char key[], char pt[]) {
    int i, j;
    for(i = 0; i < strlen(ct); i++) {
        if(ct[i] == ' ')
            pt[i] = ' ';
        else {
            for(j = 0; j < 26; j++) {
                if(ct[i] == key[j]) {
                    pt[i] = 'A' + j;
                    break;
                }
            }
        }
    }
    pt[i] = '\0';
}

int main() {
    char pt[100], key[27], ct[100], decrypted[100];
    
    printf("Enter plaintext: ");
    fgets(pt, sizeof(pt), stdin);
    pt[strcspn(pt, "\n")] = '\0'; // Remove newline

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline

    encrypt(pt, key, ct);
    printf("Ciphertext: %s\n", ct);

    decrypt(ct, key, decrypted);
    printf("Decrypted plaintext: %s\n", decrypted);

    return 0;
}
