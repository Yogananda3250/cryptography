#include <string.h>
#include <ctype.h>

void encrypt(char plaintext[], char key[]) 
{
    int i;
    char ciphertext[100];

    for (i = 0; plaintext[i] != '\0'; ++i) 
	{
        if (isalpha(plaintext[i])) 
		{
            if (islower(plaintext[i])) 
			{
                ciphertext[i] = key[plaintext[i] - 'a'];
            } 
			else 
			{
                ciphertext[i] = toupper(key[plaintext[i] - 'A']);
            }
        } 
		else 
		{ 
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[i] = '\0';
{

    printf ("Encrypted message: %s\n");
}

int main() 
{
    char plaintext[100], key[26];
    int i;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the key (a string of 26 unique characters representing the substitution): ");
    fgets(key, sizeof(key), stdin);

    
    for (i = 0; i < strlen(key); i++) 
	{
        if (key[i] == '\n') 
		{
            key[i] = '\0';
            break;
        }
    }

    
    if (strlen(key) != 26) 
	{
        printf("Invalid key! Key must be a string of 26 unique characters.\n");
        return 1;
    }

    
    for (i = 0; i < 26; i++) 
	{
        if (!isalpha(key[i])) 
		{
            printf("Invalid key! Key must contain only alphabetic characters.\n");
            return 1;
        }
    }

    
    for (i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) 
		{
            if (tolower(key[i]) == tolower(key[j])) 
			{
                printf("Invalid key! Key must contain all unique characters.\n");
                return 1; 
            }
        }
    }

    encrypt(plaintext, key);

    return0;
}
