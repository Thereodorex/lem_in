/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 20:48:22 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/12 20:48:33 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

void			ft_draw_way(t_data *data, t_way *way, float scale, int color)
{
	int		p_start[2];
	t_way	*start;

	start = way;
	p_start[0] = way->room->x * scale;
	p_start[1] = way->room->y * scale;
	ft_draw_square(data, p_start, 12, 0xffff00);
	way = way->next;
	while (way != start)
	{
		p_start[0] = way->room->x * scale;
		p_start[1] = way->room->y * scale;
		if (way->room == data->data->p->end)
			ft_draw_square(data, p_start, 12, 0x00ffff);
		else
			ft_draw_square(data, p_start, 12, color);
		way = way->next;
	}
}

void			ft_draw_ways(t_data *data, t_ways *ways, float scale, int color)
{
	int	index;

	index = -1;
	while (++index <= ways->count)
		ft_draw_way(data, ways->ways[index], scale, color);
}
