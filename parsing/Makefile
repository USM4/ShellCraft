CC = cc
CFLAGS = -Wall -Wextra -Werror
OPTION = -lreadline
NAME = libpars.a
GREEN = \033[32m
COLOR_OFF = \033[0m
LIBPARS = libpars.a
HEADERS= ./includes/minishell.h ./../libstatus.h ./../libstructs.h
SOURCES = ./src/llists/add_back.o\
	./src/llists/add_front.o\
	./src/llists/clear.o\
	./src/llists/delone.o\
	./src/llists/last.o\
	./src/llists/new.o\
	./src/llists/size.o\
	./src/utils/error_helper.o\
	./src/utils/global_utils.o\
	./src/utils/parse_data.o\
	./src/utils/parse_data_utils.o\
	./src/utils/my_malloc.o\
	./src/utils/libft_utils/ft_substr.o\
	./src/utils/libft_utils/ft_strlenp.o\
	./src/utils/libft_utils/iswspace.o\
	./src/utils/libft_utils/ft_strcpy.o\
	./src/utils/libft_utils/ft_clean.o\
	./src/utils/libft_utils/ft_itoa.o\
	./src/utils/libft_utils/ft_putstr_fd.o\
	./src/utils/libft_utils/ft_strcmp.o\
	./src/utils/libft_utils/ft_strjoin.o\
	./src/utils/libft_utils/ft_strdup.o\
	./src/parsing/lexer/lexer_utils.o\
	./src/parsing/lexer/lexer_utils1.o\
	./src/parsing/lexer/lexer_utils2.o\
	./src/parsing/lexer/lexer_utils3.o\
	./src/parsing/lexer/lexer.o\
	./src/parsing/parser/expander/expand.o\
	./src/parsing/parser/expander/expand_utils.o\
	./src/parsing/parser/expander/expand_utils1.o\
	./src/parsing/parser/parsing.o\
	./src/parsing/parser/parsing_utils.o\
	./src/parsing/command_resources/generate_cmd_list.o\
	./src/parsing/command_resources/generate_cmd_list_utils.o\
	./src/parsing/command_resources/generate_cmd_list_utils1.o\
	./src/parsing/command_resources/here_doc.o
	

all : $(NAME)

$(NAME): $(SOURCES)
		@ar rc $@ $(SOURCES)

%.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean :
	@rm -f $(SOURCES)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: fclean clean re $(NAME) all