NAME := libft.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRCS := ft_isalpha.c    ft_memcmp.c     ft_putstr_fd.c  ft_strlen.c     ft_tolower.c \
    ft_isascii.c    ft_memcpy.c     ft_strchr.c     ft_strmapi.c    ft_toupper.c \
    ft_isdigit.c    ft_memmove.c    ft_strdup.c     ft_strncmp.c  \
	ft_atoi.c       ft_isprint.c    ft_memset.c     ft_striteri.c   ft_strnstr.c    \
	ft_bzero.c      ft_itoa.c       ft_putchar_fd.c ft_strjoin.c    ft_strrchr.c    \
	ft_calloc.c     ft_putendl_fd.c ft_strlcat.c    ft_strtrim.c ft_split.c\
	ft_isalnum.c    ft_memchr.c     ft_putnbr_fd.c  ft_strlcpy.c    ft_substr.c \

BONUSRC := ft_lstnew_bonus.c ft_lstsize_bonus.c \
	ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c \
	ft_lstlast_bonus.c ft_lstdelone_bonus.c  ft_lstclear_bonus.c \
	ft_lstiter_bonus.c ft_lstmap_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJNS = $(BONUSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJNS)
	ar rcs $(NAME) $(OBJNS)

clean: 
	rm -f $(OBJS) $(OBJNS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus