#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM_NOME 50

struct cadastro{
	int ip;
	char nome[TAM_NOME];
	float nota1;
	float nota2;
	float nota3;
	float media;
	
};

void calcularmedia(struct cadastro *aluno){
	float media;
	media= aluno->nota1+aluno->nota2+aluno->nota3;
	aluno->media=media/3;
}
void situacao(struct cadastro *aluno){
	calcularmedia(aluno);
	if(aluno->media<7){
		printf("Aluno %s esta reprovado\n", aluno->nome);
	}else{
		printf("Aluno %s esta aprovado\n", aluno->nome);
	}
}
void relatariogeral(struct cadastro *aluno);

int main() {
    struct cadastro *aluno;
    int opcao, i, n;
    printf("digite a quantidade de alunos:");
    scanf("%d",&n);
    
    aluno= malloc(n*sizeof(struct cadastro));
    
    
    for(i=0;i<n;i++){	
    printf("Cadastro Aluno:\n");
    printf("ip:");
    scanf("%d",&aluno[i].ip);
    printf("nome:");
	scanf("%s",aluno[i].nome);
    printf("Nota 1:");
	scanf("%f",&aluno[i].nota1);
	while(aluno[i].nota1<0 ||aluno[i].nota1>10 ){
		printf("Nota invalida, digite novamente");
		scanf("%f",&aluno[i].nota1);
		}
	printf("Nota 2:");
	scanf("%f",&aluno[i].nota2);
	while(aluno[i].nota2<0 ||aluno[i].nota2>10 ){	
		printf("Nota invalida, digite novamente");
		scanf("%f",&aluno[i].nota2);
		}
	
	printf("Nota 3:");
    scanf("%f",&aluno[i].nota3);
	while(aluno[i].nota3<0 ||aluno[i].nota3>10 ){
	
		printf("Nota invalida, digite novamente");
    	scanf("%f",&aluno[i].nota3);
		}
	}
    
  do{
        printf("opcao:\n0-Sair\n1-Calcular media\n2-Situacao do aluno\n3-Relatorio dos alunos gerais\n");
        scanf("%d", &opcao);
		if(opcao==1){
		printf("\n"); 
            for(i=0;i<n;i++){
				calcularmedia(&aluno[i]);
                printf("%d: %.1f\n",aluno[i].ip,aluno[i].media);	
			}
			printf("\n");
		}
        if(opcao==2){
        printf("\n");
            for(i=0;i<n;i++)
        		situacao(&aluno[i]);
        		
		printf("\n");		
		}
        if(opcao==3){
		printf("\n");
        for(i=0; i< n; i++)
        relatoriogeral(&aluno[i]);
		printf("\n");

		}
    }while(opcao!=0);
    free(aluno);
   
    return 0;
}

void relatoriogeral(struct cadastro *aluno){
	calcularmedia(aluno);
	printf("Aluno:\nip:%d\nnome:%s\nnotas:%.2f %.2f %.2f\nmedia:%.2f\n",aluno->ip,aluno->nome,aluno->nota1,aluno->nota2,aluno->nota3,aluno->media);
	situacao(aluno);

	
}
