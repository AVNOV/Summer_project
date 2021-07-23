int my_str_islower(char *str)
{
    while (*str != '\0') {
        if (*str < 'a' || 'z' < *str )
	        return (0);
        ++str;
    }
    return (1);
}
