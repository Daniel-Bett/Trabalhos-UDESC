#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, b, x, y, m, n, num1, num2, verificador=1;
	
	do{																//ciclo de repetição indeterminada
		int mmc=1, mdc=1,div=2;
		printf("Digite um numero A: ");								// entrada de dados
		scanf(" %d", &a);											
		while(a<=0){												// verificador de entrada e correção
			printf("Entrada invalida, digite outro valor para A: ");
			scanf(" %d", &a);
		}
		printf("Digite um numero B: ");
		scanf(" %d", &b);
		while(b<=0){
			printf("Entrada invalida, digite outro valor para B: ");
			scanf(" %d", &b);
		}
		num1=a;														// conservar a variavel 
		num2=b;
		while(a!=1 || b!=1){										//inicio do laço do MMC e MDC
			y=a/div;
			x=a%div;
			m=b/div;
			n=b%div;
			if(x==0 || n==0){										//verificação para se manter ou nao a variavel
				if(x==0){
					a=y;
				}
				if(n==0){
					b=m;
				}
				mmc= mmc*div;
				if(x==0 && n==0){
					mdc=mdc*div;
				}
			}else{
				if(x!=0 && n!=0){									//verificação para se aumentar o teste do divisor
				div++;
				}
			}
		}
		printf("( %d , %d ): mmc %d mdc %d \n", num1, num2, mmc, mdc);
		printf("Deseja realizar mais contas?\n 0-Nao 1-sim ");		//fim do ciclo e validação para um novo
		scanf(" %d",& verificador);
		}while(verificador);
		return 0;
}
