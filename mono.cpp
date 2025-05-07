#include <stdio.h>
#include <string.h>

int main() 
{
    char msg[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char result[100];
    int choice;

    printf("Enter 1 to Encrypt or 2 to Decrypt: ");
    scanf("%d", &choice);
    getchar(); // To consume the newline after scanf

    printf("Enter message (CAPITAL letters only): ");
    fgets(msg, sizeof(msg), stdin);

    // Remove trailing newline if present
    size_t len = strlen(msg);
    if (msg[len - 1] == '\n') {
        msg[len - 1] = '\0';
    }

    if (choice == 1) {
        // Encryption
        for (int i = 0; msg[i] != '\0'; i++) {
            if (msg[i] >= 'A' && msg[i] <= 'Z')
                result[i] = key[msg[i] - 'A'];
            else
                result[i] = msg[i]; // Keep non-letter characters unchanged
        }
    } else if (choice == 2) {
        // Decryption
        for (int i = 0; msg[i] != '\0'; i++) {
            if (msg[i] >= 'A' && msg[i] <= 'Z') {
                for (int j = 0; j < 26; j++) {
                    if (msg[i] == key[j]) {
                        result[i] = 'A' + j;
                        break;
                    }
                }
            } else {
                result[i] = msg[i];
            }
        }
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    result[strlen(msg)] = '\0'; // Null-terminate the result

    printf("Result: %s\n", result);

    return 0;
}


