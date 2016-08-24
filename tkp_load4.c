/*
** tkp_load4.c for load4 in /home/d-ange_e/rendu/gfx_tekpaint
** 
** Made by d-angelo enzo
** Login   <d-ange_e@epitech.net>
** 
** Started on  Thu Jan 21 11:50:18 2016 d-angelo enzo
** Last update Fri Jan 22 15:25:00 2016 Alexandre Gotte
*/

#include "paint.h"

void		fill_head(int fd, t_bunny_pixelarray *pix, t_bjr *bjr)
{
  t_bmph       	h;
  t_bmpi       	i;

  h.type[0] = 'B';
  h.type[1] = 'M';
  h.size = 54 + ((bjr->bmp_len.x * 4) * (bjr->bmp_len.y * 4));
  h.off = 54;
  i.size = 40;
  i.width = bjr->bmp_len.x;
  i.height = bjr->bmp_len.y;
  i.planes = 1;
  i.bits = 32;
  i.comp = 0;
  i.isize = ((bjr->bmp_len.x * 4) * (bjr->bmp_len.y * 4));
  i.rx = 2835;
  i.ry = 2835;
  i.ncoulour = 0;
  i.impcol = 0;
  write(fd, &h, 14);
  write(fd, &i, 40);
}
