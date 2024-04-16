NAME = philo

CC = cc

# CFLAGS = -Wall -Wextra -Werror
CFLAGS += -pthread
# CFLAGS += -fsanitize=thread
# CFLAGS += -fsanitize=address
CFLAGS += -g

SRCS_DIR = src
OBJS_DIR = objs
SRCS	:=	main.c \
			din_philo_fix1.c \

SRCS	:=	$(addprefix ${SRCS_DIR}/, ${SRCS})

OBJS    =    $(SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o)

RM    =    rm -rf

INCLUDES = -I./include

DIR_DUP = mkdir -p $(@D)

all:${NAME}

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(RM) $(OBJS_DIR)

fclean:clean
	$(RM) $(NAME)

re:fclean all

norm:
	norminette | grep -v "OK" || true

.PHONY:
	all clean fclean re 
