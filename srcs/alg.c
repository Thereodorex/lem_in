/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:08:54 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/13 20:09:08 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		find_way(t_room *r, int *max, int maxf)
{
	int	i;

	if (r->step_e == 0)
		return (1);
	if (r->way)
		return (0);
	if (++(*max) > maxf)
		return (0);
	r->way = 2;
	i = -1;
	while (++i < r->l_count)
		if (find_way(r->links[i], max, maxf))
			return (1);
	r->way = 0;
	return (0);
}

static void		build_way(t_way *w, t_room *r)
{
	int		i;

	if (r->step_e == 0)
	{
		way_pushback(w, way_new(r));
		return ;
	}
	r->way = 1;
	way_pushback(w, way_new(r));
	i = 0;
	while (r->links[i]->way != 2 && r->links[i]->step_e != 0)
		++i;
	build_way(w, r->links[i]);
}

static void		set_ways(t_ways *w, t_param *p, int iter, int *steps)
{
	int		i;
	int		j;
	int		maxf;

	p->start->way = 1;
	w->ways = NULL;
	i = iter;
	j = p->start->l_count;
	while (j--)
	{
		maxf = 0;
		if (find_way(p->start->links[i], &maxf,
					p->s_limit ? p->s_limit / p->start->l_count : 10000000))
		{
			if (!(++w->count % 10))
				way_realloc(w);
			w->ways[w->count] = way_pushback(w->ways[w->count],
													way_new(p->start));
			build_way(w->ways[w->count], p->start->links[i]);
			if (!p->s_limit)
				return ;
		}
		*steps += maxf;
		PLUS_MAX(i, p->start->l_count);
	}
}

static void		let_it_be(t_ways *w)
{
	int		i;
	t_way	*tmp;

	i = -1;
	while (++i <= w->count)
	{
		tmp = w->ways[i];
		while (tmp->room->way)
		{
			tmp->room->way = 0;
			tmp = tmp->next;
		}
	}
}

void			comb_ways(t_param *p)
{
	int		i;
	int		steps;

	i = -1;
	steps = 0;
	while (++i < p->start->l_count && steps < (int)p->b_limit)
	{
		set_ways(i == 0 ? &p->w_main : &p->w_all, p, i, &steps);
		if (!p->s_limit)
			return ;
		if (i == 0)
			let_it_be(&p->w_main);
		if (p->w_all.count > p->w_main.count)
		{
			del_ways(&(p->w_main));
			p->w_main.count = p->w_all.count;
			p->w_main.ways = p->w_all.ways;
			let_it_be(&p->w_main);
		}
		else
			del_ways(&(p->w_all));
	}
}
