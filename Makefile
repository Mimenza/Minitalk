# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 08:28:00 by emimenza          #+#    #+#              #
#    Updated: 2023/12/14 09:28:31 by emimenza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# # Definir colores
# RED = \033[0;31m
# GREEN = \033[0;32m
# YELLOW = \033[0;33m
# NC = \033[0m # No color (reiniciar)

# #Comandos
# AR			=	ar rcs
# DEL			=	rm -f
# CC			=	gcc
# CCFLAGS		=	-Wall -Wextra -Werror

# #Nombre ejecutable
# NAME		=	minitalk.a

# #Ficheros
# SRC			=	server.c client.c utils.c
# SRC_BONUS	=	server_bonus.c client_bonus.c
# OBJ			=	$(SRC:.c=.o)
# OBJ_BONUS	=	$(SRC_BONUS:.c=.o)
# FT_PRINTF	=	ft_printf
# HEADER		=	minitalk.h

# LIBS		=	${FT_PRINTF}/ft_printf.a

# # REGLAS #
# all:	libs $(NAME)
# bonus:	libs bonus_

# #Compilar
# libs:
# 	@make -C ${FT_PRINTF}
# 	@cp ${FT_PRINTF}/ft_printf.a $(NAME)
	
# $(NAME):$(OBJ) 
# 		@$(AR) $(NAME) $(OBJ) $(LIBS) $(HEADER)
# 		@echo "$(GREEN)THE PROGRAM HAS BEEN COMPILED!$(NC)"

# bonus_:$(OBJ) $(OBJ_BONUS)
# 		@$(AR) $(NAME) $(OBJ) $(OBJ_BONUS) $(LIBS) $(HEADER)
# 		@echo "$(GREEN)THE BONUS PROGRAM HAS BEEN COMPILED!$(NC)"

# # $@ : The file name of the target of the rule. If the target is an archive member, then ‘$@’ is the name of the archive file.
# # $< : The name of the first prerequisite.

# %.o: %.c
# 	$(CC) $(CCFLAGS) -c -o $@ $<

# # Eliminar temporales
# clean:
# 	@make clean -C ${FT_PRINTF}
# 	$(DEL) $(OBJ)
# 	@echo "$(RED)OBJECT AND TEMP FILES DELETED!!$(NC)"

# fclean: clean
# 	$(DEL) $(NAME)
# 	$(DEL) ${FT_PRINTF}/ft_printf.a $(NAME)

# clean_bonus:
# 	@make clean -C ${FT_PRINTF}
# 	$(DEL) $(OBJ) $(OBJ_BONUS)
# 	@echo "$(RED)OBJECT AND TEMP FILES DELETED!!$(NC)"
	
# re:	fclean all

# Definir colores
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m # No color (reiniciar)

# Comandos
AR = ar rcs
DEL = rm -f
CC = gcc
CCFLAGS = -Wall -Wextra -Werror

# Nombre ejecutable
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_NAME_BONUS = client_bonus
SERVER_NAME_BONUS = server_bonus

# Ficheros
CLIENT_SRC = client.c utils.c
SERVER_SRC = server.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_SRC_BONUS = client_bonus.c utils.c
SERVER_SRC_BONUS = server_bonus.c
CLIENT_OBJ_BONUS = $(CLIENT_SRC_BONUS:.c=.o)
SERVER_OBJ_BONUS = $(SERVER_SRC_BONUS:.c=.o)
FT_PRINTF = ft_printf
HEADER = minitalk.h

LIBS = ${FT_PRINTF}/ft_printf.a

# REGLAS #
all: libs $(CLIENT_NAME) $(SERVER_NAME)

bonus: libs $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

# Compilar
libs:
	@make -C ${FT_PRINTF}
	@cp -n ${FT_PRINTF}/ft_printf.a $(LIBS) || true

$(CLIENT_NAME): $(CLIENT_OBJ)
	$(CC) $(CCFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJ) $(LIBS)
	@echo "$(GREEN)THE CLIENT PROGRAM HAS BEEN COMPILED!$(NC)"

$(SERVER_NAME): $(SERVER_OBJ)
	$(CC) $(CCFLAGS) -o $(SERVER_NAME) $(SERVER_OBJ) $(LIBS)
	@echo "$(GREEN)THE SERVER PROGRAM HAS BEEN COMPILED!$(NC)"

$(CLIENT_NAME_BONUS): $(CLIENT_OBJ_BONUS)
	$(CC) $(CCFLAGS) -o $(CLIENT_NAME_BONUS) $(CLIENT_OBJ_BONUS) $(LIBS)
	@echo "$(GREEN)THE CLIENT_BONUS PROGRAM HAS BEEN COMPILED!$(NC)"

$(SERVER_NAME_BONUS): $(SERVER_OBJ_BONUS)
	$(CC) $(CCFLAGS) -o $(SERVER_NAME_BONUS) $(SERVER_OBJ_BONUS) $(LIBS)
	@echo "$(GREEN)THE SERVER_BONUS PROGRAM HAS BEEN COMPILED!$(NC)"

# $@ : The file name of the target of the rule. If the target is an archive member, then ‘$@’ is the name of the archive file.
# $< : The name of the first prerequisite.

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

# Eliminar temporales
clean:
	@make clean -C ${FT_PRINTF}
	$(DEL) $(CLIENT_OBJ) $(SERVER_OBJ)
	@echo "$(RED)OBJECT AND TEMP FILES DELETED!!$(NC)"

fclean: clean
	$(DEL) $(CLIENT_NAME) $(SERVER_NAME) $(LIBS)

clean_bonus:
	@make clean -C ${FT_PRINTF}
	$(DEL) $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS) $(OBJ_BONUS)
	@echo "$(RED)OBJECT AND TEMP FILES DELETED!!$(NC)"

re: fclean all