#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;
	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int i;
	char *ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
		ret[i] = str[i], i++;
	ret[i] = 0;
	return (ret);
}

int	ft_touper(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int		ft_strcmpi(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (ft_touper(s1[i]) != ft_touper(s2[i]))
			return (ft_touper(s1[i]) - ft_touper(s2[i]));
		i++;
	}
	return (0);
}

int		count_word(char *s1)
{
	int i;
	int e;

	i = 0;
	e = 0;
	while (s1[i])
	{
		while (s1[i] == ' ' || s1[i] == '\t')
			i++;
		if (s1[i] && s1[i] != ' ' && s1[i] != '\t')
			e++;
		while (s1[i] && s1[i] != ' ' && s1[i] != '\t')
			i++;
	}
	return (e);
}

int		word_len(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

char	*ft_strndup(char *str, int n)
{
	int i;
	char *ret;

	i = 0;
	ret = (char*)malloc(sizeof(char) * (n + 1));
	while (i < n)
		ret[i] = str[i], i++;
	ret[i] = '\0';
	return (ret);
}

char 	**ft_split(char *s1)
{
	int i;
	int e;
	int nb;
	char **ret;

	i = 0;
	e = 0;
	nb = count_word(s1);
	ret = (char **)malloc(sizeof(char*) * (nb + 1));
	while (*s1)
	{
		while (*s1 && (*s1 == ' ' || *s1 == '\t'))
			s1++;
		e = word_len(s1);
		ret[i] = ft_strndup(s1, e);
		s1 += e;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	ft_sort_len_array(char **str)
{
	int i;
	char change;
	char *tmp;

	i = 0;
	change = 1;
	i = 0;
	while (change)
	{
		change = 0;
		while (str[i + 1])
		{
			if ((ft_strlen(str[i]) > ft_strlen(str[i + 1])))
			{
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
				i = 0;
				change = 1;
			}
			else
				i++;
		}
	}
}

void	ft_sort_array(char **str)
{
	int i;
	char change;
	char *tmp;

	i = 0;
	change = 1;
	i = 0;
	while (change)
	{
		change = 0;
		while (str[i + 1])
		{
			if ((ft_strcmpi(str[i], str[i + 1])) > 0)
			{
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
				i = 0;
				change = 1;
			}
			else
				i++;
		}
	}
}

void	print_tab(char **str)
{
	int i;

	i = 0;
	while (str[i + 1])
	{
		write(1, str[i], ft_strlen(str[i]));
			if (ft_strlen(str[i]) == ft_strlen(str[i + 1]))
					write(1, " ", 1);
				else
					write(1, "\n", 1);
		i++;
	}
	write(1, str[i], ft_strlen(str[i]));
}

void	al_cmp(char *str)
{
	char **split;
	int i = 0;

	split = ft_split(str);
	ft_sort_array(split);
	ft_sort_len_array(split);
	print_tab(split);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		al_cmp(av[1]);
	write(1, "\n", 1);
	return (0);
}
