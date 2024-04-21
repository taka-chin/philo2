NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -pthread
# CFLAGS += -fsanitize=thread
# CFLAGS += -fsanitize=address
# CFLAGS += -g

SRCS_DIR = src
UTILES_DIR = utils
OBJS_DIR = objs
SRCS	:=	main.c \
			check.c \
			init.c \
			destory.c \
			all_free.c \
			dining_philo.c \
			routine.c \
			put_log.c \
			$(UTILES_DIR)/ft_isdigit.c \
			$(UTILES_DIR)/ft_bzero.c \
			$(UTILES_DIR)/ft_calloc.c \
			$(UTILES_DIR)/ft_atoi.c \
			$(UTILES_DIR)/ft_put_error.c \
			$(UTILES_DIR)/create_log_time.c \
			$(UTILES_DIR)/get_now_time.c \
			$(UTILES_DIR)/actual_usleep.c \

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
