# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwells <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/07 20:20:41 by gwells            #+#    #+#              #
#    Updated: 2016/10/21 20:20:09 by gwells           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NM			= ft_nm
OTOOL		= ft_otool

$(shell mkdir -p .obj/src/otool 2> /dev/null)
$(shell mkdir -p .obj/src/nm 2> /dev/null)

OBJ_PATH	= .obj/
TMPOTOOL	= $(SRCOTOOL:.c=.o)
TMPNM		= $(SRCNM:.c=.o)
OBJOTOOL	= $(addprefix $(OBJ_PATH), $(TMPOTOOL))
OBJNM		= $(addprefix $(OBJ_PATH), $(TMPNM))
CC			= gcc
CFLAGS		= #-Wall -Wextra -Werror 
INCLUDES	= -I./includes
LIB			= -L. -lft

# ***************************OTOOL******************************************** #
COTOOL		= otool.c\
			  fatheader.c\
			  header.c\
			  parse.c\
			  arch.c

			 
SRCOTOOL	= $(addprefix src/otool/, $(COTOOL))

# ****************************NM********************************************* #
CNM			= test.c\

SRCNM		= $(addprefix src/nm/, $(CNM))

###############################################################################

all: $(OTOOL) $(NM)

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -g -o $@ -c $<

$(OTOOL): $(OBJOTOOL)
	make -C libft
	cp libft/libft.a . && cp libft/libft.h ./includes
	$(CC) $(CFLAGS) $(OBJOTOOL) $(LIB) -o $(OTOOL) 

$(NM): $(OBJNM)
	make -C libft
	cp libft/libft.a . && cp libft/libft.h ./includes
	$(CC) $(CFLAGS) $(OBJNM) $(LIB) -o $(NM) 

submodule :
	git submodule init libft
	git submodule update --remote libft
	git submodule init nmotool.wiki
	git submodule update --remote nmotool.wiki

clean:
	rm -rf $(OBJOTOOL) $(OBJNM)

fclean: clean
	rm -rf $(OTOOL) a.out $(NM) 

re: fclean $(OTOOL) $(NM)
