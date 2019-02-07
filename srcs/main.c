/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:11:22 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/07 20:22:03 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_turn	*ft_turn_add(t_turn *turn, t_room *new)
{
	t_turn *ptr;
	t_turn *start;

	start = turn;
	ptr = (t_turn *)malloc(sizeof(t_turn));
	ptr->room = new;
	ptr->next = NULL;
	if (!turn)
		return (ptr);
	while (turn->next != NULL)
		turn = turn->next;
	turn->next = ptr;
	return (start);
}

t_room	*ft_turn_get(t_turn **turn)
{
	t_room	*ptr;

	if (!turn)
		return (NULL);
	ptr = (*turn)->room;
	*turn = (*turn)->next;
	return (ptr);
}

void	ft_start_ant(t_turn **turn)
{
	int		index;
	t_room	*room;

	index = -1;
	room = ft_turn_get(turn);
	while (++index < room->link_size && room->ants > 0)
	{
		if ((room->links[index]->ants == 0) ||
			room->links[index]->flag == -1)
		{
			ft_printf("%s->%s\n", room->name, room->links[index]->name);
			if (room->links[index]->flag != -1)
				*turn = ft_turn_add(*turn, room->links[index]);
			room->links[index]->ants += 1;
			room->ants -= 1;
		}
	}

}

int		main()
{
	t_room	*start;
	t_turn	*turn;

	start =	ft_init_rooms(2);
	ft_init_len(start);
	ft_sotr_len(start);
	ft_print_rooms(start);
	turn = ft_turn_add(turn, start);
	while (turn != NULL)
		ft_start_ant(&turn);
	room_del(start);
	return (0);
}
