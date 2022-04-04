NAME		= 	libftprintf.a
SRCS		= 	ft_printf.c \
				sources/conversion_10_on_16_max.c \
				sources/conversion_10_on_16_min.c \
				sources/conversion_p.c \
				sources/flags.c \
				sources/ft_itoa_u.c \
				sources/ft_output_c.c \
				sources/ft_output_d_and_i.c \
				sources/ft_output_left_and_right_str.c \
				sources/ft_output_pointer.c \
				sources/ft_output_s.c \
				sources/ft_output_u.c\
				sources/ft_output_x.c \
				sources/ft_output_x_max.c \
				sources/ft_output_percent.c \
				sources/ft_other_func.c \
				sources/ft_other_func_2.c
CC 			= 	gcc
FLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	includes/ft_printf.h
OBJS		=	$(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS)  -c $< -o $@

${NAME}:	$(OBJS) $(INCLUDES)
			$(MAKE) -C ./libft
			cp ./libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re