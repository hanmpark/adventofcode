/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:41:04 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 00:44:10 by hanmpark         ###   ########.fr       */
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

int main() {

	t_game_info *game_info;
	if (!(game_info = calloc(100, sizeof(t_game_info)))) {
		return 1;
	}

	int fd;
	if ((fd = open(INPUT_FILE, O_RDONLY, 0644)) == -1) {
		return 2;
	}

	set_game_info(fd, game_info);
	close(fd);

	printf("Part 1) sum of IDs = %d\n", sum_ids(game_info));
	printf("Part 2) power of sets = %d\n", power_of_sets(game_info));

	free(game_info);

	return 0;
}
