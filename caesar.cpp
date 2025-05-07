#include <stdio.h>

int main() {
    char ch;
    int key, choice;

    printf("Enter key (1-25): ");
    scanf("%d", &key);
    printf("Enter 1 to Encrypt or 2 to Decrypt: ");
    scanf("%d", &choice);
    getchar(); 

    printf("Enter message (CAPITAL letters only, end with #):\n");

    while ((ch = getchar()) != '#') {
        if (ch >= 'A' && ch <= 'Z') {
            if (choice == 1) {
                ch = ((ch - 'A' + key) % 26) + 'A';
            } else if (choice == 2) {
                ch = ((ch - 'A' - key + 26) % 26) + 'A';
            }
            putchar(ch);
        } else {
            putchar(ch);
        }
    }

    printf("\n");
    return 0;
}

