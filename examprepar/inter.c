#include <unistd.h>

int isin(char *buf, char c)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void inter(char *s1, char *s2)
{
	int i;
	int e;
	char buf[50];
	char *pt = buf;
	e = 0;
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (s2[i] == *s1 && (!isin(pt, *s1)))
			{
				buf[e] = *s1;
				e++;
				break;
			}
			i++;
		}
		s1++;
	}
	write(1, buf, e);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
