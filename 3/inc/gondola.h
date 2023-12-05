/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gondola.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:18:46 by hanmpark          #+#    #+#             */
/*   Updated: 2023/12/06 00:45:15 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GONDOLA_H
# define GONDOLA_H

# define FILE_LENGTH 140

# define INPUT_FILE "./input.txt"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdbool.h>
# include <string.h>

char **get_array(int fd);
int part_numbers(char **array);
int gear_ratios(char **array);

#endif