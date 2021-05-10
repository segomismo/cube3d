#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_key
{
    void    *mlx;
    void    *win;
}               t_key;

int     key_hook(int keycode, t_key *key)
{
    if (keycode == 126)
    {
        mlx_string_put(key->mlx, key->win, 0, 50, 0xfffacd, "Tu madre");
    }
    if (keycode == 53)
    {
        mlx_destroy_window(key->mlx, key->win);
        exit (0);
    }
    return (0);
}
int main(void)
{
    t_key  key;

    key.mlx = mlx_init();
    key.win = mlx_new_window(key.mlx, 500, 500, "hola que tal");
    mlx_key_hook(key.win , key_hook, &key);
    mlx_loop(key.mlx);
}