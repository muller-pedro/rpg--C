#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>



////     ~~~~~~~~~~~~~~~~~~~~     ////
int i, j, tecla;
int i_menu_batalha = 1;
int battleST = 1;
int itensMenu = 1;
////     ~~~~~~~~~~~~~~~~~~~~     ////
void _menu1();
void batalha();
void menu_batalha();
void _showStatus();
void hit_KB();
void win_tela();
void lostTela();
void ganhouPerdeu();
void _limites();

////     ~~~~~~~~~~~~~~~~~~~~     ////
struct inimigos {
	char nome[10];
	int vida,vidaMax;
	int expFinal, stamina, staminaMax;
	int ataque, defesa;
	
	
};
struct inimigos rat = {"Rato",100,100,20,0,30,10,10};

////     ~~~~~~~~~~~~~~~~~~~~     ////

struct personagens {
	char nome[10];
	int lv, gold,vida, vidaMax;
	int stamina, staminaMax;
	int myExp, myExpMax;
	int ataque, defesa;
};
struct personagens player = {"Jogador",1 , 80, 100, 100, 0, 30, 0, 100, 14, 15};



///    ~~~~~~~~~~~~~~~~~~~~~~~      ///// 



int main(){
	system("title jogo");
	_menu1();

}



void _menu1(){
	int menu1Status = 1 ;
	int iItens = 1;
	while(menu1Status != 0){
		system("cls");
		
		switch(menu1Status){
			case 1:
				printf("\t\t\t  Life:%d/%d\n\n\n\n\n\n-> Status     Batalha     Itens      SAIR",player.vida, player.vidaMax);	
				break;
			case 2:
				printf("\t\t\t  Life:%d/%d\n\n\n\n\n\n   Status  -> Batalha     Itens      SAIR",player.vida, player.vidaMax);	
				break;
			case 3:
				printf("\t\t\t  Life:%d/%d\n\n\n\n\n\n   Status     Batalha  -> Itens      SAIR",player.vida, player.vidaMax);	
				break;
			case 4:
				printf("\t\t\t  Life:%d/%d\n\n\n\n\n\n   Status     Batalha     Itens   -> SAIR",player.vida, player.vidaMax);	
		}
		backMenu1:
		tecla = getch();
		switch(tecla){
			case 75:
				menu1Status--;
				if(menu1Status <= 0){
					menu1Status++;
				}
				break;
			case 77:
				menu1Status++;
				if(menu1Status > 4){
					menu1Status--;
				}
				break;
			case 13:
				
			switch(menu1Status){
				case 1:
					_showStatus();
					break;
				case 2:
					menu_batalha();
					break;
				case 3:
					//open itens menu
					
					while(1){
						Sleep(2);
						system("cls");
						switch(itensMenu){
							case 1:
								printf("\t\t   Gold:%d    Life:%d/%d", player.gold,player.vida, player.vidaMax);
								printf("\n\tComprar <--    Vender ");
								getch();
								break;
							case 2:
								printf("\t\t   Gold:%d    Life:%d/%d", player.gold, player.vida, player.vidaMax);
								printf("\n\tComprar        Vender <--");
								break;
							
						}
						up1:
						tecla = getch();
						switch(tecla){
							case 75:
		 						itensMenu++;
								if(itensMenu > 2){
									itensMenu = 1;
								}
								break;
						case 77:
								itensMenu--;
								if(itensMenu < 1){
									itensMenu = 2;
								}
								break;
							case 8:
								_menu1();
								break;
							case 80:
								
								while(1){
								system("cls");
									
								switch(iItens){
									case 1:
										printf("\t\t   Gold:%d    Life:%d/%d", player.gold, player.vida, player.vidaMax);
										printf("\nLife Potion <-\nl_____l\n######");
										break;
									case 2:
										printf("\t\t   Gold:%d    Life:%d/%d", player.gold, player.vida, player.vidaMax);
										printf("\nLife Potion \nl_____l <--\n######");
										break;
									case 3:
										printf("\t\t   Gold:%d    Life:%d/%d", player.gold, player.vida, player.vidaMax);
										printf("\nLife Potion \nl_____l\n###### <--");
										break;
								}
										tecla = getch();
										switch(tecla){
											case 80:
												iItens++;
												if(iItens > 3){
													iItens = 1;
												}
												break;
											case 72:
												iItens--;
												if(iItens < 1){
													iItens = 3;
												}
												break;
											case 13:
												
													switch(iItens){
														case 1:
															if(player.gold >= 20){
															player.vida += 40;
															player.gold = player.gold - 20;
															if(player.vida > player.vidaMax){
																player.vida = player.vidaMax;
															}
															
															}
															break;
														case 2:
															break;
														case 3:
															break;
													}
												
												break;
											case 8:
												_menu1();
												break;
										}
								
								}    //    ~~~~~~ FIM WHILE 
								
								getch();
							case 224:
								goto up1;
								
						}
						
						
						
						
						
						
						
					}          // --------    FIM WHILE (1)  
					
					break;
				case 4:
					system("cls");
					exit(1);
					
				
					break;
			}
				
				
				Sleep(100);
				
				break;
		}
		
		
		
	}
	
}





// ------------   BATALHA ~~ 

void menu_batalha(){
		
	while(1){
		
	switch(i_menu_batalha){
		case 1:
			system("cls");
			printf("\t\t   Gold:%d    Life:%d/%d \n", player.gold, player.vida, player.vidaMax);
			printf("\n Escolha o inimigo: \n");
			printf("\t\t rat  <-- \n");
			printf("\t\t wolf     \n");
			printf("\t\t troll    \n");
			break;
		case 2:
			system("cls");
			printf("\t\t   Gold:%d    Life:%d/%d \n", player.gold, player.vida, player.vidaMax);
			printf("Escolha o inimigo: \n");
			printf("\t\t rat      \n");
			printf("\t\t wolf  <--\n");
			printf("\t\t troll    \n");
			break;
		case 3:
			system("cls");
			printf("\t\t   Gold:%d    Life:%d/%d \n", player.gold, player.vida, player.vidaMax);
			printf("Escolha o inimigo: \n");
			printf("\t\t rat      \n");
			printf("\t\t wolf     \n");
			printf("\t\t troll <--\n");
			break;
			
	}
	menu1:
	tecla = getch();
		switch(tecla){
			case 72:
				i_menu_batalha--;
				if(i_menu_batalha < 1){
					i_menu_batalha++;
				}
				break;
			case 80:
				i_menu_batalha++;
				if(i_menu_batalha > 3){
					i_menu_batalha--;
				}
				break;
			case 13:
				batalha();
				break;
			case 8:
				_menu1();
				break;
			case 224:
				goto menu1;
		}
	
	
	}
	
	
}





void _showStatus(){
	system("cls");
	printf("\n\n\n\n\n\n\nLv: %d  Gold:%d     Life: %d/%d\nExp: %d/%d\nAtaque:%d Defesa:%d", player.lv,player.gold,player.vida,player.vidaMax,player.myExp,player.myExpMax, player.ataque, player.defesa);
	getch();
	
	
	
}



//////     ~~~~~~~~~~~~~~~~~    BATALHA     

void batalha(){
	int cont = 0, cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0, cont7 = 0, cont8 = 0, cont9 = 0, cont10 = 0;
	
	int battleST = 1;
		
	switch(i_menu_batalha){
		
		case 1:
			battleST = 1;
			break;
		case 2:
			battleST = 2;
			break;
		case 3:
			battleST = 3;
			break;
	}
	
	if(battleST = 1){
		
		while(rat.vida > 0 && player.vida > 0){
		system("cls");
		// ------------------------------------
		cont3++;
		if(cont3 % 3){
			cont2++;
		}
		
		if(cont2 % 3){
			cont1++;
		}
		
		if(cont1 % 3){
			cont++;
		}	
		
		if(cont % 3){
			cont4++;
		}
		if(cont4 % 3){
			cont5++;
		}
		if(cont5 % 3){
			cont6++;
		}
		if(cont6 % 3){
			cont7++;
		}
		if(cont7 % 3){
			cont8++;
		}
		if(cont8 % 3){
			cont9++;
		}
		if(cont9 % 3){
			cont10 = cont9 / 2;
			player.stamina++;
			rat.stamina += 1;
			
		}
		
		
		_limites();      //  DEPOIS DO CONTADOR
		
		
		printf("    %s                    %s\n       %d          -          %d\n",  player.nome ,rat.nome ,player.vida, rat.vida);
		printf("\t\t%d    %d", player.stamina , rat.stamina);
		printf("\n\n\n\n\n(backspace para FUGIR)");
		Sleep(20);
			
		//   ----     /// 
		
		hit_KB();
		
		//   ----     /// 
		
		
		
		}
		
	ganhouPerdeu();
	
	
}
	
	
	
}



//   ----------------------------------


void hit_KB(){

if(kbhit()){
			tecla = getch();
			switch(tecla){
				case 13:
					
						if(player.stamina >= 20){
							printf("\n\tataque rapido");
							rat.vida -= player.ataque + player.lv;
							player.stamina -= 20;
							Sleep(15);
							
						}else{
							printf("\n  stamina insuficiente");
							Sleep(5);
						}
					
					break;
				case 8:
					system("cls");
					printf("\n\n\tVoce Fugiu !");
					printf("\n\nLife:%d   ", player.vida);
					rat.vida = rat.vidaMax;
					Sleep(1500);
					menu_batalha();
					break;	
			}
		}


}
//   ----------------------------------







void win_tela(){

system("cls");
printf("\n\n\n\t\t Voce venceu!");
printf("\n\n\n\t\t Obteve: %d + 24 gold coins!\n", rat.expFinal, player.gold);
player.myExp += rat.expFinal;
player.gold += 24;
system("pause");


}



void lostTela(){
	
system("cls");
printf("\n\n\n\t\t Game Over!\n\n\n\n");
Sleep(300);
exit(1);
}





void ganhouPerdeu(){
		
	// ----------    Ganhou ou perdeu   --------------------------	
	if(player.vida > 0 && rat.vida <= 0){
		
		rat.vida= rat.vidaMax;
		win_tela();
		
	}else{
		lostTela();
		Sleep(200);
	}
	// ------------------------------------------------------------	
	
	
}



void _limites(){     ////////     LIMITADORES DE BATALHA     ///////////
	
	
	// -----   LIMITADOR DE STAMINA DO JOGADOR  ----------
		
		if(player.stamina > player.staminaMax){
		player.stamina = player.staminaMax;
		}
		
		// -------   limitador stamina inimigo  --------  //
		
		if(rat.stamina > rat.staminaMax){
			rat.stamina = rat.staminaMax;
			if(rat.stamina = 30){
				rat.stamina -= 30;
				player.vida -= rat.ataque;
			//	printf("\a");
				Sleep(5);
			}
		}
		// ------------------------------------	
	
	
	
	
}

