/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:25:41 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/13 19:46:51 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		move_start(t_param *p)
{
	int		i;

	i = -1;
	while (++i <= p->w_main.count)
	{
		if (p->start->ants)
		{
			p->w_main.ways[i]->next->room->ants = p->ants - p->start->ants + 1;
			buf_step(p, p->w_main.ways[i]->next->room->ants,
								p->w_main.ways[i]->next->room->name);
			--p->start->ants;
		}
	}
}

static void		move_step(t_param *p)
{
	int		i;
	t_way	*way;

	i = -1;
	while (++i <= p->w_main.count)
	{
		way = p->w_main.ways[i]->prev;
		while (way->prev->room != p->start)
		{
			if (way->prev->room->ants)
			{
				buf_step(p, way->prev->room->ants, way->room->name);
				if (way->room == p->end)
					++way->room->ants;
				else
					way->room->ants = way->prev->room->ants;
				way->prev->room->ants = 0;
			}
			way = way->prev;
		}
	}
	move_start(p);
	p->buf.buf[p->buf.len ? p->buf.len - 1 : p->buf.len++] = '\n';
}

static void		way_steps(t_param *p)
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
			way = way->next;
		}
	}
}

void			move(t_param *p)
{
	char	ch;

	way_steps(p);
	while (p->end->ants != p->ants)
	{
		ch = 0;
		move_step(p);
	}
	buf_print(p);
}
