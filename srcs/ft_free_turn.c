#include "lem_in.h"

void	ft_free_turn(t_turn *turn)
{
	t_turn	*ptr;

	while (turn != NULL)
	{
		ptr = turn;
//		ft_printf("%s %s\n", turn->name, turn->room->name);
		turn = turn->next;
		free(ptr->name);
		free(ptr);
	}
}
