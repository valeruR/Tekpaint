/*
** tkp_event.c for event in /home/gotte_a/rendu/infographie/gfx_tekpaint
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Sun Jan  3 14:27:21 2016 Alexandre Gotte
** Last update Wed Jan 27 02:34:46 2016 Alexandre Gotte
*/

#include "paint.h"

t_otab		*fill_otab()
{
  t_otab	*tools;

  tools = bunny_malloc(sizeof(t_otab) * 4);
  tools[0].func = cray;
  tools[1].func = cray_r;
  tools[2].func = cray_c;
  tools[3].func = line;
  tools[4].func = start_fill_shape;
  return (tools);
}

int	test_click(t_tbut but, t_bunny_position *p_mouse)
{
  if (p_mouse->x - 20 >= but.lx && p_mouse->x - 20 <= but.xl)
    {
      if (p_mouse->y >= but.ly && p_mouse->y <= but.yl)
	return (1);
    }
  return (0);
}

t_tbut		*fill_but()
{
  t_tbut	*but;

  if ((but = bunny_malloc(sizeof(t_tbut) * 12)) == NULL)
    return (NULL);
  but[0] = init_t_but(51, 117, 51, 147);
  but[1] = init_t_but(51, 117, 150, 243);
  but[2] = init_t_but(51, 117, 247, 340);
  but[3] = init_t_but(51, 117, 344, 437);
  but[4] = init_t_but(51, 117, 532, 626);
  but[5] = init_t_but(124, 147, 155, 189);
  but[6] = init_t_but(124, 147, 201, 235);
  but[7] = init_t_but(124, 147, 253, 287);
  but[8] = init_t_but(124, 147, 299, 333);
  but[9] = init_t_but(51, 117, 441, 529);
  but[10] = init_t_but(51, 117, 630, 709);
  but[11] = init_t_but(183, 468, 29, 307 + 18);
  return (but);
}

void	switch_fil(t_bjr *bjr)
{
  bjr->filter = bjr->filter + 1;
  if (bjr->filter == 4)
    bjr->filter = 0;
}

void	hun_save(t_bunny_pixelarray *pix, char *name, t_bjr *bjr)
{
  int	t;

  t = 0;
  while (t == 0)
    {
      if (test_exten2(name) == 1)
	t = save_img(pix, name);
      else if (test_exten2(name) == 2)
	t = save_bmp(pix, name, bjr);
    }
}
