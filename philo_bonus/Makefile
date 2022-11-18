# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 14:55:24 by yel-mrab          #+#    #+#              #
#    Updated: 2022/11/18 04:13:03 by yel-mrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus
DRBUILD = build
INC = -I ./inc
HEADERS = inc/philo_b.h
FILES = main utils/main utils/utils philo checkmeals  utils/philo utils/sema_ utils/time

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
