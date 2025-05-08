#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "53†‡‡305)6*;4826)4‡.)4‡;806*;48‡60))85;]8‡*‡‡*8\
3(88)†;46(;88*96?8)†;(485);5*2:&(4956*2(5*-4)8‡8*;4069285\
);6†8)4‡‡;1(!9;48081;8:8‡1;48‡85;4)485†528806*81(!9;48;(88;4(!\
?34;48)4‡;161;:188;‡?;";
    
    int freq[128] = {0};

    // Count frequency of each character
    for (int i = 0; text[i]; i++) {
        freq[(int)text[i]]++;
    }

    // Display frequencies
    printf("Character Frequency:\n");
    for (int i = 0; i < 128; i++) {
        if (freq[i] > 0 && (i > 32 && i < 127)) // printable characters
            printf("%c: %d\n", i, freq[i]);
    }

    return 0;
}
