#include "unistd.h"
int islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void ulstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (islower(str[i]))
			str[i] -= 32;
		else if (isupper(str[i]))
			str[i] += 32;
		i++;
	}
	write(1, str, i);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ulstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
