int my_strncmp(char const *s1, char const *s2, int nb)
{
    int i = 0;
	
    while (i <= nb && s1[i] && s1[i] == s2[i]) {
        ++i;
    }
    return (s1[i] - s2[i]);
}
