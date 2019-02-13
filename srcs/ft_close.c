/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:00:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/13 16:00:40 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

int				ft_close(t_data *data)
{
	free(data->data);
	free(data->data->steps);
	free(data->data->pos);
	free(data->data->old_pos);
	exit(0);
	return (0);
}
