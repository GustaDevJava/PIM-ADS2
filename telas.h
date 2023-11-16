struct usuario
{
    int id;
    char nome[100];
    int idade;
    char email[50];
    char senha[15];
    float saldo;
    int idIngresso[100];
    char cpf[15] ;
    char data_nascimento[100];
};

typedef struct usuario usuario;


void telaInicio()
{
    puts("---------------------------");
    puts("| Museu das Olimp�adas    |");
    puts("|                         |");
    puts("| 1 - Cadastrar           |");
    puts("| 2 - Comprar ingresso    |");
    puts("| 3 - Fazer login         |");
    puts("| 4 - Ver Cat�logo        |");
    puts("| 0 - sair                |");
    puts("|                         |");
    puts("|                         |");
    puts("|                         |");
    puts("---------------------------");
}

void telaCadastro()
{
    puts("=======================");
    puts("     TELA CADASTRO     ");
    puts("=======================");

}

void telaLogin()
{
    puts("=====================");
    puts("     TELA LOGIN      ");
    puts("=====================");

}

void telaIngressos()
{
    puts("======================");
    puts("    TELA INGRESSOS    ");
    puts("======================");

}

void telaCadastroSucesso()
{
    puts("=======================================");
    puts("     CLIENTE CADASTRADO COM SUCESSO    ");
    puts("=======================================");

}

void telaDeposito()
{
    puts("=======================================");
    puts("   INSIRA O VALOR A SER DEPOSITADO:    ");
    puts("=======================================");

}
void telaAnucioCadastro()
{
    puts("==============================================================================");
    puts("     VAMOS REALIZAR SEU CADASTRO PARA QUE VOC� CONSIGA COMPRAR O INGRESSO     ");
    puts("==============================================================================");

}

void telaAnucioLogado()
{
    puts("===========================");
    puts("     VOC� ESTA LOGADO!     ");
    puts("===========================");

}

void telaValorIngresso(float valor, int opcaoObra)
{

    if(opcaoObra == 9){
        puts("===============================================");
        printf("    Meio Ingresso valor: R$ %.2f\n", valor);
        puts("  Quantos ingressos voc� deseja comprar ?");
        puts("===============================================");
    }else{
        puts("==============================================================");
        printf("      Meio Ingresso valor: R$ %.2f\n", valor);
        puts("     Quantos ingressos voc� deseja comprar para est� obra ?");
        puts("==============================================================");
    }


}

void telaAdicionaValor(float valorIngressos)
{
        puts("=================================================================");
      printf("     Voc� precisa adicionar um valor maior ou igual a %.2f \n", valorIngressos);
      printf("     Valor a ser adicionado: ");

}

void telaPossuiCadastro()
{
    puts("===============================");
    puts("     VOC� POSSUI CADASTRO ?    ");
    puts("                               ");
    puts("  s - SIM                      ");
    puts("  n - N�O                      ");
    puts("===============================");

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
    puts("| 2 - depositar           |");
    puts("| 3 - Meus ingressos      |");
    puts("| 0 - sair                |");
    puts("|                         |");
    puts("|                         |");
    puts("|                         |");
    puts("---------------------------");
}

void telaObras()
{
    puts("----------------------------------");
    puts("| Escolha a obra que voc�        |");
    puts("| deseja ver:                    |");
    puts("|                                |");
    puts("| 1 - Tocha Olimpica de Paris    |");
    puts("| 2 - Phryges(Mascote)           |");
    puts("| 3 - Prancha do Italo Ferreira  |");
    puts("| 4 - Toca Michel Phelps         |");
    puts("| 5 - Disco(Lan�amento de disco) |");
    puts("| 6 - Maquete Stade de France    |");
    puts("| 7 - BreakDance                 |");
    puts("| 8 - Bola de basquete           |");
    puts("|     Lebrom James               |");
    puts("| 9 - Passe livre                |");
    puts("|                                |");
    puts("|                                |");
    puts("|                                |");
    puts("----------------------------------");
}

void telaIsento()
{
    puts("---------------------------");
    puts("| Qual o motivo da isen��o|");
    puts("| do ingresso ?           |");
    puts("|                         |");
    puts("| 1 - PDC                 |");
    puts("| 2 - +60                 |");
    puts("| 3 - Campanha            |");
    puts("|                         |");
    puts("|                         |");
    puts("---------------------------");
}

void telaCatalogo()
{
    puts("----------------------------------");
    puts("| 1 - Tocha Olimpica de Paris    |");
    puts("| 2 - Phryges(Mascote)           |");
    puts("| 3 - Prancha do Italo Ferreira  |");
    puts("| 4 - Toca Michel Phelps         |");
    puts("| 5 - Disco(Lan�amento de disco) |");
    puts("| 6 - Maquete Stade de France    |");
    puts("| 7 - BreakDance                 |");
    puts("| 8 - Bola de basquete           |");
    puts("|                                |");
    puts("| Passe Livre(PL)                |");
    puts("| Inteira, PL: 15,00             |");
    puts("| Meia, PL: 7,50                 |");
    puts("| Isento: Confira os termos      |");
    puts("----------------------------------");
}

void telaPagamento(float total)
{
    puts("-----------------------------");
    printf("Total: %.2f \n\n", total);
    puts("| Qual o m�todo de pagemento|");
    puts("| do ingresso ?             |");
    puts("|                           |");
    puts("| 1 - PIX                   |");
    puts("| 2 - Saldo da conta        |");
    puts("| 3 - Cart�o de credito     |");
    puts("| 4 - Cart�o de debito      |");
    puts("|                           |");
    puts("|                           |");
    puts("----------------------------");

}

void telaPagamentoD()
{
    puts("-----------------------------");
    puts("| Qual o m�todo de pagemento|");
    puts("| do ingresso ?             |");
    puts("|                           |");
    puts("| 1 - PIX                   |");
    puts("| 2 - Cart�o de credito     |");
    puts("| 3 - Cart�o de debito      |");
    puts("|                           |");
    puts("|                           |");
    puts("----------------------------");

}


