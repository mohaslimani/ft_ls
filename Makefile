# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 17:00:33 by ommadhi           #+#    #+#              #
#    Updated: 2019/10/20 18:23:12 by ommadhi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/add_all_spaces.c\
		src/ft_args.c\
		src/ft_lentlist.c\
		src/ft_bublesort.c\
		src/ft_lsr.c\
		src/free_all.c\
		src/flags.c\
		src/ft_lastaccess.c\
		src/get_data2.c\
		src/get_data.c\
		src/alloclist.c\
		src/ft_print_all.c\
		src/spaces_grp.c\
		src/spaces_nlink.c\
		src/spaces_major.c\
		src/spaces_size_c.c\
		src/spaces_minor.c\
		src/spaces_usr.c\
		src/ft_sort_rev.c\
		src/ft_stickybit.c\
		src/ft_sort_args.c\

OBJS	= $(SRCS:.c=.o)
NAME	= ft_ls
CFLAG	= -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	gcc $(CFLAG) $(SRCS) libft/libft.a -o $(NAME)

clean :
	rm -rf $(OBJS)
	@make -C libft clean

fclean : clean
	rm -rf $(NAME)
	@make -C libft fclean

re : fclean all
