#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_printf
{
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int	precision;
	int	star;
}	t_print;
int		ft_printf(const char *format, ...);
char	*conversion_10_on_16_min(unsigned int number);
char	*conversion_10_on_16_max(unsigned int number);
char	*conversion_p(unsigned long number);
int		ft_analysis_flags(const char *format, va_list ap, int index, t_print
			*flags);
int		ft_found_type(const char *str, int i);
int		ft_output_c(t_print *flags, va_list arg);
int		ft_output_s(t_print *flags, va_list arg);
int		ft_output_without(char *str);
int		ft_output_with_width(t_print *flags, char *str);
int		ft_output_x(t_print *flags, va_list arg);
int		ft_output_result_with_width(t_print *flags, char *str);
int		ft_output_x_max(t_print *flags, va_list arg);
int		ft_output_pointer(t_print *flags, va_list arg);
int		ft_output_digit_neg_with_width(t_print *flags, char *str);
int		ft_output_digit_neg_with_precision(t_print *flags, char *str);
int		ft_output_digit_with_width(char *s, t_print *flags, int len);
int		ft_output_digit_with_precision(t_print *flags, char *str);
char	*ft_new_string(char *str, int flag);
void	ft_output_x_zero(t_print *flags, char *s);
char	*ft_num_null(char *s);
int		ft_output_u(t_print *flags, va_list arg);
int		ft_output_d_and_i(t_print *flags, va_list arg);
int		ft_output_string(char *s);
void	ft_output_string_right(t_print *flags, char *s);
void	ft_output_string_left(t_print *flags, char *s);
int		ft_output_string_with_width(char *s, t_print *flags, int len);
void	ft_output_string_zero(t_print *flags, char *s);
char	*ft_itoa_u(unsigned int n);
int		ft_output_percent(t_print *flags);

#endif
