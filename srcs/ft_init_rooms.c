/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:25:52 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/08 14:49:33 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

static void	add_link(t_room **rooms, int r1, int r2)
{
//	farm_link(rooms[r1], rooms[r2]);
}

t_room		*ft_init_rooms(int ants)
{
	t_room	*room;
	t_room	**rooms;
	int		index;
	int		size;

	size = 31;
	rooms = (t_room **)malloc(sizeof(t_room *) * size);
	room = NULL;
	index = -1;
	while (++index < size)
	{
		rooms[index] = room_new(ft_itoa(index), 0, 0);
		room = room_pushback(room, rooms[index]);
	}
	index = -1;
	rooms[0]->flag = 1;
	rooms[0]->ants = ants;
	rooms[30]->flag = -1;
	add_link(rooms, 0, 1);
	free(rooms);
	return (room);
}
