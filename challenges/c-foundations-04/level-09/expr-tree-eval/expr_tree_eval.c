#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
	char	type;
	int		value;
} t_token;

int	ft_atoi(char *str);
int	parse_tokens(t_token *token, char *nptr);
int parse_rpn(t_token *rpn, int size, t_token *token);
void pop_to_rpn(char *ops, int *jdx, t_token *rpn, int *idx);

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	t_token token[512];
	t_token rpn[512];
	int size = parse_tokens(token, argv[1]);
	if (size == -1)
		return 1;
	size = parse_rpn(rpn, size, token);
	if (size == -1)
		return 1;
	int stack[512] = { 0 };
	for (int i = 0, idx = 0; i < size; i++)
	{
		if (rpn[i].type == 'N')
			stack[idx++] = rpn[i].value;
		else
		{
			if (idx < 2)
			{
				printf("Unexpected end\n");
				return 1;
			}
			int b = stack[--idx];
			int a = stack[--idx];
			if (rpn[i].value == '+')
				stack[idx++] = a + b;
			else
				stack[idx++] = a * b;
		}
	}
	printf("%d\n", stack[0]);
}

int parse_rpn(t_token *rpn, int size, t_token *token)
{
	int idx = 0, jdx = 0;
	char ops[256];

	for (int i = 0; i < size; i++)
	{
		if (token[i].type == 'N')
		{
			rpn[idx].type = token[i].type;
			rpn[idx++].value = token[i].value;
		}
		else if (token[i].type == 'P')
		{
			if (token[i].value == '(')
				ops[jdx++] = token[i].value;
			else
			{
				while (jdx > 0 && ops[jdx - 1] != '(')
					pop_to_rpn(ops, &jdx, rpn, &idx);
				if (jdx > 0 && ops[jdx - 1] == '(')
					jdx--;
				else
				{
					printf("Invalid token ')'\n");
					return -1;
				}
			}
		}
		else
		{
			if (token[i].value == '+')
			{
				while (jdx > 0 && ops[jdx - 1] != '(')
					pop_to_rpn(ops, &jdx, rpn, &idx);
			}
			else
			{
				while (jdx > 0 && ops[jdx - 1] != '(' && ops[jdx - 1] != '+')
					pop_to_rpn(ops, &jdx, rpn, &idx);
			}
			ops[jdx++] = token[i].value;
		}
	}
	while (jdx > 0)
	{
		if (ops[jdx - 1] == '(')
		{
			printf("Unexpected end\n");
			return -1;
		}
		else
			pop_to_rpn(ops, &jdx, rpn, &idx);
	}
	return idx;
}

void pop_to_rpn(char *ops, int *jdx, t_token *rpn, int *idx)
{
	*jdx = *jdx - 1;
	rpn[*idx].type = 'O';
	rpn[*idx].value = ops[*jdx];
	*idx = *idx + 1;
}

int parse_tokens(t_token *token, char *nptr)
{
	int idx = 0;

	for (int i = 0; nptr[i]; )
	{
		if (isdigit(nptr[i]))
		{
			token[idx].type = 'N';
			token[idx++].value = ft_atoi(&nptr[i]);
			while (isdigit(nptr[i]))
				i++;
		}
		else if (nptr[i] == '+' || nptr[i] == '*')
		{
			token[idx].type = 'O';
			token[idx++].value = nptr[i];
			i++;
		}
		else if (nptr[i] == '(' || nptr[i] == ')')
		{
			token[idx].type = 'P';
			token[idx++].value = nptr[i];
			i++;
		}
		else
		{
			printf("Invalid token '%c'\n", nptr[i]);
			return -1;
		}
	}
	if (idx == 0)
	{
		printf("Unexpected end\n");
		return -1;
	}
	return idx;
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	sum;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	sum = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return (sum * sign);
}
