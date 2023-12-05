# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 00:16:49 by hanmpark          #+#    #+#              #
#    Updated: 2023/12/06 00:22:06 by hanmpark         ###   ########.fr        #
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
SOURCES = ${addprefix ${SOURCES_PATH}, main.c \
										set_game_info.c}

OBJECTS = ${SOURCES:.c=.o}

%.o: %.c
	@${CC} ${CFLAGS} -I ${INC_PATH} -c $< -o $@

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
INC_PATH = ./inc/

# ---------------------------------- Rules ----------------------------------- #
NAME = aoc_2
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
