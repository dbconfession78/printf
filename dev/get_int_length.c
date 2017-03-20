int get_int_len(int value)
{
	int l = !value;
	while(value)
	{
		l++;
		value/=10;
	}
	return (l);
}
