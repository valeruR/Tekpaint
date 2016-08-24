/*
** tkp_init2.c for init2 in /home/d-ange_e/rendu/gfx_tekpaint
** 
** Made by d-angelo enzo
** Login   <d-ange_e@epitech.net>
** 
** Started on  Thu Jan 21 11:44:03 2016 d-angelo enzo
** Last update Fri Jan 22 15:13:21 2016 Alexandre Gotte
*/

#include "paint.h"

int     test_exten2(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  while(str[i] != '.')
    {
      i--;
    }
  if (reco_ext(i, str, ".tkp") == 1)
    return (1);
  else if (reco_ext(i, str, ".bmp") == 1)
    return (2);
  return (0);
}

t_tbut          init_t_but(int lx, int xl, int ly, int yl)
{
  t_tbut        but;

  but.lx = lx;
  but.xl = xl;
  but.ly = ly;
  but.yl = yl;
  return (but);
}
