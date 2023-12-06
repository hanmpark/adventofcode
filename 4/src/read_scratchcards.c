/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scratchcards.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:08:10 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 12:00:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scratchcards.h"

static t_scratchcards *get_scratchcard(char **array) {

	t_scratchcards *card;
	if (!(card = calloc(FILE_LENGTH + 1, sizeof(t_scratchcards)))) {
		free_array(array);
		return NULL;
	}

	const size_t dup_length[] = {29, 74};

	for (int i = 0; i < FILE_LENGTH; i++) {
		if (!(card[i].numbers = calloc(3, sizeof(char *)))) {
			free_array(array);
			free(card);
			return NULL;
		}
		card[i].copies = 1;
		for (int j = 0; j < 2; j++) {
			if (!j) {
				card[i].numbers[j] = strndup(array[i], dup_length[j]);
			} else {
				card[i].numbers[j] = strndup(array[i] + NUMBERS, dup_length[j]);
			}
		}
	}
	free_array(array);

	return card;
}

/*
* If 'get_copies' is set to false:
* - Compares the winning numbers with the numbers on the right
* - The first match makes the card worth one point and each match after the first doubles the point value of that card
* - Returns the sum of the points of the card
*
* If 'get_copies' is set to true:
* - You win copies of the scratchcards below the winning card equal to the number of matches of a card
* - Returns the total number of scratchcards
*/
int read_scratchcards() {

	int fd;
	if ((fd = open(INPUT_FILE, O_RDONLY, 0644)) == -1) {
		return -1;
	}

	char **array = get_array(fd);

	close(fd);
	if (!array) {
		return -1;
	}

	t_scratchcards *card;
	if (!(card = get_scratchcard(array))) {
		return -1;
	}

	int sum_of_points = count_points(card);
	int nbr_of_scratchcards = 0;

	for (int i = 0; i < FILE_LENGTH; i++) {
		nbr_of_scratchcards += card[i].copies;
	}

	printf("Part 1) sum of points = %d\n", sum_of_points);
	printf("Part 2) number of scratchcards = %d\n", nbr_of_scratchcards);

	return 0;
}
