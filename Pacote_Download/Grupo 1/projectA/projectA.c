#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
// Função para formato de texto
#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"
// Função para estilização cor de texto
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
//define da função cafeteria
#define MAX_PEDIDOS 50
#define MAX_NOME_COMPRIMENTO 50
#define MAX_ITEM_COMPRIMENTO 50
//Função sleep
void encerramento(){
int i;

sleep(1);  i=0;
for(i=0;i<=50;i++)
printf("%c",32);
printf("ENCERRANDO.");
sleep(1);  printf(".");
sleep(1);  printf(".\n");
sleep(1);  printf("\n\n\n\n\t\tIntegrantes do grupo\n\n");
sleep(1);  printf("\t\tGuilherme Pavani\n");
sleep(1);  printf("\t\tFernanda Prestes\n");
sleep(1);  printf("\t\tJonathas Seri\n");
sleep(1);
}
// FUNÇÕES DE TEXTO
void go(int x, int y) {
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
void desenhar_campo() {
    setlocale(LC_ALL, "C");
    
    int i, xi=10, yi=3, xf=110, yf=25;
    for (i = yi; i < yf; i++)
    {
        go(xi, i);
        Sleep(1); puts("\xDB");
        go(xf, i);
        Sleep(1); puts("\xDB"); }
    for (i = xi; i < xf; i++)
    {
        go(i, yi);
        Sleep(1); puts("\xDB");
        go(i, yf);
        Sleep(1); puts("\xDB"); }
    go(xf, yi);
    Sleep(1); puts("\xDB");   // canto superior direito
    go(xi, yf);
    Sleep(1); puts("\xDB");   // inferior esquerdo
    go(xi, yi);
    Sleep(1); puts("\xDB");   // canto superior esquerdo
    go(xf, yf);
    Sleep(1); puts("\xDB");   // inferior direito
    setlocale(LC_ALL, "Portuguese");
}
void cabecalho(char *texto) {
    int len = strlen(texto), i, wid = 120;
    puts("\n\n\n");
    for (i=0; i<=(wid-len)/2; i++)
        fputs(" ", stdout); 
    fputs(texto, stdout);
}
void mudar_cor() {
    int opcao;
    do {
    cabecalho("Qual cor você gostaria no programa?\n");
    puts("\n\t\t 1 - Preto com letras Verdes");
    puts("\t\t 2 - Preto com letras Azuis");
    puts("\t\t 3 - Preto com letras Roxas");
    puts("\t\t 4 - Preto com letras Vermelhas");
    puts("\t\t 5 - Escolha Padrão");
    puts("\n\t\t 0 - Seguir para o Menu Principal");
    desenhar_campo();
    go (20, 18); printf("Opção: ");  scanf("%d", &opcao);
    fflush(stdin); system("cls");
    switch (opcao) {
        case 1: system(GREEN); break;
        case 2: system(BLUE); break;
        case 3: system(MAGENTA); break;
        case 4: system(RED); break;
        case 5: system(RESET); break;
        case 0: break;
        default: opcao_invalida(); break; }
    system("cls");
    } while (opcao!= 0);
}
int opcao_invalida() {
    cabecalho("\n\n\t\t\t\t\t  Resposta Inválida, Tente Novamente   \n");
    go(41, 18); puts("Pressione <ENTER> para retornar ao menu.");
    desenhar_campo();
    getch(); }
//função jogo da velha
const int vlin[3]={6,8,10};
const int vcol[3]={11,13,15};

void linhacol(int lin, int col)
{           //para posicionar o cursor numa linha e numa coluna
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) {col-1,lin-1});
   }
void box(int lin1, int col1, int lin2, int col2){
setlocale(LC_ALL, "C");
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
        linhacol(vlin[i],vcol[j]); printf("%c",v[i][j]); }   }
}
bool continua(void){ //usuário deseja continuar s/n
     char c;
     linhacol(14,10);
     printf("Continuar? (s/n)");
     do{
      linhacol(14,26); scanf("%1c",&c); 
}while(c!='n' && c!='N' && c!='s' && c!='S' );
if(c=='n'||c=='N'){
system("cls");
printf("Retornando ao menu principal...\n");
Sleep(1000);
return false;
}
     linhacol(14,10);  printf("               ");
    if(c=='s'|| c=='S');
    printf("                   ");
return true; 
}
char ganhou(char v[3][3]) {  //recebe as matriz de jogadas,analisa essa matriz e retorna se ganhou,empatou...
    int i,j;
    for(i=0;i<3;i++) {  //alguém ganhou nas linhas?
        if(v[i][0]=='X'&&v[i][1]=='X'&&v[i][2]=='X') {
             return'X'; }
        else if(v[i][0]=='O'&&v[i][1]=='O'&&v[i][2]=='O') {
             return 'O'; }
    }
    for(i=0;i<3;i++){//Alguém ganhou nas colunas??
        if(v[0][i]=='X'&&v[1][i]=='X'&&v[2][i]=='X'){
             return'X'; }
        else if(v[0][i]=='O'&&v[1][i]=='O'&&v[2][i]=='O') {
             return 'O'; }
    }
    if(v[0][0]=='X'&&v[1][1]=='X'&&v[2][2]=='X'){ //Alguém ganhou nas diagonais??
        return 'X'; }
    else if(v[0][0]=='O'&&v[1][1]=='O'&&v[2][2]=='O'){
        return 'O'; }
    if(v[0][2]=='X'&&v[1][1]=='X'&&v[2][0]=='X'){
        return 'X'; }
    else if(v[0][2]=='O'&&v[1][1]=='O'&&v[2][0]=='O'){
        return 'O'; }
    for(i=0;i<3;i++) { //ninguém ganhou ainda tem alguma jogada restante?(ou já preencheu todas)
        for(j=0;j<3;j++){
            if(v[i][j]==' ') return ' '; }
        }
        return 'E';//default para empate
     }
void jogacomputador(char v[3][3]){
     int linha, coluna, i;
     for(i=0;i<5;i++) {
         linha=rand()%3;
         coluna=rand()%3;
         if(v[linha][coluna]==' ') break;
        }
     if(i==6){//procura por força bruta
      for(linha=0;linha<3;linha++){
           for(coluna=0;coluna<3;coluna++){
              if(v[linha][coluna]==' ') break; }
           if(v[linha][coluna]==' ') break;  }
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
           if (sscanf(entrada, "%d", &linha, stdin) != 1) {
            continue;   }
     linhacol(17, 22);
        fgets(entrada, sizeof(entrada), stdin); 
           if (sscanf(entrada, "%d", &coluna) != 1) {
            continue;   }
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            continue;   }
        else if (v[linha][coluna] == ' ') {
            break;  }
     }
linhacol(16,4); printf("                 "); 
linhacol(17,4); printf("                 "); 
linhacol(16,22); printf("                 ");
linhacol(17,22); printf("                  ");
v[linha][coluna]='X';
redesenha(v);
}
 int jogodavelha() {
char v[3][3]={{' ',' ',' '}, //onde vai estar os simbolos do jogo da velha
              {' ',' ',' '},
              {' ',' ',' '}}, quemganhou=' ';
    bool inicia;
    int placar[2]={0,0}, i, j, resp;
    float porcentagem;
    srand(time(NULL));
    inicia=rand()%2;
    box(1,1,3,50); //Monta a tela
    linhacol(2,3);printf("Jogo da velha!!");
    printf("\n\nDeseja voltar ao menu principal?SIM[1]/NAO[2]"); scanf("%d",&resp);
    switch(resp){
    case 1: return 0;
    default: break;
}
	linhacol(4,1);printf("                                                  ");
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
    printf("\n\n-->Digite APENAS 1 numero de cada vez, linha e coluna de 0 a 2\n");
    setlocale(LC_ALL, "Portuguese");
    //LAÇO PRINCIPAL(DO JOGO)
    do{
      for(i=0;i<3;i++){
        for(j=0;j<3;j++) v[i][j]=' ';  }
      quemganhou=' ';
      redesenha(v);
      linhacol(13,10);
      printf("                ");
    do{    //laço da partida
     if(inicia){
        jogausuario(v);
        quemganhou=ganhou(v);
         if(quemganhou!=' ') break;
        jogacomputador(v);
        quemganhou=ganhou(v);
         if(quemganhou!=' ') break; }
     else{
       jogacomputador(v);
       quemganhou=ganhou(v);
       if(quemganhou!=' ') break;
       jogausuario(v);
       quemganhou=ganhou(v);
       if(quemganhou!=' ') break; }
}while(quemganhou==' ');
    if(quemganhou=='X'){   //placar
      linhacol(13,10);
       printf("Voce ganhou!!!    ");
      placar[0]++; }
    else if(quemganhou=='O'){
      linhacol(13,10);
      printf("O computador ganhou!!   ");
      placar[1]++; }
    else{
      linhacol(13,10);
      printf("Empatou!!    "); }
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
//fim função jogo da velha
//inicio da função cafeteria
struct Pedido {
    int numeroMesa;
    char nomeCliente[MAX_NOME_COMPRIMENTO];
    char item[MAX_ITEM_COMPRIMENTO];
    char metodoPagamento[20];
    int numeroPessoas;
};
struct Pedido pedidos[MAX_PEDIDOS];
int totalPedidos = 0;

void fazerPedido() {
    if (totalPedidos >= MAX_PEDIDOS) {
        printf("Numero maximo de pedidos atingido.\n");
        return;  }
    struct Pedido novoPedido;
    printf("Digite o numero da mesa: ");
    scanf("%d", &novoPedido.numeroMesa);
    printf("Digite o nome do cliente: ");
    scanf("%s", novoPedido.nomeCliente);
    printf("Digite o item pedido: ");
    scanf("%s", novoPedido.item);
    printf("Digite o metodo de pagamento: ");
    scanf("%s", novoPedido.metodoPagamento);
    printf("Digite o numero de pessoas: ");
    scanf("%d", &novoPedido.numeroPessoas);
    pedidos[totalPedidos++] = novoPedido;
    printf("Pedido realizado com sucesso.\n");
}
void exibirPedidos() {
	int i;
    if (totalPedidos == 0) {
        printf("Nenhum pedido realizado ainda.\n");
        return; }
    printf("Todos os pedidos:\n");
    printf("%-10s %-20s %-20s %-20s %-15s\n", "Nº Mesa", "Nome Cliente", "Item", "Metodo Pagamento", "Nº Pessoas");
    for (i = 0; i < totalPedidos; ++i) {
        printf("%-10d %-20s %-20s %-20s %-15d\n", pedidos[i].numeroMesa, pedidos[i].nomeCliente,
               pedidos[i].item, pedidos[i].metodoPagamento, pedidos[i].numeroPessoas);  }
}
int cafeteria() {
    int escolha;
    int invalido = 0;
    do {
    	fflush(stdin);
        printf("\nSistema de Pedidos da Cafeteria\n");
        printf("\n1. Fazer um pedido\n");
        printf("2. Exibir todos os pedidos\n");
        printf("3. Sair\n");
        if(invalido == 1)
 			printf("\n\nEscolha invalida. Por favor, digite uma opcao valida.\n");
 			
        printf("\nDigite sua escolha: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                fazerPedido();
                break; 
            case 2:
                exibirPedidos();
                break;
            case 3:
                printf("Saindo...\n"); sleep(1);
                break;
            default:
            	invalido = 1;
            	break;
        }
    
    } while (escolha != 3);

    return 0;
}
//fim função cafeteria
// PROGRAMA PRINCIPAL
int main() {
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    mudar_cor();
    int resp, opcao;   
    do {
        cabecalho("M E N U   P R I N C I P A L");                   // Primeiro looping - menu principal
        puts("\n\n\n\t\tEscolha a opção desejada:\n");
        puts("\t\t 1 - Jogo da velha");
        puts("\t\t 2 - Cafeteria");
        puts("\t\t 3 - Sair");
        desenhar_campo();
        go (20, 18); printf("Opção: ");  scanf("%d", &opcao);
        fflush(stdin); system("cls");                               // Limpa o buffer do teclado e limpa a tela
        switch (opcao) {                                            // Direcionamento para o menu escolhido
            case 1:                                             
                jogodavelha();
                break;
			case 2:
			    cafeteria();                                               
            case 3: break;
            default: opcao_invalida(); break; }                     // Fecha o switch do menu principal
        system("cls");
    } while (opcao!=3);                                            // Condição para fechar o programa
    encerramento();
    desenhar_campo(); 
   
    return 0;
}
