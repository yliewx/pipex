# declare makefile variables
NAME = pipex
LIB_NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -f

# source directories
LIB_DIR = libft
INC = includes

# pipex targets
TARGET = pipex.c command_utils.c exit_utils.c pipe_utils.c
SRCS = $(addprefix srcs/, $(TARGET))
BONUS_TARGET = pipex_bonus.c command_utils_bonus.c exit_utils_bonus.c \
	heredoc_bonus.c pipe_utils_bonus.c
BONUS_SRCS = $(addprefix srcs_bonus/, $(BONUS_TARGET))

# libft targets
LIB_TARGET = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c \
	get_next_line.c
LIB_SRCS = $(addprefix srcs/, $(LIB_TARGET))
LIB_OBJS = $(LIB_SRCS:.c=.o)

# colours
GREEN = \033[0;32m
B_GREEN = \033[1;32m
BROWN = \033[0;33m
B_BROWN = \033[1;33m
END = \033[0m

# RULES
# all = create library from sub-make
all: $(LIB_NAME)

mandatory: $(SRCS) $(LIB_NAME)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -I $(INC) -L $(LIB_DIR) -l ft
	@echo "$(B_GREEN)$(NAME) compiled.$(END)"

bonus: $(BONUS_SRCS) $(LIB_NAME)
	@$(CC) $(CFLAGS) $(BONUS_SRCS) -o $(NAME) -I $(INC) -L $(LIB_DIR) -l ft
	@echo "$(B_GREEN)$(NAME) bonus compiled.$(END)"

$(LIB_NAME):
	cd $(LIB_DIR) && $(MAKE)

# remove temporary generated files
clean:
	@cd $(LIB_DIR) && $(RM) $(LIB_OBJS)
	@echo "$(B_GREEN)Removed all obj files.$(END)"

# remove library and executable file
fclean: clean
	@$(RM) $(NAME) && cd $(LIB_DIR) && $(RM) $(LIB_NAME)
	@echo "$(B_GREEN)Removed $(NAME) and $(LIB_NAME).$(END)"

# declare phony
.PHONY: all bonus clean fclean mandatory re
