NAME = libftprintf.a

SRC = ft_printf.c ft_print_string.c ft_print_ptr.c ft_print_num.c \
	 ft_print_hex.c ft_print_unsigned.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT_DIR = ./libft

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m

all: $(NAME)

$(NAME):	$(OBJS)
	@make -C $(LIBFT_DIR)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"
	@echo "$(GREEN)libft compiled!$(DEF_COLOR)"

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"
	@echo "$(BLUE)libft object files cleaned!$(DEF_COLOR)"

fclean:	clean
	@$(RM) $(LIBFT_DIR)/libft.a
	@$(RM) $(NAME)
	@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:	fclean all

test: fclean $(NAME)
	@$(CC) $(FCLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o test_printf
	./test_printf

.PHONY: all fclean clean re
