/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 06:30:15 by hharit            #+#    #+#             */
/*   Updated: 2023/01/27 07:43:21 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	default_inter(t_inter *inter)
{
	inter.x = 0;
	inter.y = 0;
	inter.stepx = 0;
	inter.stepy = 0;
	inter.horizontal = false;
	inter.vertical = false;
	inter.distance = 0;
}
