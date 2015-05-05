#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *s)
{
	int i;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	int len;
	int i;
	char *ret;

	if (src)
	{
	i = 0;
	len = ft_strlen(src);
	if ((ret = (char*)malloc(sizeof(char) * len + 1)))
	{
		while (src[i])
			ret[i] = src[i], i++;
		ret[i] = 0;
	}
	return (ret);
	}
	return (NULL);
}

int main(void)
{
	char *s1 = "toto is tata is tutu";
	char *s2;

	s2 = ft_strdup(s1);
	write(1, s2, ft_strlen(s2));
	free(s2);
}
