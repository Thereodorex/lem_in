/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:11:22 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/08 21:56:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "main.h"

void	param_init(t_param *p)
{
	p->start = NULL;
	p->end = NULL;
	p->ants = 0;
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
//	printf("steps: %d\n", r->steps);
	printf("links: %d\n", r->size);
	i = -1;
	while (++i < r->size)
		printf("%s-%s\n", r->name, r->links[i]->name);
	printf("\n");
}

void	print_farm(t_param *p)
{
	t_room	*cur;

	cur = p->start;
	ft_print_rooms(cur);
	return ;
	printf("\n");
	while (cur)
	{
		print_room(p, cur);
		cur = cur->next;
	}
}

int		main(int argc, char **argv)
{
	t_param		p;
	t_turn		*turn;

//	rrhaenys_main(argc, argv);
//	ft_open_win(argv[0]);
	param_init(&p);
	read_data(&p);
	ft_init_len(&p);
	ft_sotr_len(p.start);
	if (ft_corr_rooms(p.end) == 0)
	{
		ft_printf("There is no way!\n");
		exit(0);
	}
	print_farm(&p);
	turn = ft_init_turn_ant(p.ants, p.start);
	while (ft_muve_turn(turn) > 0)
		ft_printf("\n");
	room_del(p.start);
	return (0);
}
