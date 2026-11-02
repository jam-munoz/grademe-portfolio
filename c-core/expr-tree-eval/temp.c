
/*l20	while (*nptr != '\0')
	{
		if (check_bracket(nptr))
		{
			p = ft_strchr(nptr, '(') + 1;
			if (ft_isdigit(*p))
			{
				res = ft_atoi(p);
				while (ft_isdigit(*p))
					p++;
				if (ft_isop(*p))
				{
					if (*p == '+')
					{
						res += ft_atoi(p);
					}
					else
					{
						p++;
						res *= ft_atoi(p);
					}
				}
			}
			else 
			{
				printf("Error\n");
				return 1;
			}
		}
		if (ft_isdigit(*nptr))
		{
			res = ft_atoi(nptr);
			while (ft_isdigit(*nptr))
				nptr++;
		}
		else if (ft_isop(*nptr))
		{

			if (*nptr == '+')
			{
				res += ft_atoi(nptr);
			}
			else
			{
				nptr++;
				res *= ft_atoi(nptr);
			}
		}
		nptr++;
	}*/