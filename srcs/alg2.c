/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:38:51 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/13 23:13:52 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		sort_links(t_room *room)
{
	int		i;
	int		j;
	t_room	*tmp;

	i = -1;
	while (++i < room->l_count - 1)
	{
		j = -1;
		while (++j < room->l_count - 1 - i)
		{
			if (room->links[j]->step_e > room->links[j + 1]->step_e ||
				(room->links[j]->step_e == room->links[j + 1]->step_e &&
				room->links[j]->step_s > room->links[j + 1]->step_s))
			{
				tmp = room->links[j];
				room->links[j] = room->links[j + 1];
				room->links[j + 1] = tmp;
			}
		}
	}
}

void		way_steps(t_param *p)
{
	int		i;
	int		j;
	t_way	*way;

	i = -1;
	while (++i <= p->w_main.count)
	{
		way = p->w_main.ways[i]->prev->prev;
		j = 1;
		while (way->room != p->start)
		{
			way->steps = j++;
			way = way->prev;
		}
	}
}

int			way_enough(t_param *p)
{
	int		sum;
	int		i;

	i = -1;
	sum = 0;
	way_steps(p);
	while (++i <= p->w_main.count)
		sum += p->w_main.ways[i]->next->steps;
	return (sum >= p->ants ? 1 : 0);
}

void		del_ways(t_ways *w)
{
	int		i;

	i = -1;
	while (++i <= w->count)
		w->ways[i] = way_del(w->ways[i], w->ways[i]);
	free(w->ways);
	w->count = -1;
}

void		set_steps(t_room *end, t_room *start, int e, int n)
{
	int		i;

	end->way = 0;
	if (end == start)
		return ;
	i = -1;
	while (++i < end->l_count)
		if (e)
		{
			if (!end->links[i]->step_e || end->links[i]->step_e > n)
			{
				end->links[i]->step_e = n;
				set_steps(end->links[i], start, e, n + 1);
			}
		}
		else
		{
			sort_links(end);
			if (!end->links[i]->step_s || end->links[i]->step_s > n)
			{
				end->links[i]->step_s = n;
				set_steps(end->links[i], start, e, n + 1);
			}
		}
}
