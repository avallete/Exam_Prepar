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
	{
		if (str[i] != 127)
			ft_putchar(str[i]);
		i++;
	}
}

void kill_dbl(char *str)
{
	int i = 0;
	int e = 0;

	while (str[i] != '\0')
	{
		e = i + 1;
		while (str[e] != '\0')
		{
			if (str[e] == str[i])
				str[e] = 127;
			e++;
		}
		i++;
	}
}

int ft_union(char *str1, char *str2)
{
	int i = 0;
	int e = 0;

	kill_dbl(str1);
	kill_dbl(str2);
	while (str1[i] != '\0')
	{
		e = 0;
		while (str2[e] != '\0')
		{
			if (str2[e] == str1[i])
				str2[e] = 127;
			e++;
		}
		i++;
	}
	ft_putstr(str1);
	ft_putstr(str2);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
