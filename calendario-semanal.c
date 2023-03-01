#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int ano, mes, dia, semana, x, y, w, z, t1, t2, t3;
	
	printf("Digite o Ano que deseja(AAAA): \n"); // Inicio do codigo da entrada dos dados
	scanf(" %i", &ano);
	printf("\n1 Janeiro\n2 Fevereiro\n3 Marco\n4 Abril\n5 Maio\n6 Junho\n7 Julho\n8 Agosto\n9 Setembro\n10 Outubro\n11 Novembro\n12 Dezembro\n");
	printf("\nDigite o numero do mes correspondente que deseja: \n");
	scanf("%i", &mes);
	printf("\nDigite o dia(DD): \n");
	scanf("%i", &dia);						   // Fim do codigo da entrada de dados
	
	x = ano%100;							   //Inicio das operações
	y= x/4;									   //fim das operações
	
	if(ano>=1800 && ano<=2199){
		if(mes>0 && mes<=12){
			if(dia>0 && dia<=31){
			
				if(mes==1){								   //Codigo para as alterações nos meses em que o ano é Bissexto
					t1= ano%4;
					t2= ano%100; 
					t3= ano%400; 						   //codigo para ano bissexto
						if(t1== 0 && t2>0 ){
							mes= 13;
						}else{
							if(t3==0){
								mes= 13;
							}else{
								mes=1;
							}
						}   
					}
									if(mes==2){								   //Codigo para as alterações nos meses em que o ano é Bissexto
										t1= ano%4;
										t2= ano%100; 
										t3= ano%400; //codigo para ano bissexto
										if(t1== 0 && t2>0 ){
											mes= 14;
										}else{
											if(t3==0){
											mes=14;
											}else{
												mes=2;
											}
										}  
									}
				
												if(mes==1){									  // Codigo para numero chae do mes 1:
													z=1;
												}else{
													if(mes==2){
														z=4;
													}else{
														if(mes==3){
														z=4;
														}else{
															if(mes==4){
																z=0;
															}else{
																if(mes==5){
																	z=2;
																}else{
																	if(mes==6){
																		z=5;
																	}else{
																		if(mes==7){
																			z=0;
																		}else{
																			if(mes==8){
																				z=3;
																			}else{
																				if(mes==9){
																				z=6;
																				}else{
																					if(mes==10){
																					z=1;
																					}else{
																						if(mes==11){
																							z=4;
																						}else{
																							if(mes==12){
																								z=6;
																							}else{
																								if(mes==13){
																									z=0;
																								}else{
																									if(mes==14){
																										z=3;
																									}
																								}
																							}
																						}	
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}		
												}
												if(ano>=1800 && ano<=1899){									//numero chave do seculo
													w= 2;
												}else{ 
													if(ano>=1900 && ano<=1999){
														w=0;
													}else{
														if(ano>=2000 && ano<=2099){
															w=6;
														}else{
															if(ano>=2100 && ano<=2199){
															w=4;
															}
														}
													}	
												}
											semana= x+y+z+w+dia;											//operaçoes finais						
											semana= semana%7;
	
												if(semana==0){														//informando qual dia da semana sera
													printf("\nO dia %i sera um sabado.\n", dia);
												}else{
													if(semana==1){
														printf("\nO dia %i sera uma domingo\n", dia);
													}else{
														if(semana==2){
															printf("\nO dia %i sera uma segunda-feira\n", dia);
														}else{
															if(semana==3){
																printf("\nO dia %i sera uma terca-feira\n", dia);
															}else{
																if(semana==4){
																	printf("\nO dia %i sera uma quarta-feira\n", dia);
																}else{
																	if(semana==5){
																		printf("\nO dia %i sera uma quinta-feira\n", dia);
																	}else{
																		printf("\nO dia %i sera uma sexta-feira\n", dia);
																		}
																	}
																}
															}
														}
													}																					
			}else{
				printf("Erro! a dia esta invalida\n");
			}
				}else{
					printf("Erro! a mes esta invalida\n");
				}
					}else{
						printf("Erro! a ano esta invalida\n");
					}

	return 0;
}
