/*
** my.h for m in /home/geiger_a/rendu/CPE_2014_Pushswap
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Sat Dec  6 13:23:29 2014 anthony geiger
** Last update Sat Jan 10 10:00:43 2015 Anthony Geiger
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <term.h>
# include "struct.h"

void		my_putchar(char c);
void		my_putnbr(int nb);
void		my_putstr(char *str);
void		my_putsterr(char *str);
int		case_right(t_eta *etat);
int		case_hight(t_eta *etat);
int		case_down(t_eta *etat);
int		case_left(t_eta *etat);
int		my_putc(int c);
int		my_actualisation(struct termios *term);
void		my_show_tab(t_eta *etat, t_win *win, int size_colone);
void	        my_clean(t_win *win);
int		my_select(struct termios *term, t_eta *etat, int size_colone);
int		my_ptr_tab(unsigned long buffer, t_eta *etat);
int		my_gere_select(int argc, char **argv, int size_colone,
			       struct termios *term);
void		my_putstr_lime(char *str, int lime);
int		my_gere_key(struct termios *term, t_eta *etat);
int		case_space(t_eta *etat);
void		my_put_space(int i);
int		case_suppr();
void		my_putchar_fd0(char c);
void		my_putstr_fd0(char *str);
int		my_put_selec(t_eta *etat);
int		my_aff_fonc(int i, int colone, t_eta *etat, int size_colone);
void		my_aff_underscore(t_eta *etat, int i, int size_colone);
void		my_aff_select(t_eta *etat, int i, int size_colone);
void		my_aff_under_select(t_eta *etat, int i, int size_colone);
int		my_strlen(char *str);
void		my_aff_underscor(t_eta *etat, int i, int size_colone);
int                     get_colone_size(int argc, char **argv);
int                     nb_colone(int i, int colone, t_win *win, t_eta *etat);
void                    my_clean(t_win *win);
void		nothing();
void		my_init_tab(t_eta *etat, int argc, char **argv);
void		my_alignement(int i, int colone);
void		my_err_size(int i, int colone, t_win *win, int size_colone);
int			my_final_clear();
int                     my_put_rest(struct termios *term);
void			my_alignement(int i, int colone);
void			my_err_size(int i, int colone, t_win *win, int size_line);
int     my_strncmp(char *a, char *b, int nb);
char	*find_term(char **env);
char    *my_strnsdup(char *src, int nb);
char    *my_strnscpy(char *dest, char *src, int nb);

#endif /* !MY_H_ */
