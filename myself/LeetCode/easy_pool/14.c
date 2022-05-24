char* longestCommonPrefix(char** strs, int strs_size){
    char* base_str = strs[0];

    for(int i = 1; i < strs_size; ++i)
    {   
        int j = 0;
        while(base_str[j] == strs[i][j] && base_str[j] != '\0') ++j;
        base_str[j] = '\0';
    }

    return base_str;
}

int main()
{
    // empty test
    return 0;
}
