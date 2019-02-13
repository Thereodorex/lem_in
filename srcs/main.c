/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:11:22 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/13 13:49:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

void	param_init(t_param *p)
{
	p->start = NULL;
	p->end = NULL;
	p->ants = 0;
	p->w_all.count = 0;
	p->w_all.ways = NULL;
	way_realloc(&(p->w_all));
	p->w_main.count = 0;
	p->w_main.ways = NULL;
//	way_realloc(&(p->w_main));
	p->buf.len = 0;
}

void	print_room(t_param *p, t_room *r)
{
	int		i;

	printf("name: %s ", r->name);
	if (p->start == r)
		printf("(start)");
	else if (p->end == r)
		printf("(end)");
	printf("\n");
	printf("coord: %d %d\n", r->x, r->y);
	printf("ants: %d\n", r->ants);
	printf("steps to end: %d\n", r->step_e);
	printf("steps to start: %d\n", r->step_s);
//	printf("steps to start: %d\n", r->step_s);
	printf("way: %d\n", r->way);
	i = -1;
	while (++i < r->l_count)
		printf("%s-%s\n", r->name, r->links[i]->name);
	printf("\n");
}

void	print_farm(t_param *p)
{
	t_room	*cur;

	cur = p->start;
	printf("\n");
	while (cur)
	{
		print_room(p, cur);
		cur = cur->next;
	}
}

void	print_way(t_way *w)
{
	t_way	*tmp;

	if (!w)
		return ;
	printf("%s", w->room->name);
	tmp = w->next;
	while (tmp != w)
	{
		printf(" -> %s", tmp->room->name);
		tmp = tmp->next;
	}
	printf("\n");
}

void	print_ways(t_ways *w)
{
	int		i;

	if (!(w->ways))
		return ;
	i = -1;
	while(++i <= w->count)
	{
		printf("way%d: ", i);
		print_way((w->ways)[i]);
	}
}

int		main(int argc, char **argv)
{
	t_param		p;
	int			index;

	param_init(&p);
	read_data(&p);
	set_steps(p.end, p.start, 1, 1);
	p.end->step_e = 0;
	set_steps(p.start, p.end, 0, 1);
	p.start->step_s = 0;
	comb_ways(&p);
	print_ways(&(p.w_main));
	p.uniq_ways = MIN(p.start->l_count, p.end->l_count);
//	print_farm(&p);
	if (argc == 2 && (ft_strcmp(argv[1], "-v") == 0))
		ft_open_win(argv[0], &p, &(p.w_main), p.ants);
	else
	{
		index = 0;
		while (++index < (p.ants * 2))
			ant_muve(&(p.w_main), index, p.ants);
	}
//	free(ram);
	room_del(p.start);
	return (0);
}
