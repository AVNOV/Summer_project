
char *my_revstr(char *str)
{
    int start = 0;
    int end = 0;
    char c = 0;
    
    end = my_strlen(str) - 1;
    while (start < end) {
        c = str[start];
        str[start] = str[end];
        str[end] = c;
        start++;
        end--;
    }
    return (str);
}
