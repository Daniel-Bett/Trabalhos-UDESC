#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float altura, alturam=0, alturaf=0;
	int n, i,j=0;
	char sexo;
	printf("Quantas pessoas?");
	scanf(" %d",&n);
	for(i=1;n>=i;i++){
		printf("Digite f para feminino ou m para masculino:");
		scanf(" %c",&sexo);
		
		if(sexo == 'f'){
			printf("Digite a altura");
			scanf(" %f",&altura);
			alturaf=alturaf+altura;
			j++;
		}
			if(sexo == 'm'){
			printf("Digite a altura");
			scanf(" %f",&altura);
				while(altura<=0){
				printf("Digite a altura");
				scanf(" %f",&altura);
			}
			if(altura>alturam){
				alturam=altura;
				printf("O mais alto ate agora eh %.2f", alturam);
			}
		}
	}
	alturaf= alturaf/j;
	printf("a media das mulheres eh %.2f e dos homens o mais alto eh %.2f",alturaf,alturam);
	return 0;
}
