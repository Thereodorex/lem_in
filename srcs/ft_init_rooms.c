/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:25:52 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/08 13:17:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

static void	add_link(t_room **rooms, int r1, int r2)
{
	farm_link(rooms[r1], rooms[r2]);
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
		room = farm_pushback(room, rooms[index]);
	}
	index = -1;
	rooms[0]->flag = 1;
	rooms[0]->ants = ants;
	rooms[30]->flag = -1;
	add_link(rooms, 0, 1);
	add_link(rooms, 1, 30);
	add_link(rooms, 0, 2);
	add_link(rooms, 2, 3);
	add_link(rooms, 3, 30);
	add_link(rooms, 0, 4);
	add_link(rooms, 4, 5);
	add_link(rooms, 5, 6);
	add_link(rooms, 6, 30);
	add_link(rooms, 0, 7);
	add_link(rooms, 7, 8);
	add_link(rooms, 8, 9);
	add_link(rooms, 9, 10);
	add_link(rooms, 10, 11);
	add_link(rooms, 11, 12);
	add_link(rooms, 12, 30);
	add_link(rooms, 0, 13);
	add_link(rooms, 13, 14);
	add_link(rooms, 14, 15);
	add_link(rooms, 15, 16);
	add_link(rooms, 16, 17);
	add_link(rooms, 17, 18);
	add_link(rooms, 18, 19);
	add_link(rooms, 19, 30);
	add_link(rooms, 0, 20);
	add_link(rooms, 20, 21);
	add_link(rooms, 21, 22);
	add_link(rooms, 22, 23);
	add_link(rooms, 23, 24);
	add_link(rooms, 24, 25);
	add_link(rooms, 25, 26);
	add_link(rooms, 26, 27);
	add_link(rooms, 27, 28);
	add_link(rooms, 28, 29);
	add_link(rooms, 29, 30);
	free(rooms);
	return (room);
}
