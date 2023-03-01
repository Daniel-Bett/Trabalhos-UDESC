#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#define LIN 4
#define COL LIN

int main(int argc, char *argv[]) {
	
	int mat[LIN][COL];
	int i,j,somap=0,somas=0;
	srand(time (0));
	for(i=0; i<LIN; i++){
		for(j=0;j<COL;j++){
			mat[i][j]= rand() %10 ;
		}
	}
	printf(" Matrix(%dX%d)\n",LIN,COL);
	for(i=0; i<LIN; i++){
		for(j=0;j<COL;j++){
			printf("%3d ",mat[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<LIN;i++){
		somap=somap+mat[i][i];
		for(j=i+1;j<COL;j++)
		somas=somas+mat[i][j];
	}
	
	printf("diagonal p:%d acima da diagonal principal:%d",somap,somas);
	return 0;
}
