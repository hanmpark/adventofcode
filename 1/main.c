/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:10:30 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/04 18:57:35 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct s_number {

	char *str;
	size_t size;
	int nbr;
} t_number;

static int nbr_in_letters(char *line, bool return_nbr) {

	const t_number nbrs[] = {
		{"one", 3, 1},
		{"two", 3, 2},
		{"three", 5, 3},
		{"four", 4, 4},
		{"five", 4, 5},
		{"six", 3, 6},
		{"seven", 5, 7},
		{"eight", 5, 8},
		{"nine", 4, 9}
	};

	for (int i = 0; i < 9; i++) {
		if (!strncmp(nbrs[i].str, line, nbrs[i].size)) {
			if (return_nbr) {
				return nbrs[i].nbr;
			} else {
				return nbrs[i].size - 1;
			}
		}
	}

	return -1;
}

static int calibration_value(char *line, bool letters) {

	int i = 0;
	int first = -1;
	int last = 0;

	while (line[i]) {
		if (first == -1 && isdigit(line[i])) {
			first = line[i] - '0';
			i++;
		} else if (isdigit(line[i])) {
			last = line[i] - '0';
			i++;
		} else if (letters && nbr_in_letters(line + i, true) != -1) {
			if (first == -1) {
				first = nbr_in_letters(line + i, true);
			} else {
				last = nbr_in_letters(line + i, true);
			}
			i += nbr_in_letters(line + i, false);
		} else {
			i++;
		}
	}

	if (!last) {
		return first * 10 + first;
	}
	return first * 10 + last;
}

static int read_line(int fd, bool letters) {

	ssize_t bytes = 0;
	char buf[2];
	char line[100];

	*line = 0;
	buf[1] = 0;

	while ((bytes = read(fd, buf, 1)) > 0 && strcmp(buf, "\n")) {
		strcat(line, buf);
	}

	if (!*line) {
		return -1;
	}

	return calibration_value(line, letters);
}

int sum_of_calibration_values(int fd, bool letters) {

	int nbr = 0;
	int sum = 0;

	while ((nbr = read_line(fd, letters)) != -1) {
		sum += nbr;
	}
	close(fd);

	return sum;
}

int main() {

	int fd;

	if ((fd = open("text.txt", O_RDONLY)) == -1) {
		return 1;
	}
	printf("1) sum of all calibration values = %d\n", sum_of_calibration_values(fd, false));

	if ((fd = open("text.txt", O_RDONLY)) == -1) {
		return 1;
	}
	printf("2) sum of all calibration values = %d\n", sum_of_calibration_values(fd, true));

	return 0;
}
