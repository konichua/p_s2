# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mburnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 18:19:52 by mburnett          #+#    #+#              #
#    Updated: 2020/04/17 16:19:25 by null             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap
INC_DIR	= ./includes
SRC_DIR = ./src/
FL = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
OBJSCH = $(SRCH:.c=.o)

SRC_COM = checker_operations_s_p.c checker_validation.c find_functions.c \
        write_functions.c push_swap_first_sort.c arguments_string.c flag_v.c \
        sort_hundred.c push_swap_new.c checker.c count_operations.c \

SRC_P = push_swap_main.c\

SRC_CHEK = checker_main.c \

OBJ_DIR = ./objects/

PUSH_SWAP_FILES = $(patsubst %.c, %.o, $(SRC_P) $(SRC_COM))
PUSH_SWAP_OBJECTS = $(addprefix $(OBJ_DIR), $(PUSH_SWAP_FILES))

CHECKER_FILES = $(patsubst %.c, %.o, $(SRC_CHECK) $(SRC_COM))
CHECKER_OBJECTS = $(addprefix $(OBJ_DIR), $(CHECKER_FILES))

HEADERS_DIRECTORY = ./includes/
HEADER_FILES = dlist.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))

LIBFT	= ./LIBFT/lib_str
IFL		= -I$(INC_DIR)

SRCS_COM	= $(addprefix $(SRC_DIR), $(SRC_COM))
SRCS_CHECK	= $(addprefix $(SRC_DIR), $(SRC_CHECK))
SRCS_P		= $(addprefix $(SRC_PUSH), $(SRC_P))


all: $(NAME) $(NAME2)

$(NAME2): $(PUSH_SWAP_OBJECTS)
	$(MAKE) -C $(LIBFT)/
	gcc $(FL) $^ $(LIBFT)/libft.a $(IFL) -o $(NAME2)

$(NAME): $(CHECKER_OBJECTS)
	$(MAKE) -C $(LIBFT)/
	gcc $(FL) $^ $(LIBFT)/libft.a $(IFL) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	mkdir -p ./objects
	gcc $(FL) -c $< -o $@ -I $(HEADERS_DIRECTORY)

clean:
	$(MAKE) -C $(LIBFT) clean
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -rf $(NAME)
	rm -rf $(NAME2)

re: fclean all

.PHONY: all clean fclean re