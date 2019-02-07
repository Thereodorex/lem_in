/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:26:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/07 17:30:47 by rrhaenys         ###   ########.fr       */
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
		ft_printf("room.name=%s\n", start->name);
		index = -1;
		while (++index < start->link_size)
			ft_printf("\tlink with %s\n",
			start->links[index]->name);
		start = start->next;
	}
	return ;
}
