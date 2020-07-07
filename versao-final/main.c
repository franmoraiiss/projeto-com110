#include <stdio.h>
#include <stdlib.h>
     
// ⇃⇂ Bibliotecas para o Linux 
//#include <unistd.h>	
//#include <curses.h>
//#include <ncurses.h>

//Para rodar o código sem erros, use o Replit, pois
//ele foi construído e compilado na plataforma.
//Para movimentação do personagens digite a direção (W, A, S, D) 
//e tecle enter para efetuar o movimento. 

//Authors: Camila Braga, Francisco Morais, Joao Vitor Oliveira.

//DECLARAR FUNÇÕES
void menu();
void gameStart();
void controles();
void mapa1();
void mapa2();
void mapa3();
void mapa4();
void mapa5();
void mapa6();
void creditos();
void menuPause();
void historia();
void gameOver();

//VARIÁVEIS GLOBAIS
int coluna_atual = 1, linha_atual = 1;
char escolha = '1';
int mapaAtual;

//PROPRIEDADES DO PLAYER
struct player {
	int dinheiro;
	int vida;
};
struct player player1;

//INICIO DO PROGRAMA
int main() {

	FILE *level_file;
	level_file = fopen("level.txt", "a");    
	fclose(level_file);	

	system("clear");
	menu();

	return 0;
}

//MENU INICIAL
void menu(){   
	
	escolha = '1';
	system("clear");

	//Lê o arquivo e salvar na variavel 'mapaAtual'
	//que indica em qual level o jogador parou na ultima
	//vez que jogou. Caso não tenha jogado, irá aparecer um
	//aviso, falando que ele tem que iniciar o jogo.
	FILE *level_file;
	level_file = fopen("level.txt", "r");    
	fscanf(level_file, "%d", &mapaAtual);
	fclose(level_file);	

	//PRINTA O MENU
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

            mapaAtual = 1;

			player1.dinheiro = 0;
			player1.vida = 3;			
            
			historia();
            break;

		case '2':

			if(mapaAtual > 1) {
				
				switch(mapaAtual) {
					case 2:
						player1.dinheiro = 3;
						break;

					case 3:
						player1.dinheiro = 7;
						break;

					case 4:
						player1.dinheiro = 10;
						break;

					case 5:
						player1.dinheiro = 13;
						break;

					case 6:
						player1.dinheiro = 16;
						break;
						
					default:
						break;
				}

				player1.vida = 3;
				gameStart();	

			} else {

				printf("-- Você ainda não iniciou um jogo!!\n");
				sleep(2);

				menu();
			}

            break;

		case '3':

			system("clear");
			controles();

			break;

		case '4':

            system("clear"); 

            for(int i = 0; i < 36; i++){
                printf("#");
            } printf("\n##");

            for(int i = 0; i < 32; i++){
                printf(" ");
            } printf("## \n");

            printf("## \t Até a próxima aventura !!    ##\n");	
            printf("##                                ##\n");

            for(int i=0;i<36;i++){
                printf("#");
            }
			exit(0);
            break;
            
        default:
			menu();
			break;
    }

	return;
}

//MENU ADAPTADO PARA O 'PAUSE'
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
			return;
            break;

		case '2':            
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
  
	printf("###############################################################\n");
	printf("###############################################################\n");	
	printf("##################### Padawan Adventures ######################\n");
	printf("## \t                                                         ##\n");
	printf("## \t                                                         ##\n");
	printf("## \t Caro jovem Padawan , seu desejo de se tornar um Jedi    ##\n");	
	printf("## \t está mais próximo do que imaginas.                      ##\n");
	printf("## \t Chegue ao final de cada um dos  6  níveis,coletando     ##\n");	
	printf("## \t Todas as moedas disponíveis.                            ##\n");
	printf("## \t                                                         ##\n");
	printf("###############################################################\n");
	printf("###############################################################\n");		
		
	sleep(10);
    system("clear");

    printf("###############################################################\n");
    printf("###############################################################\n");
	printf("##################### Padawan Adventures ######################\n");
	printf("## \t                                                         ##\n");
	printf("## \t                                                         ##\n");
	printf("## \t Guarde-as, elas serao essenciais para que alcance o     ##\n");	
	printf("## \t proximo nivel, e assim quando chegar ao ultimo e mais   ##\n");
	printf("## \t complicado dos niveis, devera mostrar toda sua bravura  ##\n");	
	printf("## \t para mostrar-nos que esta do lado certo da forca, o     ##\n");	
	printf("## \t lado da luz.                                            ##\n");
    printf("## \t                                                         ##\n");
    printf("###############################################################\n");
    printf("###############################################################\n");	

    sleep(14);
    system("clear");

    printf("###############################################################\n");
    printf("###############################################################\n");
	printf("##################### Padawan Adventures ######################\n");
	printf("## \t                                                         ##\n");
	printf("## \t E ao final de tudo, ganahará seu trofeu 🏆 !!            ##\n");
	printf("## \t                                                         ##\n");	
	printf("## \t                                                         ##\n");
	printf("## \t Sua nomeacao como um <<|Jedi|>>                         ##\n");	
	printf("## \t                                                         ##\n");	
	printf("## \t                                                         ##\n");
    printf("## \t                                                         ##\n");
    printf("###############################################################\n");
    printf("###############################################################\n");	

	sleep(5);
	
	system("clear");

    printf("###############################################################\n");
    printf("###############################################################\n");
	printf("##################### Padawan Adventures ######################\n");
	printf("## \t                                                         ##\n");
	printf("## \t       W   	       W - Cima	        			         ##\n");
	printf("## \t    A  S  D        A - Esquerda                          ##\n");	
	printf("## \t                   S - Baixo                             ##\n");
	printf("## \t 				   D - Direita				             ##\n");	
	printf("## \t                                                         ##\n");	
	printf("## \t     Após digitar a direção, tecle ENTER                 ##\n");
    printf("## \t                                                         ##\n");
    printf("###############################################################\n");
    printf("###############################################################\n");	
	
	sleep(3);

	int tmp;
	printf("\n Digite qualquer tecla para continuar ⇀ ");
	scanf("%d", &tmp);

	gameStart();
}

//COMECA O JOGO
void gameStart(){

	system("clear");

	FILE *level_file;	

	if(mapaAtual == 1){
		
		//Posição inicial do jogador
		coluna_atual = 1;
		linha_atual = 1;

		//Valores iniciais do dinheiro e vida
		player1.dinheiro = 0;
		player1.vida = 3;

		//Salva no arquivo o mapa jogado
		remove("level.txt");
		level_file = fopen("level.txt", "w");    
		fprintf(level_file, "%d", mapaAtual);
		fclose(level_file);

		mapa1();
	}

	if(mapaAtual == 2){

		//Posição inicial do jogador
        coluna_atual = 1;
        linha_atual = 1;
	
		//Salva no arquivo o último mapa jogado
		remove("level.txt");
		level_file = fopen("level.txt", "w");    
		fprintf(level_file, "%d", mapaAtual);
		fclose(level_file);	

		mapa2();
	}

	if(mapaAtual == 3){

		//Posição inicial do jogador
        coluna_atual = 1;
        linha_atual = 1;

		//Salva no arquivo o último mapa jogado	
		remove("level.txt");
		level_file = fopen("level.txt", "w");    
		fprintf(level_file, "%d", mapaAtual);
		fclose(level_file);

		mapa3();
	}

	if(mapaAtual == 4){

		//Posição inicial do jogador
		coluna_atual = 1;
        linha_atual = 1;

		//Salva no arquivo o último mapa jogado
		remove("level.txt");
		level_file = fopen("level.txt", "w");    
		fprintf(level_file, "%d", mapaAtual);
		fclose(level_file);
		
		mapa4();
	}

	if(mapaAtual == 5){

		//Posição inicial do jogador
		coluna_atual = 1;
        linha_atual = 1;

		//Salva no arquivo o último mapa jogado
		remove("level.txt");
		level_file = fopen("level.txt", "w");    
		fprintf(level_file, "%d", mapaAtual);
		fclose(level_file);
		
		mapa5();
	}

	if(mapaAtual == 6){

		//Posição inicial do jogador
		coluna_atual = 1;
        linha_atual = 10;	

		mapa6();
	}	

	//Créditos
	if(mapaAtual == 7) {
		
		//Reinicia o mapa jogado para o mapa inicial para não 
		//começar o jogo dos créditos a partir do menu
		remove("level.txt");
		level_file = fopen("level.txt", "w");    
		fprintf(level_file, "%d", 1);
		fclose(level_file);	

		creditos();
	}

	return;
}

//CONSTROI O MAPA 1
void mapa1 (){

	mapaAtual = 1;
	//O desenho do mapa é feito a partir dos simbolos da matriz
	//Significado dos numeros:
	//0- vazio
	//1- parede
	//6- caveira
	//7- player1.dinheiro
	//9- player1.vida

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

	int linha, coluna; 
	char movimento;

	//Enquanto o player não atinge a posição final e possui todas as moedas, o código é executado
	while (linha_atual != 17 || coluna_atual != 29 || player1.dinheiro < 3) {

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
				
				if(mapa1[linha][coluna]==6)  
					printf("☠ ");

                if(mapa1[linha][coluna]==9)  
					printf("❤ ");     

			}
     	  	printf("\n");

        }

		printf("\t\tVIDAS: ");			
		for(int i = 0; i < player1.vida; i++){
			printf("❤ ");
		}

		printf("\t\t⍟ : %d", player1.dinheiro);
		printf("\t\tWORLD: %d", mapaAtual);

		printf("\n");

        movimento = getchar();

        if ((movimento == 'w') || (movimento == 'W')) {

            linha_atual = linha_atual - 1;

            // Se o personagem se movimentar para a parede, ele retorna pra posição onde estava
            if ((mapa1[linha_atual][coluna_atual] != 0) && (mapa1[linha_atual][coluna_atual] != 6) && (mapa1[linha_atual][coluna_atual] != 9) && (mapa1[linha_atual][coluna_atual] != 7)) {
				
                linha_atual = linha_atual + 1;
            }
        }

        if ((movimento == 's') || (movimento == 'S')) {
            linha_atual = linha_atual + 1;

            if ((mapa1[linha_atual][coluna_atual] != 0) && (mapa1[linha_atual][coluna_atual] != 6) && (mapa1[linha_atual][coluna_atual] != 9)&&(mapa1[linha_atual][coluna_atual] != 7)) {

                linha_atual = linha_atual - 1;
            }
        }

        if ((movimento == 'd') || (movimento == 'D')) {

            coluna_atual = coluna_atual + 1;

            if ((mapa1[linha_atual][coluna_atual] != 0) && (mapa1[linha_atual][coluna_atual] != 6) && (mapa1[linha_atual][coluna_atual] != 9)&&(mapa1[linha_atual][coluna_atual] != 7)) {

                coluna_atual = coluna_atual - 1;
            }
        }

        if ((movimento == 'a') || (movimento == 'A')) {

            coluna_atual = coluna_atual - 1;

            if ((mapa1[linha_atual][coluna_atual] != 0) && (mapa1[linha_atual][coluna_atual] != 6) && (mapa1[linha_atual][coluna_atual] != 9)&&(mapa1[linha_atual][coluna_atual] != 7)) {

                coluna_atual = coluna_atual + 1;

            }
        }

		if(player1.vida == 0){
			gameOver();
		}

        //Se enconstar no inimigo
        if (mapa1[linha_atual][coluna_atual] == 6) {
            coluna_atual = 1, linha_atual = 1;
            player1.vida--;        		
        }

		//Se pegar o player1.dinheiro
         if (mapa1[linha_atual][coluna_atual] == 7) {

			mapa1[linha_atual][coluna_atual] = 0;

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

			player1.dinheiro++;

        }

        //Se pegar o coração
        if (mapa1[linha_atual][coluna_atual] == 9) {

			mapa1[linha_atual][coluna_atual] = 0;

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

            if(player1.vida<3){   
            	player1.vida++;
			}	
        }

		if((movimento == 'x') || (movimento == 'X')) {
			menuPause();
		}
	}

	mapaAtual = 2;
	gameStart();

	system("clear");	
    return;
}


//CONSTROI O MAPA 2
void mapa2 (){

	mapaAtual = 2;

	//O desenho do mapa é feito a partir dos simbolos da matriz
	//Significado dos numeros:
	//0- vazio
	//1- parede
	//6- caveira
	//7- player1.dinheiro
	//9- player1.vida
	
	int mapa2[20][30] = { 
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,6,0,0,1,
	1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,7,0,0,6,0,0,0,0,1,
	1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,0,0,1,1,
	1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,0,0,0,0,1,0,1,1,1,
	1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,1,
	1,0,1,1,1,1,7,0,0,0,0,1,1,1,1,0,0,0,0,0,0,6,0,0,0,0,0,0,0,1,
	1,0,1,0,9,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1,0,0,0,0,1,
	1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0,1,
	1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,1,1,1,1,1,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,1,0,0,0,0,1,
	1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,6,0,0,0,1,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,1,1,1,0,0,1,
	1,0,0,6,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,7,0,1,0,0,0,0,0,0,0,1,
	1,0,0,1,0,0,0,0,0,0,6,0,0,1,0,0,0,1,0,1,0,1,0,0,0,6,6,6,0,1,
	1,1,0,0,1,0,0,0,1,6,0,0,6,1,0,6,0,1,0,6,0,1,0,0,6,6,6,6,0,1,
	1,1,1,0,1,0,0,0,1,0,0,6,1,1,0,6,0,0,0,6,0,0,0,6,6,6,6,6,0,1,
	1,1,1,0,9,0,0,0,6,7,0,1,1,1,0,6,0,0,6,6,6,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1
	};
	
	int linha, coluna; 
	char movimento;

	while (linha_atual != 19 || coluna_atual != 25 || player1.dinheiro < 7) {

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
				
				if(mapa2[linha][coluna]==6)  
					printf("☠ ");

                if(mapa2[linha][coluna]==9)  
					printf("❤ ");     
			}
	  	printf("\n");
        }

		printf("\t\tVIDAS: ");			
		for(int i = 0; i < player1.vida; i++){
			printf("❤ ");
		}

		printf("\t\t⍟ : %d", player1.dinheiro);
        printf("\t\tWORLD: %d", mapaAtual);
		
		printf("\n");

        movimento = getchar();

        if ((movimento == 'w') || (movimento == 'W')) {
            linha_atual = linha_atual - 1;

            //Se o personagem se movimentar para a parede, ele retorna pra posição onde estava
            if ((mapa2[linha_atual][coluna_atual] != 0) && (mapa2[linha_atual][coluna_atual] != 6) && (mapa2[linha_atual][coluna_atual] != 9) && (mapa2[linha_atual][coluna_atual] != 7)) {
                linha_atual = linha_atual + 1;
                
            }
        }

        if ((movimento == 's') || (movimento == 'S')) {
            linha_atual = linha_atual + 1;

            if ((mapa2[linha_atual][coluna_atual] != 0) && (mapa2[linha_atual][coluna_atual] != 6) && (mapa2[linha_atual][coluna_atual] != 9) && (mapa2[linha_atual][coluna_atual] != 7)) {
                linha_atual = linha_atual - 1;
                
            }
        }

        if ((movimento == 'd') || (movimento == 'D')) {

            coluna_atual = coluna_atual + 1;

            if ((mapa2[linha_atual][coluna_atual] != 0) && (mapa2[linha_atual][coluna_atual] != 6) && (mapa2[linha_atual][coluna_atual] != 9) && (mapa2[linha_atual][coluna_atual] != 7)) {
                coluna_atual = coluna_atual - 1;
               
            }
        }

        if ((movimento == 'a') || (movimento == 'A')) {
            coluna_atual = coluna_atual - 1;

            if ((mapa2[linha_atual][coluna_atual] != 0) && (mapa2[linha_atual][coluna_atual] != 6) && (mapa2[linha_atual][coluna_atual] != 9) && (mapa2[linha_atual][coluna_atual] != 7)) {
                coluna_atual = coluna_atual + 1;
               
            }
        }

        //Se enconstar no inimigo
        if (mapa2[linha_atual][coluna_atual] == 6) {
            coluna_atual = 1, linha_atual = 1;
            player1.vida--;        		
        }

        //Se pegar o coração
        if (mapa2[linha_atual][coluna_atual] == 9) {

			mapa2[linha_atual][coluna_atual] = 0;
            

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

            if(player1.vida<3){   
            	player1.vida++;
			}	
        }


        //Se pegar o player1.dinheiro
        if (mapa2[linha_atual][coluna_atual] == 7) {

			mapa2[linha_atual][coluna_atual] = 0;

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

        	player1.dinheiro++;        		
        }
		
		if((movimento == 'x') || (movimento == 'X')) {
			menuPause();
		}
	}

	system("clear");
	mapaAtual = 3;

	gameStart();

    return;
}

//CONSTROI O MAPA 3
void mapa3() {

	mapaAtual = 3;

	//O desenho do mapa é feito a partir dos simbolos da matriz
	//Significado dos numeros:
	//0- vazio
	//1- parede
	//6- caveira
	//7- player1.dinheiro
	//9- player1.vida

	int mapa3[20][30] = { 
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,6,0,1,0,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,
	1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,7,1,0,0,0,1,0,0,0,0,0,0,0,1,
	1,0,1,0,1,0,0,0,6,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,1,1,1,0,1,
	1,0,1,9,1,0,0,0,9,6,1,0,0,0,1,0,1,1,0,1,0,1,0,0,0,1,0,1,0,1,
	1,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,1,1,0,1,0,1,
	1,0,0,6,0,0,0,1,1,1,1,0,0,0,1,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,
	1,0,0,0,0,6,0,0,0,7,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,
	1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,
	1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	1,0,0,0,0,0,6,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
	1,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,1,
	1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,
	1,0,1,0,1,0,0,6,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,
	1,0,0,0,1,0,0,7,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,6,0,9,1,
	1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};

	int linha, coluna; 
	char movimento;

	while (linha_atual != 10 || coluna_atual != 29 || player1.dinheiro < 10) {

		system("clear");

		for (linha=0;linha<20;linha++) {
    		for (coluna=0;coluna<30;coluna++) {
				if ((linha == linha_atual) && (coluna == coluna_atual)) {
            		printf("♗ ");
            		continue;
         		}

				if (mapa3[linha][coluna] == 0)
					printf("  ");

				if (mapa3[linha][coluna] == 1)
					printf("✲✲");

				if (mapa3[linha][coluna] == 7)
					printf("⍟ ");

				if(mapa3[linha][coluna]==6)  
					printf("☠ ");

                if(mapa3[linha][coluna]==9)  
					printf("❤ ");     

			}
     	  	printf("\n");

        }

		printf("\t\tVIDAS: ");			

		for(int i = 0; i < player1.vida; i++){
			printf("❤ ");
		}

		printf("\t\t⍟ : %d", player1.dinheiro);
        printf("\t\tWORLD: %d", mapaAtual);

		printf("\n");

        movimento = getchar();

        if ((movimento == 'w') || (movimento == 'W')) {

            linha_atual = linha_atual - 1;

            //Se o personagem se movimentar para a parede, ele retorna pra posição onde estava
            if ((mapa3[linha_atual][coluna_atual] != 0) && (mapa3[linha_atual][coluna_atual] != 6) && (mapa3[linha_atual][coluna_atual] != 9) && (mapa3[linha_atual][coluna_atual] != 7)) {

                linha_atual = linha_atual + 1;
                
            }
        }

        if ((movimento == 's') || (movimento == 'S')) {
            linha_atual = linha_atual + 1;

            if ((mapa3[linha_atual][coluna_atual] != 0) && (mapa3[linha_atual][coluna_atual] != 6) && (mapa3[linha_atual][coluna_atual] != 9)&&(mapa3[linha_atual][coluna_atual] != 7)) {

                linha_atual = linha_atual - 1;
                
            }
        }

        if ((movimento == 'd') || (movimento == 'D')) {

            coluna_atual = coluna_atual + 1;

            if ((mapa3[linha_atual][coluna_atual] != 0) && (mapa3[linha_atual][coluna_atual] != 6) && (mapa3[linha_atual][coluna_atual] != 9)&&(mapa3[linha_atual][coluna_atual] != 7)) {

                coluna_atual = coluna_atual - 1;
               
            }
        }

        if ((movimento == 'a') || (movimento == 'A')) {

            coluna_atual = coluna_atual - 1;

            if ((mapa3[linha_atual][coluna_atual] != 0) && (mapa3[linha_atual][coluna_atual] != 6) && (mapa3[linha_atual][coluna_atual] != 9)&&(mapa3[linha_atual][coluna_atual] != 7)) {

                coluna_atual = coluna_atual + 1;
               
            }
        }

		if(player1.vida == 0){
			gameOver();
		}

        //Se enconstar no inimigo
        if (mapa3[linha_atual][coluna_atual] == 6) {
            coluna_atual = 1, linha_atual = 1;
            player1.vida--;        		
        }

		//Se pegar o player1.dinheiro
         if (mapa3[linha_atual][coluna_atual] == 7) {

			mapa3[linha_atual][coluna_atual] = 0;

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

			player1.dinheiro++;
        }

        //Se pegar o coração
        if (mapa3[linha_atual][coluna_atual] == 9) {

			mapa3[linha_atual][coluna_atual] = 0;

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

            if(player1.vida<3){   
            	player1.vida++;
			}	
        }

		if((movimento == 'x') || (movimento == 'X')) {
			menuPause();
		}
	}

	mapaAtual = 4;
	gameStart();

	system("clear");	
    return;
}

//CONSTROI MAPA 4
void mapa4() {

	mapaAtual = 4;

	//O desenho do mapa é feito a partir dos simbolos da matriz
	//Significado dos numeros:
	//0- vazio
	//1- parede
	//6- caveira
	//7- player1.dinheiro
	//9- player1.vida

	int mapa4[20][30] = { 
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,6,6,6,6,0,6,0,0,0,0,6,0,6,1,
	1,0,0,0,0,0,0,1,7,6,6,6,0,0,0,1,0,0,0,0,0,0,6,0,0,0,6,0,0,0,
	1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,0,1,0,6,6,6,0,0,0,6,1,
	1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,6,6,1,0,0,0,0,0,0,1,0,1,
	1,9,6,6,0,1,0,1,0,0,1,0,1,1,1,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,
	1,6,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,
	1,6,6,0,6,1,0,1,0,1,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,
	1,6,6,0,7,1,0,1,0,1,1,0,0,1,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,
	1,1,1,1,1,1,0,1,0,0,0,6,0,6,0,6,0,0,0,1,0,0,1,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,1,0,0,0,1,0,9,6,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,
	1,0,0,0,1,1,1,0,0,0,0,1,1,6,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,1,
	1,0,0,1,0,0,0,0,0,0,0,0,6,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,
	1,0,0,1,0,1,1,0,0,0,0,6,0,6,0,0,1,1,1,0,0,0,1,0,1,1,1,1,1,1,
	1,6,0,1,0,1,0,0,0,0,0,0,6,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,6,6,0,0,0,6,9,1,1,0,0,0,0,0,1,0,0,1,0,0,0,1,
	1,0,0,0,1,1,1,1,0,1,1,0,1,0,1,1,1,1,0,6,6,0,1,1,1,1,0,0,0,1,
	1,0,0,1,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};

	int linha, coluna; 
	char movimento;

	while (linha_atual != 2 || coluna_atual != 29 || player1.dinheiro < 13) {

		system("clear");

		for (linha=0;linha<20;linha++) {
    		for (coluna=0;coluna<30;coluna++) {
				if ((linha == linha_atual) && (coluna == coluna_atual)) {
            		printf("♖ ");
            		continue;
         		}

				if (mapa4[linha][coluna] == 0)
					printf("  ");

				if (mapa4[linha][coluna] == 1)
					printf("✲✲");

				if (mapa4[linha][coluna] == 7)
					printf("⍟ ");

				if(mapa4[linha][coluna]==6)  
					printf("☠ ");

                if(mapa4[linha][coluna]==9)  
					printf("❤ ");     

			}
     	  	printf("\n");

        }

		printf("\t\tVIDAS: ");			

		for(int i = 0; i < player1.vida; i++){
			printf("❤ ");
		}

		printf("\t\t⍟ : %d", player1.dinheiro);
        printf("\t\tWORLD: %d", mapaAtual);

		printf("\n");

        movimento = getchar();

        if ((movimento == 'w') || (movimento == 'W')) {

            linha_atual = linha_atual - 1;

            //Se o personagem se movimentar para a parede, ele retorna pra posição onde estava
            if ((mapa4[linha_atual][coluna_atual] != 0) && (mapa4[linha_atual][coluna_atual] != 6) && (mapa4[linha_atual][coluna_atual] != 9) && (mapa4[linha_atual][coluna_atual] != 7)) {

                linha_atual = linha_atual + 1;
                
            }
        }

        if ((movimento == 's') || (movimento == 'S')) {
            linha_atual = linha_atual + 1;

            if ((mapa4[linha_atual][coluna_atual] != 0) && (mapa4[linha_atual][coluna_atual] != 6) && (mapa4[linha_atual][coluna_atual] != 9)&&(mapa4[linha_atual][coluna_atual] != 7)) {

                linha_atual = linha_atual - 1;

            }
        }

        if ((movimento == 'd') || (movimento == 'D')) {

            coluna_atual = coluna_atual + 1;

            if ((mapa4[linha_atual][coluna_atual] != 0) && (mapa4[linha_atual][coluna_atual] != 6) && (mapa4[linha_atual][coluna_atual] != 9)&&(mapa4[linha_atual][coluna_atual] != 7)) {

                coluna_atual = coluna_atual - 1;
               
            }
        }

        if ((movimento == 'a') || (movimento == 'A')) {

            coluna_atual = coluna_atual - 1;

            if ((mapa4[linha_atual][coluna_atual] != 0) && (mapa4[linha_atual][coluna_atual] != 6) && (mapa4[linha_atual][coluna_atual] != 9)&&(mapa4[linha_atual][coluna_atual] != 7)) {

                coluna_atual = coluna_atual + 1;
               
            }
        }

		if(player1.vida == 0){
			gameOver();
		}

        //Se enconstar no inimigo
        if (mapa4[linha_atual][coluna_atual] == 6) {
            coluna_atual = 1, linha_atual = 1;
            player1.vida--;        		
        }

		//Se pegar o player1.dinheiro
         if (mapa4[linha_atual][coluna_atual] == 7) {

			mapa4[linha_atual][coluna_atual] = 0;

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

			player1.dinheiro++;
        }

        //Se pegar o coração
        if (mapa4[linha_atual][coluna_atual] == 9) {

			mapa4[linha_atual][coluna_atual] = 0;
            
            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

            if(player1.vida<3){   
            	player1.vida++;
			}	
        }

		if((movimento == 'x') || (movimento == 'X')) {
			menuPause();
		}
	}

	mapaAtual = 5;
	gameStart();

	system("clear");	
    return;
}

//CONSTROI MAPA 5
void mapa5() {

	mapaAtual = 5;

	//O desenho do mapa é feito a partir dos simbolos da matriz
	//Significado dos numeros:
	//0- vazio
	//1- parede
	//6- caveira
	//7- player1.dinheiro
	//9- player1.vida

	int mapa5[20][30] = { 
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,1,
	1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,
	1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,1,1,
	1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,
	1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
	0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,
	1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,
	1,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,
	1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,1,0,1,
	1,0,7,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1,0,1,0,1,
	1,1,1,1,0,0,0,0,0,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1,0,1,0,1,
	1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,0,0,7,0,0,1,1,0,1,0,0,0,1,
	1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,7,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};

	int linha, coluna; 

	char movimento;


	while (linha_atual != 7 || coluna_atual != 0 || player1.dinheiro < 16) {

		system("clear");

		for (linha=0;linha<20;linha++) {
    		for (coluna=0;coluna<30;coluna++) {
				if ((linha == linha_atual) && (coluna == coluna_atual)) {
            		printf("♕ ");
            		continue;
         		}

				if (mapa5[linha][coluna] == 0)
					printf("  ");

				if (mapa5[linha][coluna] == 1)
					printf("✲✲");

				if (mapa5[linha][coluna] == 7)
					printf("⍟ ");

				if(mapa5[linha][coluna]==6)  
					printf("☠ ");

                if(mapa5[linha][coluna]==9)  
					printf("❤ ");     

			}
     	  	printf("\n");

        }

		printf("\t\tVIDAS: ");			
		for(int i = 0; i < player1.vida; i++){
			printf("❤ ");
		}

		printf("\t\t⍟ : %d", player1.dinheiro);
        printf("\t\tWORLD: %d", mapaAtual);

		printf("\n");

        movimento = getchar();

        if ((movimento == 'w') || (movimento == 'W')) {

            linha_atual = linha_atual - 1;

            //Se o personagem se movimentar para a parede, ele retorna pra posição onde estava
            if ((mapa5[linha_atual][coluna_atual] != 0) && (mapa5[linha_atual][coluna_atual] != 6) && (mapa5[linha_atual][coluna_atual] != 9) && (mapa5[linha_atual][coluna_atual] != 7)) {

                linha_atual = linha_atual + 1;
                
            }
        }

        if ((movimento == 's') || (movimento == 'S')) {
            linha_atual = linha_atual + 1;

            if ((mapa5[linha_atual][coluna_atual] != 0) && (mapa5[linha_atual][coluna_atual] != 6) && (mapa5[linha_atual][coluna_atual] != 9)&&(mapa5[linha_atual][coluna_atual] != 7)) {

                linha_atual = linha_atual - 1;
                
            }
        }

        if ((movimento == 'd') || (movimento == 'D')) {

            coluna_atual = coluna_atual + 1;

            if ((mapa5[linha_atual][coluna_atual] != 0) && (mapa5[linha_atual][coluna_atual] != 6) && (mapa5[linha_atual][coluna_atual] != 9)&&(mapa5[linha_atual][coluna_atual] != 7)) {

                coluna_atual = coluna_atual - 1;
               
            }
        }

        if ((movimento == 'a') || (movimento == 'A')) {

            coluna_atual = coluna_atual - 1;

            if ((mapa5[linha_atual][coluna_atual] != 0) && (mapa5[linha_atual][coluna_atual] != 6) && (mapa5[linha_atual][coluna_atual] != 9)&&(mapa5[linha_atual][coluna_atual] != 7)) {

                coluna_atual = coluna_atual + 1;

            }
        }

		if(player1.vida == 0){
			gameOver();
		}

        //Se enconstar no inimigo
        if (mapa5[linha_atual][coluna_atual] == 6) {
            coluna_atual = 1, linha_atual = 1;
            player1.vida--;        		
        }

		//Se pegar o player1.dinheiro
         if (mapa5[linha_atual][coluna_atual] == 7) {

			mapa5[linha_atual][coluna_atual] = 0;

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

			player1.dinheiro++;
        }

        //Se pegar o coração
        if (mapa5[linha_atual][coluna_atual] == 9) {

			mapa5[linha_atual][coluna_atual] = 0;
            

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

            if(player1.vida<3){   
            	player1.vida++;
			}	
        }

		if((movimento == 'x') || (movimento == 'X')) {
			menuPause();
		}
	}

	mapaAtual = 6;
	gameStart();

	system("clear");	
    return;
}

//CONSTROI MAPA 6
void mapa6() {

	mapaAtual = 6;

	//O desenho do mapa é feito a partir dos simbolos da matriz
	//Significado dos numeros:
	//0- vazio
	//1- parede
	//6- caveira
	//7- player1.dinheiro
	//9- player1.vida
    //8- trofeu

	int mapa6[20][30] = { 
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,
	0,0,0,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,7,0,0,8,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};

	int linha, coluna; 
	char movimento;

	while (linha_atual != 10 || coluna_atual != 29) {

		system("clear");

		for (linha=0;linha<20;linha++) {
    		for (coluna=0;coluna<30;coluna++) {
				if ((linha == linha_atual) && (coluna == coluna_atual)) {
            		printf("♔");
            		continue;
         		}

				if (mapa6[linha][coluna] == 0)
					printf("  ");

				if (mapa6[linha][coluna] == 1)
					printf("✲✲");

				if (mapa6[linha][coluna] == 7)
					printf("⍟ ");

				if (mapa6[linha][coluna] == 8)
					printf("🏆");

				if(mapa6[linha][coluna] == 6)  
					printf("☠ ");

                if(mapa6[linha][coluna] == 9)  
					printf("❤ ");     

			}
     	  	printf("\n");

        }

		printf("\t\tVIDAS: ");			
		for(int i = 0; i < player1.vida; i++){
			printf("❤ ");
		}

		printf("\t\t⍟ : %d", player1.dinheiro);
        printf("\t\tWORLD: %d", mapaAtual);

		printf("\n");

        movimento = getchar();

        if ((movimento == 'w') || (movimento == 'W')) {

            linha_atual = linha_atual - 1;

            //Se o personagem se movimentar para a parede, ele retorna pra posição onde estava
            if ((mapa6[linha_atual][coluna_atual] != 0) && (mapa6[linha_atual][coluna_atual] != 6) && (mapa6[linha_atual][coluna_atual] != 9) && (mapa6[linha_atual][coluna_atual] != 7) && (mapa6[linha_atual][coluna_atual] != 8)) {

                linha_atual = linha_atual + 1;
               
            }
        }

        if ((movimento == 's') || (movimento == 'S')) {
            linha_atual = linha_atual + 1;

            if ((mapa6[linha_atual][coluna_atual] != 0) && (mapa6[linha_atual][coluna_atual] != 6) && (mapa6[linha_atual][coluna_atual] != 9)&&(mapa6[linha_atual][coluna_atual] != 7)&& (mapa6[linha_atual][coluna_atual] != 8)) {

                linha_atual = linha_atual - 1;
                
            }
        }

        if ((movimento == 'd') || (movimento == 'D')) {

            coluna_atual = coluna_atual + 1;

            if ((mapa6[linha_atual][coluna_atual] != 0) && (mapa6[linha_atual][coluna_atual] != 6) && (mapa6[linha_atual][coluna_atual] != 9)&&(mapa6[linha_atual][coluna_atual] != 7) && (mapa6[linha_atual][coluna_atual] != 8)) {

                coluna_atual = coluna_atual - 1;
               
            }
        }

        if ((movimento == 'a') || (movimento == 'A')) {

            coluna_atual = coluna_atual - 1;

            if ((mapa6[linha_atual][coluna_atual] != 0) && (mapa6[linha_atual][coluna_atual] != 6) && (mapa6[linha_atual][coluna_atual] != 9)&&(mapa6[linha_atual][coluna_atual] != 7) && (mapa6[linha_atual][coluna_atual] != 8)) {

                coluna_atual = coluna_atual + 1;

            }
        }

		if(player1.vida == 0){
			gameOver();
		}

        //Se enconstar no inimigo
        if (mapa6[linha_atual][coluna_atual] == 6) {
            coluna_atual = 1, linha_atual = 1;
            player1.vida--;        		
        }

		//Se pegar o player1.dinheiro
         if (mapa6[linha_atual][coluna_atual] == 7) {

			mapa6[linha_atual][coluna_atual] = 0;

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

			player1.dinheiro++;
        }

        //Se pegar o coração
        if (mapa6[linha_atual][coluna_atual] == 9) {

			mapa6[linha_atual][coluna_atual] = 0;

            coluna_atual++;
			linha_atual++;
			coluna_atual--;
			linha_atual--;

            if(player1.vida<3){   
            	player1.vida++;
			}	
        }

		if((movimento == 'x') || (movimento == 'X')) {
			menuPause();
		}
	}

	mapaAtual = 7;
	gameStart();

	system("clear");	
    return;
}

//CREDITOS
void creditos() {
    
	system("clear");
    printf("###############################################################\n");
	printf("###############################################################\n");	
	printf("##################### Padawan Adventures ######################\n");
	printf("## \t                  CRÉDITOS                               ##\n");
	printf("## \t ------------------------------------------------------- ##\n");
    printf("## \t --  Jovem Padawan  ------------------------------------ ##\n");
	printf("## \t   Parece que não posso mais te chamar                   ##\n");	
	printf("## \t de jovem, não é mesmo ?                                 ##\n");
	printf("## \t Agora, que já coletou todas as moedas, assim como       ##\n");	
	printf("## \t foi ordenado, e que conseguiu conquistar o tao sonhado  ##\n");
	printf("## \t troféu, jovem não seria o termo correto.                ##\n");
    printf("## \t                                                         ##\n");
	   
   
    sleep(5);

	printf("##															 ##\n");
	printf("## \t                                                         ##\n");
	printf("## \t  Então, acho que posso te poupar da espera !! :D        ##\n");
    printf("## \t                                                         ##\n");
	printf("## \t  Parabéns, Te nomeio (não mais jovem) :::               ##\n");	
	printf("## \t                     JEDI !!!!!                          ##\n");
	printf("## \t                                                         ##\n");	
	printf("## \t  Espero que honre sua nova conquista,  e mostre         ##\n");
	printf("## \t  para o universo inteiro do que somos capazes !!!       ##\n");
    printf("## \t                              Vejo voce em breve....     ##\n");
	printf("## \t                                                         ##\n");
	printf("###############################################################\n");
	printf("###############################################################\n");

	sleep(15);

	system("clear");
	
    printf("###############################################################\n");
	printf("###############################################################\n");	
	printf("##################### Padawan Adventures ######################\n");
	printf("## \t                  CRÉDITOS                               ##\n");
	printf("## \t ------------------------------------------------------- ##\n");
    printf("## \t --  Desenvolvedores ----------------------------------- ##\n");
	printf("## \t	Camila Braga                   \\o/                   ##\n");	
	printf("## \t	Francisco Morais               			\\o/		     ##\n");
	printf("## \t 	João Vitor									   \\o/   ##\n");	
	printf("## \t 													  	 ##\n");
	printf("## \t 													  	 ##\n");
    printf("## \t             © UAE Games Nenhum Direito Reservado        ##\n");
	printf("###############################################################\n");
	printf("###############################################################\n");

	sleep(15);

	char tmp;
    printf("\nPressione qualquer tecla para continuar...");
	scanf(" %c", &tmp);

	menu();

	return;
	
}

//EXIBE UM MENU DOS CONTROLES DO PERSONAGEM
void controles() {

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
	printf("## \t   W  - Ir para cima          ##\n");
	printf("## \t   A  - Ir para esquerda      ##\n");	
	printf("## \t   S  - Ir para baixo         ##\n");
    printf("## \t   D  - Ir para direita       ##\n");	
	printf("##                                ##\n");
	printf("## \t X - Pause         	          ##\n");	
   	printf("## \t ENTER - Confimação da opcao  ##\n");
	printf("##                                ##\n");

	for(int i=0;i<36;i++){
		printf("#");
	}

	char tmp;
	printf("\n- Pressione qualquer tecla para voltar ao Menu\n");
	scanf(" %c", &tmp);

	menu();

	return;
}

//CASO A VIDA DO PLAYER SEJA 0, A FUNÇÃO SERÁ CHAMADA
void gameOver(){

	system("clear");

	for(int i = 0; i < 36; i++){
		printf("#");
	} printf("\n");

	printf("##                                ##\n");
	printf("## \t\t   GAME OVER :(           ##\n");	   
	printf("##           💀 💀 💀                ##\n");
	printf("## \t  Better luck next time!      ##\n");	
	printf("## \t	                          ##\n");		

	for(int i=0;i<36;i++){
		printf("#");
	}

	char tmp;
	printf("\nPressione qualquer tecla para continuar\n");
	scanf(" %c", &tmp);

	menu();

	return;	
}