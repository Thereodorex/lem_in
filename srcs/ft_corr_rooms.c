/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corr_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:06:48 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/08 14:07:38 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_corr_rooms(t_room *start)
{
	int	index;

	index = -1;
	while (++index < start->link_size)
		if (start->steps[index] >= 0)
			return (1);
	return (0);
}
