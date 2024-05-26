#include <stdio.h>
#include <string.h>

int main() {
    char pt[100];
    printf("Enter the text: \n");
    fgets(pt, sizeof(pt), stdin);
    pt[strcspn(pt, "\n")] = '\0'; // Remove the newline character

    char key[100];
    printf("Enter the key: \n");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove the newline character

    char ct[100], decrypted[100];
    int i, j;

    for(i = 0; i < strlen(pt); i++) {
        if(pt[i] == ' ') {
            ct[i] = ' ';
        }
        else {
            for(j = 0; j < 26; j++) {
                if(pt[i] == key[j]) {
                    ct[i] = key[(j + 1) % 26];
                    break;
                }
            }
        }
    }
    ct[i] = '\0';

    printf("Plain text: %s\n", pt);
    printf("Cipher text: %s\n", ct);

    for(i = 0; i < strlen(ct); i++) {
        if(ct[i] == ' ') {
            decrypted[i] = ' ';
        }
        else {
            for(j = 0; j < 26; j++) {
                if(ct[i] == key[j]) {
                    decrypted[i] = key[(j - 1 + 26) % 26];
                    break;
                }
            }
        }
    }
    decrypted[i] = '\0';
    printf("Decrypted plain text: %s\n", decrypted);
    return 0;
}
