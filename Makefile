# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 12:32:20 by mdegraeu          #+#    #+#              #
#    Updated: 2022/07/18 10:00:56 by mdegraeu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS_WITHOUT_PATH = \
					main.c \
					routine.c \
					is_alive.c \
					think.c \
					eat.c \
					sleep.c \
					fork.c

ADD_WITHOUT_PATH = \
					err.c \
					atoi.c \
					destroy_mutex.c \
					free.c \
					usleep.c

INIT_WITHOUT_PATH = \
					init.c

PARSING_WITHOUT_PATH = \
					parsing.c

HEADER_WITHOUT_PATH = philo.h

OBJS_SRCS_WITHOUT_PATH = $(SRCS_WITHOUT_PATH:.c=.o)
OBJS_ADD_WITHOUT_PATH = $(ADD_WITHOUT_PATH:.c=.o)
OBJS_INIT_WITHOUT_PATH = $(INIT_WITHOUT_PATH:.c=.o)
OBJS_PARSING_WITHOUT_PATH = $(PARSING_WITHOUT_PATH:.c=.o)

PATH_TO_SRCS = ./srcs/
PATH_TO_ADD = ./add/
PATH_TO_INIT = ./init/
PATH_TO_PARSING = ./parsing/
PATH_TO_OBJS = ./objs/
PATH_TO_HEADER = ./inclds/

SRCS = $(addprefix $(PATH_TO_SRCS), $(SRCS_WITHOUT_PATH))
PARSING = $(addprefix $(PATH_TO_PARSING), $(PARSING_WITHOUT_PATH))
ADD = $(addprefix $(PATH_TO_ADD), $(ADD_WITHOUT_PATH))
INIT = $(addprefix $(PATH_TO_INIT), $(INIT_WITHOUT_PATH))

OBJS_SRCS = $(addprefix $(PATH_TO_OBJS), $(OBJS_SRCS_WITHOUT_PATH))
OBJS_PARSING = $(addprefix $(PATH_TO_OBJS), $(OBJS_PARSING_WITHOUT_PATH))
OBJS_ADD = $(addprefix $(PATH_TO_OBJS), $(OBJS_ADD_WITHOUT_PATH))
OBJS_INIT = $(addprefix $(PATH_TO_OBJS), $(OBJS_INIT_WITHOUT_PATH))

OBJS = \
		$(OBJS_SRCS) \
		$(OBJS_ADD) \
		$(OBJS_INIT) \
		$(OBJS_PARSING)

HEADER = $(addprefix $(PATH_TO_HEADER), $(HEADER_WITHOUT_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
# -fsanitize=thread
RM = rm -rf

GREEN = \033[0;92m
YELLOW = \033[0;93m
RED	= \033[0;91m
WHITE = \033[1;49;97m

all: $(PATH_TO_OBJS) $(NAME)

$(PATH_TO_OBJS):
	mkdir -p ./objs/

$(OBJS_SRCS):$(PATH_TO_OBJS)%.o	: $(PATH_TO_SRCS)%.c Makefile $(HEADER)
	printf "$(YELLOW)⏳ Compiling:$(WHITE) $< 🤞"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PARSING):$(PATH_TO_OBJS)%.o	: $(PATH_TO_PARSING)%.c Makefile $(HEADER)
	printf "$(YELLOW)⏳ Compiling:$(WHITE) $< 🤞"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_ADD):$(PATH_TO_OBJS)%.o	: $(PATH_TO_ADD)%.c Makefile $(HEADER)
	printf "$(YELLOW)⏳ Compiling: $< 🤞"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_INIT):$(PATH_TO_OBJS)%.o	: $(PATH_TO_INIT)%.c Makefile $(HEADER)
	printf "$(YELLOW)⏳ Compiling:$(WHITE) $< 🤞"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	printf "✅ $(NAME) has been build 👍\n"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

git: fclean
	git add *
	git add -u
	git commit

clean:
	$(RM) $(PATH_TO_OBJS)
	printf "$(RED)👌 Files has been deleted in $(PATH_TO_OBJS) ($(NAME))$(WHITE)\n"
	printf "✅ Clean 👍\n"

fclean: clean
	$(RM) $(NAME)
	printf "👌 $(NAME) has been deleted\n"

re: fclean all

.PHONY: all clean git fclean re