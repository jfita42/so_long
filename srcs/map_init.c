/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfita <jfita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:47:23 by jfita             #+#    #+#             */
/*   Updated: 2024/04/01 18:01:42 by jfita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	*error_zero(void)
{
	t_error	*map_err;

	map_err = ft_calloc(1, sizeof(t_error));
	if (!map_err)
		err_terminate("Malloc fail in init_error\n");
	return (map_err);
}

void	parse_map(t_data *data, int fd)
{
	if (fd < 0)
		err_terminate(MAP_CRITERR0);
	check_terminate(data);
	map_check_filetype(data->map);
	check_terminate(data);
	data->map->bigstr = read_map(fd);
	check_terminate(data);
	if (!(data->map->bigstr))
		err_terminate(MAP_CRITERR2);
	check_terminate(data);
	data->map->tab_map = ft_split((data->map->bigstr), '\n');
	if (!(data->map->tab_map) || !(data->map->tab_map[0]))
		err_terminate(MAP_CRITERR3);
	check_terminate(data);
	get_and_check(data);
	check_terminate(data);
	ft_printf("map has been parsed and is correct\n");
}
