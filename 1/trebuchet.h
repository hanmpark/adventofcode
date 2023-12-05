/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trebuchet.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:22:34 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 00:45:20 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREBUCHET_H
# define TREBUCHET_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdbool.h>

# define INPUT_FILE "./input.txt"

typedef struct s_number {

	char *str;
	size_t size;
	int nbr;
} t_number;

#endif