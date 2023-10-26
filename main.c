
#include "get_next_line.h"

void	leaks(void) {
	system("leaks -q main");
}

int main(void) {
	/*
	// imprimir nodos individuales
	char *letraA = "Neque porro";
	node *A = crear_nodo(letraA);
	// printf("Contenido nodo: %s\n", A->content);
	char *letraB = " quisquam est";
	node *B = crear_nodo(letraB);
	// printf("Contenido nodo: %s\n", B->content);
	char *letraC = " qui do\n\t\t\t Mas texto";
	node *C = crear_nodo(letraC);
	// printf("Contenido nodo: %s\n", C->content);

	aniadir_nodo(&A, B); // añadimos B después de A
	aniadir_nodo(&A, C); // añadimos C después de B

	node *contador;

	contador = A;
	while (contador) {
		printf("Nodo actual linkeado: \t%s\n\n", contador->content);
		if (contador->next == NULL)
			break;
		contador = contador->next;
	}*/

	static node *lista = NULL;
	int         fd;
	char		*str;

	fd = open("file.txt", O_RDONLY);
	int i = 0;
	while(i < 11) {
		str = get_next_line(fd);
		printf("%s\n", str);
		free(str);
		i++;
	}

	atexit(leaks);
}