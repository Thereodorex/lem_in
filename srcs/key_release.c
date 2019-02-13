/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:01:01 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/02/13 16:01:21 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "rrhaenys.h"

int				key_release(int key, t_data *data)
{
	if (key == 53)
		ft_close(data);
	else if (key == 49)
		data->data->step++;
	else if (key == 256)
		data->data->step = 0;
	return (1);
}
