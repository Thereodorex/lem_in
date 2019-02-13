/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:03:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/13 16:03:46 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

void			ft_draw_square(t_data *data, int *pos, int rad, int color)
{
	int	dx;
	int	dy;

	dx = pos[0] - rad - 1;
	while (++dx < (pos[0] + rad))
	{
		dy = pos[1] - rad - 1;
		while (++dy < (pos[1] + rad))
		{
			ft_draw_px(data, dx, dy, color);
		}
	}
}
