#include <unistd.h>

void wdmatch(char *s1, char *s2)
{
	int i = 0;
	int e = 0;
	while (s2[e] && s1[i])
	{
		if (s1[i] == s2[e])
			i++;
		e++;
	}
	if (!s1[i])
		write(1, s1, i);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		wdmatch(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
