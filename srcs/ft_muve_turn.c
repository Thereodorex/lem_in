#include "lem_in.h"

int		ft_muve_ant(t_turn *turn, t_room *room, int ant_wait)
{
	int		index;

	if (room->links[0]->ants == 0 ||
		room->links[0]->flag == -1)
	{
		ft_printf("%s-%s ", turn->name, room->links[0]->name);
		room->ants--;
		room->links[0]->ants++;
		turn->room = room->links[0];
		return (1);
	}
	index = 0;
	while (++index < room->link_size)
	{
		if ((room->links[index]->ants == 0 && ((room->steps[index - 1] + 1 + ant_wait) >= room->steps[index])) ||
			room->links[index]->flag == -1)
		{
			ft_printf("%s-%s ", turn->name, room->links[index]->name);
			room->ants--;
			room->links[index]->ants++;
			turn->room = room->links[index];
			return (1);
		}
	}
	return (0);
}

int		ft_muve_turn(t_turn *turn)
{
	t_room	*room;
	int		index;
	int		step;
	int		ant_wait;

	step = 0;
	ant_wait = 0;
	while (turn != NULL)
	{
		room = turn->room;
		index = -1;
		if (room->flag != -1)
		{
			if (ft_muve_ant(turn, room, ant_wait))
			{
				step++;
			}
			else
				ant_wait++;
		}
		turn = turn->next;
	}
	return (step);
}
