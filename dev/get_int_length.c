/**
 * get_int_len - finds the length of an int
 * @value: input number
 * Return: the length of the number
 */
int get_int_len(int value)
{
	int l = !value;

	while (value)
	{
		l++;
		value /= 10;
	}
	return (l);
}
