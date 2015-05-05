#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

void ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

void ft_strncpy(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
}

char *ft_strdup(char *str)
{
	char *ret;

	if (str)
	{
		ret = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
		ft_strncpy(ret, str, ft_strlen(str) + 1);
		return (ret);
	}
	return (NULL);
}

int ft_strnequ(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char *ft_strstr(char *s1, char *s2)
{
	while (*s1)
	{
		if (ft_strnequ(s1, s2, ft_strlen(s2)))
			return (s1);
		s1++;
	}
	return (NULL);
}

char *max;

void match_right(char *s1, char *s2)
{
	char *ret;

	ret = ft_strdup(s1);
	while (*ret)
	{
		if (ft_strstr(s2, ret))
		{
			if (ft_strlen(ret) > ft_strlen(max))
				max = ft_strdup(ret);
		}
		ret[ft_strlen(ret) - 1] = 0;
	}
}

void match_left(char *s1, char *s2)
{
	while (*s1)
	{
		match_right(s1, s2);
		s1++;
	}
}

void maxlenoc(char **argv)
{
	char *retmax;

	retmax = *argv;
	argv++;
	while (*argv)
	{
		max = "";
		match_left(retmax, *argv);
		if (ft_strlen(max) < ft_strlen(retmax))
			retmax = max;
		argv++;
	}
	ft_putstr(retmax);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_putstr(argv[1]);
	else if (argc > 2)
		maxlenoc(&argv[1]);
	write(1, "\n", 1);
	return (0);
}
