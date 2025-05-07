#include <stdio.h>
#include <string.h>

void encryptRailFence(char *msg) {
    int len = strlen(msg);
    char rail1[100], rail2[100];
    int k1 = 0, k2 = 0;

    // Divide message characters into two rails
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0)
            rail1[k1++] = msg[i];
        else
            rail2[k2++] = msg[i];
    }

    rail1[k1] = '\0';
    rail2[k2] = '\0';

    // Concatenate the two rails
    printf("Encrypted: %s%s\n", rail1, rail2);
}

void decryptRailFence(char *cipher) {
    int len = strlen(cipher);
    char plain[100];
    int mid = (len + 1) / 2; // Middle index for odd-length messages

    int i = 0, j = mid, k = 0;

    // Interleave characters from both halves
    while (i < mid || j < len) {
        if (i < mid)
            plain[k++] = cipher[i++];
        if (j < len)
            plain[k++] = cipher[j++];
    }

    plain[k] = '\0';
    printf("Decrypted: %s\n", plain);
}

int main() {
    char message[100];
    int choice;

    printf("Enter 1 to Encrypt or 2 to Decrypt: ");
    scanf("%d", &choice);
    getchar(); // Consume newline after scanf

    printf("Enter message: ");
    scanf("%[^\n]", message);

    if (choice == 1)
        encryptRailFence(message);
    else if (choice == 2)
        decryptRailFence(message);
    else
        printf("Invalid choice.\n");

    return 0;
}

