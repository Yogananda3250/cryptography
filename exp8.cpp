#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char key[] = "CIPHER", cipher[26], used[26] = {0}, ch;
    char plain[] = "HELLO WORLD";
    int i, j = 0;

    // Build cipher alphabet
    for (i = 0; key[i]; i++) {
        ch = toupper(key[i]);
        if (!used[ch - 'A']) {
            cipher[j++] = ch;
            used[ch - 'A'] = 1;
        }
    }
    for (ch = 'A'; ch <= 'Z'; ch++)
        if (!used[ch - 'A']) cipher[j++] = ch;

    // Encrypt
    printf("Encrypted: ");
    for (i = 0; plain[i]; i++) {
        ch = toupper(plain[i]);
        if (isalpha(ch)) printf("%c", cipher[ch - 'A']);
        else printf("%c", plain[i]);
    }
    printf("\n");
    return 0;
}
