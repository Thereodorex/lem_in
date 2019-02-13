/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_px.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:02:07 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/13 16:02:16 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

void			ft_draw_px(t_data *data, int x, int y, int color)
{
	float z;

	if (data->img.size_l <= 100)
		return ;
	x = (int)(WIN_W / 10 + x);
	y = (int)(WIN_H * 9 / 10 - y - 1);
	z = x + (y * WIN_W);
	if (z >= 0 && z < WIN_S &&
		x >= 0 && x <= WIN_W &&
		y >= 0)
		data->img.data[y * WIN_W + x] = color;
}
