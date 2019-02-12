/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_muve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:51:28 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/12 20:48:34 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

void	ant_muve(t_ways *ways, int way_size, int step, int ants)
{
	int		index_w;
	t_way	*start;
	char	*str;
	char	*nbr;
	t_way	*way;

	way = ways->ways[0];
	index_w = -1;
	str = ft_strnew(1000);
	ft_bzero(str, 1000);
	start = way;
	way = way->next;
	while (way != start && step > 0)
	{
		if (step <= ants)
		{
			if (ft_strlen(str) > 0)
				ft_strcat(str, " ");
			ft_strcat(str, "L");
			nbr = ft_itoa(step);
			ft_strcat(str, nbr);
			free(nbr);
			ft_strcat(str, "-");
			ft_strcat(str, way->room->name);
		}
		step--;
		way = way->next;
	}
	if (ft_strlen(str) > 0)
		ft_putendl(str);
	free(str);
}

t_room	*get_room(t_ways *ways, int step, int ants, int num)
{
	t_way	*start;
	t_way	*way;

	way = ways->ways[0];
	start = way;
	way = way->next;
	while (way != start && step > 0)
	{
		if (step <= ants)
		{
			if (step == num)
				return (way->room);
		}
		step--;
		way = way->next;
	}
	return (NULL);
}
