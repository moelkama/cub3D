#include "cub3D.h"

double teta = M_PI * 0;
double teta_vetise = M_PI / 24;
double x = 240;
double y = 200;
double  vites = 10;
int     w_hight = 600;
int     w_length =860;
double     zooom = 30;
void        *img;
void        *img2;
char        *buffer2;
int     pixel_bits2;
int     line_bytes2;
int     endian2;

void    put_map(t_cub cub)
{
    int i;
    int j;

    i = 0;
    while (cub.map[i])
    {
        j = 0;
        while (cub.map[i][j])
        {
            if (cub.map[i][j] == '0')
                mlx_put_image_to_window(cub.mlx, cub.win, cub.w0, j * cub.k, i * cub.m);
            else
                mlx_put_image_to_window(cub.mlx, cub.win, cub.w1, j * cub.k, i * cub.m);
            j++;
        }
        i++;
    }
}

int arr_size(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    return (i);
}

int checker(t_cub cub, int a, int b, int k)
{
    if (b / cub.m < 0 || b / cub.m >= arr_size(cub.map))
        return (0);
    if (a / cub.m < 0 || a / cub.m >= ft_strlen(cub.map[b / cub.m]))
        return (0);
    if (k == 0 && cub.map[b / cub.m][a / cub.m] == '1')
        return (0);
    else if (k == 1 && cub.map[b / cub.m][(a - cub.m) / cub.m] == '1')
        return (0);
    else if (k == 2 && cub.map[(b -cub.m) / cub.m][a / cub.m] == '1')
        return (0);
    return (1);
}

void    put_pixel(t_cub cub, int size, t_position position, char *buffer, int line_bytes, int pixel_bits)
{
    double R;
    double h;
    int a;
    int i;
    char    *dst;
    char    *rst;

    R = sqrt(pow(position.x - x, 2) + pow(position.y - y, 2));
    h = w_hight;
    a = h * zooom / R;
    i = 0;
    int k,m;
    while (i < (w_hight - a) / 2)
    {
        dst = buffer + (i * line_bytes + size * (pixel_bits / 8));
        //rst = buffer2 + (i * line_bytes2 + size * (pixel_bits2 / 8));
        *((unsigned int *)dst) = 13428223;//*((unsigned int *)rst);//
        i++;
    }
    k = 0;
    m = size;
    while (a > 0)
    {
        dst = buffer + (i * line_bytes + size * (pixel_bits / 8));
        rst = buffer2 + (k++ * line_bytes2 + m * (pixel_bits2 / 8));
        if (position.direct == 0)
            *((unsigned int *)dst) = 16776960;//*((unsigned int *)rst);
        else if (position.direct == 1)
            *((unsigned int *)dst) = 255;
        else if (position.direct == 2)
            *((unsigned int *)dst) = 13862815;
        else
            *((unsigned int *)dst) = 16711680;
        i++;
        a--;
    }
    while (i < w_hight)
    {
        dst = buffer + (i++ * line_bytes + size * (pixel_bits / 8));
        *((unsigned int *)dst) = 16777215;
    }
}


void    put_vector(t_cub cub)
{
    t_position position;
    double alpha;
    double z;
    int    size;
    t_position  p1;
    t_position  p2;

    alpha = teta - M_PI / 6;
    z = teta + M_PI / 6;
    size = w_length - 1;
    double next;
    next = (z - alpha) / size;

    int pixel_bits;
    int line_bytes;
    int endian;
    char *buffer;
    buffer = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
    while (alpha < z)
    {
        p1 = get_x(cub, alpha);
        p2 = get_y(cub, alpha);
    
        p1.r = sqrt(pow(p1.x - x, 2) + pow(p1.y - y, 2));
        p2.r = sqrt(pow(p2.x - x, 2) + pow(p2.y - y, 2));
        if (sin(alpha) == 1)
        {
            position = p2;
            position.direct = 1;
        }
        else if (sin(alpha) == -1)
        {
            position = p2;
            position.direct = 3;
        }
        else if (cos(alpha) == 1)
        {
            position = p1;
            position.direct = 0;
        }
        else if (cos(alpha) == -1)
        {
            position = p1;
            position.direct = 2;
        }
        else if (p1.r < p2.r)
        {
            position = p1;
            if (cos(alpha) > 0)
                position.direct = 0;
            else
                position.direct = 2;
        }
        else
        {
            position = p2;
            if (sin(alpha) > 0)
                position.direct = 1;
            else
                position.direct = 3;
        }
        // double i = x, j = y;
        // while (checker(cub, i, j, 0))
        // {
        //     if (position.direct == 0)
        //     mlx_pixel_put(cub.mlx, cub.win, i ,j, 16776960);
        //     else if (position.direct == 1)
        //         mlx_pixel_put(cub.mlx, cub.win, i ,j , 255);
        //     else if (position.direct == 2)
        //         mlx_pixel_put(cub.mlx, cub.win, i ,j , 13862815);
        //     else
        //         mlx_pixel_put(cub.mlx, cub.win, i ,j , 16711680);
        //     i += cos(alpha);
        //     j -= sin(alpha);
        // }
        put_pixel(cub, size, position, buffer, line_bytes, pixel_bits);
        size --;
        alpha += next;
    }
    mlx_put_image_to_window(cub.mlx, cub.win, img, 0, 0);
}

int move(int key, t_cub *cub)
{
    if ((key == 1 || key == 125))
    {
        x -= cos(teta) * vites;
        y += sin(teta) * vites;
        // put_vector(*cub);
    }
    else if ((key == 13 || key == 126))
    {
        x += cos(teta) * vites;
        y -= sin(teta) * vites;
        // put_vector(*cub);
    }
    else if (key == 123)
    {
        teta += teta_vetise;
        if (teta > 2 * M_PI)
            teta -= 2 * M_PI;
        else if (teta < -2 * M_PI)
            teta += 2 * M_PI;
        // put_vector(*cub);
    }
    else if (key == 124)
    {
        teta -= teta_vetise;
        if (teta > 2 * M_PI)
            teta -= 2 * M_PI;
        else if (teta < -2 * M_PI)
            teta += 2 * M_PI;
    }
    // put_map(*cub);
    put_vector(*cub);
    return (0);
}

int main(int c, char **v)
{
    t_cub   cub;
    char    *file;
    int     fd;

    file = readfile(v[1]);
    cub.map = ft_split(file, '\n');
    cub.mlx = mlx_init();
    cub.w1 = mlx_xpm_file_to_image(cub.mlx, "./textures/1.xpm", &cub.k, &cub.m);
    cub.w0 = mlx_xpm_file_to_image(cub.mlx, "./textures/0.xpm", &cub.k, &cub.m);
    cub.win = mlx_new_window(cub.mlx, w_length, w_hight, "cub3D");
    img = mlx_new_image(cub.mlx, 1000, 1000);
    int l;
    img2 = mlx_xpm_file_to_image(cub.mlx, "./textures/wall.xpm", &l, &l);
    buffer2 = mlx_get_data_addr(img2, &pixel_bits2, &line_bytes2, &endian2);
    // put_map(cub);
    // put_player(cub);
    put_vector(cub);
    mlx_hook(cub.win, 2, 0, move, &cub);
    mlx_loop(cub.mlx);
}





























int checker1(t_cub cub, int j, int i, double alpha)
{
    if (i < 0 || i / cub.m >= arr_size(cub.map))
        return (0);
    if (j < 0 || j / cub.m >= ft_strlen(cub.map[i / cub.m]))
        return (0);
    if (cos(alpha) > 0)
    {
        if (cub.map[i / cub.m][j / cub.m] == '1')
            return (0);
    }
    else
    {
        if (cub.map[i / cub.m][(j - cub.m) / cub.m] == '1')
            return (0);
    }
    return (1);
}

t_position  get_x(t_cub cub, double alpha)
{
    t_position position;
    int i;
    int j;

    i = x;
    j = y;
    if (cos(alpha) > 0 && i % cub.m)
        i += cub.m - i % cub.m;
    else
        i -= i % cub.m;
    j = y - (i - x) * tan(alpha);
    while (checker1(cub, i, j, alpha))
    {
        if (sin(alpha) == 1 || sin(alpha) == -1)
            break ;
        if (cos(alpha) > 0)
        {
            if (i % cub.m != 0)
                i += cub.m - i % cub.m;
            else
                i += cub.m;
        }
        else
        {
            if (i % cub.m != 0)
                i -= i % cub.m;
            else
                i -= cub.m;
        }
        j = y - (i - x) * tan(alpha);
    }
    position.direct = 0;
    position.x = i;
    position.y = j;
    return (position);
}

int checker2(t_cub cub, int j, int i, double alpha)
{
    if (i < 0 || i / cub.m >= arr_size(cub.map))
        return (0);
    if (j < 0 || j / cub.m >= ft_strlen(cub.map[i / cub.m]))
        return (0);
    if (sin(alpha) > 0)
    {
        if (cub.map[(i - cub.m) / cub.m][j / cub.m] == '1')
            return (0);
    }
    else
    {
        if (cub.map[i / cub.m][j / cub.m] == '1')
            return (0);
    }
    return (1);
}

t_position  get_y(t_cub cub, double alpha)
{
    t_position position;
    int i;
    int j;

    i = x;
    j = y;
    if (sin(alpha) < 0 && j % cub.m != 0)
        j += cub.m - j % cub.m;
    else
        j -= j % cub.m;
    i = x + (y - j) / tan(alpha);
    while (checker2(cub, i, j, alpha))
    {
        if (sin(alpha) > 0)
        {
            if (j % cub.m != 0)
                j -= j % cub.m;
            else
                j -= cub.m;
        }
        else
        {
            if (j % cub.m != 0)
                j += cub.m - j % cub.m;
            else
                j += cub.m;
        }
        i = x + (y - j) / tan(alpha);
    }
    position.direct = 0;
    position.x = i;
    position.y = j;
    return (position);
}