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

int ft_hidenp(char *str1, char *str2)
{
	if (*str1 == '\0' && *str2 == '\0')
	{
		ft_putchar('1');
		return (1);
	}
	while (*str2!= '\0')
	{
		if (*str2 == *str1)
			str1++;
		if (*str1 == '\0')
		{
			ft_putchar('1');
			return (1);
		}
		str2++;
	}
	ft_putchar('0');
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_hidenp(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
