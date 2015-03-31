#include <unistd.h>

int		ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	int i;
	int e;
	int f;
	char is[255] = {0};

	i = 0;
	e = 0;
	f = 0;
	while (s1[i])
	{
		if (ft_strchr(is, s1[i]) == 0)
			is[f] = s1[i], write(1, &s1[i], 1), f++;
		i++;
	}
	while(s2[e])
	{
		if (ft_strchr(is, s2[e]) == 0)
			is[f] = s2[e], write(1, &s2[e], 1), f++;
		e++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
