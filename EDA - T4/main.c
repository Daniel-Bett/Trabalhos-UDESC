#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Matriz.h"
#include "arvore_n_aria.h"

void bfs(Matriz m, int raiz);

int main(int argc, char *argv[]) {
	Matriz m;
	int raiz;
	carrega_arquivo( "entrada.txt", &m );
	mostra_matriz(m);
	printf("A partir de qual ponto deseja iniciar a busca? ");
	scanf("%d", &raiz);	
	bfs(m,raiz);
	desaloca_matriz(&m);
	return 0;
}

void bfs(Matriz m, int raiz){
	int vs[m.col];
	Fila fila;
	inicializa_fila(&fila, m.col);
	Arvore arvore;
	inicializa_Arvore(&arvore, raiz);
	raiz--;
	int i;
	for(i=0;i<m.col;i++){
		vs[i]=0;
	}
	

	vs[raiz]=1;
	inserir(&fila,raiz);
	

	
	int x;
	
	while(!fila_vazia(fila)){
		remover(&fila,&x);
			for(i=0;i<m.lin;i++){
				if(m.dados[x][i]==1){
					if(vs[i]==0){
						vs[i]=1;
						inserir(&fila,i);
						insere_filho(arvore, x+1, i+1);
					}
				}
			}
		}

	gera_xml(arvore);
	desaloca_arvore(&arvore);
	desaloca_fila(&fila);
}

