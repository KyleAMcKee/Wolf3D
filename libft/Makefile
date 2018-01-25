
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmckee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 10:43:15 by kmckee            #+#    #+#              #
#    Updated: 2017/11/20 18:57:28 by kmckee           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FUNCTIONS = toupper tolower \
			isprint isascii \
			isdigit isalpha \
			isalnum atoi \
			strncmp strcmp \
			strnstr strstr \
			strcpy strlen \
			strcpy strncpy \
			strdup strcat \
			strncat strlcat \
			strchr strrchr \
			memset bzero \
			memcpy memccpy \
			memmove memchr \
			memcmp memalloc \
			memdel strnew \
			strdel strclr \
			striter striteri\
			strmap strmapi\
			strequ strnequ\
			strsub strjoin\
			strtrim strsplit\
			itoa freearray\
			putendl putnbr\
			putchar putstr \
			putchar_fd putstr_fd\
			putendl_fd putnbr_fd\
			lstnew lstdelone\
			lstdel lstadd\
			lstiter lstmap\
			iswhitespace wordcount \
			wordcountd strfjoin \

ADD_FT = $(addprefix ft_, $(FUNCTIONS))
C_FILES = $(addsuffix .c, $(ADD_FT))
OBJ_FILES = $(addsuffix .o, $(ADD_FT))

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(C_FILES) get_next_line.c
	ar rcs $(NAME) $(OBJ_FILES) get_next_line.o

clean:
	rm -f $(OBJ_FILES) get_next_line.o

fclean:	clean
	rm -f $(NAME)

re: fclean all
