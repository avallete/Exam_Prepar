#include <unistd.h>
#include <stdlib.h>

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

void ft_switch(char **tab, int p1, int p2)
{
	char *tmp;

	if (p1 >= 0 && p2 >= 0)
	{
	tmp = tab[p1];
	tab[p1] = tab[p2];
	tab[p2] = tmp;
	}
}


int	is_word(char c)
{
	if (c != ' ' && c != '\t')
		return (1);
	return (0);
}

void	alloc_tab(char **tab, char *str)
{
	int j;
	int e;
	int i;

	j = 0;
	i = 0;
	while (str[i])
	{
		e = 0;
		while (str[i] && is_word(str[i]))
			tab[j][e] = str[i], e++, i++;
		tab[j][e] = '\0';
		while (str[i] && (!(is_word(str[i]))))
			i++;
		j++;
	}
	tab[j] = NULL;
}

void	rev_tab(char **tab)
{
	int i = 0;
	int e = 0;
	int f = 0;

	while (tab[i])
		i++;
	i--;
	f = i;
	while (e <= i / 2)
	{
		ft_switch(tab, e, f);
		e++;
		f--;
	}
}

void	rev_str(char *str)
{
	int i;
	char **tab;

	i = 0;
	tab = (char **)malloc(sizeof(char*) * 200);
	while (i < 1000)
	{
		tab[i] = (char*)malloc(sizeof(char*) * 10000);
		i++;
	}
	i = 0;
	while (str[i] && (!(is_word(str[i]))))
		i++;
	alloc_tab(tab, str + i);
	rev_tab(tab);
	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		if (tab[i + 1])
		ft_putchar(' ');
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rev_str(argv[1]);
	ft_putchar('\n');
	return (0);
}
