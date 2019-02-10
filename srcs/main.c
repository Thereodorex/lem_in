/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:11:22 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/09 06:31:36 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	printf("\n");
	while (cur)
	{
		print_room(p, cur);
		cur = cur->next;
	}
}

void	ft_print_way(char *str, t_way *way)
{
	while (way != NULL)
	{
		ft_printf("%s way=%s\n", str, way->room->name);
		way = way->next;
	}
	ft_putendl("");
}

int		main(int argc, char **argv)
{
	t_param		p;
	t_room		**rooms;
	int			rooms_count;
	t_way		*way;
	t_way		*new_way;

	param_init(&p);
	read_data(&p);
//	print_farm(&p);
	way = a_star(p.start, p.end, NULL);
	ft_print_way("way", way);
/*	while (way != NULL)
	{
		new_way = a_star(p.start, p.end, way->room);
		ft_print_way("new_way", new_way);
		way = way->next;
	}
*/	room_del(p.start);
	return (0);
}
