#include <stdio.h>
#include <stdlib.h>

#define CHAO 0
#define PAREDE 1
#define VOCE 2
#define GRAMA 3
#define OUTRA_COISA 4

//DECLARAR FUNÇÕES
int menu();
void gameStart();
void controles();
void mapa1();

//VARIAVEIS GLOBAIS
int coluna_atual = 1, linha_atual = 1;
char escolha = '1';
int vida = 3, dindin=0;


int main() {

	system("clear");
	menu();

	return 0;
}

//MENU DO JOGO
int menu(){
   
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
	printf("## \t4. Sair          		      ##\n");	
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
			break;

		default:
			menu();
			break;
      
  	}

	return 0;
}

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
	printf("## \t ↑ - Ir para cima             ##\n");
	printf("## \t ← - Ir para esquerda         ##\n");	
	printf("## \t → - Ir para direita          ##\n");	
	printf("## \t ↓ - Ir para baixo            ##\n");	
	printf("## \t ESC - Opções         	      ##\n");	
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

	return;
}

void gameStart(){

	system("clear");

	//historinha
	mapa1();

	return;
}

//MAPA1
void mapa1 (){
    
	//O desenho do mapa é feito a partir dos simbolos da matriz
	int mapa1[20][30] = { 
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
	1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,0,6,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,9,0,0,0,0,1,
	1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,
	1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,6,0,0,1,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
	1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,
	1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
	1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
	1,7,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,
	1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};
	
	int linha,coluna;
	
	char movimento;
   
	while ((movimento != 'x') && (movimento != 'X')) {
		
		system("clear");
	
		if(vida == 3){
			printf("vidas: ❤ ❤ ❤\n");
		}

		if(vida == 2){
			printf("vidas: ❤ ❤\n");
		}

		if(vida == 1){
			printf("vidas: ❤\n");
		}
 
		if(vida == 0) {
			printf("GAME OVER!");
		}

		//0- vazio
		//1- parede

		//5- saída
		//6- caveira
		//7- dinheiro
		
		//9- vida


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
					printf(" $");
				
				if (mapa1[linha][coluna] == 8)
					printf("+");
				
				if(mapa1[linha][coluna] == 5)
					printf("  → ");
					
				if(mapa1[linha][coluna]==6)  
					printf("☠ ");
                if(mapa1[linha][coluna]==9)  
					printf("❤ ");     
			}
      
	  	printf("\n");
   }
 
	printf("\n\n  (W)\n(A)+(D)\n  (S)\n\n"); /* Imprime as direcoes */
	
	/*
	if ((scanf("%c",&movimento))==0) {
        printf("mensagem de erro..\n");
        getchar(); getchar();
    }
	*/
    
	movimento = getchar();

      if ((movimento == 'w') || (movimento == 'W')) {
         linha_atual = linha_atual - 1;
         /* Se não for chao ou grama ele volta pra posicao anterior */
         if ((mapa1[linha_atual][coluna_atual] != CHAO) && (mapa1[linha_atual][coluna_atual] != GRAMA)&& (mapa1[linha_atual][coluna_atual] != 6)&&(mapa1[linha_atual][coluna_atual] != 9)) {
            linha_atual = linha_atual + 1;
            printf("\n\nups.. ali não =)\n");
            getchar(); getchar();
         }
      }
      if ((movimento == 's') || (movimento == 'S')) {
         linha_atual = linha_atual + 1;
         /* Se não for chao ou grama ele volta pra posicao anterior */
         if ((mapa1[linha_atual][coluna_atual] != CHAO) && (mapa1[linha_atual][coluna_atual] != GRAMA)&& (mapa1[linha_atual][coluna_atual] != 6)&&(mapa1[linha_atual][coluna_atual] != 9)) {
            linha_atual = linha_atual - 1;
            printf("\n\nups.. ali não =)\n");
            getchar(); getchar();
         }
      }
      if ((movimento == 'd') || (movimento == 'D')) {
         coluna_atual = coluna_atual + 1;
         /* Se não for chao ou grama ele volta pra posicao anterior */
         if ((mapa1[linha_atual][coluna_atual] != CHAO) && (mapa1[linha_atual][coluna_atual] != GRAMA) &&  (mapa1[linha_atual][coluna_atual] != 6)&&(mapa1[linha_atual][coluna_atual] != 9)) {
            coluna_atual = coluna_atual - 1;
            printf("\n\nups.. ali não =)\n");
            getchar(); getchar();
         }
      }
      if ((movimento == 'a') || (movimento == 'A')) {
         coluna_atual = coluna_atual - 1;
         /* Se não for chao ou grama ele volta pra posicao anterior */
         if ((mapa1[linha_atual][coluna_atual] != CHAO) && (mapa1[linha_atual][coluna_atual] != GRAMA )&& (mapa1[linha_atual][coluna_atual] != 6)&&(mapa1[linha_atual][coluna_atual] != 9)) {
            coluna_atual = coluna_atual + 1;
            printf("\n\nups.. ali não =)\n");
            getchar(); getchar();
         }
      }


    if (mapa1[linha_atual][coluna_atual] == 6) {
            		//printf("\n-1 Vida ");
					coluna_atual = 1, linha_atual = 1;
                    vida--;
            		
    }
    if (mapa1[linha_atual][coluna_atual] == 9) {
            		//printf("\n-1 Vida ");
                    coluna_atual++;
                    linha_atual++;
					
                    vida++;
            		
    }
   
	}
	
	return;
}

//FINAL