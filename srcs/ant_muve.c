/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_muve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:51:28 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/13 22:23:35 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

void	ft_printf_step(char *str, int step, char *name)
{
	char	*nbr;

	if (ft_strlen(str) > 0)
		ft_strcat(str, " ");
	if (ft_strlen(str) >= 900)
	{
		ft_putstr(str);
		ft_bzero(str, 1000);
	}
	ft_strcat(str, "L");
	nbr = ft_itoa(step);
	ft_strcat(str, nbr);
	free(nbr);
	ft_strcat(str, "-");
	ft_strcat(str, name);
}

void	ft_printf_way_step(t_way *way, int *ram, int step, char *str)
{
	t_way	*way_start;

	way_start = way;
	way = way->next;
	while (way != way_start && step > 0)
	{
		if (step <= (ram[1] - ram[0]))
		{
			ft_printf_step(str, (step + ram[0]), way->room->name);
		}
		step--;
		way = way->next;
	}
}

int		ant_muve(t_ways *ways, int step, int *map)
{
	int		index;
	char	str[1000];
	int		ra[2];
	int		ret;

	bzero(str, 1000);
	ret = 0;
	index = -1;
	while (++index <= (ways->count))
	{
		ra[0] = map[index];
		ra[1] = map[index + 1];
		ft_printf_way_step(ways->ways[index], ra, step, str);
	}
	ft_putstr(str);
	if (ft_strlen(str) > 0)
	{
		ft_putchar('\n');
		ret = 1;
	}
	return (ret);
}

t_room	*get_room_way(t_way *way, int step, int ants, int num)
{
	t_way	*start;

	start = way;
	if (step <= 0)
		return (way->room);
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

t_room	*get_room(t_ways *ways, int step, int ants, int num)
{
	int		index;
	int		ra[2];
	int		*map;

	map = testfun(ways, ants);
	index = -1;
	while (++index <= (ways->count))
	{
		ra[0] = map[index];
		ra[1] = map[index + 1];
		if (ra[0] < num && num <= ra[1])
			return (get_room_way(ways->ways[index], step,
								ra[1] - ra[0], num - ra[0]));
	}
	return (NULL);
}
