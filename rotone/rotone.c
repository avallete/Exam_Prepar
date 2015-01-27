#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str + i)
		i++;
	return (i);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i]), i++;
}

void ft_rotone(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			(str[i] >= 'A' && str[i] < 'Z') || (str[i] >= 'a' && str[i] < 'z') ? str[i] += 1 :\
			str[i] == 'Z' ? (str[i] = 'A') : str[i] == 'z' ? (str[i] = 'a') : (str[i] += 0);
			i++;
		}
	}

}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rotone(argv[1]);
		ft_putstr(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
