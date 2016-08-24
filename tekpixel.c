/*
** tekpixel.c for tekpixel in /home/gotte_a/rendu/infographie/gfx_fdf1
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Thu Nov 19 10:03:36 2015 Alexandre Gotte
** Last update Fri Jan 22 14:57:34 2016 Alexandre Gotte
*/

#include "paint.h"
#include <stdio.h>
#include "lapin.h"

t_color		get_pixel(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  int		pos_pix;
  t_color	c;

  pos_pix = (*pix).clipable.clip_width * pos->y + pos->x;
  c.full = ((int *)pix->pixels)[pos_pix];
  return (c);
}

int    	test_w(t_bunny_position *p, t_bunny_pixelarray *pix)
{
  if (p->x >= 0 && p->x <= pix->clipable.buffer.width && p->x < W_WIDTH)
    {
      if (p->y >= 0 && p->y <= pix->clipable.buffer.height && p->y < W_HEIGHT)
	return (0);
    }
  return (1);
}

void		tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos, unsigned int color)
{
  int		pos_pix;
  t_color	c;

  c.full = color;
  if (test_w(pos, pix) == 1)
    return;
  pos_pix = (*pix).clipable.clip_width * pos->y + pos->x;
  if (pos->x >= 0 && pos->x <= (*pix).clipable.clip_width)
    if (pos->y >= 0 && pos->y <= (*pix).clipable.clip_width)
      ((int *)pix->pixels)[pos_pix] = c.full;
}

void			fill_clipable(t_bunny_pixelarray *pix,
				      unsigned int color)
{
  int			j;
  int			i;
  t_bunny_position	pos;

  j = 0;
  while (j < (*pix).clipable.clip_height)
    {
      i = 0;
      pos.y = j;
      while (i < (*pix).clipable.clip_width)
	{
	  pos.x = i;
	  tekpixel(pix, &pos, color);
	  i = i + 1;
	}
      j = j + 1;
    }
}
