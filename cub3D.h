#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# ifndef  BUFFER_SIZE
#  define  BUFFER_SIZE 1
# endif

typedef struct s_cub
{
    void    *mlx;
    void    *win;
    void    *w1;
    void    *w0;
    char    **map;
    int     k;
    int     m;
    int     a;
}           t_cub;

typedef struct  s_position
{
    double  x;
    double  y;
    double  r;
    int     direct;
}           t_position;



#include <stdio.h>

t_position  get_y(t_cub cub, double alpha);
t_position  get_x(t_cub cub, double alpha);
char	    **ft_split(char *str, char c);
char	    *readfile(char *file);
int		    ft_strlen(char *str);
int         arr_size(char **arr);

// img
// {
//     img;
//     higt;
//     whit;
// }

// {
//     mlx;
//     win;
//     width;
//     hight;
// }

// {
//     map;
//     hight;
//     width;
// }

#endif