# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abronner <abronner@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:46:56 by abronner          #+#    #+#              #
#    Updated: 2025/07/12 10:33:32 by abronner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include colors.mk

NAME		:=	libft.a

# * DIRECTORIES ************************************************************** #

SRC_DIR		:=	srcs/

OBJ_DIR		:=	objs/

SUB_DIR		:=	ctype/ std/ strings/ split/ put/ list/ stack/

INC_DIR		:=	incl/

# * SOURCES & OBJECTS ******************************************************** #

SRCS		:=	

S_CTYPE		:=	alpha.c digit.c alnum.c graph.c print.c special.c convertchr.c

O_CTYPE		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(S_CTYPE))

S_STD		:=	mem.c mem_create.c convertstr.c convertstr_utils.c \
				convertstr_wrappers.c

O_STD		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(S_STD))

S_STRING	:=	check.c copy.c search.c create.c striter.c

O_STRING	:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(S_STRING))

S_SPLIT		:=	split.c

O_SPLIT		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(S_SPLIT))

S_PUT		:=	putstr.c putnbr.c

O_PUT		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(S_PUT))

S_LIST		:=	listnew.c listutils.c listdel.c

O_LIST		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(S_LIST))

S_STACK		:=	stack.c

O_STACK		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(S_STACK))

OBJS		:=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

# * MISC ********************************************************************* #

DOTFILES	:=	.ctype .std .string .split .put .list .stack

# * COMMANDS ***************************************************************** #

CC			:=	cc

CFLAGS		:=	-Wall -Wextra -Werror

g:	CFLAGS	+=	-g

CPPFLAGS	:=	-I$(INC_DIR)

LIBFLAGS	:=	

# * COMMANDS ***************************************************************** #

PRNT		:= printf

RM			:= rm -rf

# * V PATH ******************************************************************* #

vpath %.c $(SRC_DIR) $(patsubst %, $(SRC_DIR)%, $(SUB_DIR))

# * RULES ******************************************************************** #

all: $(NAME)

g: p_g $(NAME)

p_g:
	@$(PRNT) "Compiling $(P_NAME) with $(P_FLAG) flag\n"

ctype: .ctype

.ctype: $(OBJ_DIR) $(O_CTYPE)
	@touch .ctype
	@ar rcs $(NAME) $(O_CTYPE)
	@$(PRNT) "Adding $(P_CTYPE) files to $(P_NAME).\n"

std: .std

.std: $(OBJ_DIR) ctype $(O_STD)
	@touch .std
	@ar rcs $(NAME) $(O_STD)
	@$(PRNT) "Adding $(P_STD) files to $(P_NAME).\n"

string: .string

.string: $(OBJ_DIR) std $(O_STRING)
	@touch .string
	@ar rcs $(NAME) $(O_STRING)
	@$(PRNT) "Adding $(P_STRING) files to $(P_NAME).\n"

split: .split

.split: $(OBJ_DIR) string $(O_SPLIT)
	@touch .split
	@ar rcs $(NAME) $(O_SPLIT)
	@$(PRNT) "Adding $(P_SPLIT) files to $(P_NAME).\n"

put: .put

.put: $(OBJ_DIR) string $(O_PUT)
	@ar rcs $(NAME) $(O_PUT)
	@$(PRNT) "Adding $(P_PUT) files to $(P_NAME).\n"

list: .list

.list: $(OBJ_DIR) $(O_LIST)
	@ar rcs $(NAME) $(O_LIST)
	@$(PRNT) "Adding $(P_LIST) files to $(P_NAME).\n"

stack: .stack

.stack: $(OBJ_DIR) $(O_STACK)
	@touch .stack
	@ar rcs $(NAME) $(O_STACK)
	@$(PRNT) "Adding $(P_STACK) files to $(P_NAME).\n"

$(NAME): p_name ctype std string split put list stack

p_name:
	@$(PRNT) "Creating library $(P_NAME).\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@$(PRNT) "Creating $(P_ODIR) directory.\n"

$(OBJ_DIR)%.o: %.c 
	@$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c -o $@
	@$(PRNT) "Compiling $(P_AT).\n"

re: fclean all

clean:
	@$(RM) $(OBJ_DIR) $(DOTFILES)
	@$(PRNT) "Deleting object files for $(P_NAME).\n"

fclean: clean
	@$(RM) $(NAME)
	@$(PRNT) "Deleting library $(P_NAME).\n"

.PHONY: all bonus re clean fclean make \
	ctype std string split stack

# * PRINTING PRESETS ********************************************************************** #

P_NAME=$(C_RED)$(BLD)$(NAME)$(RESET)

P_ODIR=$(C_BLU)$(BLD)$(OBJ_DIR)$(RESET)

P_FLAG=$(C_MAG)$(BLD)-g$(RESET)

P_CTYPE=$(C_YLW)$(BLD)ctype$(RESET)

P_STD=$(C_YLW)$(BLD)std$(RESET)

P_STRING=$(C_YLW)$(BLD)string$(RESET)

P_SPLIT=$(C_YLW)$(BLD)split$(RESET)

P_PUT=$(C_YLW)$(BLD)put$(RESET)

P_LIST=$(C_YLW)$(BLD)list$(RESET)

P_STACK=$(C_YLW)$(BLD)stack$(RESET)

P_AT=$(C_GRN)$(BLD)$@$(RESET)
