/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_fast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:04:08 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/13 16:06:04 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

void		line_fast(t_data *data, int *p1, int *p2, int color)
{
	int i;
	int x[2];
	int p[2];

	x[0] = abs((int)(p2[1] - p1[1])) >> 1;
	x[1] = abs((int)(p2[0] - p1[0])) >> 1;
	ft_draw_px(data, (p[0] = p1[0]),
				(p[1] = p1[1]), color);
	if (((i = -1) == -1) && abs((int)(p2[0] - p1[0])) >=
		abs((int)(p2[1] - p1[1])))
		while (++i < abs((int)(p2[0] - p1[0])))
		{
			BLOCK_2(x[1], abs((int)(p2[0] - p1[0])), p[1],
			SGN(p2[1] - p1[1]), abs((int)(p2[1] - p1[1])));
			ft_draw_px(data, (p[0] += SGN(p2[0] - p1[0])), p[1], color);
		}
	else
		while (++i < abs((int)(p2[1] - p1[1])))
		{
			BLOCK_2(x[0], abs((int)(p2[1] - p1[1])), p[0],
			SGN(p2[0] - p1[0]), abs((int)(p2[0] - p1[0])));
			ft_draw_px(data, p[0], (p[1] += SGN(p2[1] - p1[1])), color);
		}
}

void		ft_draw_lines(t_data *data,
							t_room *room, float scale, int color)
{
	int		index;
	int		p_start[2];
	int		p_fin[2];

	while (room != NULL)
	{
		index = -1;
		p_start[0] = room->x * scale;
		p_start[1] = room->y * scale;
		while (++index < room->l_count)
		{
			p_fin[0] = room->links[index]->x * scale;
			p_fin[1] = room->links[index]->y * scale;
			line_fast(data, p_start, p_fin, color);
		}
		room = room->next;
	}
}
