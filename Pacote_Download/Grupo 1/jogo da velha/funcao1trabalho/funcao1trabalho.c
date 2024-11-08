#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
#include<locale.h>
#include<stdbool.h>
/* Função 1 teste para programa trabalho em grupo
  fonte exemplo grupo 1
  Aluna Fernanda */

const int vlin[3]={6,8,10};
const int vcol[3]={11,13,15};

void linhacol(int lin, int col)
{           //para posicionar o cursor numa linha e numa coluna
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) {col-1,lin-1});
   }
void box(int lin1, int col1, int lin2, int col2){
   int i, tamlin, tamcol;
   tamlin=lin2-lin1;
   tamcol=col2-col1;
   for(i=col1; i<=col2; i++){
   	linhacol(lin1, i); printf("%c",196);
   	linhacol(lin2, i); printf("%c",196);
   }
   for(i=lin1;i<=lin2;i++){
   	linhacol(i,col1); printf("%c",179);
   	linhacol(i,col2); printf("%c",179);
   }
   linhacol(lin1,col1); printf("%c",218);
   linhacol(lin1,col2); printf("%c",191);
   linhacol(lin2,col1); printf("%c",192);
   linhacol(lin2,col2); printf("%c",217);
}
void redesenha(char v[3][3]){
       int i,j;
       for(i=0;i<3;i++){
       	for(j=0;j<3;j++){
       		linhacol(vlin[i],vcol[j]); printf("%c",v[i][j]);
		   }
	   }
}
bool continua(void){ //usuário deseja continuar s/n
     char c;
     linhacol(14,10);
     printf("Continua? (s/n)");
     do{
     	linhacol(14,26); scanf("%c",&c);
	 }while(c!='n' && c!='N' && c!='s' && c!='S' );
     linhacol(14,10);
     printf("               ");
    return(c=='s'|| c=='S'); 
}

char ganhou(char v[3][3]){//recebe as matriz de jogadas,analisa essa matriz e retorna se ganhou,empatou...
    int i,j;
    for(i=0;i<3;i++){//alguém ganhou nas linhas?
    	if(v[i][0]=='X'&&v[i][1]=='X'&&v[i][2]=='X'){
    		return'X';
		}
		else if(v[i][0]=='O'&&v[i][1]=='O'&&v[i][2]=='O'){
			return 'O';
		}
	}
	for(i=0;i<3;i++){//Alguém ganhou nas colunas??
	if(v[0][i]=='X'&&v[1][i]=='X'&&v[2][i]=='X'){
		return'X';
	}
	else if(v[0][i]=='O'&&v[1][i]=='O'&&v[2][i]=='O'){
		return 'O';
	}
	}
	if(v[0][0]=='X'&&v[1][1]=='X'&&v[2][2]=='X'){ //Alguém ganhou nas diagonais??
		return 'X';
	}
	else if(v[0][0]=='O'&&v[1][1]=='O'&&v[2][2]=='O'){
		return 'O';
	}
	if(v[0][2]=='X'&&v[1][1]=='X'&&v[2][0]=='X'){
		return 'X';
	}
	else if(v[0][2]=='O'&&v[1][1]=='O'&&v[2][0]=='O'){
		return 'O';
	}
	for(i=0;i<3;i++){ //ninguém ganhou ainda tem alguma jogada restante?(ou já preencheu todas)
		for(j=0;j<3;j++){
			if(v[i][j]==' ') return ' ';
		}
	}
	return 'E';//default para empate
}
void jogacomputador(char v[3][3]){
     int linha, coluna, i;
     for(i=0;i<5;i++){
     	 linha=rand()%3;
         coluna=rand()%3;
         if(v[linha][coluna]==' ') break;
	 }
     if(i==6){//procura por força bruta
     	for(linha=0;linha<3;linha++){
     		for(coluna=0;coluna<3;coluna++){
     			if(v[linha][coluna]==' ') break;
			 }
			 if(v[linha][coluna]==' ') break;
		 }
	 }
	 v[linha][coluna]='O';
	 redesenha(v);
}
void jogausuario(char v[3][3]){
	int linha, coluna;
	char entrada[10];
	linhacol(16,4);
	printf("Escolha a linha:  ");
	linhacol(17,4);
	printf("Escolha a coluna:  ");
	while(1){
	linhacol(16, 22);
        fgets(entrada, sizeof(entrada), stdin); // Lê a linha inteira
        
        if (sscanf(entrada, "%d", &linha) != 1) {
            continue;
        }
        linhacol(17, 22);
        fgets(entrada, sizeof(entrada), stdin); 
        if (sscanf(entrada, "%d", &coluna) != 1) {
            continue;
        }
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            continue;
        }
        if (v[linha][coluna] == ' ') {
            break;
        }
    }
	linhacol(16,4); printf("                 ");
	linhacol(16,4); printf("                 ");
	v[linha][coluna]='X';
	redesenha(v);
}

int main() {
	char v[3][3]={{' ',' ',' '}, //onde vai estar os simbolos do jogo da velha
	              {' ',' ',' '},
				  {' ',' ',' '}}, quemganhou=' ';
    bool inicia;
    int placar[2]={0,0}, i, j;
    float porcentagem;
    srand(time(NULL));
    inicia=rand()%2;
    //Monta a tela
    box(1,1,3,50);
    linhacol(2,3);printf("Jogo da velha!!");
    linhacol(6,12);printf("%c",179); //desenha o jogo da velha a #
    linhacol(6,14);printf("%c",179);
    linhacol(7,11);printf("%c%c%c%c%c",196, 197, 196, 197,196);
    linhacol(8,12);printf("%c",179);
    linhacol(8,14);printf("%c",179);
    linhacol(9,11);printf("%c%c%c%c%c",196,197,196,197,196);
    linhacol(10,12);printf("%c",179);
    linhacol(10,14);printf("%c",179);
    box(20,1,22,50); //mostra o placar
    linhacol(21,3);
    printf("Placar: 0 usuario X computador 0(0%%)");
    setlocale(LC_ALL, "Portuguese");
    //LAÇO PRINCIPAL(DO JOGO)
    do{
    for(i=0;i<3;i++){
    	for(j=0;j<3;j++) v[i][j]=' ';
	}
	quemganhou=' ';
	redesenha(v);
	linhacol(13,10);
	printf("                ");
	//laço da partida
	do{
		if(inicia){
			jogausuario(v);
			quemganhou=ganhou(v);
			if(quemganhou!=' ') break;
			jogacomputador(v);
			quemganhou=ganhou(v);
			if(quemganhou!=' ') break;
		}
		else{
			jogacomputador(v);
			quemganhou=ganhou(v);
			if(quemganhou!=' ') break;
			jogausuario(v);
			quemganhou=ganhou(v);
			if(quemganhou!=' ') break;
		}
	}while(quemganhou==' ');
	//placar
	if(quemganhou=='X'){
		linhacol(13,10);
		printf("Voce ganhou!!!    ");
		placar[0]++;
	}
	else if(quemganhou=='O'){
		linhacol(13,10);
		printf("O computador ganhou!!   ");
		placar[1]++;
	}
	else{
		linhacol(13,10);
		printf("Empatou!!    ");
	}
	     inicia= !inicia;//inverte o valor aquele que é inicia
	     porcentagem=(float) placar[0]/(placar[0]+placar[1])*100;
	    linhacol(21,3);
	    printf("                                  ");
	     linhacol(21,3);
    	printf("Placar:%d usuario X computador %d (%.1f%%)",placar[0],placar[1],porcentagem);
	}while(continua()); //é uma função boleana, vai retornar true( se é pra continuar o jogo)ou false(se vai interromper)
	linhacol(25,1); printf(".");
	return 0;
}
