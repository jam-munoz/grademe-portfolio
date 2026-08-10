int	valid_time(int hh, int mm, int ss)
{
	if (ss > 59 && !(ss == 60 && hh == 23 && mm == 59))
		return 0;
	if (hh > 23 || mm > 59 || hh < 0 || mm < 0 || ss < 0)
		return 0;
	else return 1;
}
