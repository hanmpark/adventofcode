/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scratchcards.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:56:10 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 11:29:54 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRATCHCARDS_H
# define SCRATCHCARDS_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <stdbool.h>

# define FILE_LENGTH 203
# define TRIM 10
# define NUMBERS 32

# define INPUT_FILE "./input.txt"

typedef struct s_scratchcards {

	char **numbers;
	int copies;
} t_scratchcards;

char **get_array(int);
int read_scratchcards();
int count_points(t_scratchcards *);
void free_array(char **);
void free_cards(t_scratchcards *);

#endif