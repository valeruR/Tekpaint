/*
** tkp_load2.c for load2 in /home/d-ange_e/rendu/gfx_tekpaint
** 
** Made by d-angelo enzo
** Login   <d-ange_e@epitech.net>
** 
** Started on  Thu Jan 21 11:46:02 2016 d-angelo enzo
** Last update Fri Jan 22 15:22:20 2016 Alexandre Gotte
*/

#include "paint.h"

void                    fill_pixa(int fd, t_savei *f, t_bunny_pixelarray *pix)
{
  unsigned int          col;
  t_bunny_position      p;
  char                  c;

  p = init_bun_pos(0, 0);
  while (c != '|')
    {
      col = 0;
      c = 'a';
      while (c != ':' && c != '|')
        {
          if(read(fd, &c, 1) == 0)
            return;
          if (c != ':' && c != '|')
            col = (col * 10) + (c - 48);
        }
      p.x++;
      if (p.x >= f->width)
        p = init_bun_pos(0, p.y + 1);
      tekpixel(pix, &p, col);
    }
}

void	add_name(t_bjr *bjr, char *name)
{
  int   i;

  i = 0;
  while (name[i] != '\0')
    {
      bjr->name[i] = name[i];
      i++;
    }
  bjr->name[i] = 0;
}

t_bunny_pixelarray      *load_pix(char *path, t_bjr *bjr)
{
  int                   fd;
  t_savei               file;
  t_bunny_pixelarray    *pix;

  fd = open(path, O_RDONLY);
  if (fd == -1)
    return (NULL);
  if ((file.name = bunny_malloc(sizeof(char) * 256)) == NULL)
    return (NULL);
  read(fd, file.name, 256);
  recup_len_file(fd, &file);
  bjr->m_pix = bunny_new_pixelarray(file.width, file.height);
  pix = bjr->m_pix;
  fill_pixa(fd, &file, pix);
  close(fd);
  add_name(bjr, file.name);
  write(1, "file loaded\n", 12);
  bunny_free(file.name);
  return (pix);
}

unsigned int    my_getnbri(char *nb, int s, int len)
{
  int   i;
  int   nbr;

  i = s;
  nbr = 0;
  if (nb == NULL)
    return (0);
  while (nb[i] != '\0' && i < (s + len))
    {
      nbr = (nbr * 10) + (nb[i] - 48);
      i++;
    }
  return (nbr);
}

unsigned int	get_c(char *nb, int s, int len)
{
  int		i;
  int		nbr;

  i = s;
  nbr = 0;
  if (nb == NULL)
    return (0);
  while (nb[i] != '\0' && i < (s + len))
    {
      nbr = (nbr * 10) + (nb[i]);
      i++;
    }
  return (nbr);
}
