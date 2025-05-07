#include <stdio.h>
int modInverse(int a) {
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1) return i;
    return -1;
}
int main() {
    char ct[] = "BUEUBUBUEBUBUUUUBUUBUEUUB"; 
    int c1 = 1, p1 = 4, c2 = 20, p2 = 19;    
    int a = ((c2 - c1 + 26) * modInverse((p2 - p1 + 26) % 26)) % 26;
    int b = (c1 - a * p1 + 26 * 26) % 26;
    int a_inv = modInverse(a);
    printf("Decrypted: ");
    for (int i = 0; ct[i]; i++) {
        int y = ct[i] - 'A';
        int x = (a_inv * (y - b + 26)) % 26;
        printf("%c", x + 'A');
    }
    printf("\n");
    return 0;
}
