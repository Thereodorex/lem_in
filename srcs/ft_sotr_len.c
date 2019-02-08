/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sotr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 21:54:54 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/08 22:43:54 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_swap_room(t_room **room1, t_room **room2)
{
	t_room *room;

	if (room1 == room2)
		return ;
	room = *room1;
	*room1 = *room2;
	*room2 = room;
}

static void	ft_swap_int(int *p1, int *p2)
{
	int p;

	if (p1 == p2)
		return ;
	p = *p1;
	*p1 = *p2;
	*p2 = p;
}

void		ft_sotr_len(t_room *this)
{
	int	index;
	int	max;
	int	size;

	if (this->visited == 1)
		return ;
	this->visited = 1;
	size = this->size + 1;
	while (--size > 0)
	{
		index = -1;
		max = 0;
		while (++index < size)
		{
			if (this->steps[max] < this->steps[index])
				max = index;
		}
		ft_swap_room(&this->links[max], &this->links[size - 1]);
		ft_swap_int(&this->steps[max], &this->steps[size - 1]);
	}
	index = -1;
	while (++index < this->size)
		ft_sotr_len(this->links[index]);
	this->visited = 0;
}
