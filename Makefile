# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 12:01:08 by alvarrod          #+#    #+#              #
#    Updated: 2023/11/08 20:23:04by alvarrod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.h inc
vpath %.c src
vpath %.o obj

NAME 							:= cub3D
LIBFT							:= ./libft/libft.a

#COLORS
DEFAULT							:=	\033[1;39m
PURPLE							:=	\033[1;91m
GREEN							:=	\033[1;32m
YELLOW							:=	\033[1;93m
CYAN							:=	\033[1;96m
RED								:=	\033[1;95m

#FLAGS
CC								:= gcc
CFLAGS							:= -c -Wall -Wextra -Werror -I/usr/include -Imlx_linux
MLX_FLAGS			            :=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

RM								:= rm -f 

#INCLUDES
INC								:= -I inc ./libft/libft.a 

#MAIN DIRECTORIES
SRC_DIR							:= src
OBJ_DIR							:= obj
INC_DIR 						:= inc

#FILES DIRECTORIES
#SRC
CUB3D_SRC_DIR					:= $(SRC_DIR)/cub3D
PARSER_SRC_DIR					:= $(SRC_DIR)/parser
EXECUTER_SRC_DIR				:= $(SRC_DIR)/executer
#OBJ
CUB3D_OBJ_DIR					:= $(OBJ_DIR)/cub3D
PARSER_OBJ_DIR					:= $(OBJ_DIR)/parser
EXECUTER_OBJ_DIR				:= $(OBJ_DIR)/executer


#EXECUTION FILES
#CUB3D
CUB3D_SOURCES				:= 	main utils  textures drow_screen raycasting
CUB3D_FINAL_SRC				:= 	$(addprefix $(CUB3D_SRC_DIR)/, $(addsuffix .c, $(CUB3D_SOURCES)))
CUB3D_FINAL_OBJ				:= 	$(addprefix $(CUB3D_OBJ_DIR)/, $(addsuffix .o, $(CUB3D_SOURCES)))

#PARSER
PARSER_SOURCES					:= 	load_cub3D read_content load_textures load_walls
PARSER_FINAL_SRC				:= 	$(addprefix $(PARSER_SRC_DIR)/, $(addsuffix .c, $(PARSER_SOURCES)))
PARSER_FINAL_OBJ				:= 	$(addprefix $(PARSER_OBJ_DIR)/, $(addsuffix .o, $(PARSER_SOURCES)))

#EXECUTER
EXECUTER_SOURCES				:=  event_handler cub3D_game
EXECUTER_FINAL_SRC				:= 	$(addprefix $(EXECUTER_SRC_DIR)/, $(addsuffix .c, $(EXECUTER_SOURCES)))
EXECUTER_FINAL_OBJ				:= 	$(addprefix $(EXECUTER_OBJ_DIR)/, $(addsuffix .o, $(EXECUTER_SOURCES)))

#FINAL FILES
EXEC_SRCS 						:= $(CUB3D_FINAL_SRC) $(PARSER_FINAL_SRC) $(EXECUTER_FINAL_SRC)
EXEC_OBJS 						:= $(CUB3D_FINAL_OBJ) $(PARSER_FINAL_OBJ) $(EXECUTER_FINAL_OBJ)

#------------------------------------------------------------MINISHELL--------------------------------------------------------------------------------
begin:
	@make  -s -C libft
	@cp $(LIBFT) ./inc
	@make -s all
#areglar makefile que compile
all: $(NAME) 

$(NAME): $(EXEC_OBJS)  $(LIBFT)
	@echo "$(PURPLE)##############################$(DEFAULT)"
	@echo "$(YELLOW)       Generating $@ $(DEFAULT)"
	@mkdir -p $(@D)
	@$(CC) $^ $(MLX_FLAGS) -o $@
	@echo "$(PURPLE)##############################$(DEFAULT)"

$(EXEC_OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(@D)
	@printf "$(GREEN)       Generating $@ $(DEFAULT)        \n"
	@$(CC) $(CFLAGS)  $< -o $@

clean:
	@echo "$(PURPLE)##############################$(DEFAULT)"
	@$(RM) -rf obj
	@echo "$(RED)      🗑️ DELETED $(OBJ_DIR)/*$(DEFAULT)"
	@make clean -s -C libft 

fclean: clean
	@$(RM) -rf $(NAME)
	@echo "$(RED)      🗑️ DELETED $(NAME) $(DEFAULT)"
	@make fclean -s -C libft 

re: fclean begin

.PHONY: begin all re fclean clean

-include $(EXEC_OBJS:.o=.d)
