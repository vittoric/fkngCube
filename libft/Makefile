# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arr02 <arr02@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 13:47:16 by arr02             #+#    #+#              #
#    Updated: 2022/11/07 14:33:58y arr02            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT		=	\033[1;39m
PURPLE		=	\033[1;91m
GREEN		=	\033[38;5;34m
YELLOW		=	\033[1;93m
CYAN		=	\033[1;96m
RED			=	\033[1;95m

#TAGS
NAME 			= libft.a

LIBFT			= libft
FTPRINTF		= ft_printf
GNL				= get_next_line
TESTSTACK		= teststack

#COMPILATION
CC				= gcc
CFLAGS			= -c -Wall -Wextra -Werror -g

#OTHERS
RM				= rm -rf 
AR				= ar rcs

LIBFTSRCS		= ft_rm_char_from_str.c ft_strisnum.c ft_sort_matrix.c ft_fstrjoin.c ft_error.c ft_init_double_pointer.c ft_atoi.c ft_atol.c ft_strisdigit.c ft_array_is_sorted.c ft_array_has_value.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strarr_len.c ft_realloc_str.c ft_strncpy.c ft_isspace.c ft_strcmp.c ft_putendl.c ft_free_double_void_pointer.c ft_lst_to_str.c
LIBFTOBJS		= $(LIBFTSRCS:.c=.o)

FT_PRINTFSRCS	= ft_base_converter.c ft_printchar.c ft_printf.c ft_printhexa.c ft_printint.c ft_printpointer.c ft_printstring.c ft_printunint.c  
FT_PRINTFOBJS 	= $(FT_PRINTFSRCS:.c=.o)

GNLSRCS			= get_next_line.c get_next_line_utils.c
GNLOBJS			= $(GNLSRCS:.c=.o)

ALLSRCS			= $(LIBFTSRCS) $(FT_PRINTFSRCS) $(GNLSRCS) $(STACKSRCS) 
ALLOBJS			= $(ALLSRCS:.c=.o)
ALLOBJSDIR		= $(addprefix obj/, $(ALLOBJS)) 



vpath %.c src/ft_printf
vpath %.c src/gnl
vpath %.c src/libft

vpath %.o obj

vpath %.h inc

all: 
	@mkdir -p obj/
	@make -s $(NAME)

$(NAME):$(FT_PRINTFOBJS) $(GNLOBJS) $(LIBFTOBJS) 
	@echo "$(PURPLE)\n##################################$(DEFAULT)"
	@echo "$(YELLOW)       Generating $@ $(DEFAULT)"
	@$(AR) $(NAME) $(ALLOBJSDIR) 

$(FT_PRINTFOBJS): %.o: %.c $(FTPRINTF).h
	@printf "$(GREEN)       Generating $@ $(DEFAULT)        \r"
	@$(CC) $(CFLAGS) -I inc/ $<
	@mv $*.o obj/

$(GNLOBJS): %.o: %.c $(GNL).h
	@printf "$(GREEN)       Generating $@ $(DEFAULT)        \r"
	@$(CC) $(CFLAGS) -I inc/ $<
	@mv $*.o obj/

$(LIBFTOBJS): %.o: %.c $(LIBFT).h
	@printf "$(GREEN)       Generating $@ $(DEFAULT)        \r"
	@$(CC) $(CFLAGS) -I inc/ $<
	@mv $*.o obj/


clean:
	@$(RM) $(ALLOBJSDIR) 

fclean: clean 
	@$(RM) $(NAME) 

re:	fclean all

.PHONY: clean fclean re all 