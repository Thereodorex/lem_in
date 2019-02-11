/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:11:22 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/11 18:11:24 by rrhaenys         ###   ########.fr       */
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

void	ft_print_way(char *str, t_way *way, int index)
{
	while (way != NULL)
	{
		ft_printf("%d %s way=%s\n", index, str, way->room->name);
		way = way->next;
	}
	ft_putendl("");
}

int		way_len(t_way *way)
{
	int	index;

	index = 0;
	while (way != NULL)
	{
		way = way->next;
		index++;
	}
	return (index);
}

int		ways_max_len(t_ways *ways)
{
	int len;
	int	index;
	int len_i;

	len = 0;
	index = -1;
	while (++index < ways->size)
	{
		len_i = way_len(ways->way[index]);
		len = (len > len_i ? len : len_i);
	}
	return (len);
}

float	ways_min_par(t_ways *ways, int ants)
{
	float par;
	float par_i;

	par = ants / (float)ways->size + ways_max_len(ways);
	while (ways != NULL)
	{
		par_i = ants / (float)ways->size + ways_max_len(ways);
		par = (par < par_i ? par : par_i);
		ways = ways->next;
	}
	return (par);
}

void	ft_print_ways(char *str, t_ways *ways, int ants)
{
	int		index;
	int		max_size;
	int		max_way_len;
	int		way_len;
	float	par;
	float	min_par;

	max_size = 0;
	min_par = ways_min_par(ways, ants);
	while (ways != NULL)
	{
		par = ants / (float)ways->size + ways_max_len(ways);
		index = -1;
		ft_putendl("____________________________________");
		ft_printf("par:%f\n", par);
		ft_printf("size:%d\n", ways->size);
		ft_printf("ways_max_len:%d\n", ways_max_len(ways));
		max_size = (max_size > ways->size ? max_size : ways->size);
		while (++index < ways->size)
			ft_print_way(str, ways->way[index], index);
		ways = ways->next;
	}
	ft_printf("max_size:%d\n", max_size);
	ft_printf("min par=%f\n", min_par);
}

t_ways	*ways_push(t_ways *ways, t_way *way)
{
	t_ways	*new;
	t_ways	*start;

	new = (t_ways *)malloc(sizeof(t_ways));
	new->way = (t_way **)malloc(sizeof(t_way *));
	new->way[0] = way;
	new->next = NULL;
	new->size = 1;
	if (ways == NULL)
		return (new);
	start = ways;
	while (ways->next != NULL)
		ways = ways->next;
	ways->next = new;
	return (start);
}

int		way_intersection(t_way *way1, t_way *way2)
{
	t_way	*ptr2;

	way1 = way1->next;
	while (way1 != NULL)
	{
		ptr2 = way2->next;
		while (ptr2 != NULL)
		{
			if (way1->room == ptr2->room &&
				way1->next != NULL)
				return (0);
			ptr2 = ptr2->next;
		}
		way1 = way1->next;
	}
	return (1);
}

void	ways_add(t_ways *ways, t_way *way)
{
	t_way	**new;
	int		index;

	ways->size++;
	new = (t_way **)malloc(sizeof(t_way *) * ways->size);
	index = -1;
	while (++index < (ways->size - 1))
		new[index] = ways->way[index];
	new[index] = way;
	free(ways->way);
	ways->way = new;
}

void	ways_update(t_ways *ways)
{
	t_ways	*ptr1;
	t_ways	*ptr2;
	int		index;
	int		fined;

	ptr1 = ways;
	while (ptr1 != NULL)
	{
		ptr2 = ways;
		while (ptr2 != NULL)
		{
			fined = 1;
			index = -1;
			while (++index < ptr2->size)
				if (way_intersection(ptr1->way[0], ptr2->way[index]) == 0)
					fined = 0;
			if (fined == 1)
				ways_add(ptr2, ptr1->way[0]);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

int		way_cmp(t_way *way1, t_way *way2)
{
	while (way1 != NULL && way2 != NULL && way1->room == way2->room)
	{
		way1 = way1->next;
		way2 = way2->next;
	}
	return (way1 == NULL && way2==NULL);
}

int		ways_fined(t_ways *ways, t_way *way)
{
	int	index;
	
	while (ways != NULL)
	{
		if (way_cmp(ways->way[0], way) == 1)
			return (0);
		ways = ways->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_param		p;
	t_ways		*ways;
	t_way		*new_way;
	t_room		*room;
	int			step;

	param_init(&p);
	read_data(&p);
	new_way = a_star(p.start, p.end, NULL);
/*
	ways = NULL;
	ways = ways_push(ways, new_way);
	room = p.start->next;
	while (room != NULL)
	{
		new_way = a_star(p.start, p.end, room);
		if (new_way != NULL && (ways_fined(ways, new_way) == 1))
			ways = ways_push(ways, new_way);
		room = room->next;
	}
	ways_update(ways);
*/
	step = -1;
	while (++step < (p.ants + way_len(new_way)))
		ant_muve(new_way, way_len(new_way), step, p.ants);
	free_ways_a(new_way, NULL, NULL);
//	ft_print_ways("ways", ways, p.ants);
	room_del(p.start);
	return (0);
}
