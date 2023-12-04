/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:41:04 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/04 23:43:24 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_game.h"

static int sum_ids(t_game_info *game_info) {

	int sum = 0;

	for (int i = 0; i < 100; i++) {
		if (game_info[i].max_red_cube <= 12 && game_info[i].max_green_cube <= 13 && game_info[i].max_blue_cube <= 14) {
			sum += game_info[i].id;
		}
	}
	return sum;
}

static int power_of_sets(t_game_info *game_info) {

	int power = 0;

	for (int i = 0; i < 100; i++) {
		power += game_info[i].max_red_cube * game_info[i].max_green_cube * game_info[i].max_blue_cube;
	}
	return power;
}

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

	ssize_t check;
	char buf[2];
	char game_input[200];

	buf[1] = 0;
	*game_input = 0;

	while ((check = read(fd, buf, sizeof(char))) > 0 && *buf != '\n') {
		strcat(game_input, buf);
	}
	return strdup(game_input);
}

static void set_game_info(int fd, t_game_info *game_info) {

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

int main() {

	t_game_info *game_info;
	int fd;

	if (!(game_info = calloc(100, sizeof(t_game_info)))) {
		return 1;
	}

	if ((fd = open("input.txt", O_RDONLY, 0644)) == -1) {
		return 2;
	}

	set_game_info(fd, game_info);

	printf("sum of IDs = %d\n", sum_ids(game_info));
	printf("power of sets = %d\n", power_of_sets(game_info));
	free(game_info);

	return 0;
}
