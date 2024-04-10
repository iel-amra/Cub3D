
NAME		:= cub3D

CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror -O3 #-g3 -fsanitize=address


# ----------------------- Directories ---------------------------
OBJS_DIR 	:= objs
SRC_DIR 	:= src/
INCLUDE_DIR := includes/

MLX_DIR		:= mlx

# ----------------------- Files ---------------------------


SRC_COMMON	:=  main.c events.c utils.c init.c init_mapinfos.c check_error.c  raycast.c raycast_utils.c
SRC_MAND	:= 
SRC_BONUS 	:= 
OBJS_COMMON		:= $(addprefix ${OBJS_DIR}/, ${SRC_COMMON:.c=.o})
OBJS_MAND		:= $(addprefix ${OBJS_DIR}/, ${SRC_MAND:.c=.o})
OBJS_BONUS		:= $(addprefix ${OBJS_DIR}/bonus/, ${SRC_BONUS:.c=.o})

HEADER_COMMON		:= $(addprefix ${INCLUDE_DIR}, cube3d.h config_strings_en.h)
HEADER_BONUS		:= $(addprefix ${INCLUDE_DIR}, )


LIBFT		:= libft/libft.a
MLX			:= mlx/libmlx.a


all:	 ${NAME}

${LIBFT}: FORCE
			@make FLAGS="$(FLAGS)" -C libft

$(MLX): FORCE
			@make -C mlx

${NAME}: 	 ${OBJS_COMMON} $(OBJS_MAND)
	${CC}   ${FLAGS} -o $@ $^ -Ilibft/src -I${INCLUDE_DIR} -lm -Lmlx -lmlx -lXext -lX11 -Llibft -lft $(MLX)


${OBJS_DIR}/%.o :  ${SRC_DIR}%.c $(HEADER_COMMON) ${LIBFT} $(MLX) Makefile
			@mkdir -p $(@D)
			${CC} ${FLAGS}  -c  $< -o $@ -Ilibft/src -I${INCLUDE_DIR}  -I$(MLX_DIR)/ -include cube3d.h

FORCE:

clean:		
			@make clean -C libft
			@make clean -C mlx
			rm -f -r ${OBJS_DIR}

fclean:		clean
			@make fclean -C libft
			rm -f  ${NAME}

re:			fclean all

.PHONY:		all clean fclean re FORCE mlx
