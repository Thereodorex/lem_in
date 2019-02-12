/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:07:52 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/12 18:32:52 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_way	*way_new(t_room *room)
{
	t_way	*new;

	if (!(new = (t_way *)malloc(sizeof(t_way))))
		STOP;
	new->steps = 0;
	new->room = room;
	new->next = new;
	new->prev = new;
	return (new);
}

t_way	*way_pushback(t_way *start, t_way *new)
{
	t_way	*end;

	if (!new)
		return (start);
	if (!start)
		return (new);
	end = start->prev;
	start->prev = new;
	end->next = new;
	new->prev = end;
	new->next = start;
	return (start);
}

t_way	*way_del(t_way *start, t_way *from)
{
	if (!start || !from)
		return (start);
	if (from == start)
	{
		start->prev->next = NULL;
		while (start)
		{
			from = start->next;
			start->room->way = 0;
			free(start);
			start = from;
		}
	}
	else
	{
		from->prev->next = start;
		start->prev = from->prev;
		while (from != start)
		{
			from->room->way = 0;
			free(from);
			from = from->next;
		}
	}
	return (NULL);
}

t_way	*way_cpy(t_way *from, t_way *to)
{
	t_way	*new;

	new = NULL;
	if (!from || !to)
		return (NULL);
	while (from != to)
	{
		new = way_pushback(new, way_new(from->room));
		from = from->next;
	}
	new = way_pushback(new, way_new(to->room));
	return (new);
}

void	way_realloc(t_ways *w)
{
	t_way	**new;
	int		i;

	if (!(new = (t_way **)malloc(sizeof(t_way *) * (w->count + 10))))
		STOP;
	i = -1;
	while (++i < w->count)
		new[i] = w->ways[i];
	if (!(i % 10))
		new[i++] = NULL;
	while (i % 10)
		new[i++] = NULL;
	free(w->ways);
	w->ways = new;
}
