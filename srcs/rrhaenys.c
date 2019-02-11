/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrhaenys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 04:06:41 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/11 19:29:01 by rrhaenys         ###   ########.fr       */
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
	new->last = new;
	if (way == NULL)
		return (new);
	way = way->last;
	while (way->last->next != NULL)
		way->last = way->last->next;
	way->last->next = new;
	way->last = new;
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

void	free_ways_a(t_way *old, t_way *frontier, t_way *way)
{
	t_way	*ptr;

	while (old != NULL)
	{
		ptr = old;
		old = old->next;
		free(ptr);
	}
	while (frontier != NULL)
	{
		ptr = frontier;
		frontier = frontier->next;
		free(ptr);
	}
	while (way != NULL)
	{
		ptr = way;
		way = way->next;
		free(ptr);
	}
}

t_way	*return_way(t_room *current, t_way *way)
{
	t_way	*prev;
	t_way	*ret;

	ret = NULL;
	current = get_way(way, current)->room;
	while (current != NULL)
	{
		ret = way_pushbask(ret, current, NULL);
		prev = get_way(way, current);
		if ((prev = get_way(way, prev->from)) == NULL)
			break;
		current = prev->room;
	}
	free_ways_a(NULL, NULL, way);
	return (ret);
}

t_way	*a_star(t_room *start, t_room *end, t_room *old_room)
{
	t_way	*frontier;
	t_way	*old;
	t_way	*way;
	t_room	*current;
	t_way	*frontier_start;
	int		index;

	frontier = NULL;
	old = NULL;
	way = NULL;
	if (old_room != NULL)
		old = way_push(old, old_room, NULL);
	frontier = way_push(frontier, start, NULL);
	frontier_start = frontier;
	way = way_push(way, start, NULL);
	while (frontier != NULL)
	{
		current = frontier->room;
		old = way_push(old, current, NULL);
		if (current == end)
		{
			free_ways_a(old, frontier_start, NULL);
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
	free_ways_a(old, frontier_start, way);
	return (NULL);
}
