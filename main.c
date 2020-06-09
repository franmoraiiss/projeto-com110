#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//DECLARAR FUNÇÕES
void menu();
void gameStart();
void controles();
void mapa1();
void mapa2();
void menuPause();
void historia();

//VARIAVEIS GLOBAIS
int coluna_atual = 1, linha_atual = 1;
char escolha = '1';
int vida = 3;
int dinheiro = 0;
int mapaAtual = 1;

//INICIO DO PROGRAMA
int main() {
	system("clear");
	menu();

	return 0;
}

//FAZ O MENU INICIAL
void menu(){   

	system("clear");

  	for(int i = 0 ; i < 36; i++){
	    printf("#");
	} printf("\n");		

	printf("######## Padawan Adventures ######## \n");

	for(int i = 0; i < 36; i++){
		printf("#");
	} printf("\n##");



	for(int i = 0; i < 32; i++){
		printf(" ");
	} printf("## \n");


	printf("## \tEscolha uma opcao:            ##\n");	
	printf("##                                ##\n");
	printf("## \t1. Iniciar                    ##\n");
	printf("## \t2. Continuar                  ##\n");
	printf("## \t3. Controles         	      ##\n");
	printf("## \t4. Sair do jogo   		      ##\n");
    printf("##                                ##\n");


	for(int i=0;i<36;i++){
		printf("#");
	}


	if(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' ){
	 	printf("\n /!\\ Insira um valor válido!\n");
	}


    printf("\n> Escolha: ");
  	scanf(" %c", &escolha);


	switch(escolha){

		case '1':
			
            historia();
			gameStart();

            break;

		case '2':

           system("clear");
           printf("Continuar \n\n");
			//Continuar

            break;

		case '3':

			system("clear");
			controles();

			break;

		case '4':
            system("clear");      
            printf("\nAté a próxima aventura !!\n\n");
			exit(0);

            break;
            
        default:
			menu();

			break;
      }

	return;
}


//REFAZ O MENU ADAPTADO PARA O 'PAUSE'
void menuPause(){

	system("clear");

  	for(int i = 0 ; i < 36; i++){
	    printf("#");
	} printf("\n");
		

	printf("############## PAUSA ############### \n");

	for(int i = 0; i < 36; i++){
		printf("#");
	} printf("\n##");


	for(int i = 0; i < 32; i++){
		printf(" ");
	} printf("## \n");


	printf("## \tEscolha uma opcao:            ##\n");	
	printf("##                                ##\n");
	printf("## \t1. Continuar                  ##\n");	
	printf("## \t2. Sair	                      ##\n");	
    printf("##                                ##\n");
		

	for(int i=0;i<36;i++){
		printf("#");
	}

	escolha = '1';
	if(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' ){
	 	printf("\n /!\\ Insira um valor válido!\n");
	}


    printf("\n> Escolha: "); 
  	scanf(" %c", &escolha);


	switch(escolha){
		case '1':

			gameStart();
            break;

		case '2':
            mapaAtual = 1;
	        linha_atual = 1;
	        coluna_atual = 1;
            
            dinheiro = 0;
		    vida = 3;
           
            
            system("clear");
			menu();

            break; 

		default:

			menuPause();
			break;
  	}
	return;
}


//INTRODUZ A HISTORIA DO PERSONAGEM E DO JOGO
void historia() {

	system("clear");
    
    //Parte 1 -> historia
  
	printf("###############################################################\n");
	printf("###############################################################\n");	
	printf("##################### Padawan Adventures ######################\n");
	printf("## \t                                                         ##\n");
	printf("## \t                                                         ##\n");
	printf("## \t Caro jovem Padawan , seu desejo de se tornar um Jedi    ##\n");	
	printf("## \t está mais próximo do que imaginas.                      ##\n");
	printf("## \t Chegue ao final de cada um dos (x) níveis,coletando     ##\n");	
	printf("## \t Todas as moedas disponíveis.                            ##\n");
	printf("## \t                                                         ##\n");
	printf("###############################################################\n");
	printf("###############################################################\n");	
	
		
	sleep(1);
    system("clear");
    
    //Parte 2 -> historia

    printf("###############################################################\n");
    printf("###############################################################\n");
	printf("##################### Padawan Adventures ######################\n");
	printf("## \t                                                         ##\n");
	printf("## \t                                                         ##\n");
	printf("## \t Guarde-as, elas serao essenciais para que alcance o     ##\n");	
	printf("## \t proximo nivel, e assim quando chegar ao ultimo e mais   ##\n");
	printf("## \t complicado dos niveis, devera mostrar toda sua bravura  ##\n");	
	printf("## \t para mostrar-ns que estao do lado certo da forca, o     ##\n");	
	printf("## \t lado da luz.                                            ##\n");
    printf("## \t                                                         ##\n");
    printf("###############################################################\n");
    printf("###############################################################\n");	

    sleep(1);
    system("clear");

    //Parte 3 -> historia

    printf("###############################################################\n");
    printf("###############################################################\n");
	printf("##################### Padawan Adventures ######################\n");
	printf("## \t                                                         ##\n");
	printf("## \t E ao final de tudo, ganahará seu trofeu ❄ !!            ##\n");
	printf("## \t                                                         ##\n");	
	printf("## \t                                                         ##\n");
	printf("## \t Sua nomeacao como um <<|Jedi|>>                         ##\n");	
	printf("## \t                                                         ##\n");	
	printf("## \t                                                         ##\n");
    printf("## \t                                                         ##\n");
    printf("###############################################################\n");
    printf("###############################################################\n");	

	
	if(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' ){
	 	printf("\n /!\\ Insira um valor válido!\n");
	}
    escolha:
    
    printf("\n↦ Digite 0 se estiver pronto para essa aventura ⇀  ");
  	scanf(" %c", &escolha);

	switch(escolha){

		case '0':
			
			gameStart();
            break;
        
        default:
        goto escolha;
        break;    
    }
}


//COMECA O JOGO
void gameStart(){

	system("clear");

	//historinha

    /*Adicionei no switch pois estavam tendo alguns bugs 
    1-> Quando o jogo reiniciava ele estava mantendo as VIDAS e o dinheiro
    2-> Quando 'x' era precionado no mapa 2 estava voltando para o mapa 1
    3-> Quando 'x' era pricionado o personagem voltava para posicao inicial
    Assim corrigi esse erros colocando essas funcoes dentro do switch
    la eles so reiniciam essa variaveis se o jogador escolher sair e comecar de novo
    */
	//2-> mapaAtual = 1; 
	//3-> linha_atual = 18;
	//3-> coluna_atual = 3;


	if(mapaAtual == 1){
		//1-> dinheiro = 0;
		//1->vida = 3;
		mapa1();

		//Atualiza o mapaAtual para 2 e restaura a coluna e linha para posição inicial

		mapaAtual = 2;
		coluna_atual = 1;
		linha_atual = 1;
	}

	

	if(mapaAtual == 2){
		mapa2();
	}
	//mapa3();
	//mapa4();
	//mapa5();
	return;
}


//CONSTROI O MAPA 1
void mapa1 (){

	mapaAtual = 1;

	//O desenho do mapa é feito a partir dos simbolos da matriz
	//Significado dos numeros:
	//0- vazio
	//1- parede
	//5- saída
	//6- caveira
	//7- dinheiro
	//9- vida



	int mapa1[20][30] = { 
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,9,1,1,
	1,0,0,0,0,0,1,0,0,1,0,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,0,6,1,0,1,1,1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9,1,1,0,0,1,
	1,0,1,0,1,0,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,
	1,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,6,0,0,6,7,6,0,0,0,0,0,0,1,
	1,0,1,0,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,1,
	1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,6,0,6,0,0,0,0,0,0,1,
	1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,6,0,1,1,1,1,1,1,1,1,1,1,1,
	1,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,0,0,0,7,0,0,0,0,0,0,0,6,0,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
	1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,
	1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,6,0,0,1,0,0,0,0,1,
	1,0,0,1,0,0,0,6,0,0,0,0,1,6,0,6,0,0,0,6,0,0,0,0,1,0,0,0,0,1,
	1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
	1,0,0,1,0,0,0,1,1,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};

	int linha,coluna; 

	char movimento;


	while (linha_atual != 17 || coluna_atual != 29) {

		system("clear");

		for (linha=0;linha<20;linha++) {
    		for (coluna=0;coluna<30;coluna++) {
				if ((linha == linha_atual) && (coluna == coluna_atual)) {
            		printf("♙ ");
            		continue;
         		}

				if (mapa1[linha][coluna] == 0)
					printf("  ");

				if (mapa1[linha][coluna] == 1)
					printf("✲✲");

				if (mapa1[linha][coluna] == 7)
					printf("⍟ ");

				if (mapa1[linha][coluna] == 8)
					printf("+");

				if(mapa1[linha][coluna] == 5)
					printf("→→→");

				if(mapa1[linha][coluna]==6)  
					printf("☠ ");

                if(mapa1[linha][coluna]==9)  
					printf("❤ ");     

			}
     	  	printf("\n");

        }

		printf("\t\tVIDAS: ");			

		for(int i = 0; i < vida; i++){
			printf("❤ ");
		}

		printf("\t\t⍟ : %d", dinheiro);

		printf("\n");

        if(vida == 0) {
            system("clear");
            printf("GAME OVER!!!!\nBetter luck next time Padawan!\n");
        }

        movimento = getchar();

        if ((movimento == 'w') || (movimento == 'W')) {

            linha_atual = linha_atual - 1;

            /* Se o personagem se movimentar para a parede, ele retorna pra posição onde estava */

            if ((mapa1[linha_atual][coluna_atual] != 0) && (mapa1[linha_atual][coluna_atual] != 6) && (mapa1[linha_atual][coluna_atual] != 9) && (mapa1[linha_atual][coluna_atual] != 7)) {

                linha_atual = linha_atual + 1;
                //getchar(); getchar();
            }
        }

        if ((movimento == 's') || (movimento == 'S')) {
            linha_atual = linha_atual + 1;

            if ((mapa1[linha_atual][coluna_atual] != 0) && (mapa1[linha_atual][coluna_atual] != 6) && (mapa1[linha_atual][coluna_atual] != 9)&&(mapa1[linha_atual][coluna_atual] != 7)) {

                linha_atual = linha_atual - 1;
                //getchar(); getchar();
            }
        }

        if ((movimento == 'd') || (movimento == 'D')) {

            coluna_atual = coluna_atual + 1;

            if ((mapa1[linha_atual][coluna_atual] != 0) && (mapa1[linha_atual][coluna_atual] != 6) && (mapa1[linha_atual][coluna_atual] != 9)&&(mapa1[linha_atual][coluna_atual] != 7)) {

                coluna_atual = coluna_atual - 1;
               // getchar(); getchar();
            }
        }



        if ((movimento == 'a') || (movimento == 'A')) {

            coluna_atual = coluna_atual - 1;

            if ((mapa1[linha_atual][coluna_atual] != 0) && (mapa1[linha_atual][coluna_atual] != 6) && (mapa1[linha_atual][coluna_atual] != 9)&&(mapa1[linha_atual][coluna_atual] != 7)) {

                coluna_atual = coluna_atual + 1;

               // getchar(); getchar();
            }
        }

        //Se enconstar no inimigo
        if (mapa1[linha_atual][coluna_atual] == 6) {
            coluna_atual = 1, linha_atual = 1;
            vida--;        		
        }

		//Se pegar o dinheiro
         if (mapa1[linha_atual][coluna_atual] == 7) {

			mapa1[linha_atual][coluna_atual] = 0;

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

			dinheiro++;
        }

        //Se pegar o coração
        if (mapa1[linha_atual][coluna_atual] == 9) {

			mapa1[linha_atual][coluna_atual] = 0;
            

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

            if(vida<3){   
            	vida++;
			}	
        }

		if((movimento == 'x') || (movimento == 'X')) {
			menuPause();
		}
	}
	system("clear");	
    return;
}


//CONSTROI O MAPA 2
void mapa2 (){

	//O desenho do mapa é feito a partir dos simbolos da matriz
	//Significado dos numeros:
	//0- vazio
	//1- parede
	//5- saída
	//6- caveira
	//7- dinheiro
	//9- vida
	
	int mapa2[20][30] = { 
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,7,0,1,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,
	1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,5,1,1,1,1
	};
	
	int linha,coluna; 
	char movimento;

	while ((movimento != 'x') && (movimento != 'X')) {

		system("clear");

		for (linha=0;linha<20;linha++) {
    		for (coluna=0;coluna<30;coluna++) {

				if ((linha == linha_atual) && (coluna == coluna_atual)) {
            		printf("♘ ");
            		continue;
         		}

				if (mapa2[linha][coluna] == 0)
					printf("  ");

				if (mapa2[linha][coluna] == 1)
					printf("✲✲");

				if (mapa2[linha][coluna] == 7)
					printf(" ⍟");

				if (mapa2[linha][coluna] == 8)
					printf("+");

				if(mapa2[linha][coluna] == 5)
					printf("  ");

				if(mapa2[linha][coluna]==6)  
					printf("☠ ");

                if(mapa2[linha][coluna]==9)  
					printf("❤ ");     
			}
	  	printf("\n");
        }

		printf("\t\tVIDAS: ");			

		for(int i = 0; i < vida; i++){
			printf("❤ ");
		}

		printf("\t\t⍟: %d", dinheiro);
		printf("\n");

        if(vida == 0) {
            system("clear");
            printf("GAME OVER!!!!\nBetter luck next time Padawan!\n");
        }

        movimento = getchar();

        if ((movimento == 'w') || (movimento == 'W')) {
            linha_atual = linha_atual - 1;

            /* Se o personagem se movimentar para a parede, ele retorna pra posição onde estava */

            if ((mapa2[linha_atual][coluna_atual] != 0) && (mapa2[linha_atual][coluna_atual] != 6) && (mapa2[linha_atual][coluna_atual] != 9) && (mapa2[linha_atual][coluna_atual] != 7)) {
                linha_atual = linha_atual + 1;
                //getchar(); getchar();
            }
        }

        if ((movimento == 's') || (movimento == 'S')) {
            linha_atual = linha_atual + 1;

            if ((mapa2[linha_atual][coluna_atual] != 0) && (mapa2[linha_atual][coluna_atual] != 6) && (mapa2[linha_atual][coluna_atual] != 9) && (mapa2[linha_atual][coluna_atual] != 7)) {
                linha_atual = linha_atual - 1;
                //getchar(); getchar();
            }
        }

        if ((movimento == 'd') || (movimento == 'D')) {

            coluna_atual = coluna_atual + 1;

            if ((mapa2[linha_atual][coluna_atual] != 0) && (mapa2[linha_atual][coluna_atual] != 6) && (mapa2[linha_atual][coluna_atual] != 9) && (mapa2[linha_atual][coluna_atual] != 7)) {
                coluna_atual = coluna_atual - 1;
               // getchar(); getchar();
            }
        }

        if ((movimento == 'a') || (movimento == 'A')) {
            coluna_atual = coluna_atual - 1;

            if ((mapa2[linha_atual][coluna_atual] != 0) && (mapa2[linha_atual][coluna_atual] != 6) && (mapa2[linha_atual][coluna_atual] != 9) && (mapa2[linha_atual][coluna_atual] != 7)) {
                coluna_atual = coluna_atual + 1;
               // getchar(); getchar();
            }
        }

        //Se enconstar no inimigo
        if (mapa2[linha_atual][coluna_atual] == 6) {
            coluna_atual = 1, linha_atual = 1;
            vida--;        		
        }

        //Se pegar o coração
        if (mapa2[linha_atual][coluna_atual] == 9) {

			mapa2[18][4] = 0;

            coluna_atual++;
            coluna_atual--;
            //linha_atual++;
            if(vida<3){   
            	vida++;
			}	
        }

        //Se pegar o dinheiro
        if (mapa2[linha_atual][coluna_atual] == 7) {

            coluna_atual++;
			linha_atual++;

			mapa2[14][19] = 0;

			coluna_atual--;
			linha_atual--;

            dinheiro++;        		
        }
	}

	system("clear");

	menuPause();

    return;
}


//EXIBE UM MENU DOS CONTROLES DO PERSONAGEM
void controles(){

	system("clear");

  	for(int i=0;i<36;i++){
		printf("#");
	} printf("\n");
	
	printf("############ Controles ############# \n");

	for(int i=0;i<36;i++){
		printf("#");
	} printf("\n##");

	for(int i=0;i<32;i++){
		printf(" ");
	} printf("## \n");

	printf("## \tMovimentação:                 ##\n");	
	printf("##                                ##\n");
	printf("## \t ↑(W) - Ir para cima          ##\n");
	printf("## \t ←(A) - Ir para esquerda      ##\n");	
	printf("## \t →(D) - Ir para direita       ##\n");	
	printf("## \t ↓(S) - Ir para baixo         ##\n");	
	printf("## \t X - Opções         	      ##\n");	
   	printf("##                                ##\n");

	for(int i=0;i<36;i++){
		printf("#");
	}

	char tmp;

	printf("\n- Pressione 4 para voltar ao Menu\n");
	scanf(" %c", &tmp);


	if(tmp=='4'){	
    	menu();
  	} else {
    	system("clear");
		controles();
	  }

}


//THE END