/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrhaenys_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:09:51 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/08 14:10:03 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		rrhaenys_main(int argc, char **argv)
{
	t_room	*start;
	int		ants;
	t_turn	*turn;

	ants = 1;
	if (argc == 2)
		ants = ft_atoi(argv[1]);
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
