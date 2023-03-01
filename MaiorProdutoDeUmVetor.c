#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
		
	int i, n, maior, menor, teste;
	printf("Tamanho");
	scanf("%d", &n);
	int v[n];
	
	for(i=0;i<n;i++){
			v[i]= rand()%10+1;
	}
	maior= v[0]*v[1];
	
	for(i=0;i<n;i++){
		printf("%d ", v[i]);	
		}
	
	for(i=1;i<n;i++){
		teste= v[i]*v[i-1];
		if(maior< teste)
		maior= teste;
	}
	
	printf("\n o maior produto eh %d", maior);
	return 0;
}
