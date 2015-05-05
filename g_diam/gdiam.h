#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct		s_list
{
	int				val;
	int				view;
	struct s_list	*links[1024];
	struct	s_list	*next;
}					t_list;
