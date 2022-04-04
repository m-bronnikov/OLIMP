#include <stdbool.h>
#include <stdio.h>

#include <string.h>

#define alphabet_size 26
#define first_alphabet_letter 'a'

bool canConstruct(char * ransomNote, char * magazine){
    int counter[alphabet_size];
    memset(counter, 0, alphabet_size * sizeof(int));

    // count each letter magazine
    while(*magazine != '\0' && ++counter[*(magazine++) - first_alphabet_letter]);

    while(*ransomNote != '\0')
    {
        if(!counter[*(ransomNote++) - first_alphabet_letter]--)
            return false;
    }

    return true;
}


int main()
{
    char *magazine = "aaaaabbbbbbccccceeeeeeeiiiil";
    char *note = "lia";

    printf("%d\n", canConstruct(note, magazine));

    return 0;
}