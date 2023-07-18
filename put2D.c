#include "cub3D.h"

// void    put_map(t_cub cub)
// {
//     int i;
//     int j;

//     i = 0;
//     while (cub.map[i])
//     {
//         j = 0;
//         while (cub.map[i][j])
//         {
//             if (cub.map[i][j] == '0')
//                 mlx_put_image_to_window(cub.mlx, cub.win, cub.w0, j * cub.k, i * cub.m);
//             else
//                 mlx_put_image_to_window(cub.mlx, cub.win, cub.w1, j * cub.k, i * cub.m);
//             j++;
//         }
//         i++;
//     }
// }

// void    put_player(t_cub cub)
// {
//     int i;
//     int j;

//     i = x;
//     while (i < x + 4)
//     {
//         j = y;
//         while (j < y + 4)
//         {
//             mlx_pixel_put(cub.mlx, cub.win, i, j, 16776960);
//             j++;
//         }
//         i++;
//     }
// }