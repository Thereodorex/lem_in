/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrhaenys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 04:06:41 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/09 06:24:06 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		neighbors(t_way *old, t_room *current)
{
	while (old != NULL)
	{
		if (old->room == current)
			return (1);
		old = old->next;
	}
	return (0);
}

t_way	*way_push(t_way *way, t_room *room, t_room *from)
{
	t_way	*new;
	t_way	*start;

	start = way;
	new = (t_way *)malloc(sizeof(t_way));
	new->room = room;
	new->from = from;
	new->next = NULL;
	if (way == NULL)
		return (new);
	while (way->next != NULL)
		way = way->next;
	way->next = new;
	return (start);
}

t_way	*way_pushbask(t_way *way, t_room *room, t_room *from)
{
	t_way	*new;
	t_way	*start;

	start = way;
	new = (t_way *)malloc(sizeof(t_way));
	new->room = room;
	new->from = from;
	new->next = NULL;
	if (way == NULL)
		return (new);
	new->next = way;
	return (new);
}

t_way	*get_way(t_way *way, t_room *room)
{
	while (way != NULL)
	{
		if (way->room == room)
			return (way);
		way = way->next;
	}
	return (way);
}

t_way	*return_way(t_room *current, t_way *way)
{
	t_way	*prev;
	t_way	*ret;

	ret = NULL;
	current = get_way(way, current)->room;
	while (current != NULL)
	{
//		ft_printf("way=%s\n", current->name);
		ret = way_pushbask(ret, current, NULL);
		if ((prev = get_way(way, current)) == NULL)
			return (ret);
		if ((prev = get_way(way, prev->from)) == NULL)
			return (ret);
		current = prev->room;
	}
	return (ret);
}

t_way	*a_star(t_room *start, t_room *end)
{
	t_way	*frontier;
	t_way	*old;
	t_way	*way;
	t_room	*current;
	t_way	*prev;
	int		index;

	frontier = NULL;
	old = NULL;
	way = NULL;
	frontier = way_push(frontier, start, NULL);
	way = way_push(way, start, NULL);
	while (frontier != NULL)
	{
		current = frontier->room;
		old = way_push(old, current, NULL);
		if (current == end)
		{
			return return_way(current, way);
		}
		index = -1;
		while (++index < current->size)
		{
			if (neighbors(old, current->links[index]) == 0)
			{
				frontier = way_push(frontier, current->links[index], NULL);
				way = way_push(way, current->links[index], current);
			}
		}
		frontier = frontier->next;
	}
	return (NULL);
}
