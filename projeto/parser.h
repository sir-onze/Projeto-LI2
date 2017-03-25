#include "estado.h"

#define SIZE 10
#define TAM 50
#define TRUE 1
#define FALSE 0

#define PLAYER "http://127.0.0.1/knight.png"
#define ENEMY "http://127.0.0.1/monster.png"
#define WALL "http://127.0.0.1/lava_pool1.png"
#define GOAL "http://127.0.0.1/tombstone.png"

void parse();
void print_square(int x, int y, int tam);
ESTADO init();
void print_board();
void print_img(int px, int py, int size, char *fig);
void print_move(ESTADO e, int dx, int dy);
void print_player(ESTADO e);
void print_enemies(ESTADO e);
void print_walls(ESTADO e);
int pos_val(ESTADO e, int x, int y);