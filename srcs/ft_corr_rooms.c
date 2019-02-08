/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corr_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:06:48 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/08 15:36:42 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_corr_rooms(t_room *end)
{
	int	index;

	index = -1;
	while (++index < end->size)
		if (end->steps[index] >= 0)
			return (1);
	return (0);
}
