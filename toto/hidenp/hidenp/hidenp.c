#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	hidenp(char *s1, char *s2)
{
	int i;
	int e;

	i = 0;
	e = 0;
	if (s1 && s2)
	{
		if (*s1 == '\0')
			write(1, "1", 1);
		while (s2[i])
		{
			if (s1[e] == s2[i])
				e++;
			if (e == ft_strlen(s1))
			{
				write(1 ,"1", 1);
				return ;
			}
			i++;
		}
		write(1, "0", 1);
	}
}


int		main(int ac, char **av)
{
	if (ac == 3)
		hidenp(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
