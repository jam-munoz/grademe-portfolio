int isleap(int year);

int	days_in_month(int year, int month)
{
	if (month < 1 || month > 12)
		return -1;

	switch(month)
	{
		case 4: case 6: case 9: case 11: return 30;
		case 2: if(isleap(year)) 
					return 29; 
				else 
					return 28;
		default: return 31; 
	}
}

int isleap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}