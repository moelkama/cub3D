#include "cub3D.h"

// int checker1(t_cub cub, int j, int i, double alpha)
// {
//     if (i < 0 || i / cub.m >= arr_size(cub.map))
//         return (0);
//     if (j < 0 || j / cub.m >= ft_strlen(cub.map[i / cub.m]))
//         return (0);
//     if (cos(alpha) > 0)
//     {
//         if (cub.map[i / cub.m][j / cub.m] == '1')
//             return (0);
//     }
//     else
//     {
//         if (cub.map[i / cub.m][(j - cub.m) / cub.m] == '1')
//             return (0);
//     }
//     return (1);
// }

// t_position  get_x(t_cub cub, double alpha)
// {
//     t_position position;
//     int i;
//     int j;

//     i = x;
//     j = y;
//     if (cos(alpha) > 0 && i % cub.m)
//         i += cub.m - i % cub.m;
//     else
//         i -= i % cub.m;
//     j = y - (i - x) * tan(alpha);
//     while (checker1(cub, i, j, alpha))
//     {
//         if (sin(alpha) == 1 || sin(alpha) == -1)
//             break ;
//         if (cos(alpha) > 0)
//         {
//             if (i % cub.m != 0)
//                 i += cub.m - i % cub.m;
//             else
//                 i += cub.m;
//         }
//         else
//         {
//             if (i % cub.m != 0)
//                 i -= i % cub.m;
//             else
//                 i -= cub.m;
//         }
//         j = y - (i - x) * tan(alpha);
//     }
//     position.direct = 0;
//     position.x = i;
//     position.y = j;
//     return (position);
// }

// int checker2(t_cub cub, int j, int i, double alpha)
// {
//     if (i < 0 || i / cub.m >= arr_size(cub.map))
//         return (0);
//     if (j < 0 || j / cub.m >= ft_strlen(cub.map[i / cub.m]))
//         return (0);
//     if (sin(alpha) > 0)
//     {
//         if (cub.map[(i - cub.m) / cub.m][j / cub.m] == '1')
//             return (0);
//     }
//     else
//     {
//         if (cub.map[i / cub.m][j / cub.m] == '1')
//             return (0);
//     }
//     return (1);
// }

// t_position  get_y(t_cub cub, double alpha)
// {
//     t_position position;
//     int i;
//     int j;

//     i = x;
//     j = y;
//     if (sin(alpha) < 0 && j % cub.m != 0)
//         j += cub.m - j % cub.m;
//     else
//         j -= j % cub.m;
//     i = x + (y - j) / tan(alpha);
//     while (checker2(cub, i, j, alpha))
//     {
//         if (sin(alpha) > 0)
//         {
//             if (j % cub.m != 0)
//                 j -= j % cub.m;
//             else
//                 j -= cub.m;
//         }
//         else
//         {
//             if (j % cub.m != 0)
//                 j += cub.m - j % cub.m;
//             else
//                 j += cub.m;
//         }
//         i = x + (y - j) / tan(alpha);
//     }
//     position.direct = 0;
//     position.x = i;
//     position.y = j;
//     return (position);
// }