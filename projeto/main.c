#include <stdio.h>
#include "parser.h"

void print_header(){
	printf("Content-Type: text/html; charset=utf-8\n\n");
	printf("<header>\n");
	printf("<title> É Para o 10 </title>\n");
	printf("<body> \n");
	printf("<svg height=600 width=800> \n");
}

void print_footer(){
  
  printf("</header>\n");
  printf("</svg> \n");
  printf("</body> \n");
}

int main(){

	print_header();
	parse();
	print_footer();

	return 0;
}