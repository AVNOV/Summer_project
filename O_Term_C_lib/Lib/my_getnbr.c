int	my_getnbr(char const *str)
{
    int temp = 0;
    int neg = 1;
    int compt = 0;
	
    while (str[compt] != '\0') {
        if (str[compt] == '-') {
            neg = neg * (-1);
        } else if (str[compt] >= '0' || str[compt] <= '9') {
            temp = temp * 10;
            temp = temp + str[compt] - '0';
        }
        compt = compt + 1;
    }
    return (temp * neg);
}
