#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

void ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

void ft_bzero(char *s, int n)
{
	int i;

	i = 0;
	if (s)
	{
		while(i < n)
		{
			s[i] = 0;
			i++;
		}
	}
}

int     ft_strcmp(char  *s1, char *s2)
{
    while (*s1 == *s2)
    {
        if (*s1 == 0)
            return (0);
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

int get_mode(char **n1, char **n2)
{
	char *tmp;

	if ((ft_strlen(*n1) > ft_strlen(*n2)) || (ft_strlen(*n1) == ft_strlen(*n2) && ft_strcmp(*n1, *n2) > 0))
		return (0);
	/* Place the grater number in n1*/ 
	else if ((ft_strlen(*n1) < ft_strlen(*n2)) || (ft_strlen(*n1) == ft_strlen(*n2) && ft_strcmp(*n1, *n2) < 0))
	{
		tmp = *n2;
		*n2 = *n1;
		*n1 = tmp;
		return (1);
	}
	return (0);
}

void do_op(char *result, int resp, int p1, int p2, char *n1, char *n2, int mode)
{
	int unit, dec, a, b;
	
	unit = resp;
	dec = resp - 1;
	p1 < 0 ? (a = 0) : (a = n1[p1] - '0');
	p2 < 0 ? (b = 0) : (b = n2[p2] - '0');
	if (mode) /* we need do addition */
	{
		result[unit] = ((a + b) % 10);
		result[dec] = ((a + b) / 10);
	}
	else /* substract it */
	{
		b += result[unit];
		if (a >= b)
			result[unit] = a - b;
		else
		{
			a += 10;
			result[unit] = a - b;
			result[dec] = 1;
		}	
	}
}

void print_res(char *result, int size)
{
	int i;
	char c;

	i = 0;
	while(result[i] == 0)
		i++;
	while (i < size)
	{
		c = result[i] + '0';
		write(1, &c, 1);
		i++;
	}	
}

void infin_add(char *n1, char *n2, int mode)
{
	char *result;
	int size;
	int p1, p2, resp;
	
	size = ft_strlen(n1) + ft_strlen(n2);
	result = (char*)malloc(sizeof(char) * (size + 1));
	ft_bzero(result, size);
	p1 = ft_strlen(n1)  - 1;
	p2 = ft_strlen(n2) - 1;
	resp = p1 + p2 + 1;
	while (p1 >= 0 || p2 >= 0)
	{
		do_op(result, resp, p1, p2, n1, n2, mode);
		resp--, p1--, p2--;
	}
	print_res(result, size);
}

void wrap(char *n1, char *n2)
{
	int mode;

	mode = 1;
	if (*n1 == '0' && *n2 == '0')
	{
		ft_putstr("0");
		return;
	}
	if (*n1 == '-' && *n2 == '-')
	{
		n1++;
		n2++;
		ft_putstr("-");
	}
/* if sign is not egual */
	else if (*n2 == '-')
	{
		n2++;
		if (get_mode(&n1, &n2))
			ft_putstr("-");
		mode = 0;
	}
	else if (*n1 == '-')
	{
		n1++;
		if (!get_mode(&n1, &n2))
			ft_putstr("-");
		mode = 0;
	}
	infin_add(n1, n2, mode);	
}

int main(int argc, char **argv)
{
	if (argc == 3)
		wrap(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
