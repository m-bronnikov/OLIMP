#include <stdio.h>

char* removeStars(char* s){
    int i = 0;
    for(int j = 0; s[j] != 0; ++j) {
        s[i++] = s[j];
        if(s[j] == '*') {
            i -= 2;
        }
    }

    s[i] = '\0';
    return s;
}


int main() {
    char strbuf[] = "erase*****";
    char* str = strbuf;
    str = removeStars(str);
    printf("%s\n", str);
    return 0;
}
