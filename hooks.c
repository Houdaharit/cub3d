/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <hharit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:21:28 by ahakam            #+#    #+#             */
/*   Updated: 2023/01/18 00:44:07 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


int	is_valid(int keycode, t_cube *vars, int i, int j)
{
	if (ft_strchr("0", vars->str[i
				+ vars->y_player][j + vars->x_player
			- 1]) && (keycode == 123 || keycode == 0))
		return (1);
	else if (ft_strchr("0", vars->str[i
				+ vars->y_player][j + vars->x_player + 1])
	&& (keycode == 124 || keycode == 2))
		return (1);
	else if (ft_strchr("0", vars->str[i + vars->y_player + 1][j + vars->x_player])
		&& (keycode == 125 || keycode == 1))
		return (1);
	else if (ft_strchr("0", vars->str[i + vars->y_player - 1][j
			+ vars->x_player]) && (keycode == 126 || keycode == 13))
		return (1);
	return (0);
}

int	is_valid_move(int keycode, t_cube *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->str[i])
	{
		j = 0;
		while (vars->str[i][j])
		{
			if (vars->str[i][j] == 'N' || vars->str[i][j] == 'W' || vars->str[i][j] == 'E' || vars->str[i][j] == 'S')
			{
				if ((keycode == 125 || keycode == 1) || (keycode == 126 || keycode == 13)
                     || (keycode == 123 || keycode == 0) || (keycode == 124 || keycode == 2))
					return (is_valid(keycode, vars, i, j));
			}
			j++;
		}
		i++;
	}
	return (0);
}
int	key_hook(int keycode, t_cube *vars)
{	
	if (keycode == 53)
		exit(0);
	if ((keycode == 124 || keycode == 2) && is_valid_move(keycode, vars))
	{
		vars->x_player += 1;
		mlx_clear_window(vars->mlx, vars->mlx_win);
		//draw_map(vars);
	}
	if ((keycode == 1 || keycode == 125) && is_valid_move(keycode, vars))
	{
		vars->y_player += 1;
		mlx_clear_window(vars->mlx, vars->mlx_win);
		//draw_map(vars);
	}
	if (keycode == 0 || keycode == 13 || keycode == 123 || keycode == 126)
		click_handle(keycode, vars);
	return (0);
}

void	click_handle(int keycode, t_cube *vars)
{
	if ((keycode == 0 || keycode == 123) && is_valid_move(keycode, vars))
	{
		vars->x_player -= 1;
		mlx_clear_window(vars->mlx, vars->mlx_win);
		//draw_map(vars);
	}
	if ((keycode == 13 || keycode == 126) && is_valid_move(keycode, vars))
	{
		vars->y_player -= 1;
		mlx_clear_window(vars->mlx, vars->mlx_win);
		//draw_map(vars);
	}
}
