/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ways.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:13:13 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/14 13:25:21 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

static void	print_way(t_way *w)
{
	t_way	*tmp;

	if (!w)
		return ;
	ft_printf("%s", w->room->name);
	tmp = w->next;
	while (tmp != w)
	{
		ft_printf(" -> %s", tmp->room->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void		print_ways(t_ways *w)
{
	int		i;

	if (!(w->ways))
		return ;
	i = -1;
	while (++i <= w->count)
	{
		ft_printf("way%d: ", i);
		print_way((w->ways)[i]);
	}
}

void		check_ways(t_param *p)
{
	if (p->w_main.ways == NULL || p->w_main.ways[0] == NULL)
		STOP_IN;
}
