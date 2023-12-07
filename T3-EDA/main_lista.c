#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Pilha.h"
// Feito por Daniel Bett e Arthur Lucena
typedef struct{
	int hora;
	int min;
}Hora;

typedef struct{
	int dia;
	int mes;
	int ano;
}Data;

typedef struct{
	Data data;
	Hora inicio;
	Hora fim;
	char descricao[50];
	char local[50];
}Evento;

int comparaDescricao(void *infoLista, char descricao[]);
int comparaHora(void *infoLista, void *info);
int comparaData(void *infoLista, void *info);
int verificaConflito(Evento *a, Evento *b);

int cadastrar(Lista *p, int (*comparaData)(void*,void*),int (*comparaHora)(void*,void*), int (*verificaConflito)(Evento*,Evento*));
int cadastrarArq (Lista *p,Evento *e, int (*comparaData)(void*,void*),int (*comparaHora)(void*,void*), int (*verificaConflito)(Evento*,Evento*));

void lerArquivo(const char *nomeArquivo, Lista *p, int (*comparaData)(void*, void*), int (*comparaHora)(void*, void*), int (*verificaConflito)(Evento*, Evento*));
void salvarArquivo(const char *nomeArquivo, Lista *p);

void mostra_evento(void *x);
void mostra_evento_data(Data data, Lista l, void (*mostra)(void*),int (*comparaData)(void*,void*));
void mostra_evento_descricao(Lista l, void (*mostra)(void*), int (*compara)(void*, char*), char descricao[]);

int removerData(Lista *p, Data data,int (*comparaData)(void*,void*));
int removerDataHora(Lista *p, Data data, Hora hora,int (*comparaData)(void*,void*), int (*comparaHora)(void*, void*));



int main(int argc, char *argv[]) {
	Lista l;
	char arq[50];
	int abrirArq,escolha,i;
	Data d;
	Hora h;


	inicializa_lista(&l, sizeof(Evento));
	
	printf("Deseja abrir de um arquivo? 1-Sim 0-Nao");
	scanf("%d", &abrirArq);
	if(abrirArq){
		printf("Digite o nome do Arquivo a ser aberto(Nao esqueca do .txt): ");
		scanf("%s", arq);
	    lerArquivo(arq, &l, comparaData, comparaHora, verificaConflito);
	}
	
	do{
		printf("Digite o numero para a acao: 1-Cadastrar 2-Mostrar Todos os Evento 3-Mostrar Eventos de uma Data 4-Mostrar Eventos pela Descricao 5-Remover Evento 6-Sair\n");
		scanf("%d",&escolha);
		
		switch(escolha){
			case 1:
				cadastrar(&l,comparaData,comparaHora, verificaConflito);
				break;
			case 2:
				if(lista_vazia(l)){
					printf("Lista Vazia\n");
				}else{
						mostra_lista(l,mostra_evento);
				}
				break;
			case 3:
				if(lista_vazia(l)){
					printf("Lista Vazia\n");
					
				}else{
					printf("Digite em ordem Dia Mes e Ano\n");
					scanf("%d %d %d", &d.dia,&d.mes,&d.ano);
					if(d.dia<0 ||d.dia>31||d.mes<0||d.mes>12||d.ano<0){
						printf("Dia inexistente");
						break;
					}
						mostra_evento_data(d,l,mostra_evento,comparaData);
					break;
				}
			case 4:
				if (lista_vazia(l)) {
	      		  printf("Lista Vazia\n");
	  			  }else {
				        char descricao_pesquisa[50];
				        printf("Digite a descricao para pesquisa: ");
				        getchar();
				        fgets(descricao_pesquisa, sizeof(descricao_pesquisa), stdin);
				        descricao_pesquisa[strcspn(descricao_pesquisa, "\n")] = '\0'; 
				        mostra_evento_descricao(l, mostra_evento, comparaDescricao, descricao_pesquisa);
				    }
				break;
			case 5:
				if(lista_vazia(l)){
					printf("Lista vazia!");
					break;
				}
				printf("Escolha como deseja remover: 1- Remover todos os eventos da data 2- Remover Evento por data e hora");
				scanf("%d",&i);
				if(i==1){
					Data d;
					printf("Digite em ordem Dia Mes e Ano");
					scanf("%d %d %d", &d.dia,&d.mes,&d.ano);
					if(d.dia<0 ||d.dia>31||d.mes<0||d.mes>12||d.ano<0){
						printf("Dia inexistente");
						break;
					}
					removerData(&l,d,comparaData);
					break;
				}else{
					if(i==2){
					printf("Digite em ordem Dia Mes e Ano");
					scanf("%d %d %d", &d.dia,&d.mes,&d.ano);
					if(d.dia<0 ||d.dia>31||d.mes<0||d.mes>12||d.ano<0){
						printf("Dia inexistente");
						break;
					}
						printf("Digite em ordem Hora e Min");
						scanf("%d %d",&h.hora,&h.min);
						if(h.hora<0||h.hora>23||h.min<0||h.min>59){
							printf("Hora inexistente");
							break;
						}
						removerDataHora(&l,d,h,comparaData,comparaHora);
						break;
					}
				}
				case 6:
					printf("Digite o nome da maneira que deseja salvar o arquivo(Nao esqueca do .txt) ");
					scanf("%s", arq);
					salvarArquivo(arq,&l);
					limpa_lista(&l);
					break;
			}

		}while(escolha !=6);
	
	
	return 0;
}

int cadastrar(Lista *p, int (*comparaData)(void*,void*), int (*comparaHora)(void*,void*), int (*verificaConflito)(Evento*,Evento*)){
    Evento *e = malloc(sizeof(Evento)); 

    if (e == NULL) {
    return 0;
	}

    printf("Digite o Dia, mes e ano do evento: ");
    scanf("%d %d %d", &e->data.dia, &e->data.mes, &e->data.ano);
    if(e->data.dia<=0||e->data.mes<=0||e->data.mes>12||e->data.dia>31||e->data.ano<0){
    	printf("Erro de entrada");
    	return 0;
	}
    getchar();

    printf("Digite a hora e os minutos do inicio do evento: ");
    scanf("%d %d", &e->inicio.hora, &e->inicio.min);
    if(e->inicio.hora<0||e->inicio.hora>=24||e->inicio.min>59||e->inicio.min<0){
    	printf("Erro de entrada");
    	return 0;
	}

    printf("Digite a hora e os minutos do fim do evento: ");
    scanf("%d %d", &e->fim.hora, &e->fim.min);
    if(e->fim.hora<0||e->fim.hora>=24||e->fim.min>59||e->fim.min<0|| e->inicio.hora>e->fim.hora|| e->fim.hora==e->inicio.hora &&e->fim.min<e->inicio.min){
    	printf("Erro de entrada");
    	return 0;
	}

    printf("Digite a descricao do evento: ");
    getchar();
    fgets(e->descricao, sizeof(e->descricao), stdin);
    e->descricao[strcspn(e->descricao, "\n")] = '\0';

    printf("Digite o local do evento: ");
    fgets(e->local, sizeof(e->local), stdin);
    e->local[strcspn(e->local, "\n")] = '\0';

    Elemento *aux = p->cabeca;
	int cont=0;
    while (aux != NULL) {
        if (comparaData(aux->info, e) == 0) {
            if ((comparaData(aux->info, e) == 0 && verificaConflito(aux->info, e))){
                printf("Conflito de horario! O evento nao pode ser adicionado.\n");
                free(e);
                return 0;
            }
    }

        if (comparaData(aux->info, e) < 0 || (comparaData(aux->info, e) == 0 && comparaHora(aux->info, e) < 0)) {
            cont++;
        }
        
		aux = aux->proximo;

    }

    return insere_pos(p, e,cont); 
}


int comparaData(void *infoLista, void *info){
    Evento *a = (Evento*)infoLista, *b = (Evento*)info;
    
    if (a->data.ano < b->data.ano)
        return -1;
    else if (a->data.ano > b->data.ano)
        return 1;

    if (a->data.mes < b->data.mes)
        return -1;
    else if (a->data.mes > b->data.mes)
        return 1;

    if (a->data.dia < b->data.dia)
        return -1;
    else if (a->data.dia > b->data.dia)
        return 1;

    return 0;
}

int comparaHora(void *infoLista, void *info) {
    Evento *a = (Evento*)infoLista;
    Evento *b = (Evento*)info;

    if (a->inicio.hora != b->inicio.hora) {
        return a->inicio.hora - b->inicio.hora;
    }

    return a->inicio.min - b->inicio.min;
}

int verificaConflito(Evento *a, Evento *b) {
    if ((a->inicio.hora < b->fim.hora && a->fim.hora > b->inicio.hora) ||
        (a->inicio.hora == b->inicio.hora && a->inicio.min < b->fim.min) ||
        (a->fim.hora == b->fim.hora && a->fim.min > b->inicio.min)||
		(a->inicio.hora >=b->fim.hora && a->inicio.min<b->fim.min)) {
        return 1; 
    }
    return 0;
}

void mostra_evento_data(Data data, Lista l, void (*mostra)(void*),int (*comparaData)(void*,void*)){
	Evento *e=malloc(sizeof(Evento));
	e->data.ano=data.ano;
	e->data.dia=data.dia;
	e->data.mes=data.mes;
	
	Elemento *aux=l.cabeca;
	
	while(aux!=NULL){
		if(comparaData(aux->info,e)==0)
			mostra(aux->info);
		aux=aux->proximo;
	}
	free(e);
}

int comparaDescricao(void *infoLista, char descricao[]){
	Evento *a = (Evento*)infoLista;
    
    
    if(strcmp(a->descricao,descricao)==0)
    	return 1;

	return 0;    
}
void mostra_evento_descricao(Lista l, void (*mostra)(void*), int (*compara)(void*, char*), char descricao[]){

	
	Elemento *aux=l.cabeca;
	while(aux!=NULL){
	if(compara(aux->info, descricao))
		mostra(aux->info);
	aux=aux->proximo;	
	}

}

int removerData(Lista *p, Data data,int (*comparaData)(void*,void*)){
	if(lista_vazia(*p))
		return 0;
	int cont=0;
	Pilha pi;
	inicializa_pilha(&pi,p->tamInfo);
	
	Elemento *aux= p->cabeca;
	Evento e;
	e.data=data;
	while(aux!=NULL){
		if(comparaData(aux->info,&e)==0){
			empilha(&pi,cont);
		}
			aux=aux->proximo;
			cont++;
	}
	if(pilha_vazia(pi)){
		printf("Evento nao encontrado");
		return 0;
	}
	while(!pilha_vazia(pi)){
		desempilha(&pi,&cont);
		remove_pos(p,&e,cont);
	}
	return 1;
}
int removerDataHora(Lista *p, Data data, Hora hora,int (*comparaData)(void*,void*), int (*comparaHora)(void*, void*)){
	if(lista_vazia(*p))
		return 0;
	int achou=-1, cont=0;
	Elemento *aux= p->cabeca;
	Evento e;
	e.data=data;
	e.inicio=hora;
	while(aux!=NULL){
		if(comparaData(aux->info,&e)==0 && comparaHora(aux->info,&e) == 0){
			achou=cont;
		}
			aux=aux->proximo;
			cont++;
	}
	if(achou==-1){
		printf("Evento não encontrado");
		return 0;
	}
	remove_pos(p,&e,achou);
	return 1;
}
void mostra_evento(void *x){
	Evento *e= x;
	
	printf("Data: %.2d/%.2d/%.4d\nInicio: %.2d:%.2d\nFim: %.2d:%.2d\nDescricao: %s\nLocal: %s\n", e->data.dia,e->data.mes,e->data.ano, e->inicio.hora,e->inicio.min,e->fim.hora,e->fim.min,e->descricao,e->local);
}

void lerArquivo(const char *nomeArquivo, Lista *p, int (*comparaData)(void*, void*), int (*comparaHora)(void*, void*), int (*verificaConflito)(Evento*, Evento*)) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    Evento e;

       while (fscanf(arquivo, "%d %d %d %d %d %d %d ", &e.data.ano, &e.data.mes, &e.data.dia, &e.inicio.hora, &e.inicio.min, &e.fim.hora, &e.fim.min) == 7) {
          if (fscanf(arquivo, "%49[^.]. ", e.descricao) != 1) {
            perror("Erro ao ler descrição");
            exit(EXIT_FAILURE);
        }

        if (fscanf(arquivo, "%49[^.]. ", e.local) != 1) {
            perror("Erro ao ler local");
            exit(EXIT_FAILURE);
        }
        cadastrarArq(p, &e, comparaData, comparaHora, verificaConflito);
    }

    fclose(arquivo);
}

int cadastrarArq (Lista *p,Evento *e, int (*comparaData)(void*,void*),int (*comparaHora)(void*,void*), int (*verificaConflito)(Evento*,Evento*)){
	Elemento *aux = p->cabeca;
	int cont=0;
    while (aux != NULL) {
        if (comparaData(aux->info, e) == 0) {
            if ((comparaData(aux->info, e) == 0 && verificaConflito(aux->info, e))){
                printf("Conflito de horario! O evento nao pode ser adicionado.\n");
                return 0;
            }
        }

        if (comparaData(aux->info, e) < 0 || (comparaData(aux->info, e) == 0 && comparaHora(aux->info, e) < 0)) {
            cont++;
        }
        
		aux = aux->proximo;

    }

    return insere_pos(p, e,cont); 
}

void salvarArquivo(const char *nomeArquivo, Lista *p) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }

    Elemento *aux = p->cabeca;

    while (aux != NULL) {
        Evento *e = aux->info;
        fprintf(arquivo, "%d %d %d %d %d %d %d %s. %s.\n",
                e->data.ano, e->data.mes, e->data.dia,
                e->inicio.hora, e->inicio.min,
                e->fim.hora, e->fim.min,
                e->descricao, e->local);
        aux = aux->proximo;
    }

    fclose(arquivo);
}


