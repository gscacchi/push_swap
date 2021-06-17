NAME = checker

NAME2 = push_swap

SRCS =  checker.c \
		checker2.c \
		ft_split.c \
		get_next_line.c \
		get_next_line_utils.c \
		operators.c \
		utils.c \
		utils2.c \
		utils3.c

SRCS2 =  push_swap.c \
		push_swap2.c \
		push_swap3.c \
		push_swap4.c \
		push_swap5.c \
		ft_split.c \
		get_next_line.c \
		get_next_line_utils.c \
		operators.c \
		utils.c \
		utils2.c \
		utils3.c 

OBJS = $(SRCS:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: 		$(NAME) $(NAME2)

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME2): 	$(OBJS2)
			$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2)

clean: 		$(MAKE) clean
			$(RM) $(OBJS) $(OBJS2)

fclean: 	clean
			$(RM) $(OBJS) $(OBJS2) $(NAME) $(NAME2)

re: 		fclean $(NAME)

.PHONY: 	all clean fclean re