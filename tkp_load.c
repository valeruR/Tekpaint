/*
** tkp_load.c for load img in /home/gotte_a/rendu/infographie/gfx_tekpaint
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Tue Jan 12 12:41:20 2016 Alexandre Gotte
** Last update Fri Jan 22 15:27:39 2016 Alexandre Gotte
*/

#include "paint.h"

void	put_to_file(unsigned int nb, int fd)
{
  if (nb >= 10)
    put_to_file(nb / 10, fd);
  nb = nb % 10;
  nb = nb + 48;
  write(fd, &nb, 1);
}

void			w_pix(int width, int height, t_bunny_pixelarray *pix, int fd)
{
  t_bunny_position	p;
  t_color		c;
  char			car;

  p = init_bun_pos(0, 0);
  car = ':';
  while (p.y < height)
    {
      p.x = 0;
      while (p.x < width)
	{
	  c = get_pixel(pix, &p);
	  put_to_file(c.full, fd);
	  write(fd, &car, 1);
	  p.x++;
	}
      p.y++;
    }
}

void	write_name(char *name, int fd)
{
  int	i;
  char	*new;

  i = 0;
  if((new = bunny_malloc(sizeof(char) * 256)) == NULL)
    return;
  while (i < 256)
    {
      new[i] = 0;
      i++;
    }
  i = 0;
  while (name[i] != '\0')
    {
      new[i] = name[i];
      i++;
    }
  write(fd, new, 256);
  bunny_free(new);
}

int		save_img(t_bunny_pixelarray *pix, char *name)
{
  t_savei	save;
  int		fd;
  char		c;

  c = ':';
  save.width = 1024;
  save.height = 768;
  fd = open(name, O_WRONLY | O_CREAT, 00666);
  if (fd == -1)
    {
      write(2, "can't save the file\n", 20);
      return (1);
    }
  write_name(name, fd);
  write(fd, &c, 1);
  put_to_file(save.width, fd);
  write(fd, &c, 1);
  put_to_file(save.height, fd);
  write(fd, &c, 1);
  w_pix(save.width, save.height, pix, fd);
  c = '|';
  write(fd, &c, 1);
  write(1, "save done\n", 10);
  close(fd);
  return (1);
}

void   	recup_len_file(int fd, t_savei *file)
{
  char 	c;
  int	compt;

  c = 'a';
  compt = 0;
  file->width = 0;
  file->height = 0;
  read(fd, &c, 1);
  while (compt < 2)
    {
      read(fd, &c, 1);
      if (c == ':')
	{
	  read(fd, &c, 1);
	  compt++;
	}
      if (compt == 0)
	file->width = (file->width * 10) + (c - 48);
      else if (compt == 1)
	file->height = (file->height * 10) + (c - 48);
    }
}
