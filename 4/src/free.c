/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:47:56 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 10:48:42 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scratchcards.h"

void free_array(char **array) {

	if (array) {
		for (int i = 0; array[i]; i++) {
			free(array[i]);
		}
		free(array);
	}
}

void free_cards(t_scratchcards *card) {

	for (int i = 0; i < FILE_LENGTH; i++) {
		for (int j = 0; j < 2; j++) {
			free(card[i].numbers[j]);
			card[i].numbers[j] = NULL;
		}
		free(card[i].numbers);
	}
	free(card);
}
