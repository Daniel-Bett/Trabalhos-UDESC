#include <stdio.h>

int main(){
	int votos,voto=0,branco=0, nulo=0, valido=0;
	int n, i;
	
	printf("Quantos votos: ");
	scanf(" %d",&n);
	
	for(i=1;i<=n;i++){
		printf("Digite:\n1-Nulo\n2-branco\n3-valido");
		scanf(" %d",&votos);
		while(votos<0 || votos>3){
			printf("Digite:\n1-Nulo\n2-branco\n3-valido");
			scanf(" %d",&votos);
		}
		if(votos==1){
			nulo++;
		}else{
			if(votos==2){
				branco++;
			}else{
				if(votos==3){
					valido++;
				}
			}
		}
		voto++;
	}
	valido=(100*valido)/n;
	branco=(100*branco)/n;
	nulo=(100*nulo)/n;

	printf("%d de votos sendo:\n %d%%  valido\n %d%%  branco\n %d%%  nulo",voto, valido,branco,nulo);
}
