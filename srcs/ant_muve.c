/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_muve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:51:28 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/11 17:54:53 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ant_muve(t_way *way, int way_size, int step, int ants)
{
	int		index_w;
	char	*str;
	char	*nbr;

	index_w = -1;
	str = ft_strnew(1000);
	ft_bzero(str, 1000);
	while (way != NULL && step > 0)
	{
		if (step <= ants)
		{
			ft_strcat(str, "L");
			nbr = ft_itoa(step);
			ft_strcat(str, nbr);
			free(nbr);
			ft_strcat(str, "-");
			ft_strcat(str, way->room->name);
			ft_strcat(str, " ");
		}
		step--;
		way = way->next;
	}
	ft_putendl(str);
	free(str);
}
