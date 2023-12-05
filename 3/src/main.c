/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:55:57 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 00:34:15 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gondola.h"

static void free_array(char **array) {

	if (array) {
		for (int i = 0; array[i]; i++) {
			free(array[i]);
		}
		free(array);
	}
}

int main() {

	int fd;
	if ((fd = open(INPUT_FILE, O_RDONLY, 0644)) == -1) {
		return 1;
	}

	char **array;
	if (!(array = get_array(fd))) {
		return 2;
	}

	printf("Part 1) sum of all of the part numbers in the engine schematic: %d\n", part_numbers(array));
	printf("Part 2) sum of all of the gear ratios in the engine schematic: %d\n", gear_ratios(array));

	free_array(array);

	return 0;
}
