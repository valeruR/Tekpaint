/*
** tkp_ui.c for tkp_ui in /home/gotte_a/rendu/infographie/gfx_tekpaint
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Sun Jan  3 20:15:01 2016 Alexandre Gotte
** Last update Wed Jan 27 02:25:52 2016 Alexandre Gotte
*/

#include "paint.h"

void			teksqu(t_bjr *bjr, t_bunny_position pos, int rad)
{
  t_bunny_position	p;

  p = init_bun_pos(0, 0);
  while (p.y < 0 + (16 * 2))
    {
      p.x = 0;
      while (p.x < 0 + (16 * 2))
	{
	  tekpixel(bjr->m_pix, &p, WHITE);
	  p.x = p.x + 1;
	}
      p.y = p.y + 1;
    }
  p = init_bun_pos(pos.x, pos.y);
  while (p.y < pos.y + (rad * 2))
    {
      p.x = pos.x;
      while (p.x < pos.x + (rad * 2))
	{
	  tekpixel(bjr->m_pix, &p, bjr->c.full);
	  p.x = p.x + 1;
	}
      p.y = p.y + 1;
    }
}

void			disp_ui(t_bjr *bjr)
{
  t_bunny_position	p;

  p = init_bun_pos(350, 400);
  tekcirclep(bjr->ui_pix, &p, 20, bjr->c.full);
  p.x = p.x + 1;
  tekcirclep(bjr->ui_pix, &p, 20, bjr->c.full);
}

void			ui_tool(t_bjr *bjr)
{
  t_bunny_position	p[5];
  int			i;

  i = 0;
  p[0] = init_bun_pos(128, 58);
  p[1] = init_bun_pos(128, 156);
  p[2] = init_bun_pos(128, 253);
  p[3] = init_bun_pos(128, 350);
  p[4] = init_bun_pos(128, 538);
  while (i < 5)
    {
      if (bjr->tool != i)
	tekcircle(bjr->ui_pix, &p[i], 5, WHITE);
      else
	tekcircle(bjr->ui_pix, &p[i], 5, RED);
      i = i + 1;
    }
}
