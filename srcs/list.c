/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:09:12 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/07 20:36:25 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*room_new(char *name, int x, int y)
{
	t_room		*new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		STOP;
	new->name = name;
	new->x = x;
	new->y = y;
	new->ants = 0;
	new->link_size = 0;
	new->next = NULL;
	new->links = NULL;
	new->visited = 0;
	new->flag = 0;
	return (new);
}

t_room			*farm_pushback(t_room *start, t_room *new)
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
		if (start->steps)
		{
			free(start->steps);
			start->steps = NULL;
		}
		free(start);
		start = tmp;
	}
	return (NULL);
}

t_room		**link_add(t_room *links, int size, t_room *new)
{
	int		i;
	t_room	**tmp;
	int		*tmp_int;

	tmp = links->links;
	if (!(links->links = (t_room **)malloc(sizeof(t_room *) * (size + 1))))
		STOP;
	tmp_int = links->steps;
	if (!(links->steps = (int *)malloc(sizeof(int) * (size + 1))))
		STOP;
	i = -1;
	while (++i < size)
	{
		links->links[i] = tmp[i];
		links->steps[i] = -1;
	}
	links->links[size] = new;
	links->steps[size] = -1;
	free(tmp);
	free(tmp_int);
	return (links->links);
}

void		farm_link(t_room *room1, t_room *room2)
{
	room1->links = link_add(room1, room1->link_size++, room2);
	room2->links = link_add(room2, room2->link_size++, room1);
}
