struct usuario
{
    int id;
    char nome[100];
    int idade;
    char email[50];
    char senha[15];
    float saldo;
    int idIngresso[100];
    // char cpf[14] ;
    // char data_nascimento[10];
};

typedef struct usuario usuario;


void telaInicio()
{
    puts("---------------------------");
    puts("|                         |");
    puts("| 1 - cadastrar           |");
    puts("| 2 - comprar ingresso    |");
    puts("| 3 - Fazer login         |");
    puts("| 0 - sair                |");
    puts("|                         |");
    puts("|                         |");
    puts("|                         |");
    puts("---------------------------");
}

void telaCompraIngressoLogado(usuario usuaarios[], int i)
{
    puts("---------------------------");
    printf(" %s            saldo: %.2f          \n \n", usuaarios[i].nome, usuaarios[i].saldo);
    puts("|                         |");
    puts("| 1 - Ingresso Inteiro    |");
    puts("| 2 - Meia Entrada        |");
    puts("| 3 - Isento              |");
    puts("| 0 - sair                |");
    puts("|                         |");
    puts("|                         |");
    puts("|                         |");
    puts("---------------------------");
}

void telaUsuarioLogado(usuario usuaarios[], int i)
{
    puts("---------------------------");
    printf(" %s            saldo: %.2f          \n \n", usuaarios[i].nome, usuaarios[i].saldo);
    puts("| 1 - Comprar ingresso    |");
    puts("| 2 - Ver apresentações   |");
    puts("| 3 - depositar           |");
    puts("| 4 - Meus ingressos      |");
    puts("| 0 - sair                |");
    puts("|                         |");
    puts("|                         |");
    puts("|                         |");
    puts("---------------------------");
}

void telaObras()
{
    puts("---------------------------");
    puts("| Escolha a obra que você |");
    puts("| deseja ver:             |");
    puts("|                         |");
    puts("| 1 - Obra 1              |");
    puts("| 2 - Obra 2              |");
    puts("| 3 - Obra 3              |");
    puts("| 4 - Obra 4              |");
    puts("| 5 - Obra 5              |");
    puts("| 6 - Obra 6              |");
    puts("| 7 - Obra 7              |");
    puts("| 8 - Obra 8              |");
    puts("| 9 - Passe livre         |");
    puts("|                         |");
    puts("|                         |");
    puts("|                         |");
    puts("---------------------------");
}

void telaIsento()
{
    puts("---------------------------");
    puts("| Qual o motivo da isenção|");
    puts("| do ingresso ?           |");
    puts("|                         |");
    puts("| 1 - PDC                 |");
    puts("| 2 - +60                 |");
    puts("| 3 - Campanha            |");
    puts("|                         |");
    puts("|                         |");
    puts("---------------------------");
}


