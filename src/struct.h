/*
** struct.h for struct in /home/geiger_a/rendu/PSU_2014_my_select
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Tue Dec 16 13:57:46 2014 anthony geiger
** Last update Thu Dec 18 16:59:10 2014 anthony geiger
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# define HIGHT 4283163
# define DOWN 4348699
# define LEFT 4479771
# define RIGHT 4414235
# define ESC 27
# define SPACE 32
# define ENT 10
# define SUPPR_KEY 127
# define SUPPR_SYST 1741551364

typedef struct		s_win
{
  unsigned short	ws_row;
  unsigned short	ws_col;
}			t_win;

typedef	struct		s_eta
{
  int			argc;
  char			*str;
  char			select;
  char			suppr_boole;
  char			cursor;
}			t_eta;

typedef	struct		s_key
{
  unsigned long		key;
  int			(*ptr_tab)(t_eta *etat);
}			t_key;

#endif /* !STRUCT_H_ */
