/*
** tkp_init.c for init in /home/gotte_a/rendu/infographie/gfx_tekpaint
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Sun Jan  3 14:56:19 2016 Alexandre Gotte
** Last update Fri Jan 22 15:19:04 2016 Alexandre Gotte
*/

#include "paint.h"

void 	init_name(char *name, t_bjr *bjr)
{
  int	i;

  i = 0;
  while (name[i] != '\0')
    {
      bjr->name[i] = name[i];
      i++;
    }
  bjr->name[i] = 0;
}

t_bjr		init_t_bjr()
{
  t_bjr		bjr;

  bjr.ctz.nb = 0;
  if((bjr.ctz.z_pix = bunny_malloc(sizeof(t_bunny_pixelarray *) * 3)) != NULL)
    {
      bjr.ctz.z_pix[0] = bunny_new_pixelarray(W_WIDTH - 500, W_HEIGHT);
      bjr.ctz.z_pix[1] = bunny_new_pixelarray(W_WIDTH - 500, W_HEIGHT);
      bjr.ctz.z_pix[2] = bunny_new_pixelarray(W_WIDTH - 500, W_HEIGHT);
    }
  bjr.c.full = BLACK;
  bjr.tool = 0;
  bjr.radius = 10;
  bjr.filter = 0;
  bjr.bmp_len.x = 800;
  bjr.bmp_len.y = 600;
  bjr.mcd.cloy = 0;
  bjr.mcd.clil = 0;
  bjr.line.pts = 0;
  bjr.m_pix = NULL;
  init_name("new_file.tkp", &bjr);
  return (bjr);
}

t_bunny_position	init_bun_pos(int x, int y)
{
  t_bunny_position	p;

  p.x = x;
  p.y = y;
  return (p);
}

int	reco_ext(int i, char *path, char *ext)
{
  int	j;

  j = 0;
  while (path[i] != '\0' && ext[j] != '\0')
    {
      if (ext[j] != path[i])
	return (0);
      i++;
      j++;
    }
  if (ext[j] == '\0' && path[i] == '\0')
    return (1);
  return (0);
}

int	test_exten(int ac, char **av)
{
  int	i;

  i = 0;
  if (ac <= 1)
    return (0);
  while (av[1][i] != '\0')
    {
      i++;
    }
  while(av[1][i] != '.')
    {
      i--;
    }
  if (reco_ext(i, av[1], ".tkp") == 1)
    return (1);
  else if (reco_ext(i, av[1], ".bmp") == 1)
    return (2);
  return (0);
}
