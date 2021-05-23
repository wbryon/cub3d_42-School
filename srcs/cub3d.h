/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:54:29 by wbryon            #+#    #+#             */
/*   Updated: 2021/02/26 18:43:39 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"

typedef	struct	s_keys
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			look_left;
	int			look_right;
	int			esc;
}				t_keys;

typedef struct	s_check
{
	int			shot;
	int			id_count;
	int			r;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			s;
	int			f;
	int			c;
}				t_check;

typedef struct	s_color
{
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
}				t_color;
typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			line_l;
	int			bpp;
	int			endian;
	int			shot_w;
	int			shot_h;
	int			screen_w;
	int			screen_h;
}				t_win;

typedef	struct	s_tx
{
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	int			ceil;
	int			floor;
	int			ceil_color;
	int			floor_color;
	int			tx_h;
	int			tx_w;
	int			texx;
	int			texy;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		step;
	double		texpos;
	void		*img_no;
	void		*img_so;
	void		*img_ea;
	void		*img_we;
	char		*addr_no;
	char		*addr_so;
	char		*addr_ea;
	char		*addr_we;
	int			line_l;
	int			bpp;
	int			en;
}				t_tx;

typedef	struct	s_sprite
{
	char		*path_s;
	char		*addr;
	void		*img;
	int			line_l;
	int			bpp;
	int			en;
	int			spritescreenx;
	int			vmovescreen;
	int			spriteheight;
	int			spritewidth;
	int			drawstartx;
	int			drawendx;
	int			drawstarty;
	int			drawendy;
	int			stripe;
	int			tx_h;
	int			tx_w;
	int			texx;
	int			texy;
	int			texture;
	int			*spriteorder;
	int			nbsprites;
	double		*x;
	double		*y;
	double		invdet;
	double		spritex;
	double		spritey;
	double		transformx;
	double		transformy;
	double		*spritedist;
	double		tmp_dist;
	double		*zbuffer;
}				t_sprite;

typedef	struct	s_player
{
	int			hit;
	int			side;
	int			stepx;
	int			stepy;
	double		wallx;
	double		posx;
	double		posy;
	double		invdet;
	double		dirx;
	double		diry;
	double		olddirx;
	double		olddiry;
	double		movespeed;
	double		planex;
	double		planey;
	double		oldplanex;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	double		pwd;
	double		coef;
	double		diff;
	int			plr_count;
}				t_player;

typedef	struct	s_map
{
	char		**map;
	int			mapx;
	int			mapy;

}				t_map;

typedef	struct	s_all
{
	t_keys		key;
	t_check		check;
	t_color		col;
	t_tx		tx;
	t_win		win;
	t_player	plr;
	t_sprite	sprite;
	t_map		map;
}				t_all;

void			make_map(t_list **head, int size, t_all *all);
void			read_map(char *argv, t_all *all);
void			clear_file(t_list *file);
void			sortsprites(t_all *all);
void			init_player(t_all *all);
void			read_plr_pos(char *line, t_all *all);
void			position_n_s(char *line, t_all *all);
void			position_w_e(char *line, t_all *all);
void			init_sprite(t_all *all);
void			init_all_vars(t_all *all);
void			init_plr_vars(t_all *all);
void			init_sprite_vars(t_all *all);
void			init_tx_vars(t_all *all);
void			init_win_check_vars(t_all *all);
void			dda_execute(t_all *all);
void			init_distance(t_all *all);
void			ray_direction(t_all *all, int x);
void			cast_rays(t_all *all);
void			sprite_position(t_all *all, int i);
void			ray_sprite(t_all *all, int y);
void			sprite_width(t_all *all);
void			draw_texture(t_all *all, int x, int y);
void			draw_sprite(t_all *all, int y);
void			my_mlx_pixel_put(t_all *all, int x, int y, int color);
void			my_mlx_texel_put(t_all *all, int x, int y);
void			draw_vert_line(t_all *all, int x, int y);
void			sprite_put(t_all *all, int x, int y);
void			create_image(t_all *all);
void			get_image(t_all *all);
int				move_key(t_all *all);
int				key_press(int key, t_all *all);
int				key_release(int key, t_all *all);
int				rule(t_all *all);
void			move_up_down(t_all *all, double speed);
void			move_left_right(t_all *all, double speed);
void			look_left_right(t_all *all, double rs);
int				exit_hook(void);
int				check_valid_id(char *line);
void			parse_id(t_all *all);
void			id_distributor(char *line, t_all *all);
void			parse_r(char *line, t_all *all);
void			parse_path_no(char *line, t_all *all);
void			parse_path_so(char *line, t_all *all);
void			parse_path_we(char *line, t_all *all);
void			parse_path_ea(char *line, t_all *all);
void			parse_path_s(char *line, t_all *all);
void			parse_c(char *line, t_all *all);
void			parse_f(char *line, t_all *all);
void			get_resolution(char **line, t_all *all);
void			get_tx_no(t_all *all);
void			get_tx_so(t_all *all);
void			get_tx_we(t_all *all);
void			get_tx_ea(t_all *all);
void			get_tx_s(t_all *all);
void			get_textures(t_all *all);
void			get_colors(char *line, t_all *all);
int				skip_spaces(char *line);
int				skip_digits(char *line);
int				begin_map(t_all *all);
int				end_map(t_all *all);
int				check_chars_in_map(t_all *all);
int				check_chars_joined(int i, int j, int ret, t_all *all);
int				check_around_character(int i, int j, int ret, t_all *all);
void			check_map_extension(char *str);
void			check_open(char *str);
void			errors_table_1(int error_nb);
void			errors_table_2(int error_nb);
void			errors_table_3(int error_nb);
void			errors_table_4(int error_nb);
void			errors_table_5(int error_nb);
void			errors_table_6(int error_nb);
void			errors_table_7(int error_nb);
void			errors_table_8(int error_nb);
void			errors_table_9(int error_nb);
void			errors_table_10(int error_nb);
void			screenshot(t_all *all);
void			take_shot(t_all *all);
void			bitmap_header(t_all *all, int fd_read);
void			bitmap_info(t_all *all, int fd_read);
void			fill_color(t_all *all, int fd_read);
void			play_game(t_all *all);

#endif
