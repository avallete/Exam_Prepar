#include <unistd.h>
#include <stdlib.h>

typedef	struct	s_tree
{
	char *str;
	struct s_tree *left;
	struct s_tree *right;
}				t_tree;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i]), i++;
}

int ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

t_tree	*create_node(char *str)
{
	t_tree *new;

	new = (t_tree*)malloc(sizeof(t_tree));
	if (new)
	{
		new->str = str;
		new->left = NULL;
		new->right = NULL;
	}
	return (new);
}

void insert_data(t_tree **tree, char *str)
{
	t_tree *tmp;

	if (*tree)
	{
		tmp = *tree;
		if (ft_strcmp(tmp->str, str) >= 0)
			insert_data(&tmp->left, str);
		else
			insert_data(&tmp->right, str);
	}
	else
		*tree = create_node(str);
}

void	print_tree(t_tree *tree)
{
	if (tree)
	{
		if (tree->left)
			print_tree(tree->left);
		ft_putstr(tree->str);
		ft_putchar('\n');
		if (tree->right)
			print_tree(tree->right);
	}
}

void	ft_sort(int argc, char **argv)
{
	int i;
	t_tree *t;

	i = 1;
	t = NULL;
	while (i < argc)
	{
		insert_data(&t, argv[i]);
		i++;
	}
	print_tree(t);
}

int main(int argc, char **argv)
{
	if (argc > 1)
		ft_sort(argc, argv);
	else
		ft_putchar('\n');
	return (0);
}
