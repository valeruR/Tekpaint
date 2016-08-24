/*
** fct_useful.c for fct_usefull in /home/gotte_a/rendu/infographie/gfx_fdf2
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Mon Dec 14 10:11:47 2015 Alexandre Gotte
** Last update Fri Jan 15 13:51:30 2016 Alexandre Gotte
*/

#include "fct_uf.h"

unsigned int	abs_val(unsigned int a)
{
  if (a < 0)
    a = a * -1;
  return (a);
}

double		divis_neu(double a, double b)
{
  double	rep;
  double        rest;

  rep = a / b;
  rest = a - (rep * b);
  rest = rest * 10;
  rest = rest / b;
  rest = rest / 10;
  rep = rep + rest;
  return (rep);
}

t_pos2		init_t_pos2(int x, int y)
{
  t_pos2	pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}

t_pos3		init_t_pos3(int x, int y, int z)
{
  t_pos3	pos;

  pos.x = x;
  pos.y = y;
  pos.z = z;
  return (pos);
}
