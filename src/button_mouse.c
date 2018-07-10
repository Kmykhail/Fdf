/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:13:00 by kmykhail          #+#    #+#             */
/*   Updated: 2018/03/15 21:13:02 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_del_struct(t_dot **new)
{
	int i;

	i = 0;
	while ((*new)->mass && (*new)->mass[i])
	{
		free((*new)->mass[i]);
		(*new)->mass[i] = NULL;
		i++;
	}
	free((*new)->mass);
	(*new)->mass = NULL;
	free(*new);
	*new = NULL;
}

void    ft_default_butt(t_tool *tool)
{
    MVX = 0;
    MVY = 0;
    DEPTH = 0.0;
    ZOOM = 0;
    tool->ang_x = 0;
    tool->ang_y = 0;
    tool->ang_z = 0;
    tool->cos_x = 0;
    tool->cos_y = 0;
    tool->cos_z = 0;
    tool->sin_x = 0;
    tool->sin_y = 0;
    tool->sin_z = 0;
}

int		ft_press_butt(int key, t_tool *tool)
{
	if (key == 53)
	{
		ft_del_tool(&tool);
		exit(1);
	}
    if (key == 76)
        ft_default_butt(tool);
	else if (key == 126 || key == 125)
		MVY += (key == 126) ? -5 : 5;
	else if (key == 123 || key == 124)
		MVX += (key == 123) ? -5 : 5;
	else if (key == 86 || key == 83)
		tool->ang_y += (key == 86) ? -5 : 5;
	else if (key == 87 || key == 84)
		tool->ang_x += (key == 87) ? -5 : 5;
	else if (key == 88 || key == 85)
		tool->ang_z += (key == 88) ? -5 : 5;
	else if (key == 89 || key == 91)
		DEPTH += (key == 89) ? -0.1 : 0.1;
	else if (key == 78 || key == 69)
    {
        ZOOM += (key == 69) ? 1 : 0;
        ZOOM += (key == 78 && ZOOM > 0) ? -1 : 0;
    }
    mlx_clear_window(MLX_PTR, WIN_PTR);
	ft_del_struct(&tool->cp_new);
	free(tool->cp_new);
	ft_calcul_pixel(tool->cp_org, tool);
	return (0);
}

void	ft_bind_key(t_tool *tool)
{
	ft_print_about(tool);
	mlx_hook(WIN_PTR, 2, 5, ft_press_butt, tool);
	mlx_hook(WIN_PTR, 17, 4, ft_mouse_exit, (void *)0);
}

int		ft_mouse_exit(void *par)
{
	par = NULL;
	exit(1);
}
