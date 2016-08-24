/*
** fct_uf.h for fct_uf in /home/gotte_a/rendu/infographie/gfx_fdf2/include
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Mon Dec 14 10:14:43 2015 Alexandre Gotte
** Last update Fri Jan 22 14:32:27 2016 Alexandre Gotte
*/

#ifndef _FCT_UF_H_
# define _FCT_UF_H_

typedef struct	s_pos2
{
  int		x;
  int		y;
}		t_pos2;
typedef struct	s_pos3
{
  int		x;
  int		y;
  int		z;
}		t_pos3;

unsigned int   	abs_val(unsigned int a);
double		divis_neu(double a, double b);
t_pos2		init_t_pos2(int x, int y);
t_pos3		init_t_pos3(int x, int y, int z);
#endif
