# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 18:37:53 by mohtakra          #+#    #+#              #
#    Updated: 2023/09/14 17:49:08 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC = ft_itoa.c ft_atoi.c ft_isdigit.c ft_isalpha.c ft_tolower.c\
	ft_strdup.c ft_strjoin.c\
	ft_strchr.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strlcpy.c\
	ft_freematrix.c ft_split.c \
	ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c

SRCB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c  \
	ft_lstclear.c ft_lstdelone.c del.c
	
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
all: $(NAME) bonus

$(NAME): $(OBJB) $(OBJ)
		@ar rc $@ $(OBJ) $(OBJB)

%.o: %.c libft.h
		@$(CC) -o $@ -c $< $(CFLAGS)


clean:
		@$(RM) $(OBJ) $(OBJB)
fclean: clean
		@$(RM) $(NAME)

bonus : $(OBJB)
		@ar rc $(NAME) $(OBJB)
	
re: fclean all

.PHONY : clean $(NAME) all fclean bonus re