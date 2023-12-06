/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:40:57 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 12:17:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scratchcards.h"

static void set_copies(int nbr, t_scratchcards *card) {

	for (int i = 0; i < card->copies; i++) {
		for (int j = 0; j < nbr; j++) {
			if (card[j + 1].numbers) {
				card[j + 1].copies++;
			}
		}
	}
}

static int skip_to_next_number(char *str) {

	int count = 0;
	while (str[count] && !isdigit(str[count])) {
		count++;
	}
	while (str[count] && isdigit(str[count])) {
		count++;
	}
	while (str[count] && !isdigit(str[count])) {
		count++;
	}
	return count;
}

static int get_scratchcard_points(int *copies, char *winning_numbers, char *numbers) {

	int i = 0;
	int point = 0;
	while (winning_numbers[i]) {
		int j = 0;
		while (numbers[j]) {
			if (atoi(winning_numbers + i) == atoi(numbers + j)) {
				if (point) {
					point *= 2;
				} else {
					point++;
				}
				(*copies)++;
			}
			j += skip_to_next_number(numbers + j);
		}
		i += skip_to_next_number(winning_numbers + i);
	}
	return point;
}

/*
* Returns the sum of the points of the cards:
* - The first match makes the card worth one point and each match after the first doubles the point value of that card
*/
int count_points(t_scratchcards *card) {

	int sum = 0;

	for (int i = 0; i < FILE_LENGTH; i++) {
		int copies = 0;
		sum += get_scratchcard_points(&copies, card[i].numbers[0], card[i].numbers[1]);
		set_copies(copies, card + i);
	}
	free_cards(card);

	return sum;
}
