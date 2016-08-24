/*
** tekline.c for tekpaint in /home/valeru_r/rendu/Mod_Infographie/gfx_tekpaint
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Wed Jan 13 15:18:37 2016 Reever Valerus
** Last update Fri Jan 22 14:47:58 2016 Alexandre Gotte
*/

#include "lapin.h"
#include "include/paint.h"

int             pixelcolor(const unsigned int *color,
                           const t_bunny_position *c, t_bunny_position posi)
{
  t_color       color0;
  t_color       color1;
  int           m;
  int           pospix;
  double        nb;

  color0.full = color[0];
  color1.full = color[1];
  m = ((c[1].x - c[0].x) * (c[1].x - c[0].x))
    + ((c[1].y - c[0].y) * (c[1].y - c[0].y));
  pospix = (posi.x - c[0].x) * (posi.x - c[0].x)
    + (posi.y - c[0].y) * (posi.y - c[0].y);
  nb = ((double)pospix / (double)m);
  color0.argb[RED_CMP] = (nb * color1.argb[RED_CMP])
    + ((1 - nb) * color0.argb[RED_CMP]);
  color0.argb[GREEN_CMP] = (nb * color1.argb[GREEN_CMP])
    + ((1 - nb) * color0.argb[GREEN_CMP]);
  color0.argb[BLUE_CMP] = (nb * color1.argb[BLUE_CMP])
    + ((1 - nb) * color0.argb[BLUE_CMP]);
  return (color0.full);
}

int	errdy(int sx, int dy, int *err, t_bunny_position posi)
{
  *err -= dy;
  posi.x += sx;
  return (posi.x);
}

int     errdx(int sy, int dx, int *err, t_bunny_position posi)
{
  *err += dx;
  posi.y += sy;
  return (posi.y);
}

void	init_line(t_bunny_position *d, t_bunny_position *s, const t_bunny_position *co)
{
  if ((d->x = co[1].x - co[0].x) < 0)
    d->x = -(co[1].x - co[0].x);
  if ((s->x = co[0].x) < co[1].x)
    s->x = 1;
  else
    s->x = -1;
  if ((d->y = co[1].y - co[0].y) < 0)
    d->y = -(co[1].y - co[0].y);
  if (co[0].y < co[1].y)
    s->y = 1;
  else
    s->y = -1;
}

void                    tekline(t_bunny_pixelarray *pix,
                                  t_bunny_position *co,
                                  unsigned int color)
{
  t_bunny_position	d;
  t_bunny_position	s;
  int                   err;
  int                   e2;
  t_bunny_position      posi;

  posi.x = co[0].x;
  posi.y = co[0].y;
  init_line(&d, &s, co);
  if (d.x > d.y)
    err = d.x;
  else
    err = (-d.y) / 2;
  while (posi.x <= co[1].x)
    {
      tekpixel(pix, &posi, color);
      if (posi.x == co[1].x && posi.y == co[1].y)
        return ;
      e2 = err;
      if (e2 > -d.x)
        posi.x = errdy(s.x, d.y, &err, posi);
      if (e2 < d.y)
        posi.y = errdx(s.y, d.x, &err, posi);
    }
}
