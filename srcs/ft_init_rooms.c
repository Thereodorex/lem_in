/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:25:52 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/07 19:38:07 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

t_room	*ft_init_rooms(int ants)
{
	t_room	*room;
	t_room	**rooms;
	int		index;
	int		size;

	size = 6;
	rooms = (t_room **)malloc(sizeof(t_room *) * size);
	room = NULL;
	index = -1;
	while (++index < size)
	{
		rooms[index] = room_new(ft_itoa(index), 0, 0);
		room = farm_pushback(room, rooms[index]);
	}
	index = -1;
	rooms[0]->flag = 1;
	rooms[0]->ants = ants;
	farm_link(rooms[0], rooms[2]);
	farm_link(rooms[2], rooms[3]);
	farm_link(rooms[3], rooms[4]);
	farm_link(rooms[4], rooms[5]);
	farm_link(rooms[0], rooms[1]);
	farm_link(rooms[1], rooms[5]);
	rooms[5]->flag = -1;
	free(rooms);
	return (room);
}
