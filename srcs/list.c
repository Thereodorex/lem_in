/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:09:12 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/13 17:00:49 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*room_new(char *name, int x, int y)
{
	t_room		*new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		STOP;
	if ((new->name = ft_strdup(name)) == NULL)
		STOP;
	new->x = x;
	new->y = y;
	new->ants = 0;
	new->step_e = 0x7fffffff;
	new->step_s = 0;
	new->ants = 0;
	new->way = 0;
	new->next = NULL;
	new->l_count = 0;
	new->links = NULL;
	return (new);
}

t_room			*room_pushback(t_room *start, t_room *new)
{
	t_room		*end;

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

t_room			*room_del(t_room *start)
{
	t_room	*tmp;

	if (!start)
		return (NULL);
	while (start)
	{
		tmp = start->next;
		if (start->name)
			ft_strdel(&start->name);
		if (start->links)
		{
			free(start->links);
			start->links = NULL;
		}
		free(start);
		start = tmp;
	}
	return (NULL);
}

t_room			**link_add(t_room **links, int size, t_room *new)
{
	int		i;
	t_room	**tmp;

	tmp = links;
	if (!(links = (t_room **)malloc(sizeof(t_room *) * (size + 1))))
		STOP;
	i = -1;
	while (++i < size)
		links[i] = tmp[i];
	links[size] = new;
	free(tmp);
	return (links);
}

void			room_link(t_room *room1, t_room *room2)
{
	room1->links = link_add(room1->links, (room1->l_count)++, room2);
	room2->links = link_add(room2->links, (room2->l_count)++, room1);
}
