# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 08:28:00 by emimenza          #+#    #+#              #
#    Updated: 2023/10/31 12:11:00 by emimenza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Definir colores
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m # No color (reiniciar)

#Comandos
AR			=	ar rcs
DEL			=	rm -f
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror

#Nombre ejecutable
NAME		=	minitalk.a

#Ficheros
SRC			=	server.c client.c utils.c
OBJ			=	$(SRC:.c=.o)
#FT_LIBFT	=	./Libft
FT_PRINTF	=	./ft_printf
HEADER		=	minitalk.h

LIBS		=	${FT_PRINTF}/ft_printf.a
#${FT_LIBFT}/libft.a

# REGLAS #
all:	libs $(NAME)

#Compilar
libs:
	@make -C ${FT_PRINTF}
	@cp ${FT_PRINTF}/ft_printf.a $(NAME)
#@make -C ${FT_LIBFT}
#@cp ${FT_LIBFT}/libft.a $(NAME)
	
$(NAME):$(OBJ) 
		@$(AR) $(NAME) $(OBJ) $(LIBS) $(HEADER)
		@echo "$(GREEN)THE PROGRAM HAS BEEN COMPILED!$(NC)"

# $@ : The file name of the target of the rule. If the target is an archive member, then ‘$@’ is the name of the archive file.
# $< : The name of the first prerequisite.

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

# Eliminar temporales
clean:
#@make clean -C ${FT_LIBFT}
	@make clean -C ${FT_PRINTF}
	$(DEL) $(OBJ)
	@echo "$(RED)OBJECT AND TEMP FILES DELETED!!$(NC)"

fclean: clean
	$(DEL) $(NAME)
#$(DEL) ${FT_LIBFT}/libft.a $(NAME)
	$(DEL) ${FT_PRINTF}/ft_printf.a $(NAME)

re:	fclean all