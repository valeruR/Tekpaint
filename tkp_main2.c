/*
** tkp_main2.c for main2 in /home/d-ange_e/rendu/gfx_tekpaint
** 
** Made by d-angelo enzo
** Login   <d-ange_e@epitech.net>
** 
** Started on  Thu Jan 21 11:51:38 2016 d-angelo enzo
** Last update Wed Jan 27 02:18:06 2016 Alexandre Gotte
*/

#include "paint.h"

t_bunny_response        key(t_bunny_event_state state, t_bunny_keysym keysym,
                            void *data)
{
  t_bjr                 *bjr;

  bjr = data;
  if (state == 1 && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  gere_event_key(state, keysym, bjr);
  return (GO_ON);
}

void	c2(t_bjr *bjr, t_bunny_position *p_mouse)
{
  if (bjr->tool == 3 && bjr->line.pts == 0)
    {
      bjr->line.pos = *p_mouse;
      bjr->line.pos.x -= 500;
      bjr->line.pts = 1;
    }
  else if (bjr->tool == 3 && bjr->line.pts == 1)
    bjr->line.pts = 2;
  bjr->mcd.cloy = 1;
  gere_event_mouse(bjr);
  bjr->mcd.clil = 0;
  bjr->mcd.cloy = 0;
}

t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mousebutton button, void *data)
{
  t_bjr                 *bjr;
  t_bunny_position      *p_mouse;

  p_mouse = (t_bunny_position*)bunny_get_mouse_position();
  bjr = data;
  hun_ctz(bjr);
  if (state == 1 && button == BMB_RIGHT)
    {
      p_mouse->x -= 500;
      bjr->c = get_pixel(bjr->m_pix, p_mouse);
    }
  else if (state == 0 && button == BMB_LEFT)
    {
      gere_event_mouse(bjr);
      bjr->mcd.clil = 1;
    }
  else if (state == 1 && button == BMB_LEFT)
    c2(bjr, p_mouse);
  return (GO_ON);
}

t_bunny_response	move(const t_bunny_position *relative, void *data)
{
  t_bjr                 *bjr;

  bjr = data;
  if (bjr->mcd.clil == 1)
    {
      gere_event_mouse(bjr);
    }
  return (GO_ON);
}

t_bunny_response        loop(void *truc)
{
  t_bjr                 *bjr;
  t_bunny_pixelarray    *fil_pix;
  t_bunny_position      b_pos;

  bjr = truc;
  disp_ui(bjr);
  b_pos = init_bun_pos(500, 0);
  fil_pix = bunny_new_pixelarray(W_WIDTH - 500, W_HEIGHT);
  do_effect(bjr, fil_pix);
  ui_tool(bjr);
  bjr->fil_pix = fil_pix;
  bunny_blit(&bjr->win->buffer, &bjr->ui_pix->clipable, NULL);
  bunny_blit(&bjr->win->buffer, &fil_pix->clipable, &b_pos);
  bunny_display(bjr->win);
  bunny_set_key_response((t_bunny_key)key);
  bunny_set_click_response((t_bunny_click)click);
  bunny_set_move_response((t_bunny_move)move);
  bunny_delete_clipable(&fil_pix->clipable);
  return (GO_ON);
}
