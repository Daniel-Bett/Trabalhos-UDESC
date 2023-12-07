 #include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include "PilhaGenerica.h"

void mostra_int( void *x );
void troca(int x, int y, int cor, int corOriginal, Matriz* m, PilhaGenerica* cx, PilhaGenerica* cy);
int olhaCor(int x, int y, Matriz* m);
void olhaVizinho(int x, int y, int cor, int corOriginal, Matriz* m, PilhaGenerica* cx, PilhaGenerica* cy);

int main(int argc, char *argv[]) {
    Matriz m;
    PilhaGenerica cx, cy;
    int x, y, cor, corOriginal;

    // Carregar matriz a partir do arquivo (substitua com sua implementação)
    carrega_arquivo("entrada.txt", &m);

    // Inicializar pilhas
    inicializa_pilha(&cx, m.col * m.lin, sizeof(int));
    inicializa_pilha(&cy, m.col * m.lin, sizeof(int));

    mostra_matriz(m);
	printf("Digite a coordenada da linha: ");
    scanf("%d", &x);
    printf("Digite a coordenada da coluna: ");
    scanf("%d", &y);
    printf("Digite a cor para substituir: ");
    scanf("%d", &cor);
	
	if(x<m.lin && y<m.col && x>-1 &&y>-1){	    
		corOriginal = olhaCor(x, y, &m);
	
		if(cor!= corOriginal){
			do{	
			desempilha(&cx,&x);
			desempilha(&cy,&y);
			troca(x, y, cor, corOriginal, &m, &cx, &cy);
			mostra_matriz(m);
			}while(!pilha_vazia(cx));
		}
	}
	
	mostra_matriz(m);
	
	//salva arquivo
	salva_arquivo("resultado.txt", &m);
	printf("Arquivo salvo em resultado.txt");
	
	// Desalocar memória
    desaloca_matriz(&m);
    desaloca_pilha(&cx);
    desaloca_pilha(&cy);
    
    return 0;
}

int olhaCor(int x, int y, Matriz* m) {
    return m->dados[x][y];
}

void troca(int x, int y, int cor, int corOriginal, Matriz* m, PilhaGenerica* cx, PilhaGenerica* cy) {
    m->dados[x][y] = cor;
    olhaVizinho(x,y,cor,corOriginal, m, cx,cy);
}

void mostra_int( void *x ){
	int *a = x;
	printf("%d\n", *a);
}

void olhaVizinho(int x, int y, int cor, int corOriginal, Matriz* m, PilhaGenerica* cx, PilhaGenerica* cy){
	x++;
	if(x<m->lin && y<m->col && x>-1 && y>-1){
		if(m->dados[x][y]==corOriginal){
			empilha(cx, &x);
			empilha(cy,&y);
		} 
	}
	x-=2;
	if(x<m->lin && y<m->col && x>-1 && y>-1){	
		if(m->dados[x][y]==corOriginal){
			empilha(cx, &x);
			empilha(cy,&y);
		} 
	}
	x++;
	y++;
	if(x<m->lin && y<m->col && x>-1 && y>-1){
		if(m->dados[x][y]==corOriginal){
			empilha(cx, &x);
			empilha(cy,&y);
		} 
	}
	y-=2;
	if(x<m->lin && y<m->col && x>-1 && y>-1){
		if(m->dados[x][y]==corOriginal){
			empilha(cx, &x);
			empilha(cy,&y);
		} 
	}
	
}


