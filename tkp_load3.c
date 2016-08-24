/*
** tkp_load3.c for load3 in /home/d-ange_e/rendu/gfx_tekpaint
** 
** Made by d-angelo enzo
** Login   <d-ange_e@epitech.net>
** 
** Started on  Thu Jan 21 11:47:37 2016 d-angelo enzo
** Last update Fri Jan 22 15:24:33 2016 Alexandre Gotte
*/

#include "paint.h"

int	get_nbrf(const int fd, int len)
{
  int   i;
  char  c;
  int   res;

  i = 0;
  res = 0;
  while (i < len)
    {
      read(fd, &c, 1);
      res = (res * 10) + (c - 0);
      i++;
    }
  return (res);
}

void	get_dim(const int fd, t_bmph *h, t_bmpi *i, t_bjr *bjr)
{
  read(fd, h, 14);
  read(fd, i, 40);
  bjr->bmp_len = init_bun_pos(i->width, i->height);
}

void	rd_i(const int fd, unsigned short bits, t_color *c)
{
  if (bits == 32)
    read(fd, &c->argb[3], 1);
  read(fd, &c->argb[2], 1);
  read(fd, &c->argb[1], 1);
  read(fd, &c->argb[0], 1);
}

t_bunny_pixelarray	*load_bmp(char *path, t_bjr  *bjr)
{
  int			fd;
  t_bunny_position	p;
  t_color		c;
  t_bmph		h;
  t_bmpi		i;

  if ((fd = open(path, O_RDONLY)) == -1)
    return (NULL);
  if ((bjr->m_pix = bunny_new_pixelarray(W_WIDTH - 500, W_HEIGHT)) == NULL)
    return(NULL);
  get_dim(fd, &h, &i, bjr);
  p = init_bun_pos(0, i.height);
  read(fd, c.argb, 3);
  while (p.y >= 0)
    {
      rd_i(fd, i.bits, &c);
      tekpixel(bjr->m_pix, &p, c.full);
      p.x = p.x + 1;
      if (p.x >= i.width)
	{
	  p.x = 0;
	  p.y = p.y - 1;
	}
    }
  return (bjr->m_pix);
}

void	wr_col(const int fd, t_color *tmp)
{
  write(fd, &tmp->argb[3], 1);
  write(fd, &tmp->argb[2], 1);
  write(fd, &tmp->argb[1], 1);
  write(fd, &tmp->argb[0], 1);
}

int			save_bmp(t_bunny_pixelarray *pix, char *name, t_bjr *bjr)
{
  int			fd;
  t_bunny_position	p;
  t_color		tmp;

  p = init_bun_pos(0, bjr->bmp_len.y);
  if ((fd = open(name, O_CREAT| O_WRONLY, 00666)) == -1)
    return (1);
  fill_head(fd, pix, bjr);
  write(fd, "ulll", 3);
  while (p.y >= 0)
    {
      p.x = 0;
      while (p.x < bjr->bmp_len.x)
	{
	  tmp = get_pixel(pix, &p);
	  wr_col(fd, &tmp);
	  p.x = p.x + 1;
	}
      p.y = p.y - 1;
    }
  close(fd);
  write(1, "save done\n", 11);
  return (1);
}

t_bunny_pixelarray      *load_ui(char *path, t_bjr  *bjr)
{
  int                   fd;
  t_bunny_position      p;
  t_color               c;

  if ((fd = open(path, O_RDONLY)) == -1)
    return (NULL);
  bjr->ui_pix = bunny_new_pixelarray(W_HEIGHT, W_HEIGHT);
  p = init_bun_pos(0, W_HEIGHT);
  while (p.y >= 0)
    {
      read(fd, &c.argb[2], 1);
      read(fd, &c.argb[1], 1);
      read(fd, &c.argb[0], 1);
      tekpixel(bjr->ui_pix, &p, c.full);
      p.x = p.x + 1;
      if (p.x >= 500)
        {
          p.x = 0;
          p.y = p.y - 1;
        }
    }
  close(fd);
  return (bjr->ui_pix);
}
