/*
** tkp_event2.c for event2 in /home/d-ange_e/rendu/gfx_tekpaint
** 
** Made by d-angelo enzo
** Login   <d-ange_e@epitech.net>
** 
** Started on  Thu Jan 21 11:40:22 2016 d-angelo enzo
** Last update Fri Jan 22 15:12:46 2016 Alexandre Gotte
*/

#include "paint.h"

void		event_click2(t_bjr *bjr, t_bunny_position *p_mouse, t_tbut *but)
{
  if (test_click(but[5], p_mouse) == 1 || test_click(but[7], p_mouse) == 1)
    bjr->radius = bjr->radius + 1;
  else if (test_click(but[6], p_mouse) == 1 || test_click(but[8], p_mouse) == 1)
    bjr->radius = bjr->radius - 1;
  else if (test_click(but[9], p_mouse) == 1)
    switch_fil(bjr);
  else if (test_click(but[10], p_mouse) == 1)
    hun_save(bjr->fil_pix, bjr->name, bjr);
  else if (test_click(but[11], p_mouse) == 1)
    bjr->c = get_pixel(bjr->ui_pix, p_mouse);
}

void            event_click(t_bjr *bjr, t_bunny_position *p_mouse)
{
  t_tbut        *but;
  int           i;

  if ((but = fill_but()) == NULL)
    return;
  i = 0;
  while (i < 5)
    {
      if (test_click(but[i], p_mouse) == 1)
        {
          bjr->tool = i;
          return;
        }
      i++;
    }
  event_click2(bjr, p_mouse, but);
  bunny_free(but);
}

void                    gere_event_mouse(t_bjr *bjr)
{
  t_otab                *tools;
  t_bunny_position      *p_mouse;

  p_mouse = (t_bunny_position*)bunny_get_mouse_position();
  if (bjr->mcd.cloy == 1)
    event_click(bjr, p_mouse);
  p_mouse->x = p_mouse->x - 500;
  tools = fill_otab();
  if (bjr->tool == 3 && bjr->line.pts != 2)
    return;
  tools[bjr->tool].func (bjr, p_mouse);
  bunny_free(tools);
}
void                    gere_event_key(t_bunny_event_state state,
                                       t_bunny_keysym keysym,
                                       t_bjr *bjr)
{
  if (keysym == BKS_N && state == 1)
    fill_clipable(bjr->m_pix, WHITE);
  else if (keysym == BKS_I && state == 1)
    switch_fil(bjr);
  else if (keysym == BKS_LEFT && state == 1)
    fast_color(bjr, 0);
  else if (keysym == BKS_RIGHT && state == 1)
    fast_color(bjr, 1);
  else if (keysym == BKS_UP && state == 1)
    bjr->radius = bjr->radius + 1;
  else if (keysym == BKS_DOWN && state == 1)
    bjr->radius = bjr->radius - 1;
  else if (keysym == BKS_P && state == 1)
    switch_pen(bjr, 1);
  else if (keysym == BKS_M && state == 1)
    switch_pen(bjr, 0);
  else if (keysym == BKS_Z && state == 1)
    hun_ctz2(bjr);
}
