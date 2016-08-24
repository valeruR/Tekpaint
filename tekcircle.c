/*
** tekcircle.c for tekcircle in /home/gotte_a/rendu/infographie/xorshape_2020
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Thu Dec  3 10:27:15 2015 Alexandre Gotte
** Last update Fri Jan 22 14:45:32 2016 Alexandre Gotte
*/

#include "paint.h"
#include "lapin.h"

void			put_pixel(t_bunny_pixelarray *pix, int x, int y, unsigned int color)
{
  t_bunny_position	pos_put;

  pos_put.x = x;
  pos_put.y = y;
  tekpixel(pix, &pos_put, color);
}

void			tekcircle(t_bunny_pixelarray *pix, t_bunny_position *pos,
				  double radius, unsigned int color)
{
  t_bunny_position	pos_p;
  int			m;

  pos_p.x = 0;
  pos_p.y = radius;
  m = 5 - (4 * radius);
  while (pos_p.x <= pos_p.y)
    {
      put_pixel(pix, pos->x + pos_p.x, pos->y + pos_p.y, color);
      put_pixel(pix, pos->x + pos_p.y, pos->y + pos_p.x, color);
      put_pixel(pix, pos->x - pos_p.x, pos->y + pos_p.y, color);
      put_pixel(pix, pos->x - pos_p.y, pos->y + pos_p.x, color);
      put_pixel(pix, pos->x + pos_p.x, pos->y - pos_p.y, color);
      put_pixel(pix, pos->x + pos_p.y, pos->y - pos_p.x, color);
      put_pixel(pix, pos->x - pos_p.x, pos->y - pos_p.y, color);
      put_pixel(pix, pos->x - pos_p.y, pos->y - pos_p.x, color);
      if (m > 0)
	{
	  pos_p.y = pos_p.y - 1;
	  m = m - (8 * pos_p.y);
	}
      pos_p.x = pos_p.x + 1;
      m = m + (8 * pos_p.x) + 4;
    }
}

void			pros_lep(t_bunny_pixelarray *pix, t_bunny_position *pos,
				 double radius, unsigned int color)
{
  t_bunny_position	pos_p;
  int			m;

   pos_p.x = 0;
   pos_p.y = radius;
   m = 5 - (4 * radius);
   while (pos_p.x <= pos_p.y)
     {
       put_pixel(pix, pos->x + pos_p.x, pos->y + pos_p.y, color);
       put_pixel(pix, pos->x + pos_p.y, pos->y + pos_p.x, color);
       put_pixel(pix, pos->x - pos_p.x, pos->y + pos_p.y, color);
       put_pixel(pix, pos->x - pos_p.y, pos->y + pos_p.x, color);
       put_pixel(pix, pos->x + pos_p.x, pos->y - pos_p.y, color);
       put_pixel(pix, pos->x + pos_p.y, pos->y - pos_p.x, color);
       put_pixel(pix, pos->x - pos_p.x, pos->y - pos_p.y, color);
       put_pixel(pix, pos->x - pos_p.y, pos->y - pos_p.x, color);
       if (m > 0)
	 {
	   pos_p.y = pos_p.y - 1;
	   m = m - (8 * pos_p.y);
	 }
       pos_p.x = pos_p.x + 1;
       m = m + (8 * pos_p.x) + 4;
     }
}

void	tekcirclep(t_bunny_pixelarray *pix, t_bunny_position *pos,
		   double radius, unsigned int color)
{
  while (radius >= 0)
    {
      pros_lep(pix, pos, radius, color);
      radius = radius - 1;
    }
}

