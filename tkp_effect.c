/*
** tkp_effect.c for effect in /home/gotte_a/rendu/infographie/gfx_tekpaint
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Sun Jan  3 19:36:02 2016 Alexandre Gotte
** Last update Wed Jan 20 02:45:15 2016 Alexandre Gotte
*/

#include "paint.h"

void			base(t_bjr *bjr, t_bunny_pixelarray *pix)
{
  t_bunny_position	p;
  t_color		tmp;

  p = init_bun_pos(0, 0);
  while (p.y < W_HEIGHT)
    {
      p.x = 0;
      while (p.x < W_WIDTH)
	{
	  tmp = get_pixel(bjr->m_pix, &p);
	  tekpixel(pix, &p, tmp.full);
	  p.x = p.x + 1;
	}
      p.y = p.y + 1;
    }
}

void			invert(t_bjr *bjr, t_bunny_pixelarray *pix)
{
  t_bunny_position	p;
  t_color		tmp;

  p = init_bun_pos(0, 0);
  while (p.y < W_HEIGHT)
    {
      p.x = 0;
      while (p.x < W_WIDTH)
	{
	  tmp = get_pixel(bjr->m_pix, &p);
	  tmp.argb[0] = 255 - tmp.argb[0];
	  tmp.argb[1] = 255 - tmp.argb[1];
	  tmp.argb[2] = 255 - tmp.argb[2];
	  tekpixel(pix, &p, tmp.full);
	  p.x = p.x + 1;
	}
      p.y = p.y + 1;
    }
}

void			shade_of_grey(t_bjr *bjr, t_bunny_pixelarray *pix)
{
  t_bunny_position	p;
  t_color		tmp;
  unsigned char		moy;

  p = init_bun_pos(0, 0);
  while (p.y < W_HEIGHT)
    {
      p.x = 0;
      while (p.x < W_WIDTH)
	{
	  tmp = get_pixel(bjr->m_pix, &p);
	  moy = (tmp.argb[0] + tmp.argb[1] + tmp.argb[2]) / 3;
	  tmp.argb[0] = moy;
	  tmp.argb[1] = moy;
	  tmp.argb[2] = moy;
	  tekpixel(pix, &p, tmp.full);
	  p.x = p.x + 1;
	}
      p.y = p.y + 1;
    }
}

void			black_n_white(t_bjr *bjr, t_bunny_pixelarray *pix)
{
  t_bunny_position	p;
  t_color		tmp;
  unsigned char		moy;

  p = init_bun_pos(0, 0);
  while (p.y < W_HEIGHT)
    {
      p.x = 0;
      while (p.x < W_WIDTH)
	{
	  tmp = get_pixel(bjr->m_pix, &p);
	  moy = (tmp.argb[0] + tmp.argb[1] + tmp.argb[2]) / 3;
	  if (moy >= 128)
	    tmp.full = WHITE;
	  else
	    tmp.full = BLACK;
	  tekpixel(pix, &p, tmp.full);
	  p.x = p.x + 1;
	}
      p.y = p.y + 1;
    }
}

void		do_effect(t_bjr *bjr, t_bunny_pixelarray *pix)
{
  if (bjr->filter == 0)
    base(bjr, pix);
  else if (bjr->filter == 1)
    invert(bjr, pix);
  else if (bjr->filter == 2)
    shade_of_grey(bjr, pix);
  else if (bjr->filter == 3)
    black_n_white(bjr, pix);
}
