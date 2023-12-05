/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:18:58 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 00:33:56 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_game.h"

static void read_game_sets(t_game_info *game_info, char *game_sets) {

	const t_colors colors[] = {
		{"red", 3},
		{"green", 5},
		{"blue", 4}
	};
	int i = 0;

	while (game_sets[i]) {
		if (isdigit(game_sets[i])) {
			int nbr = atoi(game_sets + i);

			while (isdigit(game_sets[i]) || game_sets[i] == ' ') {
				i++;
			}
			for (int j = 0; j < 3; j++) {
				if (!strncmp(game_sets + i, colors[j].color_name, colors[j].size)) {
					if (j == RED && game_info->max_red_cube < nbr) {
						game_info->max_red_cube = nbr;
					} else if (j == GREEN && game_info->max_green_cube < nbr) {
						game_info->max_green_cube = nbr;
					} else if (j == BLUE && game_info->max_blue_cube < nbr) {
						game_info->max_blue_cube = nbr;
					}
					i += colors[j].size;
				}
			}
		} else {
			i++;
		}
	}
}

static char *get_line(int fd) {

	char buf[2];
	char game_input[200];

	buf[1] = 0;
	*game_input = 0;

	ssize_t check;
	while ((check = read(fd, buf, sizeof(char))) > 0 && *buf != '\n') {
		strcat(game_input, buf);
	}
	return strdup(game_input);
}

/*
* Sets the games' info and store them into an array of structure:
* - Reads line by line
* - For each game, finds and store the maximum number of each color of cubes that appeared during the three sets
*/
void set_game_info(int fd, t_game_info *game_info) {

	for (int i = 0; i < 100; i++) {
		char *game_sets = get_line(fd);
		game_info[i].id = i + 1;
		game_info[i].max_red_cube = 0;
		game_info[i].max_green_cube = 0;
		game_info[i].max_blue_cube = 0;
		read_game_sets(&game_info[i], game_sets);
		free(game_sets);
	}
}
