/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:07:19 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/08 14:07:49 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_turn(t_turn *turn)
{
	t_turn	*ptr;

	while (turn != NULL)
	{
		ptr = turn;
//		ft_printf("%s %s\n", turn->name, turn->room->name);
		turn = turn->next;
		free(ptr->name);
		free(ptr);
	}
}
