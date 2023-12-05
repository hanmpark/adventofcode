/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:19:43 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 00:35:48 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gondola.h"

static char *get_line(int fd) {

	char buf[2];
	char game_input[200];

	buf[1] = 0;
	*game_input = 0;

	ssize_t check;
	while ((check = read(fd, buf, sizeof(char))) > 0 && *buf != '\n') {
		strcat(game_input, buf);
	}

	if (!*game_input) {
		return NULL;
	}
	return strdup(game_input);
}

/*
* Creates a 2D array of lines
*/
char **get_array(int fd) {

	char **array;

	if (!(array = calloc(FILE_LENGTH + 1, sizeof(char *)))) {
		return NULL;
	}

	int i = 0;
	while ((array[i++] = get_line(fd)) != NULL) {
		continue;
	}

	close(fd);

	return array;
}
