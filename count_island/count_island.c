#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef	struct		s_env
{
	char			**tab;
	char			*map;
	int				col;
	int				ligne;
	int				len;
	char			val;
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

void	grep_map(char *map, int fd, t_env *env)
{
	int ret;
	char c;

	ret = read(fd, map, 1000000);
	map[ret] = '\0';
	env->len = ret;
}

void	take_size(t_env *env)
{
	int i;
	int e;

	i = 0;
	while (env->map[i] != '\n')
		env->col++, i++;
	env->ligne++;
	i++;
	while (env->map[i])
	{
		if (env->map[i] == '\n')
			env->ligne++;
		i++;
	}
}

void	count_island(int fd)
{
	t_env env;
	int i;

	i = 0;
	env.ligne = 0;
	env.col = 0;
	env.val = '0';
	env.map = (char*)malloc(sizeof(char) * 1000000);
	grep_map(env.map, fd, &env);
	take_size(&env);
	while (env.map[i] != 'X')
		i++;
	if (env.map[i] == 'X')
		resolve_island(env.map, i, env.val, &env);
	ft_putstr(env.map);
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
