# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 14:55:24 by yel-mrab          #+#    #+#              #
#    Updated: 2022/05/04 10:31:57 by yel-mrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus_
DRBUILD = build
INC = -I ./inc
HEADERS = inc/philo.h
FILES = main utils/main utils/utils

OBJS = $(addprefix $(DRBUILD)/, $(FILES:=.o))
 
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(DRBUILD)/%.o : src/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean :
	rm -rf $(DRBUILD)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : re clean fclean all
