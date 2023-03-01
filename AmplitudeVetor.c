#include <stdio.h>
#include <stdlib.h>
#define N 10

int main(int argc, char *argv[]) {
	float v[N], maior, menor;
	int i, j;
	
	for(i=0;i<N;i++){
		v[i]= rand() %100 + 1;
	
	for(i=0;i<N;i++){
		printf("%.0f ", v[i]);	
		}
	
	maior= v[0];
	menor= v[0];
	
	for(i=0;i<N;i++){
			if(menor> v[i])
			menor= v[i];
			if(maior<v[i])
			maior= v[i];
		}
	
	
	printf("A amplitude desse Vetor: %.0f ", maior-menor);
	return 0;
}
