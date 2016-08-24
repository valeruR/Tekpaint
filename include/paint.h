/*
** paint.h for paint.h in /home/gotte_a/rendu/infographie/gfx_tekpaint/include
** 
** Made by Alexandre Gotte
** Login   <gotte_a@epitech.net>
** 
** Started on  Sun Jan  3 13:34:18 2016 Alexandre Gotte
** Last update Wed Jan 27 02:17:31 2016 Alexandre Gotte
*/

#ifndef _PAINT_H_
# define _PAINT_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "lapin.h"
#include "fct_uf.h"

#define W_WIDTH 1524
#define W_HEIGHT 768

typedef struct		s_tbut
{
  int			lx;
  int			xl;
  int		        ly;
  int			yl;
}			t_tbut;

typedef struct		s_line
{
  int			pts;
  t_bunny_position	pos;
}			t_line;

typedef struct		s_mcd
{
  int			clil;
    int			cloy;
  t_bunny_position	pav;
}			t_mcd;

typedef struct		s_bmpdata
{
  int			pos_pix;
  int			i_width;
  int			i_height;
}			t_bmpdata;

typedef	struct		s_ctz
{
  t_bunny_pixelarray	**z_pix;
  int			nb;
  int			us;
}			t_ctz;

typedef struct		s_bjr
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*m_pix;
  t_bunny_pixelarray	*fil_pix;
  t_bunny_pixelarray	*ui_pix;
  t_ctz			ctz;
  t_bunny_position	bmp_len;
  t_color		c;
  int			tool;
  int			radius;
  int			filter;
  t_mcd			mcd;
  t_line		line;
  char			name[256];
}			t_bjr;

typedef struct		s_otab
{
  void			(*func)(t_bjr *, t_bunny_position *);
}			t_otab;

typedef struct		s_savei
{
  char			*name;
  int			width;
  int			height;
  unsigned int		*pixs;
}			t_savei;

typedef	struct		s_bmph
{
  unsigned char		type[2];
  unsigned int		size;
  unsigned int		reserved;
  unsigned int		off;
}__attribute__((packed))			t_bmph;

typedef	struct		s_bmpi
{
  unsigned int		size;
  int			width;
  int			height;
  unsigned short	planes;
  unsigned short	bits;
  unsigned int		comp;
  unsigned int		isize;
  int			rx;
  int			ry;
  unsigned int		ncoulour;
  unsigned int		impcol;
}__attribute__((packed))     	t_bmpi;

void		       	tekcircle(t_bunny_pixelarray *pix, t_bunny_position *pos, 
				  double radius, unsigned int color);
void		       	tekcirclep(t_bunny_pixelarray *pix, t_bunny_position *pos, 
				  double radius, unsigned int color);
void			tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos, 
				 unsigned int color);
void		       	fill_clipable(t_bunny_pixelarray *pix, unsigned int color);
void			tekline(t_bunny_pixelarray *pix, t_bunny_position *pos, 
				unsigned int color);
void			cray(t_bjr *bjr, t_bunny_position *pos);
void			cray_r(t_bjr *bjr, t_bunny_position *pos);
void			gere_event_mouse(t_bjr *bjr);
t_bjr			init_t_bjr();
t_bunny_position	init_bun_pos(int x, int y);
void			cray_c(t_bjr *bjr, t_bunny_position *pos);
void			gere_event_key(t_bunny_event_state state, 
				       t_bunny_keysym keysym,
				       t_bjr *bjr);
t_color			get_pixel(t_bunny_pixelarray *pix, t_bunny_position *pos);
void			fast_color(t_bjr *bjr, int m);
void			switch_pen(t_bjr *bjr, int m);
void		       	disp_ui(t_bjr *bjr);
void		       	line(t_bjr *bjr, t_bunny_position *pos);
int			save_img(t_bunny_pixelarray *pix, char *name);
t_bunny_pixelarray	*load_pix(char *path, t_bjr *bjr);
int			test_exten(int ac, char **av);
void			init_name(char *name, t_bjr *bjr);
void		       	fill_shape(t_bjr *bjr, t_bunny_position pos, t_color f, int *i);
void			start_fill_shape(t_bjr *bjr, t_bunny_position *pos);
void			pross_fill(t_bunny_position tmp, t_color f, t_bjr *bjr, int *i);
t_bunny_pixelarray	*load_bmp(char *path, t_bjr  *bjr);
t_tbut			init_t_but(int lx, int xl, int ly, int yl);
void			do_effect(t_bjr *bjr, t_bunny_pixelarray *pix);
t_bunny_pixelarray	*load_ui(char *path, t_bjr  *bjr);
int			save_bmp(t_bunny_pixelarray *pix, char *name, t_bjr *bjr);
int			test_exten2(char *str);
t_bunny_response        loop(void *truc);
void			event_click(t_bjr *bjr, t_bunny_position *p_mouse);
void			gere_event_mouse(t_bjr *bjr);
t_otab			*fill_otab();
int			 test_click(t_tbut but, t_bunny_position *p_mouse);
t_tbut			*fill_but();
void			switch_fil(t_bjr *bjr);
void			hun_save(t_bunny_pixelarray *pix, char *name, t_bjr *bjr);
int			reco_ext(int i, char *path, char *ext);
void			recup_len_file(int fd, t_savei *file);
void			fill_head(int fd, t_bunny_pixelarray *pix, t_bjr *bjr);
void			gere_event_key(t_bunny_event_state state,
                                       t_bunny_keysym keysym,
                                       t_bjr *bjr);
void			hun_ctz(t_bjr *bjr);
void			hun_ctz2(t_bjr *bjr);
void			ui_tool(t_bjr *bjr);
#endif
