SRC		=  \
ft_atoi.c \
ft_split.c \
ft_strncmp.c	\
ft_strchr.c \
ft_strdup.c \
ft_calloc.c \
ft_memcmp.c \
ft_strndup.c \
ft_strjoin.c \
ft_strlen.c \
ft_strlcpy.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_abs.c \
ft_min.c \
ft_max.c \
ft_if.c \
ft_errorifnull.c \
ft_free.c		\
ft_free_array.c \
ft_open.c \
ft_close.c \
ft_substr.c \
ft_atoi.c \
ft_is_whitespace.c \
ft_strcpy.c \
ft_putstr.c \
ft_putendl.c \
ft_strcmp.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_hasonly.c \
ft_itoa.c \
ft_llst_addback.c \
ft_llst_addfront.c \
ft_llst_clear.c \
ft_llst_cut.c \
ft_llst_del.c \
ft_llst_del_if.c \
ft_llst_dup.c \
ft_llst_find.c \
ft_llst_getlast.c \
ft_llst_insert.c \
ft_llst_iterate.c \
ft_llst_extract.c\
ft_llst_isall.c \
ft_llst_joinbefore.c \
ft_llst_join.c \
ft_llst_midnext.c \
ft_llst_nextif.c \
ft_llst_previf.c \
ft_llst_ndel.c \
ft_llst_new.c \
ft_llst_reverse_iterate.c \
ft_llst_size.c \
ft_llst_sizeif.c \
is_charset.c \
print_big_hexa.c \
print_char.c \
print_int.c \
print_little_hexa.c \
print_pointer.c \
print_pourcentage.c \
print_string.c \
print_unsigned_int.c \
ft_printf_psf.c \
ft_printf_spaces.c \
ft_printf.c \
ft_printf_addons.c \
ft_get_next_line.c
OBJS		= $(addprefix ${OBJS_DIR}, ${SRC:.c=.o})

#Directories
OBJS_DIR = objs/
SRC_DIR = src/
INCLUDE_DIR = src/

NAME		= libft.a

HEADER		= $(addprefix ${INCLUDE_DIR}, libft.h)

CC			= gcc

FLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${OBJS_DIR}%.o : ${SRC_DIR}%.c	${HEADER} Makefile
			@mkdir -p $(@D)
			${CC} -include $(INCLUDE_DIR)libft.h ${FLAGS} -c  $< -o $@

${NAME}:	${OBJS}
			ar -crs ${NAME} ${OBJS}

clean:
			rm -f -r ${OBJS_DIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re debug
