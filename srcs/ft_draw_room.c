/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:07:17 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/13 16:12:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

void			ft_draw_room(t_data *data, t_room *room, float scale, int color)
{
	int		p_start[2];

	while (room != NULL)
	{
		p_start[0] = room->x * scale;
		p_start[1] = room->y * scale;
		ft_draw_square(data, p_start, 10, color);
		room = room->next;
	}
}
