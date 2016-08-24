/*
** tkp_color.c for coooooolloooor in /home/gotte_a/rendu/infographie/gfx_tekpaint
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Sun Jan  3 19:47:24 2016 Alexandre Gotte
** Last update Sun Jan  3 20:04:09 2016 Alexandre Gotte
*/

#include "paint.h"

unsigned int	*fill_fcolor()
{
  unsigned int	*color;

  color = bunny_malloc(sizeof(unsigned int) * 10);
  color[0] = WHITE;
  color[1] = BLACK;
  color[2] = RED;
  color[3] = GREEN;
  color[4] = YELLOW;
  color[5] = PINK;
  color[6] = TEAL;
  color[7] = BLUE;
  color[8] = WHITE;
  color[9] = WHITE;
  return (color);
}
  
void		fast_color(t_bjr *bjr, int m)
{
  unsigned int	*color;
  int		i;
  int		nc;

  color = fill_fcolor();
  i = 0;
  while (i < 8)
    {
      if (color[i] == bjr->c.full)
	nc = i;
      i = i + 1;
    }
  if (m == 0)
    {
      nc = nc - 1;
      if (nc == -1)
	nc = 7;
    }
  else if (m == 1)
    {
      nc = nc + 1;
      if (nc == 8)
	nc = 0;
    }
  bjr->c.full = color[nc];
  bunny_free(color);
}
