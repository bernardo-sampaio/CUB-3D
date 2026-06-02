# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealbino <ealbino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/30 22:02:32 by ealbino           #+#    #+#              #
#    Updated: 2025/11/30 22:02:36 by ealbino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

OBJS = ./ft_isalpha.o ./ft_isdigit.o ./ft_isalnum.o ./ft_isascii.o \
	./ft_isprint.o ./ft_strlen.o ./ft_memset.o ./ft_bzero.o \
	./ft_memcpy.o ./ft_memmove.o ./ft_strlcpy.o ./ft_strlcat.o \
	./ft_toupper.o ./ft_tolower.o ./ft_strchr.o ./ft_strrchr.o \
	./ft_strncmp.o ./ft_memchr.o ./ft_memcmp.o ./ft_strnstr.o \
	./ft_atoi.o ./ft_calloc.o ./ft_strdup.o ./ft_substr.o \
	./ft_strjoin.o ./ft_strtrim.o ./ft_split.o ./ft_itoa.o \
	./ft_strmapi.o ./ft_striteri.o ./ft_putchar_fd.o ./ft_putstr_fd.o \
	./ft_putendl_fd.o ./ft_putnbr_fd.o

OBJS_BONUS = ./ft_lstnew.o ./ft_lstadd_front.o ./ft_lstadd_back.o ./ft_lstsize.o \
	./ft_lstlast.o ./ft_lstdelone.o ./ft_lstclear.o ./ft_lstiter.o ./ft_lstmap.o

HEADER = ./libft.h
NAME = ./libft.a

all: $(NAME)

$(OBJS): $(HEADER)

$(NAME): $(OBJS)
	$(AR) r $@ $(OBJS)

bonus: .bonus_done

.bonus_done: $(OBJS_BONUS)
	$(AR) r $(NAME) $(OBJS_BONUS)
	touch .bonus_done

$(OBJS_BONUS): $(HEADER)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) .bonus_done

re: fclean all

.PHONY: all bonus clean fclean re

