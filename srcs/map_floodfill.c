/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_floodfill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:50:49 by jfita             #+#    #+#             */
/*   Updated: 2024/04/26 14:29:01 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_flooding(const t_map *map, t_map *fmap)
{
	if (fmap->nb_collect != map->nb_collect || fmap->nb_exit != map->nb_exit)
	{
		ft_printf("/!\\ MAP PATHING ERROR /!\\\n");
		if (fmap->nb_collect != map->nb_collect)
			ft_printf(MAP_ERR7);
		if (fmap->nb_exit != map->nb_exit)
			ft_printf(MAP_ERR6);
		err_terminate("--REVIEW WALL PLACEMENTS--\n");
	}
}

static void	floodfill(t_map *fmap, size_t x, size_t y)
{
	if (fmap->tab_map[y][x] == '1') //condition de retour final. 
		return ; // Si la case renvoyee est un 1, c'est qu'on a rempli toute la map
	else if (fmap->tab_map[y][x] == 'E')
		++(fmap->nb_exit); //on a trouve la sortie
	else if (fmap->tab_map[y][x] == 'C')
		++(fmap->nb_collect); //on a trouve un collect
	fmap->tab_map[y][x] = '1'; //A chaque call, remplacer la case sur laquelle on se trouve par un 1
	
	if (y - 1 > 0 && fmap->tab_map[y - 1][x] != '1') // si c'est different de 1 c'est qu'on peut avancer
		floodfill(fmap, x, y - 1); //On teste vers le haut
	if (y + 1 < fmap->height && fmap->tab_map[y + 1][x] != '1')
		floodfill(fmap, x, y + 1); //vers le bas
	if (x - 1 > 0 && fmap->tab_map[y][x - 1] != '1')
		floodfill(fmap, x - 1, y); // vers la gauche
	if (x + 1 < fmap->width && fmap->tab_map[y][x + 1] != '1')
		floodfill(fmap, x + 1, y); //vers la droite

	//la fonction teste toutes les cases traversables et les change en 1. 
	//Si on peut plus bouger c'est que tout est rempli, on return.
	//Ensuite plus qu'a comparer les valeurs nb_collect et nb_exit de fmap avec celles trouvees dans ton .ber
}

void	map_flood(const t_data *data)
{
	data->fmap->width = data->map->width;
	data->fmap->height = data->map->height;
	data->fmap->bigstr = ft_strdup(data->map->bigstr);
	data->fmap->tab_map = ft_split(data->fmap->bigstr, '\n');
	if (!data->fmap->tab_map)
	{
		err_terminate("Malloc fail for split in map_flood");
		return ;
	}
	map_get_pos(data->fmap, 'P');
	floodfill(data->fmap, data->fmap->pos->x, data->fmap->pos->y);
	check_flooding(data->map, data->fmap);
}
