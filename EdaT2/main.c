#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Pilha.h"

typedef struct{
	int **dados;
	int n;
} Matriz;

void inicializa_matriz(Matriz *p, int n);
int abre_arquivo(Matriz *m, char* nome_arquivo, int* vInicial, int* vFinal);
void bfs(Matriz m, int vInicial, int vFinal);

int main(int argc, char *argv[]) {
	Matriz m;
	int vInicial, vFinal;

	abre_arquivo(&m,"entrada.txt",&vInicial,&vFinal); // Todas as entradas são feitas pelo arquivo
	bfs(m,vInicial-1,vFinal-1);
	
	return 0;
}

void inicializa_matriz( Matriz *p, int n ){
	p->n = n;
	p->dados = malloc( sizeof(int*) * n );
	int i,j;
	for( i = 0 ; i < n ; i++ ){
		p->dados[i] = malloc( sizeof(int) * n );
		for( j = 0 ; j < n ; j++ )
			p->dados[i][j] = 0;
	}
}


int abre_arquivo(Matriz *p, char* nome_arquivo, int* vInicial, int* vFinal){
	FILE *f=fopen(nome_arquivo, "rt");
	if(f==NULL)
		return 0;
		
	int n;
	fscanf(f, "%d" , &n); // salva o tamanho da matriz
	inicializa_matriz(p,n);
	int i,j;
	for( i = 0 ; i < p->n ; i++ )
		for( j = 0 ; j < p->n ; j++ )
			fscanf( f, "%d", &p->dados[i][j]); //anexa os valores a posição da matriz
	
			
	fscanf(f,"%d %d",vInicial,vFinal); //anexa os valores de inicio e de fim
	return 1;
}
void bfs(Matriz m, int vInicial, int vFinal){
	
	int *vs=malloc(sizeof(int)*m.n);
	int *va=malloc(sizeof(int)*m.n);

	int i;
	for(i=0;i<m.n;i++){
		vs[i]=0;
		va[i]=0;

	}
	
	Fila f;
	inicializa_fila(&f,m.n);
	
	vs[vInicial]=1;	
	
	inserir(&f,vInicial);
	
	int achou = 0;
	int x;
	while(!fila_vazia(f) & !achou){
		remover(&f,&x);
		if(x==vFinal){
			achou=1;
		}else{
			for(i=0;i<m.n;i++){
				if(m.dados[x][i]==1){
					if(vs[i]==0){
						vs[i]=1;
						va[i]=x;
						inserir(&f,i);
					}
				}
			}
		}
	}
	
	if(achou){
		Pilha p;
		inicializa_pilha(&p, m.n);
		while(x != 0){
			empilha(&p, x);
			x= va[x];
			
		}
		
			
		while(!pilha_vazia(p)){
			desempilha(&p,&x);
			printf("%d\n",x+1);
		}
		printf("\n");
		
	}else{
		printf("B nao eh alcancavel atraves de A");
	}

}

