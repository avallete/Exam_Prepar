#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i]), i++;
}

int	is_word(char c)
{
	if (c != ' ' && c != '\t')
		return (1);
	return (0);
}

void	rstr_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] && (!is_word(str[i])))
			i++;
		while (str[i] && is_word(str[i]))
		{
			str[i] >= 'A' && str[i] <= 'Z' ? (str[i] += 32) : (str[i] = str[i]);
			i++;
		}
		str[i - 1] >= 'a' && str[i - 1] <= 'z' ? (str[i - 1] -= 32) : (str[i- 1] = str[i - 1]);
		i++;
	}
	ft_putstr(str);
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			rstr_capitalizer(argv[i]), i++;
			ft_putchar('\n');
		}
	}
	else
			ft_putchar('\n');
	return (0);
}
