##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

NAME = my_rpg

## ------ COLORS ------ ##

DEFAULT     =   "\033[00m"
RED         =   "\033[31m"
GREEN       =   "\033[1;32m"
TEAL        =   "\033[1;36m"
YELLOW      =   "\033[1;7;25;33m"
MAGENTA     =   "\033[1;3;4;35m"
ERROR       =   "\033[5;7;1;31m"
BLINK       =   "\033[5m"
END         =   "\n"

SRC = $(wildcard src/*.c) \
	  $(wildcard src/displays/*.c) \
	  $(wildcard src/events/*.c) \
	  $(wildcard src/init/*.c) \
	  $(wildcard src/collision/*.c) \
	  $(wildcard src/entities/*.c) \
	  $(wildcard src/boss/*.c) \
	  $(wildcard src/mobs/*.c) \
	  $(wildcard src/object/*.c) \
	  $(wildcard src/interface/*.c) \
	  $(wildcard src/utils/*.c) \
	   $(wildcard src/save/*.c) \
	  $(wildcard src/player/*.c) \
	  $(wildcard src/tp/*.c) \
	  $(wildcard src/utils/list/*.c)

OBJ = $(SRC:.c=.o)

CC = @gcc

CFLAGS += -Wall -Wcomment -I./include -g3

FFLAGS += -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -lm

.c.o:
	$(CC) $(CFLAGS) $(FFLAGS) -c $< -o $@ && \
	printf "["$(GREEN)"OK"$(DEFAULT)"] "$(TEAL)$<$(DEFAULT)" -----> "$(GREEN)$@$(DEFAULT)$(END) || \
	printf "["$(RED)"KO"$(DEFAULT)"] "$(BLINK)$(YELLOW)$^$(DEFAULT)$(END) 1>&2

all: $(NAME)
	@printf "["$(GREEN)"INFO"$(DEFAULT)"]     "$(MAGENTA)"GOOD GAME :p"$(DEFAULT)$(END)

$(NAME): $(OBJ)
	@make --no-print-directory -C lib re
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(FFLAGS) lib/libmy
	@printf "["$(GREEN)"OK"$(DEFAULT)"]"$(TEAL)" Done : "$(GREEN)$@$(DEFAULT)$(END) || \
	printf "["$(RED)"KO"$(DEFAULT)"]"$(BLINK)$(YELLOW)$(NAME)$(DEFAULT)$(END) 1>&2

clean:
	@make --no-print-directory -C lib/ clean
	@rm -f $(OBJ)
	@printf "["$(RED)"DEL"$(DEFAULT)"] $(OBJ)"$(END)m

fclean: clean
	@make --no-print-directory -C lib/ fclean
	@rm -f $(NAME)
	@printf "["$(RED)"DEL"$(DEFAULT)"] $(NAME)"$(END)

re: fclean all
