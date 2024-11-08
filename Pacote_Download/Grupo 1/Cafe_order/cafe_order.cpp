#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEDIDOS 50
#define MAX_NOME_COMPRIMENTO 50
#define MAX_ITEM_COMPRIMENTO 50

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
        return;
    }

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
    if (totalPedidos == 0) {
        printf("Nenhum pedido realizado ainda.\n");
        return;
    }

    printf("Todos os pedidos:\n");
    printf("%-10s %-20s %-20s %-20s %-15s\n", "Nº Mesa", "Nome Cliente", "Item", "Método Pagamento", "Nº Pessoas");
    for (int i = 0; i < totalPedidos; ++i) {
        printf("%-10d %-20s %-20s %-20s %-15d\n", pedidos[i].numeroMesa, pedidos[i].nomeCliente,
               pedidos[i].item, pedidos[i].metodoPagamento, pedidos[i].numeroPessoas);
    }
}

int main() {
    int escolha;
    do {
        printf("\nSistema de Pedidos da Cafeteria\n");
        printf("\n1. Fazer um pedido\n");
        printf("2. Exibir todos os pedidos\n");
        printf("3. Sair\n");
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
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha invalida. Por favor, digite uma opcao valida.\n");
        }
    } while (escolha != 3);

    return 0;
}
