NAME = libftprintf.a
CC_FLAGS = -c -I
MOULINETTE = -Wall -Wextra -Werror
C_FILES = ft_printf.c ft_printf_utils.c ft_printf_utils_lf.c ft_printf_utils_ptr.c

O_FILES = ft_printf.o ft_printf_utils.o ft_printf_utils_lf.o ft_printf_utils_ptr.o
.PHONY: all clean fclean re
all: $(NAME)
$(NAME): $(O_FILES)
	cc $(MOULINETTE) $(CC_FLAGS) $(C_FILES)
	ar rc $(NAME) $(O_FILES)
clean:
	rm -f $(O_FILES)
fclean: clean
	rm -f $(NAME)
re: fclean all
