/*
** tkp_main.c for tkp_main in /home/gotte_a/rendu/infographie/gfx_tekpaint
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Sun Jan  3 13:48:11 2016 Alexandre Gotte
** Last update Wed Jan 27 02:33:17 2016 Alexandre Gotte
*/

#include "paint.h"

void	hun_exten(int ac, char **av, t_bjr *bjr)
{
  int	t;

  t = test_exten(ac, av);
  if (t == 1)
    bjr->m_pix = load_pix(av[1], bjr);
  else if (t == 2)
    bjr->m_pix = load_bmp(av[1], bjr);
  else
    bjr->m_pix = NULL;
  if (bjr->m_pix != NULL)
    write(1, "file loaded\n", 12);
}

void	put_name(t_bjr *bjr)
{
  int	i;

  i = 0;
  write(1, "name = ", 8);
  while (bjr->name[i] != '\0' && i < 256)
    {
      write(1, &bjr->name[i], 1);
      i++;
    }
  write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
  t_bjr	bjr;

  bjr = init_t_bjr();
  bjr.win = bunny_start(W_WIDTH, W_HEIGHT, false, "operation Da Vinci");
  if (argc > 1)
    hun_exten(argc, argv, &bjr);
  if (bjr.m_pix == NULL)
    {
      bjr.m_pix = bunny_new_pixelarray(W_WIDTH - 500, W_HEIGHT);
      fill_clipable(bjr.m_pix, WHITE);
    }
  if (argc > 1 && test_exten(argc, argv) != 0)
    init_name(argv[1], &bjr);
  put_name(&bjr);
  bjr.ui_pix = load_ui("interface2.7.bmp", &bjr);
  if (bjr.ui_pix == NULL)
    return (-1);
  bunny_set_loop_main_function(loop);
  bunny_loop(bjr.win, 255, &bjr);
  bunny_delete_clipable(&bjr.m_pix->clipable);
  bunny_stop(bjr.win);
  return (0);
}
