/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gear_ratios.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:10:01 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 00:39:58 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gondola.h"

static int get_whole_number(char *array, int i) {

	while (array[i] && isdigit(array[i])) {
		i--;
	}
	return atoi(array + i + 1);
}

static int check_gear(char **array, int x, int y) {

	int start_stamp = y;
	int end_stamp = y + 2;

	if (start_stamp - 1 >= 0) {
		start_stamp--;
	}
	x--;

	int product = 1;
	int is_gear = 0;

	for (int i = 0; i < 3; i++) {
		y = start_stamp;
		while ((x >= 0 && x < FILE_LENGTH) && array[x][y] && y < end_stamp) {
			if (isdigit(array[x][y])) {
				is_gear++;
				product *= get_whole_number(array[x], y);
				while (array[x][y] && isdigit(array[x][y])) {
					y++;
				}
			} else {
				y++;
			}
		}
		x++;
	}

	if (is_gear == 2) {
		return product;
	}
	return 0;
}

/*
* Little algorithm to find any '*' symbol that is adjacent to exactly two part numbers:
* - Those two numbers are multiplied
* - Returns the sum of all the products found
*/
int gear_ratios(char **array) {

	int x = 0;
	int sum = 0;

	while (array[x]) {
		int y = 0;
		while (array[x][y]) {
			if (array[x][y] == '*') {
				sum += check_gear(array, x, y);
			}
			y++;
		}
		x++;
	}
	return sum;
}
