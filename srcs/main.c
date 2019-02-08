/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:11:22 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/08 13:19:09 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_room(t_room *r)
{
	int		i;

	printf("name: %s\n", r->name);
	printf("coord: %d %d\n", r->x, r->y);
	printf("ants: %d\n", r->ants);
	printf("steps: %d\n", r->steps);
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
	while (cur)
	{
		print_room(cur);
		cur = cur->next;
	}
}

int		main()
{
	t_param		p;

	read_data(&p);
	print_farm(&p);
	room_del(p.start);
	return (0);
}
