#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
//Função sleep
void encerramento(){
int i;
for(i=0;i<=119;i++)
printf("%c",220);
sleep(1);  i=0;
for(i=0;i<=50;i++)
printf("%c",32);
printf("ENCERRANDO.");
sleep(1);  printf(".");
sleep(1);  printf(".\n");
sleep(1);
}

// Função para formato de texto
#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"
#define REVERSE "\x1b[7m"

// Função para estilização cor de texto
#define RESET "\x1b[0m"
#define BLACKF "\x1b[30m"
#define REDF "\x1b[31m"
#define GREENF "\x1b[32m"
#define YELLOWF "\x1b[33m"
#define BLUEF "\x1b[34m"
#define MAGENTAF "\x1b[35m"
#define CYANF "\x1b[36"
#define WHITEF "\x1b[37"

// Função para estilização cor de fundo
#define RESET "\x1b[0m"
#define BLACK "\x1b[40m"
#define RED "\x1b[41m"
#define GREEN "\x1b[42m"
#define YELLOW "\x1b[43m"
#define BLUE "\x1b[44m"
#define MAGENTA "\x1b[45m"
#define CYAN "\x1b[46"
#define WHITE "\x1b[47"


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
        puts("\xDB");
        go(xf, i);
        puts("\xDB"); }

    for (i = xi; i < xf; i++)
    {
        go(i, yi);
        puts("\xDB");
        go(i, yf);
        puts("\xDB"); }

    go(xf, yi);
    puts("\xDB");   // canto superior direito
    go(xi, yf);
    puts("\xDB");   // inferior esquerdo
    go(xi, yi);
    puts("\xDB");   // canto superior esquerdo
    go(xf, yf);
    puts("\xDB");   // inferior direito
    
    setlocale(LC_ALL, "Portuguese"); 
}

void cabecalho(char *texto) {
    int len = strlen(texto), i, wid = 120;
    puts("\n\n\n");
    for (i=0; i<=(wid-len)/2; i++)
        fputs(" ", stdout);  
    fputs(texto, stdout); 
}

void rodape() {
    puts("\n\n");
    go(41, 18); puts("Pressione <ENTER> para retornar ao menu.");
    getch(); }

void opcao_invalida() {
    puts(RED BOLD UNDERLINE"\n\n *****************************  O P Ç Ã O    I N V Á L I D A  ***************************** \n" RESET);
    go(41, 18); puts("Pressione <ENTER> para retornar ao menu.");
    getch(); }

void mudar_cor() {
    int opcao;
    
    do {
    cabecalho("Qual cor você gostaria no programa?\n");
    puts("\n\t\t 1 - Preto com letras Verdes");
    puts("\t\t 2 - Preto com letras Azuis");
    puts("\t\t 3 - Preto com letras Roxas");
    puts("\t\t 4 - Preto com letras Amarelas");
    puts("\t\t 5 - Escolha Padrão");
    puts("\n\t\t 0 - Seguir para o Menu Principal");
    desenhar_campo();
    go (20, 18); printf("Opção: ");  scanf("%d", &opcao);
    
    fflush(stdin); system("cls");
    
    switch (opcao) {
        case 1: system("color 0A"); break;
        case 2: system("color 09"); break;
        case 3: system("color 05"); break;
        case 4: system("color 06"); break;
        case 5: system("color 0F"); break;
        case 0: break;
        default: opcao_invalida(); break; }

    system("cls");
    } while (opcao!= 0); 
}

// FUNÇÕES DE CÁLCULO DE ÁREA DE FIGURAS PLANAS

float circulo() {                                           // Função que calcula a área do círculo
    float r, area, PI, dia;
    go (20, 6); printf("Digite o diâmetro do círculo: ");
    scanf("%f", &dia);
    PI = 3.14159265;
    r = dia/2;
    area = PI*r*r;
    go (20, 11); printf(">>>  A área do círculo é: %.3f", area);
    return; }

float losango() {                                           // Função que calcula a área do losango
    float area, D1, D2;
    go (20, 6); printf("Digite a diagonal 1: "); scanf("%f", &D1);
    go (20, 7); printf("Digite a diagonal 2: "); scanf("%f", &D2);
    area = (D1*D2) /2;
    go (20, 11); printf(">>>  A área do losango é: %.3f", area);
    return; }

float paralelogramo() {                                     // Função que calcula a área do paralelogramo
    float area, alt, base;
    go (20, 6); printf("Digite a base: "); scanf("%f", &base);
    go (20, 7); printf("Digite a altura: "); scanf("%f", &alt);
    area = base*alt;
    go (20, 11); printf(">>> A área do paralelogramo é: %.3f", area);
    return; }
     
float trapezio() {                                          // Função que calcula a área do trapézio
    float area, B, base, alt;
    go (20, 6); printf("Digite a base maior: "); scanf("%f", &B);
    go (20, 7); printf("Digite a base menor: "); scanf("%f", &base);
    go (20, 8); printf("Digite a altura: "); scanf("%f", &alt);
    area = ((B+base)/2)*alt;
    go (20, 11); printf(">>> A área do trapézio é: %.3f", area);
    return; }

int pitagoras(float A, float B, float C) {                  // Função para checar se o triângulo é retângulo
    if (A > B && A > C)
        return (pow(A,2) == (pow(B,2) + pow(C,2)));
    else if (B > A && B > C)
        return (pow(B,2) == (pow(A,2) + pow(C,2)));
    else if (C > A && C > B)
        return (pow(C,2) == (pow(A,2) + pow(B,2)));
    else return 0; }

float tri_equi(float A) {                                   // Função que calcula a área do triângulo equilátero
    float area;
    area = ((A*A) /4)*1.732050808;
    go (20, 11); printf("Triângulo Equilátero >>> área: %.3f", area);
    return; }

float tri_ret(float A, float B, float C) {                  // Função que calcula a área do triângulo retângulo
    float area;
    if (A > B && A > C)
        area = (B*C) /2;
    else if (B > A && B > C)
        area = (A*C) /2;
    else
        area = (A*B) /2;
    go (20, 11); printf("Triângulo Retângulo >>> área: %.3f", area);
    return; }

float tri_iso(float A, float B, float C) {                  // Função que calcula a área do triângulo isósceles
    float Base, Lado, h, area, b;
    if (A == B && A != C){
        Base = C; Lado = A; }
    else if (A == C && A != B){
        Base = B; Lado = A; }
    else{
        Base = A; Lado = B; }
    
    b = Base/2;
    h = sqrt(pow(Lado, 2) - pow(b, 2));
    area = (b * h) / 2;
    go (20, 11); printf("Triângulo Isósceles >>> área: %.3f", area);
    return; }

float tri_esc(float A, float B, float C) {                  // Função que calcula a área do triângulo escaleno
    float semi_perim, area;
    semi_perim = (A + B + C) / 2;
    area = sqrt(semi_perim* (semi_perim - A)* (semi_perim - B)* (semi_perim - C));
    go (20, 11); printf("Triângulo Escaleno >>> área: %.3f", area);
    return; }

int triangulo() {                                           // Função que separa qual tipo de triângulo pedido
    float A, B, C, area;
    go (20, 6); printf("Digite o lado A do triângulo: "); scanf("%f", &A);
    go (20, 7); printf("Digite o lado B do triângulo: "); scanf("%f", &B);
    go (20, 8); printf("Digite o lado C do triângulo: "); scanf("%f", &C);

    if (A < B+C && B < A+C && C < A+B) {
        if (A == B && B == C)
            tri_equi(A);
        else if (pitagoras(A, B, C))
            tri_ret(A, B, C);
        else if (A == B || B == C || C == A)
            tri_iso(A, B, C);
        else 
            area = tri_esc(A,B,C);
    } else {
        go (20, 11); printf("A figura informada não é um triângulo!"); } }

// FUNÇÕES DE CÁLCULO DE VOLUME DE SÓLIDOS GEOMÉTRICOS

float esf() {                                               // Função que calcula o volume da esfera
    float r, vol, dia;
    go (20, 6); printf("Digite o diâmetro: "); scanf("%f", &dia);
    r = dia /2;
    vol = ((4*3.14159265) /3)*r*r*r;
    go (20, 11); printf(">>> O volume da esfera é: %.3f",  vol);
    return; }
     
float cone() {                                              // Função que calcula o volume do cone
    float r, vol, dia, alt;
    go (20, 6); printf("Digite o diametro da base: "); scanf("%f",&dia);
    go (20, 8); printf("Digite altura: "); scanf("%f",&alt);
    r = dia/2;
    vol = (3.14159265 /3)*r*r*alt;
    go (20, 11); printf(">>> O volume do cone circular é: %.3f", vol );
    return; }
     
float cilindro() {                                          // Função que calcula o volume do cilindro
    float r, vol, dia, alt;
    go (20, 6); printf("Digite o diametro: "); scanf("%f",&dia);
    go (20, 7); printf("Digite altura: "); scanf("%f",&alt);
    r = dia/2;
    vol = 3.14159265*r*r*alt;
    go (20, 11); printf(">>> O volume do cilindro é: %.3f", vol);
    return; }

float paral() {                                             // Função que calcula o volume do paralelepípedo
    float vol, comp, larg, alt;
    go (20, 6); printf("Digite o comprimento: "); scanf("%f",&comp);
    go (20, 7); printf("Digite a largura: "); scanf("%f",&larg);
    go (20, 8); printf("Digite a altura: "); scanf("%f",&alt);
    vol = comp*larg*alt;
    go (20, 11); printf(">>> O volume do paralelepipedo é: %.3f",vol);
    return; }

// FUNÇÃO DE CÁLCULO DE CONVERSÃO DE MEDIDAS

float m_j() {                                               // Função que converte metros para jardas
    float total, num;
    go (20, 6); printf("Digite o valor em metros a ser convertido: "); scanf("%f", &num);
    total = num*1.09361;
    go (20, 11); printf("%.3f m = %.3f yd", num, total);
    return; }
                   
float j_m() {                                               // Função que converte jardas para metros
    float total, num;
    go (20, 6); printf("Digite o valor em jardas a ser convertido: "); scanf("%f", &num);
    total = num /1.09361;
    go (20, 11); printf("%.3f yd = %.3f m", num, total);
    return; }

float cmcub_polcub() {                                      // Função que converte centímetros cub para polegadas cub
    float total, num;
    go (20, 6); printf("Digite o valor em centimetros cubicos a ser convertido: "); scanf("%f", &num);
    total = num /16.387064;
    go (20, 11); printf("%.3f cm3 = %.3f in3", num, total);
    return; }

float polcub_cmcub() {                                      // Função que converte polegadas cub para centímetros cub
    float total, num;
    go (20, 6); printf("Digite o valor em polegadas cubicas a ser convertido: "); scanf("%f", &num);
    total = num*16.387064;
    go (20, 11); printf("%.3f in3 = %.3f cm3", num, total);
    return; }

float l_gl() {                                              // Função que converte litros em galões
    float total, num;
    go (20, 6); printf("Digite o valor em litros a ser convertido: "); scanf("%f", &num);
    total = num*0.2642;
    go (20, 11); printf("%.3f L = %.3f gal", num, total);
    return; }

float gl_l() {                                              // Função que converte galões em litros
    float total, num;
    go (20, 6); printf("Digite o valor em galoes a ser convertido: "); scanf("%f", &num);
    total = num/0.2642;
    go (20, 11); printf("%.3f gal = %.3f L", num, total);
    return; }

float kg_lib() {                                            // Função que converte quilos em libras
    float total, num;
    go (20, 6); printf("Digite o valor em quilogramas a ser convertido: "); scanf("%f", &num);
    total = num*2.20462262;
    go (20, 11); printf("%.3f kg = %.3f lb", num, total);
    return; }

float lib_kg() {                                            // Função que converte libras em quilos
    float total, num;
    go (20, 6); printf("Digite o valor em libras a ser convertido: "); scanf("%f", &num);
    total = num/2.20462262;
    go (20, 11); printf("%.3f lb = %.3f kg", num, total);
    return; }    

// FUNÇÃO DE SORTEAR DADOS

int dados (num) {                                           // Função para escolher um número aleatório
    int qt, i;
    do {
        go (20, 7); printf("Quantos números quer que sejam sorteados? (até 5) "); scanf("%d", &qt);
    } while (qt>5);

    for (i = 1; i<= qt; i++) {
        go (20, 9+i); printf("O número sorteado foi: %d", (1+ rand() % num));
    }
    return; }

// PROGRAMA PRINCIPAL

int main() {
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    mudar_cor();

    int opcao;    
    do {
                                                           
        cabecalho("M E N U   P R I N C I P A L");                   // Primeiro looping - menu principal
        puts("\n\n\n\t\tEscolha a opção desejada:\n");
           
        puts("\t\t 1 - Calcular área de figuras planas");
        puts("\t\t 2 - Calcular volume de sólidos geométricos");
        puts("\t\t 3 - Converter medidas");
        puts("\t\t 4 - Jogar Dados");
        puts("\t\t 5 - Sair");
        desenhar_campo();
        go (20, 18); printf("Opção: ");  scanf("%d", &opcao);
           
        fflush(stdin); system("cls");                               // Limpa o buffer do teclado e limpa a tela
           
        switch (opcao) {                                            // Direcionamento para o menu escolhido

            case 1:                                                 // Segundo looping - submenu 1 (Figuras Planas)
                do {

                cabecalho("ÁREA DE FIGURAS PLANAS");
                puts("\n\n\t Escolha a opção desejada:\n");
                puts("\t 1 - Círculo");
                puts("\t 2 - Losango");
                puts("\t 3 - Paralelogramo");
                puts("\t 4 - Trapézio");
                puts("\t 5 - Triângulo");
                puts("\t 0 - Retornar");
                desenhar_campo();
                go (20, 18); printf("Opção: ");  scanf("%d", &opcao);

                fflush(stdin); system("cls");

                switch(opcao) {

                    case 1:          
                        cabecalho("1. ÁREA DO CÍRCULO"); desenhar_campo();
                        circulo(); rodape(); break;

                    case 2:
                        cabecalho("2. ÁREA DO LOSANGO"); desenhar_campo();
                        losango(); rodape(); break;

                    case 3:
                        cabecalho("3. ÁREA DO PARALELOGRAMO"); desenhar_campo();
                        paralelogramo(); rodape(); break;

                    case 4:
                        cabecalho("4. ÁREA DO TRAPÉZIO"); desenhar_campo();
                        trapezio(); rodape(); break;

                    case 5:
                        cabecalho("5. ÁREA DO TRIÂNGULO"); desenhar_campo();
                        triangulo(); rodape(); break;

                    case 0: break;
             
                    default: opcao_invalida(); break; }             // Fecha o switch do submenu 1 (Figuras Planas)
           
                system("cls");
                } while (opcao!=0);                                 // Condição para voltar para o menu principal

                break;                                              // Fim do looping - submenu 1 (Figuras Planas)  
             
            case 2:                                                 // Terceiro looping - submenu 2 (Volume de Sólidos)
                do {
                   
                cabecalho("VOLUME DE SÓLIDOS GEOMÉTRICOS");        
                puts("\n\n\t Escolha a opção desejada:\n");
                puts("\t 1 - Esfera");
                puts("\t 2 - Cone Circular");
                puts("\t 3 - Cilindro");
                puts("\t 4 - Paralelepipedo");
                puts("\t 0 - Retornar");
                desenhar_campo();
                go (20, 18); printf("Opção: ");  scanf("%d", &opcao);

                fflush(stdin); system("cls");

                switch (opcao) {

                    case 1:
                        cabecalho("1. VOLUME DA ESFERA"); desenhar_campo();
                        esf(); rodape(); break;
           
                    case 2:
                        cabecalho("2. VOLUME DO CONE CIRCULAR"); desenhar_campo();
                        cone(); rodape(); break;
                   
                    case 3:
                        cabecalho("3. VOLUME DO CILINDRO"); desenhar_campo();
                        cilindro(); rodape(); break;
               
                    case 4:
                        cabecalho("4. VOLUME DO PARALELEPÍPEDO"); desenhar_campo();
                        paral(); rodape(); break;
                   
                    case 0: break;

                    default: opcao_invalida(); break; }             // Fecha o switch do submenu 2 (Volume de Sólidos)
           
                system("cls");
                } while (opcao!=0);                                 // Condição para voltar para o menu principal

                break;                                              // Fim do looping - submenu 2 (Volume de Sólidos)
       
            case 3:                                                 // Quarto looping - submenu 3 (Converter Medidas)
                do {

                cabecalho("CONVERTER MEDIDAS");
                puts("\n\n\t Escolha a opção desejada:\n");
                puts("\t Converter:\n");
                puts("\t 1 - Metros para Jardas\t\t\t\t\t 5 - Litros para Galões\n");
                puts("\t 2 - Jardas para Metros\t\t\t\t\t 6 - Galões para Litros\n");
                puts("\t 3 - Centímetros cúbicos para Polegadas cúbicas\t\t 7 - Quilogramas para Libras\n");
                puts("\t 4 - Polegadas cúbicas para Centímetros cúbicos\t\t 8 - Libras para Quilogramas\n");
                puts("\t 0 - Retornar");
                desenhar_campo();
                go (20, 18); printf("Opção: ");  scanf("%d", &opcao);
     
                fflush(stdin); system("cls");
          
                switch (opcao) {

                    case 1:
                        cabecalho("1. METROS EM JARDAS"); desenhar_campo();    
                        m_j(); rodape(); break;
               
                    case 2:
                        cabecalho("2. JARDAS EM METROS"); desenhar_campo();
                        j_m(); rodape(); break;
                 
                    case 3:
                        cabecalho("3. CENTÍMETROS CÚBICOS EM POLEGADAS CÚBICAS"); desenhar_campo();      
                        cmcub_polcub(); rodape(); break;
               
                    case 4:
                        cabecalho("4. POLEGADAS CÚBICAS EM CENTÍMETROS CÚBICOS"); desenhar_campo();
                        polcub_cmcub(); rodape(); break;
               
                    case 5:
                        cabecalho("5. LITROS EM GALÕES"); desenhar_campo();
                        l_gl(); rodape(); break;
               
                    case 6:
                        cabecalho("6. GALÕES EM LITROS"); desenhar_campo();
                        gl_l(); rodape(); break;
               
                    case 7:
                        cabecalho("7. QUILOGRAMAS EM LIBRAS"); desenhar_campo();
                        kg_lib(); rodape(); break;
               
                    case 8:
                        cabecalho("8. LIBRAS EM QUILOGRAMAS"); desenhar_campo();
                        lib_kg(); rodape(); break;
               
                    case 0: break;
             
                    default: opcao_invalida(); break; }             // Fecha o switch do submenu 3 (Converter Medidas)
           
                system("cls");
                } while (opcao!=0);                                 // Condição para voltar para o menu principal

                break;                                              // Fim do looping - submenu 3 (Converter Medidas)  
             
            case 4:                                                 // Quinto looping - submenu 4 (Jogar Dados) 
                do { 
                   
                cabecalho("JOGAR DADOS");        
                puts("\n\n\t Qual dado você quer jogar:\n");
                puts("\t 1 - Dado de 4  lados");
                puts("\t 2 - Dado de 6  lados");
                puts("\t 3 - Dado de 8  lados");
                puts("\t 4 - Dado de 12 lados");
                puts("\t 5 - Dado de 20 lados");
                puts("\t 6 - Outros (escolha o número máximo do dado)");
                puts("\t 0 - Retornar");
                desenhar_campo();
                go (20, 18); printf("Opção: ");  scanf("%d", &opcao);

                fflush(stdin); system("cls");
               
                int num;                                            // Declaração das variáveis que serão usadas no switch

                switch (opcao) {

                    case 1:
                        cabecalho("Dado de 4 lados"); desenhar_campo(); 
                        dados(4); rodape(); break;
           
                    case 2:
                        cabecalho("Dado de 6 lados"); desenhar_campo(); 
                        dados(6); rodape(); break;
                   
                    case 3:
                        cabecalho("Dado de 8 lados"); desenhar_campo(); 
                        dados(8); rodape(); break;
               
                    case 4:
                        cabecalho("Dado de 12 lados"); desenhar_campo(); 
                        dados(12); rodape(); break;

                    case 5:
                        cabecalho("Dado de 20 lados"); desenhar_campo(); 
                        dados(20); rodape(); break;
               
                    case 6:
                        cabecalho("Outro Valor"); desenhar_campo(); 
                        go (20, 6); printf("Digite o número máximo para ser sorteado: "); scanf("%d", &num);
                        dados(num); rodape(); break;
                   
                    case 0: break;

                    default: opcao_invalida(); break; }             // Fecha o switch do submenu 4 (Jogar Dados)
           
                system("cls");
                } while (opcao!=0);                                 // Condição para voltar para o menu principal

                break;                                              // Fim do looping - submenu 4 (Jogar Dados)
       
            case 5: break;
                 
            default: opcao_invalida(); break; }                     // Fecha o switch do menu principal
           
        system("cls");
    } while (opcao!=5);                                             // Condição para fechar o programa
    encerramento();
     cabecalho("Agradecimentos");
    puts("\n\n\t\t Integrantes do grupo:\n");
    puts("\t\t Guilherme Pavani Manoel de Paula");
    puts("\t\t Fernanda Prestes Lisboa");
    puts("\t\t Jonathas Teri");
    desenhar_campo(); rodape();

    return 0;
}
