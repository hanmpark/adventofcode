# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 00:25:23 by hanmpark          #+#    #+#              #
#    Updated: 2023/12/06 00:25:58 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------- Colors ---------------------------------- #
CYAN = \033[38;5;117m
ROSE = \033[38;5;169m
BOLD = \033[1m
CUR = \033[3m
DEF = \033[0m

# --------------------------------- Compiler --------------------------------- #
SOURCES_PATH = ./src/
SOURCES = main.c

OBJECTS = ${SOURCES:.c=.o}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

CC = clang
CFLAGS = -Wall -Wextra -Werror -g

# ---------------------------------- Rules ----------------------------------- #
NAME = aoc_1
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJECTS}
	@printf "${CYAN}Compiled ${BOLD}${CUR}${NAME}${DEF}\n"
	@${CC} ${CFLAGS} ${OBJECTS} -o ${NAME}

clean:
	@printf "${ROSE}Deleted object files${DEF}\n"
	@${RM} ${OBJECTS}

fclean: clean
	@printf "${ROSE}Deleted ${BOLD}${CUR}${NAME}${DEF}\n"
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
