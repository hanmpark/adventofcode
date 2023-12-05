/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:34:06 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 00:37:19 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gondola.h"

static bool check_symbol(char **array, int x, int y) {

	int start_stamp = y;

	while (array[x][y] && isdigit(array[x][y])) {
		y++;
	}

	int end_stamp = y + 1;

	if (start_stamp - 1 >= 0) {
		start_stamp--;
	}
	x--;

	for (int i = 0; i < 3; i++) {
		y = start_stamp;
		while ((x >= 0 && x < FILE_LENGTH) && array[x][y] && y < end_stamp) {
			if (array[x][y] != '.' && !isdigit(array[x][y])) {
				return true;
			}
			y++;
		}
		x++;
	}

	return false;
}

/*
* Little algorithm to find and add up every numbers that are adjacent to a symbol
*/
int part_numbers(char **array) {

	int x = 0;
	int sum = 0;

	while (array[x]) {
		int y = 0;
		while (array[x][y]) {
			if (isdigit(array[x][y])) {
				if (check_symbol(array, x, y)) {
					sum += atoi(array[x] + y);
				}
				while (array[x][y] && isdigit(array[x][y])) {
					y++;
				}
			} else {
				y++;
			}
		}
		x++;
	}
	return sum;
}
