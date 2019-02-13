/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:11:22 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/13 19:10:56 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	param_init(t_param *p)
{
	p->start = NULL;
	p->end = NULL;
	p->ants = 0;
	p->w_all.count = -1;
	p->w_all.ways = NULL;
	way_realloc(&(p->w_all));
	p->w_main.count = -1;
	p->w_main.ways = NULL;
	p->buf.len = 0;
	p->s_limit = 50000000;
	p->b_limit = 50000000;
	p->step_mode = 0;
}
/*
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
*/
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

void	set_limits(t_param *p, char *mode)
{
	if (!ft_strcmp(mode, "0"))
		p->s_limit = 0;
	else if (!ft_strcmp(mode, "2"))
		p->b_limit = 100000000;
	else if (!ft_strcmp(mode, "3"))
	{
		p->s_limit = 100000000;
		p->b_limit = 200000000;
	}
	else if (!ft_strcmp(mode, "4"))
	{
		p->s_limit = 200000000;
		p->b_limit = 500000000;
	}
	else if (!ft_strcmp(mode, "5"))
	{
		p->s_limit = 500000000;
		p->b_limit = 2000000000;
	}
	else if (ft_strcmp(mode, "1"))
		STOP_IN;
}

void	get_args(t_param *p, int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-s"))
			p->step_mode = 1;
		else if (!ft_strcmp(argv[i], "-d"))
		{
			if (++i < argc)
				set_limits(p, argv[i]);
			else
				STOP_IN;
		}
		else if (!ft_strcmp(argv[i], "-help"))
		{
			ft_printf("usage: lim-in [-help] [-v] [-s] [-d [0-5]]\n");
			exit(0);
		}
		else
			STOP_IN;
	}
}

int		main(int argc, char **argv)
{
	t_param		p;

	param_init(&p);
	get_args(&p, argc, argv);
	read_data(&p);
	set_steps(p.end, p.start, 1, 1);
	p.end->step_e = 0;
	set_steps(p.start, p.end, 0, 1);
	p.start->step_s = 0;
	comb_ways(&p);
//	print_ways(&(p.w_main));
	move(&p);
	room_del(p.start);
	del_ways(&p.w_main);
	return (0);
}
