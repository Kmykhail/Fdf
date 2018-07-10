/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:13:00 by kmykhail          #+#    #+#             */
/*   Updated: 2018/03/15 21:13:02 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# define LNE	tool->line
# define ITR	tool->itr
# define S_BUFF	tool->s_buff
# define CL_NUM	tool->cl_num
# define ARR	tool->buff
# define CHR	ft_strchr
# define SCALE	tool->scale
# define MLX_PTR	tool->mlx_ptr
# define WIN_PTR	tool->win_ptr
# define C_X	dot->mass[i]->x
# define C_Y	dot->mass[i]->y
# define C_Z	dot->mass[i]->z
# define COS_X	tool->cos_x
# define COS_Y	tool->cos_y
# define COS_Z	tool->cos_z
# define SIN_X	tool->sin_x
# define SIN_Y	tool->sin_y
# define SIN_Z	tool->sin_z
# define FAULT	tool->fault
# define F2		tool->f2
# define DIST	tool->dist
# define MVX	tool->mvx
# define MVY	tool->mvy
# define DEPTH	tool->depth
# define ZOOM	tool->zoom
# define ERROR	tool->error
# define RX		tool->rx
# define RY		tool->ry

typedef struct		s_dots
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_dots	**mass;
}					t_dot;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				zoom;
	int				mvx;
	int				mvy;
	int				mvz;
	int				rx;
	int				ry;
	int				s_dot;
	int				str_x;
	int				end_y;
	float			depth;
	int				dx;
	int				sx;
	int				sy;
	int				fault;
	int				f2;
	int				dy;
	int				s_buff;
	int				itr;
	char			*line;
	char			**buff;
	int				*num;
	int				ch;
	int				dist;
	int				error;
	int				ang_x;
	double			cos_x;
	double			cos_y;
	double			cos_z;
	double			sin_x;
	double			sin_y;
	double			sin_z;
	int				ang_y;
	int				ang_z;
	int				scale;
	t_dot			*cp_new;
	t_dot			*cp_org;
}					t_tool;

int					ft_valid_line(t_tool *tool);
void				ft_free_struct(t_dot **dot);
int					ft_z_color(t_tool *tool, int c);
int					ft_cnt_num(t_tool *tool);
void				ft_init_var_1(t_tool *tool, t_dot *dot);
void				ft_init_var_2(t_tool *tool);
void				ft_calcul_pixel(t_dot *dot, t_tool *tool);
void				ft_fill_dots_2(t_dot *dot, t_tool *tool, int c, int l);
int					ft_press_butt(int key, t_tool *tool);
int					ft_mouse_exit(void	*par);
void				ft_del_tool(t_tool **tool);
void				ft_bind_key(t_tool *tool);
void				ft_print_about(t_tool *tool);
void				ft_del_struct(t_dot **dot);
void				ft_fill_dots(t_dot *dot, t_tool *tool, int l);
#endif
