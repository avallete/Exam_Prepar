#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef	struct				s_env
{
	char				**map;
	int				x;
	int				y;
	int				len;
	char				val;
}					t_env;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str, 1), str++;
}

void	grep_map(int fd, t_env *env)
{
	int ret;
	int x;
	int y;
	char c;

	y = 0;
	x = 0;
	while ((ret = read(fd, &c, 1)))
	{
		if ((c != '\n'))
			env->map[y][x] = c, x++;
		if (c == '\n' || c == '\0')
			env->map[y][x] = '\0', y++, x = 0;
	}
	env->map[y][x] = 0;
	env->map[y] = NULL;
	env->x = x;
	env->y = y;
	env->len = ret;
}

void	resolve(char **map, char val, int x, int y)
{
	if (map[y])
	{
		if (map[y][x] == 'X')
		{
			map[y][x] = val;
			if (x > 0)
				resolve(map, val, x - 1, y);
			if (y > 0)
				resolve(map, val, x, y - 1);
			if (map[y][x] + 1)
				resolve(map, val, x + 1, y);
			if (map[y + 1])
				resolve(map, val, x, y + 1);
		}
	}
}

void	resolve_map(char **map, char val, int x, int y)
{
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'X')
				resolve(map, val, x, y), val++;
			x++;
		}
		y++;
	}
}

void	print_map(t_env *env)
{
	int y;

	y = 0;
	while(env->map[y])
		ft_putstr(env->map[y]), ft_putchar('\n'), y++;
}

void	count_island(int fd)
{
	t_env env;
	int i;

	i = 0;
	env.val = '0';
	env.map = (char**)malloc(sizeof(char*) * 1000);
	env.map[1000] = NULL;
	while (i < 1000)
		env.map[i] = (char*)malloc(sizeof(char) * 100000), i++;
	grep_map(fd, &env);
	resolve_map(env.map, env.val, 0, 0);
	print_map(&env);
}

int main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > -1)
			count_island(fd);
	}
	ft_putchar('\n');
	return (0);
}
