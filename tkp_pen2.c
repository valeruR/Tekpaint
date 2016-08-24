/*
** tkp_pen2.c for pen2 in /home/d-ange_e/rendu/gfx_tekpaint
** 
** Made by d-angelo enzo
** Login   <d-ange_e@epitech.net>
** 
** Started on  Thu Jan 21 11:53:32 2016 d-angelo enzo
** Last update Fri Jan 22 15:35:10 2016 Alexandre Gotte
*/

#include "paint.h"

void    switch_pen(t_bjr *bjr, int m)
{
  if (bjr->tool == 3)
    bjr->line.pts = 0;
  if (m == 0)
    {
      bjr->tool = bjr->tool - 1;
      if (bjr->tool == -1)
        bjr->tool = 4;
    }
  else if (m == 1)
    {
      bjr->tool = bjr->tool + 1;
      if (bjr->tool == 5)
        bjr->tool = 0;
    }
}

void    cray_r(t_bjr *bjr, t_bunny_position *pos)
{
  tekcirclep(bjr->m_pix, pos, bjr->radius, bjr->c.full);
  pos->x++;
  tekcirclep(bjr->m_pix, pos, bjr->radius, bjr->c.full);
}

void                    cray_c(t_bjr *bjr, t_bunny_position *pos)
{
  t_bunny_position      p;

  p = init_bun_pos(pos->x - bjr->radius, pos->y - bjr->radius);
  while ((p.y < pos->y + bjr->radius))
    {
      p.x = pos->x - bjr->radius;
      while ((p.x < pos->x + bjr->radius))
        {
          if (p.y < W_HEIGHT && p.x < W_WIDTH)
	    tekpixel(bjr->m_pix, &p, bjr->c.full);
          p.x = p.x + 1;
        }
      p.y = p.y + 1;
    }
}

void                    cray(t_bjr *bjr, t_bunny_position *pos)
{
  t_bunny_position      p;
  t_color               col;

  p = init_bun_pos(pos->x - 1, pos->y - 1);
  col = bjr->c;
  col.argb[3] = 255;
  while ((p.y < pos->y + 1))
    {
      p.x = pos->x - 1;
      while ((p.x < pos->x + 1))
        {
          if (p.y < W_HEIGHT && p.x < W_WIDTH)
            tekpixel(bjr->m_pix, &p, col.full);
          p.x = p.x + 1;
        }
      p.y = p.y + 1;
    }
}

void                    line(t_bjr *bjr, t_bunny_position *pos)
{
  t_bunny_position      p[2];

  p[0] = bjr->line.pos;
  bjr->line.pts = 0;
  p[1] = *pos;
  if (p[0].x >= 0 && p[1].x >= 0)
    {
      tekline(bjr->m_pix, p, bjr->c.full);
    }
}
