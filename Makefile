# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbalesme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 15:23:40 by sbalesme          #+#    #+#              #
#    Updated: 2022/07/14 13:50:41 by sbalesme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c\
			srcs/operation.c\
			srcs/pars.c\
			srcs/pars_check.c\
			srcs/short.c\
			srcs/small_short.c\
			srcs/short_bis.c\
			srcs/short_utils.c

SRCS_B	=	bonus/operation.c\
			bonus/pars.c\
			bonus/pars_check.c\
			bonus/main.c\
			bonus/solve.c
	
OBJS	=	$(SRCS:.c=.o)

OBJS_B	=	$(SRCS_B:.c=.o)

LIB		=	get_next_line

HEADER	=	include

NAME	=	push_swap

NAME_B	=	checker

CFLAG	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

.c.o:
		$(CC) $(CFLAG) -I $(HEADER) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		$(CC) $(CFLAG) $(OBJS) -I $(HEADER) -o $(NAME)

$(NAME_B):	$(OBJS_B)
		$(CC) $(CFLAG) $(OBJS_B) -I $(HEADER) -L gnl -l$(LIB) -o $(NAME_B)

lib:
		make -C gnl all 

bonus:
		make lib
		make $(NAME_B)

all:	$(NAME)

clean:
		$(RM) $(OBJS)
		$(RM) $(OBJS_B)
		make -C gnl clean 


fclean:	clean
		$(RM) $(NAME)
		$(RM) $(NAME_B)
		make -C gnl fclean 

re:		fclean
		make all

.PHONY:	re fclean clean all bonus lib
