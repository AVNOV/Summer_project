
int my_compute_square_root(int nb)
{
    int temp = 0;

	while (my_compute_power_rec(temp, 2) < nb) {
		temp++;
	}
	return (temp);
}
