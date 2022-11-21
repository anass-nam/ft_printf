NAME = libftprintf.a
SRC =	ft_printf.c ft_printf_utils.c
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
R        := $(shell tput -Txterm setaf 1)
G        := $(shell tput -Txterm setaf 2)
Y       := $(shell tput -Txterm setaf 3)

all: $(NAME)
	@echo $(G) "ALL functions are done!"

$(NAME): $(OBJS)
	@ar rcs $@ $(OBJS)

%.o: %.c ft_printf.h
	@echo $(Y) Compiling: $< ... Done!
	@cc $(CFLAGS) -c $< \

clean:
	@echo $(R) Cleaned
	@rm -f $(OBJS)

fclean: clean
	@echo $(R) Fully cleaned
	@rm -f $(NAME)

re: fclean all