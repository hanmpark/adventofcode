/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:38:37 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 00:45:23 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_GAME_H
# define CUBE_GAME_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

# define RED 0
# define GREEN 1
# define BLUE 2

# define INPUT_FILE "./input.txt"

typedef struct s_game_info {

	int id;
	int max_red_cube;
	int max_green_cube;
	int max_blue_cube;
} t_game_info;

typedef struct s_colors {

	char *color_name;
	size_t size;
} t_colors;

void set_game_info(int fd, t_game_info *game_info);

#endif