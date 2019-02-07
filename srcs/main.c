/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:11:22 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/07 21:39:53 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main()
{
	t_room	*start;
	int		ants;
	t_turn	*turn;

	ants = 3;
	start =	ft_init_rooms(ants);
	ft_init_len(start);
	if (ft_corr_rooms(start) == 0)
	{
		ft_printf("There is no way!\n");
		exit(0);
	}
	ft_sotr_len(start);
//	ft_print_rooms(start);
	turn = ft_init_turn_ant(ants, start);
	while (ft_muve_turn(turn) > 0)
		ft_printf("\n");
	ft_free_turn(turn);
//	ft_print_rooms(start);
	room_del(start);
	return (0);
}
