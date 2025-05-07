#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100], result[100];
    int i, j, klen, choice;

    // Get user choice
    printf("Enter 1 to Encrypt or 2 to Decrypt: ");
    scanf("%d", &choice);
    getchar(); // Consume newline after scanf

    // Get text (plaintext or ciphertext)
    printf("Enter text: ");
    scanf("%s", text);

    // Get key
    printf("Enter key: ");
    scanf("%s", key);

    klen = strlen(key);

    for (i = 0, j = 0; text[i] != '\0'; i++) {
        char t = tolower(text[i]);
        char k = tolower(key[j % klen]);

        if (t >= 'a' && t <= 'z') {
            if (choice == 1) {
                // Encrypt
                result[i] = ((t - 'a' + (k - 'a')) % 26) + 'a';
            } else if (choice == 2) {
                // Decrypt
                result[i] = ((t - 'a' - (k - 'a') + 26) % 26) + 'a';
            } else {
                printf("Invalid choice.\n");
                return 1;
            }
            j++;
        } else {
            // Leave non-letter characters unchanged
            result[i] = text[i];
        }
    }

    result[i] = '\0';

    if (choice == 1)
        printf("Encrypted text: %s\n", result);
    else
        printf("Decrypted text: %s\n", result);

    return 0;
}

