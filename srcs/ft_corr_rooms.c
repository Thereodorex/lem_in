#include "lem_in.h"

int		ft_corr_rooms(t_room *start)
{
	int	index;

	while(start != NULL)
	{
		if (start->flag == -1)
		{
			index = -1;
			while (++index < start->link_size)
				if (start->steps[index] >= 0)
					return (1);
		}
		start = start->next;
	}	
	return (0);
}
