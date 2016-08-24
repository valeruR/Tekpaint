/*
** tkp_pen.c for tkp_pen in /home/gotte_a/rendu/infographie/gfx_tekpaint
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Sun Jan  3 14:12:20 2016 Alexandre Gotte
** Last update Fri Jan 22 15:33:46 2016 Alexandre Gotte
*/

#include "paint.h"

int	test_bord(t_bunny_position *pos)
{
  if (pos->x > W_WIDTH - 500)
    return (0);
  if (pos->x < 0)
    return (0);
  if (pos->y > W_HEIGHT)
    return (0);
  if (pos->y < 0)
    return (0);
  return (1);
}

void	pross_fill(t_bunny_position tmp, t_color f, t_bjr *bjr, int *i)
{
  tekpixel(bjr->m_pix, &tmp, bjr->c.full);
  *i = *i + 1;
  fill_shape(bjr, tmp, f, i);
}

void			fill_shape(t_bjr *bjr, t_bunny_position pos, t_color f, int *i)
{
  t_bunny_position	tmp;
  t_color		c_tmp;

  if (*i > (10000 * 6))
     return;
  tmp = init_bun_pos(pos.x, pos.y - 1);
  c_tmp = get_pixel(bjr->m_pix, &tmp);
  if (c_tmp.full == f.full && c_tmp.full != bjr->c.full && test_bord(&tmp))
    pross_fill(tmp, f, bjr, i);
  tmp = init_bun_pos(pos.x - 1, pos.y);
  c_tmp = get_pixel(bjr->m_pix, &tmp);
  if (c_tmp.full == f.full && c_tmp.full != bjr->c.full && test_bord(&tmp))
    pross_fill(tmp, f, bjr, i);
  tmp = init_bun_pos(pos.x, pos.y + 1);
  c_tmp = get_pixel(bjr->m_pix, &tmp);
  if (c_tmp.full == f.full && c_tmp.full != bjr->c.full && test_bord(&tmp))
    pross_fill(tmp, f, bjr, i);
  tmp = init_bun_pos(pos.x + 1, pos.y);
  c_tmp = get_pixel(bjr->m_pix, &tmp);
  if (c_tmp.full == f.full && c_tmp.full != bjr->c.full && test_bord(&tmp))
    pross_fill(tmp, f, bjr, i);
}

void		start_fill_shape(t_bjr *bjr, t_bunny_position *pos)
{
  t_color	f;
  int		i;

  f = get_pixel(bjr->m_pix, pos);
  fill_shape(bjr, *pos, f, &i);
}
