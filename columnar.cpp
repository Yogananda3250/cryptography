#include <stdio.h>
#include <string.h>

void encrypt(char message[], char key[]) {
    int cols = strlen(key);
    int len = strlen(message);
    int rows = (len + cols - 1) / cols;
    char grid[rows][cols];
    int k = 0;

    // Fill the grid row-wise
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            grid[i][j] = (k < len) ? message[k++] : 'X';

    // Output encrypted message column-wise based on key order
    printf("Encrypted: ");
    for (int num = 1; num <= cols; num++) {
        for (int j = 0; j < cols; j++) {
            if (key[j] - '0' == num) {
                for (int i = 0; i < rows; i++) {
                    printf("%c", grid[i][j]);
                }
            }
        }
    }
    printf("\n");
}

void decrypt(char cipher[], char key[]) {
    int cols = strlen(key);
    int len = strlen(cipher);
    int rows = (len + cols - 1) / cols;
    char grid[rows][cols];
    int colLens[cols];
    int k = 0;

    // Determine number of characters per column
    for (int i = 0; i < cols; i++)
        colLens[i] = rows;

    // Fill grid column-wise based on key
    for (int num = 1; num <= cols; num++) {
        for (int j = 0; j < cols; j++) {
            if (key[j] - '0' == num) {
                for (int i = 0; i < rows; i++) {
                    grid[i][j] = cipher[k++];
                }
            }
        }
    }

    // Read message row-wise
    printf("Decrypted: ");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            printf("%c", grid[i][j]);
    printf("\n");
}

int main() {
    int choice;
    char message[200], key[20];

    printf("Enter 1 to Encrypt or 2 to Decrypt: ");
    scanf("%d", &choice);
    getchar(); // Consume newline

    printf("Enter message: ");
    scanf("%[^\n]", message);
    getchar(); // Consume newline

    printf("Enter numeric key (e.g., 3214): ");
    scanf("%s", key);

    if (choice == 1)
        encrypt(message, key);
    else if (choice == 2)
        decrypt(message, key);
    else
        printf("Invalid choice.\n");

    return 0;
}

