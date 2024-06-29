/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:08:03 by jfita             #+#    #+#             */
/*   Updated: 2024/06/29 15:24:43 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define BUFFERSIZE 10000
# define TILE 32

// Player speed and HP
# define SPEED 4
# define HP 2

// Invader respawn time in millisecs
# define RSPWN 5000

// Map critical errors messages that justify instant termination.
# define MAP_CRITERR0 "/!\\ CRITICAL MAP ERROR /!\\\nError opening map file\n"
# define MAP_CRITERR1 "/!\\ CRITICAL MAP ERROR /!\\\nMap file is not a .ber\n"
# define MAP_CRITERR2 "/!\\ CRITICAL MAP ERROR/!\\\nMap file is unreadable\n"
# define MAP_CRITERR3 "/!\\ CRITICAL MAP ERROR /!\\\nMap split failure\n"

// Map errors messages due to no respect of rules.
# define MAP_ERR0 "-Spawn amount is invalid\n"
# define MAP_ERR1 "-Exit amount is invalid\n"
# define MAP_ERR2 "-No collectibles in map\n"
# define MAP_ERR3 "-Map contains invalid characters\n"
# define MAP_ERR4 "-Map is not surrounded by walls\n"
# define MAP_ERR5 "-Map is not rectangle, won't check further\n"
# define MAP_ERR8 "-Map has empty lines\n"
# define MAP_ERR6 "-Exit is unreachable\n"
# define MAP_ERR7 "-At least one collectible is unreachable\n"

// Error codes sent by check functions. Will be checked before attempting flood,
// Print & terminate if any is found.
# define ERR_S 0
# define ERR_E 1
# define ERR_C 2
# define ERR_I 3
# define ERR_W 4
# define ERR_R 5
# define ERR_L 6
# define CHECK -1

// Player movement directions, each corresponding to a sprite index

# define UP 21
# define DOWN 22
# define LEFT 23
# define RIGHT 24
# define DUL 25
# define DUR 26
# define DDL 27
# define DDR 28

// Invader movement directions

# define INVUP 0
# define INVDOWN 1
# define INVLEFT 2
# define INVRIGHT 3
# define INVDUL 4
# define INVDUR 5
# define INVDDL 6
# define INVDDR 7

// Invader respawn time in millisecs

# define RSPWN 5000

// Images amount for malloc
# define NBRIMG 59

// Textures path and indexes
# define T_WALL1 "textures/roid1.xpm"
# define T_WALL1_IND 0
# define T_WALL2 "textures/roid2.xpm"
# define T_WALL2_IND 1
# define T_WALL3 "textures/roid3.xpm"
# define T_WALL3_IND 2
# define T_WALL4 "textures/roid4.xpm"
# define T_WALL4_IND 3
# define T_WALL5 "textures/roid5.xpm"
# define T_WALL5_IND 4
# define T_WALL6 "textures/roid6.xpm"
# define T_WALL6_IND 5
# define T_WALL7 "textures/roid7.xpm"
# define T_WALL7_IND 6
# define T_WALL8 "textures/roid8.xpm"
# define T_WALL8_IND 7
# define T_WALL9 "textures/roid9.xpm"
# define T_WALL9_IND 8

# define T_BACK "textures/back.xpm"
# define T_BACK_IND 9
# define T_BACK2 "textures/back2.xpm"
# define T_BACK2_IND 10
# define T_BACK3 "textures/back3.xpm"
# define T_BACK3_IND 11
# define T_BACK4 "textures/back4.xpm"
# define T_BACK4_IND 12
# define T_BACK5 "textures/back5.xpm"
# define T_BACK5_IND 13
# define T_BACK6 "textures/back6.xpm"
# define T_BACK6_IND 14
# define T_BACK7 "textures/back7.xpm"
# define T_BACK7_IND 15
# define T_BACK8 "textures/back8.xpm"
# define T_BACK8_IND 16
# define T_BACK9 "textures/back9.xpm"
# define T_BACK9_IND 17
# define T_BACK10 "textures/back10.xpm"
# define T_BACK10_IND 18
# define T_BACKN "textures/backn.xpm"
# define T_BACKN_IND 19
# define T_EXIT "textures/gate.xpm"
# define T_EXIT_IND 20

# define T_SHIPUP "textures/ship.xpm"
# define T_SHIPUP_IND 21
# define T_SHIPDOWN "textures/ship_down.xpm"
# define T_SHIPDOWN_IND 22
# define T_SHIPLEFT "textures/ship_left.xpm"
# define T_SHIPLEFT_IND 23
# define T_SHIPRIGHT "textures/ship_right.xpm"
# define T_SHIPRIGHT_IND 24
# define T_SHIPDUL "textures/ship_dul.xpm"
# define T_SHIPDUL_IND 25
# define T_SHIPDUR "textures/ship_dur.xpm"
# define T_SHIPDUR_IND 26
# define T_SHIPDDL "textures/ship_ddl.xpm"
# define T_SHIPDDL_IND 27
# define T_SHIPDDR "textures/ship_ddr.xpm"
# define T_SHIPDDR_IND 28

# define T_COLLECT "textures/planet.xpm"
# define T_COLLECT_IND 29
# define T_COLLECT1 "textures/planet1.xpm"
# define T_COLLECT1_IND 30
# define T_COLLECT2 "textures/planet2.xpm"
# define T_COLLECT2_IND 31
# define T_COLLECT3 "textures/planet3.xpm"
# define T_COLLECT3_IND 32
# define T_COLLECT4 "textures/planet4.xpm"
# define T_COLLECT4_IND 33
# define T_COLLECT5 "textures/planet5.xpm"
# define T_COLLECT5_IND 34
# define T_COLLECT6 "textures/planet6.xpm"
# define T_COLLECT6_IND 35
# define T_COLLECT7 "textures/planet7.xpm"
# define T_COLLECT7_IND 36
# define T_COLLECT8 "textures/planet8.xpm"
# define T_COLLECT8_IND 37

# define T_TERRA "textures/terra.xpm"
# define T_TERRA_IND 38
# define T_TERRA1 "textures/terra1.xpm"
# define T_TERRA_IND1 39
# define T_TERRA2 "textures/terra2.xpm"
# define T_TERRA_IND2 40
# define T_TERRA3 "textures/terra3.xpm"
# define T_TERRA_IND3 41
# define T_TERRA4 "textures/terra4.xpm"
# define T_TERRA_IND4 42

# define T_LASER "textures/laser.xpm"
# define T_LASER_IND 43
# define T_LASER1 "textures/laser1.xpm"
# define T_LASER1_IND 44
# define T_LASER2 "textures/laser2.xpm"
# define T_LASER2_IND 45
# define T_LASER3 "textures/laser3.xpm"
# define T_LASER3_IND 46

# define T_VLASER "textures/vert_laser.xpm"
# define T_VLASER_IND 47
# define T_VLASER1 "textures/vert_laser1.xpm"
# define T_VLASER1_IND 48
# define T_VLASER2 "textures/vert_laser2.xpm"
# define T_VLASER2_IND 49
# define T_VLASER3 "textures/vert_laser3.xpm"
# define T_VLASER3_IND 50

# define T_INVADER "textures/invader.xpm"
# define T_INVADER_IND 51
# define T_INVADER1 "textures/invader1.xpm"
# define T_INVADER1_IND 52
# define T_INVADER2 "textures/invader2.xpm"
# define T_INVADER2_IND 53
# define T_INVADERS "textures/invader_spawn.xpm"
# define T_INVADERS_IND 54

# define T_BOOM "textures/boom.xpm"
# define T_BOOM_IND 55
# define T_BOOM1 "textures/boom1.xpm"
# define T_BOOM1_IND 56
# define T_BOOM2 "textures/boom2.xpm"
# define T_BOOM2_IND 57
# define T_BOOM3 "textures/boom3.xpm"
# define T_BOOM3_IND 58

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct s_pos
{
	size_t		x;
	size_t		y;
}				t_pos;

typedef struct s_player
{
	t_pos		*pos;
	int			pp[2];
	int			tl[2];
	int			tr[2];
	int			bl[2];
	int			br[2];
	int			pc[2];
	size_t		tc[2];
	size_t		move_left;
	size_t		move_right;
	size_t		move_up;
	size_t		move_down;
	size_t		move_dul;
	size_t		move_dur;
	size_t		move_ddl;
	size_t		move_ddr;
	size_t		collect;
	size_t		dir;
	size_t		moves;
	size_t		hp;
	bool		moving;
	bool		shooting;
	long long	last_shoot;
	long long	cooldown;
	long long	inv_frame;
}				t_player;

typedef struct s_invader
{
	int			pp[2];
	int			tl[2];
	int			tr[2];
	int			bl[2];
	int			br[2];
	int			pc[2];
	size_t		tc[2];
	int			spawn[2];
	int			sprite;
	size_t		dir;
	bool		moving;
	bool		alive;
	bool		collide;
	long long	last_death;
	long long	cooldown;
}				t_invader;

typedef struct s_map
{
	char		**tab_map;
	char		*filename;
	char		*bigstr;
	int			exit[2];
	size_t		nb_collect;
	size_t		nb_spawn;
	size_t		nb_exit;
	size_t		nb_invaders;
	size_t		width;
	size_t		height;
	t_pos		*pos;
}				t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_img		***img_array;
	size_t		nb_imgs;
	t_map		*map;
	t_map		*fmap;
	t_player	*player;
	t_list		*invader;
	t_pos		*laser;
	long long	tictac;
}				t_data;

typedef struct s_error
{
	bool		err_spawn;
	bool		err_ext;
	bool		err_col;
	bool		err_inv;
	bool		err_wall;
	bool		err_rect;
	bool		err_line;
}				t_error;

void			check_flooding(const t_map *map, t_map *fmap);
void			map_flood(const t_data *data);
void			map_check_elems(char const *str);
void			map_check_walls(const t_map *map);
void			map_check_dims(t_map *map);
void			map_check_filetype(const t_map *map);
void			map_check_line(const char *str);

t_map			*map_zero(void);
t_error			*error_zero(void);
t_data			*data_zero(void);
t_img			*img_zero(void);
t_player		*player_zero(void);

int				char_check(char const *str);
int				count_char(char const *str, char c);
void			parse_map(t_data *data, int fd);
void			map_get_elems(t_map *map);
char			*read_map(int fd);
void			map_get_dims(t_data *data);
void			map_get_pos(t_map *map, char c);
void			check_report(int err_no);
void			err_set(int err_no, t_error *map_err);
bool			err_eval(t_error *map_err);
void			err_print(t_error *map_err);
int				err_terminate(char *msg);
void			check_terminate(t_data *data);
void			get_and_check(t_data *data);

t_data			*init_data(const char *mapfile);
void			init_mlx(t_data *data, size_t width, size_t height);
void			init_img(t_data *data);
void			init_first_sprites(t_data *data);
void			init_second_sprites(t_data *data);
void			init_bonus_sprites(t_data *data);

void			xpm_to_img(t_data *data, size_t i, char *path);
void			put_image(t_data *data, size_t i, size_t x, size_t y);

void			start_game(const char *mapfile);

void			free_data(t_data *data);
void			free_map(t_map *map);
void			free_mlx(t_data *data);
void			free_player(t_player *player);
void			free_array(t_data *data);
void			free_invader(t_data *data);

int				handle_keypress(int keysym, t_data *data);
int				handle_keyrelease(int keysym, t_data *data);
int				on_destroy(t_data *data);

int				ft_range_rand(int max);
int				ft_rand(void);
size_t			pseudo_rand(size_t x, size_t y, size_t range, t_data *data);
void			init_pos(t_data *data, char c);

void			update_pos(t_data *data);
int				get_rdist(t_data *data);
int				get_ldist(t_data *data);
int				get_ddist(t_data *data);
int				get_udist(t_data *data);

t_img			***create_img_array(t_data *data);
void			initialize_array(t_data *data);
void			fill_img_array(t_data *data, int i, int j);

void			render_player(t_data *data, int index);
void			draw_movement(t_data *data);
void			put_movement(t_data *data, int x, int y);
void			draw_img_array(t_data *data);

void			collect_collide(t_data *data);
void			terraform(t_data *data, int i, int j);
void			exit_collide(t_data *data);

void			move_straight(t_data *data, int dir);
void			move_diag(t_data *data, int dir);
void			movement(t_data *data);
void			move_player(t_data *data, int dir);

void			chrono(t_data *data);
long long		millitimestamp(void);

void			shoot_right(t_data *data);
void			shoot_left(t_data *data);
void			shoot_up(t_data *data);
void			shoot_down(t_data *data);
void			shoot(t_data *data);
void			render_laser(t_data *data, int x, int y, int index);

void			invader_alloc(int i, int j, t_data *data);
void			init_invader(t_data *data);
void			update_invader(t_data *data);
void			render_invader(t_data *data, t_invader *invader);

void			update__invader_pos(t_invader *invader);
void			draw_invader(t_data *data, t_invader *invader);

void			invader_movement(t_invader *invader);
void			inv_move_diag(t_invader *invader, int dir, t_data *data);
void			inv_move_straight(t_invader *invader, int dir, t_data *data);
void			move_invader(t_invader *invader, int dir, t_data *data);

void			player_collide(t_data *data, t_invader *invader);

int				get_invudist(t_invader *invader, t_data *data);
int				get_invddist(t_invader *invader, t_data *data);
int				get_invldist(t_invader *invader, t_data *data);
int				get_invrdist(t_invader *invader, t_data *data);

void			laser_collide(t_data *data, size_t index);
void			check_laser(t_invader *invader, t_data *data, size_t index);

void			render_boom(t_data *data, t_invader *invader);

void			respawn_invader(t_invader *invader);
void			kill_invader(t_invader *invader);

void			render_hud(t_data *data);
void			reset_hud(t_data *data);
void			render_hud_moves(t_data *data);

#endif