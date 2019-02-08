/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:29:27 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/08 15:30:24 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_rooms(t_room *start)
{
	t_room	*tmp;
	int		index;

	if (!start)
		return ;
	while (start)
	{
		ft_printf("room.name=%s ants=%d %s\n", start->name,
		start->ants,
		(start->flag == 0 ? "" : (start->flag == 1 ? "Start" : "End")));
		index = -1;
		while (++index < start->size)
			ft_printf("\t->%s:%d\n",
			start->links[index]->name, start->steps[index]);
		start = start->next;
	}
	return ;
}
