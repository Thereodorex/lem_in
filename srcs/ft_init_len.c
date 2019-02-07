/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:55:46 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/07 19:18:47 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_get_min_len(t_room *this)
{
	int	index;
	int	min;

	index = -1;
	if (this->link_size == 0)
		return (-1);
	min = this->steps[0];
	while (++index < this->link_size)
		if (min > this->steps[index] || min < 0)
			min = this->steps[index];
	return (min);
}

static int		ft_init_len1(t_room *this, int len)
{
	int	index;

	if (this->flag == -1)
		return (0);
	if (this->visited == 1)
		return (-1);
	this->visited = 1;
	index = -1;
	while (++index < this->link_size)
		this->steps[index] = ft_init_len1(this->links[index], len + 1);
	this->visited = 0;
	return (ft_get_min_len(this) + 1);
}

static void	ft_init_len2(t_room *this)
{
	int	index;

	if (this->visited == 1)
		return ;
	this->visited = 1;
	index = -1;
	while (++index < this->link_size)
	{
		if (this->steps[index] == -1)
			this->steps[index] = ft_get_min_len(this->links[index]) + 1;
		ft_init_len2(this->links[index]);
	}
	this->visited = 0;
}

void		ft_init_len(t_room *start)
{
	ft_init_len1(start, 0);
	ft_init_len2(start);
}
