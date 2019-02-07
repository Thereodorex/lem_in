/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:07:52 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/07 13:45:09 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_way	*way_new(t_room *room)
{
	t_way	*new;

	if (!(new = (t_way *)malloc(sizeof(t_way))))
		STOP;
	new->room = room;
	new->next = NULL;
	return (new);
}

t_way	*way_pushback(t_way *start, t_way *new)
{
	t_way	*end;

	if (!new)
		return (start);
	new->next = NULL;
	if (!start)
		return (new);
	end = start;
	while (end->next)
		end = end->next;
	end->next = new;
	return (start);
}

t_way	*way_del(t_way *way)
{
	t_way	*tmp;

	if (!way)
		return (NULL);
	while (way)
	{
		tmp = way->next;
		free(way);
		way = tmp;
	}
	return (NULL);
}

t_way	*way_cpy(t_way *way)
{
	t_way	*new;

	new = NULL;
	while (way)
	{
		new = way_pushback(new, way_new(way->room));
		way = way->next;
	}
	return (new);
}

void	way_realloc(t_param *p)
{
	t_way	**new;
	int		i;

	p->ways_count += 10;
	if (!(new = (t_way **)malloc(sizeof(t_way *) * (p->ways_count))))
		STOP;
	i = -1;
	while (++i < p->ways_count - 10)
		new[i] = p->ways[i];
	free(p->ways);
	p->ways = new;
}
