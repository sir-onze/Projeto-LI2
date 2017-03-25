#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estado.h"
#include "parser.h"
#include <time.h>
//ola
ESTADO init(){

	ESTADO e = {{0}};
	e.jog.x = 5;
	e.jog.y = 9;
	e.goal.x = 5;
	e.goal.y = 0;
	int ni=10+(1*2);/*o 1 é o nivel correspondente; mudar para variavel quando implementar mos os niveis*/
	
	/** Posicionar os inimigos no tabuleiro dentro dos parâmetros do mesmo(escrever o método***)*/
	e.num_inimigos = 0;
	int i=0;
	while(i<ni){

		int x=rand() % (SIZE + 0) + 0;
		int y=rand() % (SIZE + 0) + 0;
		
		if(pos_val(e, x, y)){
			e.inimigo[i].x = x;
			e.inimigo[i].y = y;
			e.num_inimigos++;
			i++;
		}
	}
	
	/** Posicionar os obstáculos no tabuleiro dentro dos parâmetros do mesmo(escrever o método***)*/
	e.num_obstaculos = 0;
	i=0;
	while(i<ni){
		
		int x=rand() % (SIZE + 0) + 0;
		int y=rand() % (SIZE + 0) + 0;
		
		if(pos_val(e, x, y)){
			e.obstaculo[i].x = x;
			e.obstaculo[i].y = y;
			e.num_obstaculos++;
			i++;
		}
	}

	return e;
}

void print_image(int x, int y, int tam, char *name){
	
	printf("<image x=%d y=%d width=%d height=%d xlink:href=\"%s\" />\n", tam*x, tam*y, tam, tam, name);
}

void print_square(int x, int y, int tam){
	
	char *color[] = {"#444400", "#777700"};
	int idx=(x+y)%2;
	printf("<rect x=%d y=%d width=%d height=%d fill=%s />\n", tam*x, tam*y, tam, tam, color[idx]);
}

void print_board(){
	
	int x, y;
	for(y=0;y<SIZE;y++)
		for(x=0;x<SIZE;x++)
			print_square(x, y, TAM);
}


/*int val=0;
	if(i==-1)
		if(x>=0 && y>=0 && x<=SIZE-1 && y<=SIZE-1 && e.obstaculo[x].x)
			val=1;
	else
		if(x>=0 && y>=0 && x<=SIZE-1 && y<=SIZE-1 && e.obstaculo[x].x)
			if(e.inimigo[i].x==0 && e.inimigo[i].y==0 && e.obstaculo[i].x==0 && e.obstaculo[i].y==0 && e.goal.x == 0)
				val=1;
	return val;*/
int pos_val(ESTADO e, int x, int y){

	int i=0;

	if(x<0 || y<0 || x>=SIZE || y>=SIZE){
		for(i=0; i<e.num_inimigos; i++){
			if(e.inimigo[i].x==x || e.inimigo[i].y==y)
				return 0;
		}

		for (int j=0; j<e.num_obstaculos ; j++){
			if(e.obstaculo[j].x==x || e.obstaculo[j].y==y || e.goal.x ==x)
				return 0;
		}
	}

	return 1;
}

void print_move(ESTADO e, int dx, int dy){

	int x = e.jog.x + dx;
	int y = e.jog.y + dy;

	ESTADO ne = e;
	
	if(pos_val(e, x, y)){
		
		ne.jog.x = x;
		ne.jog.y = y;
		ne.inimigo[0].x = e.jog.x;
		ne.inimigo[0].y = e.jog.y;

		printf("<a xlink:href=\"http://127.0.0.1/cgi-bin/projeto?%s\">\n", estado2str(ne));
		print_square(x, y, TAM);
		printf("</a>\n");
	}
}

void print_player(ESTADO e){

	print_image(e.jog.x, e.jog.y, TAM, PLAYER);
	print_move(e, -1,  0);
	print_move(e, +1,  0);
	print_move(e,  0, -1);
	print_move(e,  0, +1);
	print_move(e, -1,  -1);
	print_move(e, +1,  +1);
	print_move(e,  +1, -1);
	print_move(e,  -1, +1);
}

void print_enemies(ESTADO e){

	for(int i=0; i<e.num_inimigos; i++)
		print_image(e.inimigo[i].x, e.inimigo[i].y, TAM, ENEMY);
}

void print_walls(ESTADO e){

	for(int i=0; i<e.num_obstaculos; i++)
		print_image(e.obstaculo[i].x, e.obstaculo[i].y, TAM, WALL);
}

void print_goal(ESTADO e){

	print_image(e.goal.x, e.goal.y, TAM, GOAL);
}

void parse(){

	srand(time(NULL));

	ESTADO e;
	char *args = getenv("QUERY_STRING");

	if(strlen(args) == 0)
		e = init(0);
	else
		e = str2estado(args);
	if(e.new_level==1)
		e=init();

	print_board();
	print_player(e);
	print_enemies(e);
	print_walls(e);
	print_goal(e);
}
