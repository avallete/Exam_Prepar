#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	rotone(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] >= 'a' && str[i] < 'z' ? (str[i] += 1) : 0;
		str[i] >= 'A' && str[i] < 'Z' ? (str[i] += 1) : 0;
		str[i] == 'z' ? (str[i] = 'a') : 0;
		str[i] == 'Z' ? (str[i] = 'A') : 0;
		i++;
	}
	write(1, str, ft_strlen(str));
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	write(1, "\n", 1);
	return (0);
}
