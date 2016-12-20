# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwells <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/07 20:20:41 by gwells            #+#    #+#              #
#    Updated: 2016/12/14 14:56:25 by gwells           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM			= ft_nm
OTOOL		= ft_otool

$(shell mkdir -p .obj/src/otool 2> /dev/null)
$(shell mkdir -p .obj/src/nm 2> /dev/null)

OBJ_PATH	= .obj/
TMPOTOOL	= $(SRCOTOOL:.c=.o)
TMPNM		= $(SRCNM:.c=.o)
TMPNMOTOOL	= $(SRCNMOTOOL:.c=.o)
OBJOTOOL	= $(addprefix $(OBJ_PATH), $(TMPOTOOL))
OBJNM		= $(addprefix $(OBJ_PATH), $(TMPNM))
OBJNMOTOOL	= $(addprefix $(OBJ_PATH), $(TMPNMOTOOL))
CC			= gcc
CFLAGS		= #-Wall -Wextra -Werror 
INCLUDES	= -I./includes
LIB			= -L. -lft

# ***************************NMOTOOL******************************************** #
CNMOTOOL	= arch_tools.c\
			  print_tools.c\

SRCNMOTOOL	= $(addprefix src/, $(CNMOTOOL))

# ***************************OTOOL******************************************** #
COTOOL		= otool.c\
			  fatheader.c\
			  header.c\
			  parse.c\
			  arch.c\
			  print.c\
			 
SRCOTOOL	= $(addprefix src/otool/, $(COTOOL))

# ****************************NM********************************************* #
CNM			= arch.c\
			  fatheader.c\
			  header.c\
			  nm.c\
			  parse.c\
			  print.c\
			  printaddr.c\
			  ptrfunc.c\
			  ptrsym.c\
			  ptrsymsect.c\
			  through_seg.c\
			  sort.c\

SRCNM		= $(addprefix src/nm/, $(CNM))

###############################################################################

all: $(OTOOL) $(NM)

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -g -o $@ -c $<

$(OTOOL): $(OBJOTOOL) $(OBJNMOTOOL)
	make -C libft
	cp libft/libft.a . && cp libft/libft.h ./includes
	$(CC) $(CFLAGS) $(OBJOTOOL) $(OBJNMOTOOL) $(LIB) -o $(OTOOL) 

$(NM): $(OBJNM) $(OBJNMOTOOL)
	make -C libft
	cp libft/libft.a . && cp libft/libft.h ./includes
	$(CC) $(CFLAGS) $(OBJNM) $(OBJNMOTOOL) $(LIB) -o $(NM) 

submodule :
	git submodule init libft
	git submodule update --remote libft
	git submodule init nm-otool.wiki
	git submodule update --remote nm-otool.wiki

clean:
	rm -rf $(OBJOTOOL) $(OBJNM)

fclean: clean
	rm -rf $(OTOOL) a.out $(NM) 

re: fclean $(OTOOL) $(NM)
