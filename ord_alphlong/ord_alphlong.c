#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
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

int		is_alpha(char c)
{
	int i;

	(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ?\
		  (i = 1) : (i = 0);
	return (i);
}

int		is_digit(char c)
{
	int i;

	(c >= '0' && c <= '9' ? (i = 1) : (i = 0));
	return (i);
}

int		ft_alcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (*str1 && *str2 && i == 0)
	{
		if ((is_alpha(*str1) && is_alpha(*str2)))
		{
			if (*str1 != *str2)
			{
				if (*str1 >= 'a' && *str1 <= 'z' && *str2 >= 'A' && *str2 <= 'Z')
					*str1 - 32 != *str2 ? (i = *str1 - 32 - *str2) : (i = i);
				else if (*str1 >= 'A' && *str1 <= 'Z' && *str2 >= 'a' && *str2 <= 'z')
					*str1 + 32 != *str2 ? (i = *str1 + 32 - *str2) : (i = i);
				else
					i = *str1 - *str2;
			}
		}
		str1++;
		str2++;
	}
	return (i);
}

void    ft_str_to_tab(char **tab, char *str)
{
	int i = 0;
	int j;

	while (*str)
	{
		j = 0;
		while ((is_alpha(*str) || (is_digit(*str))) && *str)
			tab[i][j] = *str, j++, str++;
		tab[i][j] = '\0';
		while (!(is_alpha(*str)) && *str)
			str++;
		i++;
	}
	tab[i] = NULL;
}

void    ft_switch_place(char **tab, int p1, int p2)
{
	char *tmp;

	tmp = tab[p1];
	tab[p1] = tab[p2];
	tab[p2] = tmp;
}

void	sort_alph(char **tab)
{
	int i;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		while (tab[i + 1] && (ft_alcmp(tab[i], tab[i + 1])) > 0)
		{
			ft_switch_place(tab, i, i + 1);
			i = 0;
		}
		i++;
	}
}

void	sort_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		while (tab[i + 1] && (ft_strlen(tab[i]) > ft_strlen(tab[i + 1])))
		{
			ft_switch_place(tab, i, i + 1);
			i = 0;
		}
		i++;
	}
}

void	ft_ord(char *str)
{
	char **tab;
	int		i;
	int		e;

	i = 0;
	e = 0;
	tab = (char**)malloc(sizeof(char*) * 100);
	while (i < 100)
	{
		tab[i] = (char*)malloc(sizeof(char) * 1000);
		i++;
	}
	ft_str_to_tab(tab, str);
	sort_alph(tab);
	sort_len(tab);
	i = 0;
	e = ft_strlen(tab[i]);
	while (tab[i])
	{
		ft_putstr(tab[i]);
		i++;
		if (tab[i] && ft_strlen(tab[i]) != e)
		{
			ft_putchar('\n');
			e = ft_strlen(tab[i]);
		}
		else if (tab[i])
			ft_putchar(' ');
	}
}
int main(int argc, char **argv)
{
	if (argc == 2)
		ft_ord(argv[1]);
	ft_putchar('\n');
	return (0);
}
