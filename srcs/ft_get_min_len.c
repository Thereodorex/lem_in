/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:57:09 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/08 23:43:58 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_get_min_len(t_room *this)
{
	int	index;
	int	min;

	index = -1;
	if (this->size == 0)
		return (-1);
	min = this->steps[0];
	while (++index < this->size)
		if (min > this->steps[index] || min < 0)
			min = this->steps[index];
	return (min);
}

static void		ft_toroom(t_room *this, t_room *me, int len)
{
	int	index;

	index = -1;
	while (++index < this->size)
		if (this->links[index] == me)
			this->steps[index] = len;
}

static int		ft_init_len1(t_room *this, int len)
{
	int	index;
	int	min;

	if (this->flag == -1)
		return (0);
	if (this->visited == 1)
		return (-1);
	this->visited = 1;
	index = -1;
	min = -1;
	while (++index < this->size)
	{
		if (this->steps[index] == -1)
		{
			this->steps[index] = ft_init_len1(this->links[index], len);
			if (this->steps[index] != -1)
				ft_toroom(this->links[index], this, this->steps[index] + 1);
		}
		if (this->steps[index] != -1)
		{
			if (min == -1)
				min = this->steps[index] + 1;
			else if (min > (this->steps[index] + 1))
				min = this->steps[index] + 1;
		}
	}
	this->visited = 0;
	return (min);
}

static int	ft_init_len2(t_room *this)
{
	int	index;
	int	min;

	index = -1;
	min = -1;
	ft_printf("s %s\n", this->name);
	while (++index < this->size)
	{
		if (this->steps[index] == -1)
			this->steps[index] = ft_init_len2(this->links[index]) + 1;
		if (min == -1)
			min = this->steps[index];
		else if (min > this->steps[index])
			min = this->steps[index];
	}
	ft_printf("f %s\n", this->name);
	return (min);
}

void		ft_init_len(t_param *p)
{
	t_room	*room;

	ft_init_len1(p->start, 0);
/*	room = p->start;
	while (room != NULL)
	{
		ft_init_len2(room);
		room = room->next;
	}*/
}
