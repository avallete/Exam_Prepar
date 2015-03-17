#include <gdiam.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	init_struct(t_list *begin)
{
	int i;

	i = 0;
	while (i < 1024)
		begin->links[i] = NULL, i++;
}

int main(int argc, char **argv)
{
	t_list begin;

	if (argc == 2)
	{
		init_struct(&begin);
	}
	ft_putchar('\n');
	return (0);
}
