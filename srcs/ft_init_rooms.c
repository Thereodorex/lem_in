/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:25:52 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/07 17:31:36 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

t_room	*ft_init_rooms(int size)
{
	t_room	*room;
	t_room	**rooms;
	int		index;
	int		link_count;

	rooms = (t_room **)malloc(sizeof(t_room *) * size);
	room = NULL;
	index = -1;
	while (++index < size)
	{
		rooms[index] = room_new(ft_itoa(index), 0, 0);
		room = farm_pushback(room, rooms[index]);
	}
	index = -1;
	link_count = 10 + rand() % 20;
	while (++index < link_count)
		farm_link(rooms[rand() % size], rooms[rand() % size]);
	free(rooms);
	return (room);
}
