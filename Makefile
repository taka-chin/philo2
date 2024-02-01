NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -pthread
CFLAGS += -fsanitize=thread
# CFLAGS += -fsanitize=address
CFLAGS += -g

SRCS_DIR = src
UTILS_DIR = utils
OBJS_DIR = objs
SRCS	:=	main.c \
				error.c \
				check.c \
				init.c \
				$(UTILS_DIR)/ft_atoi.c \
				$(UTILS_DIR)/ft_bzero.c \
				$(UTILS_DIR)/ft_calloc.c \
				$(UTILS_DIR)/ft_isdigit.c \
				$(UTILS_DIR)/all_free.c \
				# $(UTILS_DIR)/get_now_time.c \
				$(UTILS_DIR)/get_thread_num.c \
				$(UTILS_DIR)/actual_usleep.c \
				$(UTILS_DIR)/create_log_time.c \
				# log.c \
				pthread.c \
				dead_or_alive.c \
				observe.c \
				philo_actions.c \
				destory.c \

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
