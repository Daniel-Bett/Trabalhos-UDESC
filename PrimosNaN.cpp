#include <stdio.h>

int main(){
	int x, b, i,a;
	printf("Digite um numero inicial: ");
	scanf("%d",&a);
	printf("Digite um numero para saber a quantidade de num primos ate ele: ");
	scanf("%d",&b);
	int contp=0;
	
	if(a>b){
		i=a;
		a=b;
		b=i;
	}
	
	for(x=a;x<=b;x++){
	int cont=0;
	for(i=2;i<=x;i++){
		if(x%i==0){
			cont++;
			
		}
	}
	if(cont==1){
		printf("\n%d eh primo",x);
		contp++;
	}}
	printf("\n\ntemos um total de %d num primos", contp);
	return 0;
}
