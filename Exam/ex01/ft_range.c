#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int size;
	int			*tab;
	int			i;
	int			begin;
	int			inc;

	i = 0;
	end > start ? (size = end - start) : end < start ? (size = start - end) : (size = 0);
	tab = (int*)malloc(sizeof(int) * size + 1);
	end > start ? (begin = start, inc = 1) : (begin = start, inc = -1);
	while (i <= size)
	{
		tab[i] =  begin;
		i++, begin += inc;
	}
	return (tab);
}

int main(void)
{
	int *tab;
	int i;

	i = 0;
	tab = ft_range(1, 3);
	while (i <= 3)
	{
		printf("%d: %d\n", i, tab[i]);
		i++;
	}
	i = 0;
	printf("________\n");
	tab = ft_range(-1, 2);
	while (i <= 3)
	{
		printf("%d: %d\n", i, tab[i]);
		i++;
	}
	i = 0;
	printf("________\n");
	tab = ft_range(0, 0);
	while (i <= 2)
	{
		printf("%d: %d\n", i, tab[i]);
		i++;
	}
	i = 0;
	printf("________\n");
	tab = ft_range(0, -3);
	while (i <= 4)
	{
		printf("%d: %d\n", i, tab[i]);
		i++;
	}
	return (0);
}
