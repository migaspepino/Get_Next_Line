# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 18:26:42 by mimarque          #+#    #+#              #
#    Updated: 2021/12/12 22:24:07 by mimarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES= get_next_line_utils.c get_next_line.c

NAME=get_next_line.a

LIBSO=get_next_line.so

CC=gcc

CFLAGS=-Wall -Wextra -Werror

HDR_NAME=get_next_line.h

OBJ_DIR=obj/

SRC_NAMES=${SRC_FILES:.c=.o}

BONUS_NAMES=${BONUS_FILES:.c=.o}

SRC_NAMES_O=$(addprefix $(OBJ_DIR), $(SRC_NAMES))

BONUS_NAMES_O=$(addprefix $(OBJ_DIR), $(BONUS_NAMES))

HDR= $(addprefix $(HDR_DIR),$(HDR_NAME))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(SRC_NAMES)
	ar -rc $@ $(SRC_NAMES_O)
	ranlib $@

$(OBJ_DIR):
	mkdir $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)$@

clean:
	rm -rf $(OBJ_DIR)

sclean: clean
	rm -rf $(NAME) $(LIBSO) a.out

fclean: clean
	rm -f $(NAME)

re: sclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC_FILES) $(BONUS_FILES)
	gcc -nostartfiles -shared -o libft.so $(SRC_FILES) $(BONUS_FILES)

.PHONY: all clean fclean re so
