#include <stdio.h>
#include <ctype.h>

char decrypt(char c) {
    switch (toupper(c)) {
        case 'A': return 'N'; case 'B': return 'I'; case 'C': return 'G'; case 'D': return 'W';
        case 'E': return 'T'; case 'F': return 'C'; case 'G': return 'O'; case 'H': return 'E';
        case 'I': return 'Y'; case 'J': return 'S'; case 'K': return 'M'; case 'L': return 'D';
        case 'O': return 'V'; case 'Q': return '.'; case 'R': return 'E'; case 'S': return 'A';
        case 'T': return 'R'; case 'U': return 'E'; case 'W': return 'O'; case 'X': return 'U';
        case 'Y': return 'S'; case 'Z': return 'V';
        default: return c;
    }
}

int main() {
    char ciphertext[] = "KXJEY";
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        printf("%c", decrypt(ciphertext[i]));
    }
    printf("\n");
    return 0;
}
