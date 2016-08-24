/*
** tkp_z.c for ctrlz in /home/gotte_a/rendu/infographie/tekpaint/current/gfx_tekpaint
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Fri Jan 22 09:48:28 2016 Alexandre Gotte
** Last update Fri Jan 22 15:36:24 2016 Alexandre Gotte
*/

#include "paint.h"

void			fill_zpix(t_bjr *bjr)
{
  t_bunny_position	p;
  t_color		c;

  p = init_bun_pos(0, 0);
  while (p.y < W_HEIGHT)
    {
      p.x = 0;
      while (p.x < W_WIDTH - 500)
	{
	  c = get_pixel(bjr->m_pix, &p);
	  tekpixel(bjr->ctz.z_pix[bjr->ctz.nb], &p, c.full);
	  p.x = p.x + 1;
	}
      p.y = p.y + 1;
    }
}

void			fill_zpix2(t_bjr *bjr)
{
  t_bunny_position	p;
  t_color		c;

  p = init_bun_pos(0, 0);
  while (p.y < W_HEIGHT)
    {
      p.x = 0;
      while (p.x < W_WIDTH - 500)
	{
	  c = get_pixel(bjr->ctz.z_pix[bjr->ctz.nb], &p);
	  tekpixel(bjr->m_pix, &p, c.full);
	  p.x = p.x + 1;
	}
      p.y = p.y + 1;
    }
}

void	hun_ctz(t_bjr *bjr)
{
  bunny_delete_clipable(&bjr->ctz.z_pix[bjr->ctz.nb]->clipable);
  bjr->ctz.z_pix[bjr->ctz.nb] = bunny_new_pixelarray(W_WIDTH - 500, W_HEIGHT);
  fill_zpix(bjr);
  bjr->ctz.nb =  bjr->ctz.nb + 1;
  if (bjr->ctz.nb > 2)
    bjr->ctz.nb = 0;
  bjr->ctz.us = 1;
}


void	hun_ctz2(t_bjr *bjr)
{
  fill_zpix2(bjr);
  bjr->ctz.nb -= 1;
  if (bjr->ctz.nb < 0)
    {
      bjr->ctz.nb = 0;
      bjr->ctz.us = 0;
    }
}
