##
## Makefile for Makefile_comp in //home/gotte_a/rendu/Makefiles/Makefile_comp
## 
## Made by Alexandre Gotte
## Login   <gotte_a@epitech.net>
## 
## Started on  Sun Oct 25 23:00:05 2015 Alexandre Gotte
## Last update Fri Jan 22 14:39:58 2016 Alexandre Gotte
##

NAME	= tekpaint

SRCS	= tekpixel.c \
	tekline.c \
	tekcircle.c \
	fct_uf.c \
	tkp_main.c \
	tkp_main2.c \
	tkp_event.c \
	tkp_event2.c \
	tkp_pen.c \
	tkp_pen2.c \
	tkp_init.c \
	tkp_init2.c \
	tkp_effect.c \
	tkp_color.c \
	tkp_ui.c \
	tkp_load.c \
	tkp_load2.c \
	tkp_load3.c \
	tkp_load4.c \
	tkp_z.c 

OBJS	= $(SRCS:.c=.o)

CC	= gcc 

RM	= rm -f

CFLAGS	= -ansi -pedantic -Iinclude -Wall -Werror

LDFLAGS = -I/home/${USER}/.froot/include \
	-L/home/${USER}/.froot/lib \
	-llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm  

all: $(NAME) 

$(NAME): $(OBJS) 
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
