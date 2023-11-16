#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "telas.h"

#define TAM 100

struct ingresso
{
    int id;
    char obra[100];
    char tipoIngresso[100];
    char dono[100];
    int idDono;
    char  validaIngresso[50];
    char pagamento[100];
};

typedef struct ingresso ingresso;

void telaUsuarioLogado(usuario usuarios[], int i);
void usuarioLogado(usuario usuarios[], int idLogado, ingresso ingressos[]);
void compraIngressos(usuario usuarios[], int idLogado, ingresso ingressos[]);
void criaIngresso(ingresso ingressos[], usuario usuarios[], int idLogado, int qnt, int opcaoObra, int tipoIngresso, int pagamento);
void realizarLogin(int contador, usuario usuarios[], ingresso ingressos[]);
void realizarLoginCIP(usuario usuarios[], ingresso ingressos[], int idPrmCmp);
void realizarCadastro(usuario usuarios[], int CIP);
void adicionaSaldoCIP(usuario usuarios[], int idLogado, float valorIngressos);
void validadorIngressos(ingresso ingressos[], int i, int ingressoValido);
void converteIngressoCSV(ingresso ingressos[]);

int idIngresso = 0, contadorCriaIngresso = 0;
int contador = 0, id = 0;

int main()
{
    setlocale(LC_ALL, "Portuguese");
 //   int qntU = 1, qntI = 1;
    usuario usuarios[100];
    ingresso ingressos[100];
    int opcao, mudarTela = 0;
    char emailValidar[50];
    char senhaValidar[15];
    int logado = 0;
    //int compEmail, compSenha;
    int idLogado = 0;
    char cadastrarNovamente;
    int validaNovamente = 0;
    char sim[3] = "sim";
    char nao = 'n';
    int opcaoObras, opcaoTipoIngresso;
    char cadastroSN;
    int idPrmCmp;


    do
    {

        telaInicio();
        scanf("%d", &opcao);

        if (opcao != NULL)
        {
            system("cls");
        }

        switch (opcao)
        {
        case 0:
            puts("=======================================");
            printf("Obrigado por acessar o nosso sistema!\n");
            puts("=======================================");
            break;
        case 1:
            realizarCadastro(usuarios, 0);
            break;
        case 2:

            telaPossuiCadastro();
            fflush(stdin);
            scanf("%c", &cadastroSN);

            if(cadastroSN == 's')
            {
                realizarLogin(contador, usuarios, ingressos);
            }else
            {
                telaAnucioCadastro();
                idPrmCmp = 1;
                realizarCadastro(usuarios, idPrmCmp);

                idPrmCmp = contador;
                idPrmCmp = idPrmCmp - 1;
                realizarLoginCI(usuarios,ingressos, idPrmCmp);

            }


            break;
        case 3:
            realizarLogin(contador, usuarios, ingressos);
            break;
        case 4:
            telaCatalogo();
            break;
        default:
            printf("Opção invalida \n");
            break;
        }
    } while (opcao != 0);
}




void usuarioLogado(usuario usuarios[], int idLogado, ingresso ingressos[])
{
    int opcao, comparador, pag;
    float saldo;

    do
    {
        telaUsuarioLogado(usuarios, idLogado);
        scanf("%d", &opcao);

        if (opcao != NULL)
        {
            system("cls");
        }

        switch (opcao)
        {
        case 0:
            system("cls");
            puts("Saindo");
            break;
        case 1:
            compraIngressos(usuarios, idLogado, ingressos);
            break;
        case 2:
            printf("Viu apresentação");
            break;
        case 3:
            telaDeposito();
            scanf("%f", &saldo);

            usuarios[idLogado].saldo += saldo;

            telaPagamentoD();
            scanf("%d", &pag);

            if(usuarios[idLogado].saldo > saldo){
                converteUsuarioCSV(usuarios);
                system("cls");
                puts("Saldo adicionado com sucesso!");
            }else{
                system("cls");
                puts("Erro ao adicionar saldo!");
            }

            break;
        case 4:
            telaIngressos();

            for(int i = 0; i < contadorCriaIngresso; i++){

                comparador = strcmp(ingressos[i].dono, usuarios[idLogado].nome);

                if(comparador == 0 && ingressos[i].idDono == usuarios[idLogado].id)
                {
                    printf("\nID Ingresso: %d\n", ingressos[i].id);
                    printf("Dono Ingresso: %s\n", ingressos[i].dono);
                    printf("Obra: %s\n", ingressos[i].obra);
                    printf("Tipo Ingresso: %s\n", ingressos[i].tipoIngresso);
                    printf("--------------------------------- \n");
                }

            }

            break;
        default:
            printf("Opção inválida");
            break;
        }
    } while (opcao != 0);
}

void compraIngressos(usuario usuarios[], int idLogado, ingresso ingressos[])
{
    int opcaoCompra, tipoIngresso, opcaoObra, qnt, opcaoPag;
    float total, valor;
    char sn;

    telaCompraIngressoLogado(usuarios, idLogado);
    scanf("%d", &opcaoCompra);

    if (opcaoCompra != NULL)
    {
        system("cls");
    }

    switch (opcaoCompra)
    {
    case 0:
        break;
    case 1:
        tipoIngresso = 4;

        telaObras();
        scanf("%d", &opcaoObra);

        telaValorIngresso(15.00, opcaoObra);
        scanf("%d", &qnt);

        total = 15.00 * qnt;

        telaPagamento(total);
        scanf("%d", &opcaoPag);

        if(opcaoPag != 2){
            telaAdicionaValor(total);
            scanf("%f", &valor);

            usuarios[idLogado].saldo += valor;
        }

        puts("Você deseja continuar com a compra ? (s/n)");
        fflush(stdin);
        scanf("%c", &sn);

        if (sn == 's' && usuarios[idLogado].saldo > total)
        {
            usuarios[idLogado].saldo = usuarios[idLogado].saldo - total;
            criaIngresso(ingressos, usuarios, idLogado, qnt, opcaoObra, tipoIngresso, opcaoPag);
        }
        else if(sn == 'n')
        {
            system("cls");
            puts("Compra cancelada");
        }
        else
        {
            system("cls");
            puts("Seu saldo é insulficiente para comprar esse ingresso");
        }
        break;
    case 2:
        tipoIngresso = 5;

        telaObras();
        scanf("%d", &opcaoObra);

        telaValorIngresso(7.50, opcaoObra);
        scanf("%d", &qnt);

        total = 7.50 * qnt;

        telaPagamento(total);
        scanf("%d", &opcaoPag);

        if(opcaoPag != 2){
            telaAdicionaValor(total);
            scanf("%f", &valor);
            puts("=================================================================");

            usuarios[idLogado].saldo += valor;
        }

        puts("Você deseja continuar com a compra ? (s/n)");
        fflush(stdin);
        scanf("%c", &sn);


        if (sn == 's' && usuarios[idLogado].saldo > total)
        {
            puts("=====================================================================================");
            puts("Saiba que ao adquirir este ingresso, você terá que comprovar o motivo da meia entrada");
            puts("=====================================================================================");
            usuarios[idLogado].saldo = usuarios[idLogado].saldo - total;

            criaIngresso(ingressos, usuarios, idLogado, qnt, opcaoObra, tipoIngresso, opcaoPag);
        }else if(sn == 'n')
        {
            system("cls");
            puts("Compra cancelada");
        }
        else
        {
            system("cls");
            puts("Seu saldo é insulficiente para comprar esse ingresso");
        }
        break;
    case 3:
        telaIsento();
        scanf("%d", &tipoIngresso);

        telaObras();
        scanf("%d", &opcaoObra);

        puts("Este tipo de ingresso só pode ser adquirido uma vez, pelo usuario cadastrado");
        qnt = 1;

        criaIngresso(ingressos, usuarios, idLogado, qnt, opcaoObra, tipoIngresso, opcaoPag);

        break;
    default:
        printf("Opção inválida");
    }
}

void criaIngresso(ingresso ingressos[], usuario usuarios[], int idLogado, int qnt, int opcaoObra, int tipoIngresso, int pagamento)
{
    int comparador, ingressoValido = 1;


    for(int q = 0; q < qnt; q++)
    {
        for(int i = contadorCriaIngresso; i < 100; i++)
        {
            idIngresso++;
            ingressos[i].id = idIngresso;
            ingressos[i].idDono = usuarios[idLogado].id;
            strcpy(ingressos[i].dono, usuarios[idLogado].nome);
            validadorIngressos(ingressos, i, ingressoValido);
            retornaObra(opcaoObra, ingressos, i);
            retornaTipoPagamento(pagamento, ingressos, i);
            retornaTipoIngresso(tipoIngresso, ingressos, i);
            contadorCriaIngresso++;
            break;
        }
    }


    converteIngressoCSV(ingressos);

    for(int i = 0; i <= contadorCriaIngresso; i++)
    {

        comparador = strcmp(ingressos[i].dono, usuarios[idLogado].nome);

        if(comparador == 0)
        {
            printf("\nID Ingresso: %d\n", ingressos[i].id);
            printf("Dono Ingresso: %s\n", ingressos[i].dono);
            printf("Obra: %s\n", ingressos[i].obra);
            printf("Tipo Ingresso: %s\n", ingressos[i].tipoIngresso);
            printf("Status: %s\n", ingressos[i].validaIngresso);
            printf("Pagamento: %s\n", ingressos[i].pagamento);
            printf("---------------------------------\n");
        }

    }
}

void realizarLogin(int contador, usuario usuarios[], ingresso ingressos[])
{

    char emailValidar[50];
    char senhaValidar[15];
    int compSenha, compEmail, compCPF, logado, idLogado;

            telaLogin();
            fflush(stdin);
            printf("Informe seu e-mail ou CPF: \n");
            scanf("%50[^\n]s", &emailValidar);
            fflush(stdin);
            printf("Informe sua senha: \n");
            scanf("%15[^\n]s", &senhaValidar);
            fflush(stdin);
            puts("=====================");

            for (int i = 0; i <= contador; i++)
            {

                compCPF = strcmp(usuarios[i].cpf, emailValidar);
                compEmail = strcmp(usuarios[i].email, emailValidar);
                compSenha = strcmp(usuarios[i].senha, senhaValidar);

                if(compCPF == 0 || compEmail == 0){
                    if (compSenha == 0)
                    {
                    logado = 1;
                    idLogado = i;
                    break;
                    }

                }else{
                    logado = 0;
                }

            }

            if (logado)
            {
                telaAnucioLogado();
                usuarioLogado(usuarios, idLogado, ingressos);
            }
            else
            {
                system("cls");
                printf("E-mail/CPF ou senha inválidos \n");
            }


}

void realizarCadastro(usuario usuarios[], int CIP)
{

    int validaNovamente;
    char cadastrarNovamente;

         do
            {
                for (int i = contador; i < 100; i++)
                {
                    telaCadastro();
                    id++;
                    usuarios[i].id = id;
                    fflush(stdin);
                    puts("Insira seu nome: ");
                    scanf("%100[^\n]s", &usuarios[i].nome);
                    fflush(stdin);
                    puts("Insira sua Data de Nascimento (dia/mês/ano): ");
                    gets(usuarios[i].data_nascimento);
                    puts("Insira sua idade: ");
                    scanf("%d", &usuarios[i].idade);
                    fflush(stdin);
                    puts("Insira seu CPF: ");
                    gets(usuarios[i].cpf);
                    puts("Insira seu email: ");
                    scanf("%50[^\n]s", &usuarios[i].email);
                    fflush(stdin);
                    puts("Insira sua senha: ");
                    scanf("%15[^\n]s", &usuarios[i].senha);
                    fflush(stdin);
                    puts("=======================");
                    contador++;
                    break;
                }

                converteUsuarioCSV(usuarios);
                system("cls");
                telaCadastroSucesso();
                for (int i = id  - 1; i < contador; i++)
                {
                    printf("Id: %d \n", usuarios[i].id);
                    printf("Nome: %s \n", usuarios[i].nome);
                    printf("Idade: %d \n", usuarios[i].idade);
                }


                if(CIP == 0){
                    printf("Deseja realizar um novo cadastro? (s/n)");
                    scanf("%c", &cadastrarNovamente);
                    fflush(stdin);

                    if (cadastrarNovamente == 's')
                    {
                        validaNovamente = 0;
                    }
                    else
                    {
                        validaNovamente = 1;
                    }
                }else{
                    validaNovamente = 1;
                }


            } while (validaNovamente != 1);
}

void realizarLoginCI(usuario usuarios[], ingresso ingressos[], int idPrmCmp)
{

    telaAnucioLogado();
    puts("Escolha o tipo de ingresso que você deseja");

    compraIngressos(usuarios, idPrmCmp, ingressos);
    usuarioLogado(usuarios, idPrmCmp, ingressos);

}

void retornaObra(int opcaoObra, ingresso ingressos[], int idIngresso)
{
    char obra1[50] = "Tocha Olimpica de Paris";
    char obra2[50] = "Phryges(Mascote)";
    char obra3[50] = "Prancha do Italo Ferreira";
    char obra4[50] = "Toca Michel Phelps";
    char obra5[50] = "Disco(Lançamento de disco)";
    char obra6[50] = "Maquete Stade de France";
    char obra7[50] = "BreakDance";
    char obra8[50] = "Bola de basquete Lebrom James";
    char passeLivre[50] = "Passe Livre";
    char obraErro[50] = "Erro";

    switch(opcaoObra)
    {
        case 1:
            strcpy(ingressos[idIngresso].obra, obra1);
            break;
        case 2:
            strcpy(ingressos[idIngresso].obra, obra2);
            break;
		case 3:
		    strcpy(ingressos[idIngresso].obra, obra3);
            break;
        case 4:
            strcpy(ingressos[idIngresso].obra, obra4);
            break;
		case 5:
		    strcpy(ingressos[idIngresso].obra, obra5);
            break;
		case 6:
		    strcpy(ingressos[idIngresso].obra, obra6);
            break;
        case 7:
            strcpy(ingressos[idIngresso].obra, obra7);
            break;
		case 8:
		    strcpy(ingressos[idIngresso].obra, obra8);
            break;
        case 9:
            strcpy(ingressos[idIngresso].obra, passeLivre);
            break;
        default:
            strcpy(ingressos[idIngresso].obra, obraErro);
            break;

    }
}

void retornaTipoIngresso(int tipoIngresso, ingresso ingressos[], int idIngresso)
{
    char meiaEntrada[50] = "Meia";
    char inteira[50] = "Inteira";
    char pdc[50] = "PDC, Isento";
    char mais60[50] = "+60, Isento";
    char campanha[50] = "Campanha, Isento";
    char erro[50] = "Erro";

    switch(tipoIngresso)
    {
        case 1:
            strcpy(ingressos[idIngresso].tipoIngresso, pdc);
            break;
        case 2:
            strcpy(ingressos[idIngresso].tipoIngresso, mais60);
            break;
		case 3:
		    strcpy(ingressos[idIngresso].tipoIngresso, campanha);
            break;
        case 4:
		    strcpy(ingressos[idIngresso].tipoIngresso, inteira);
            break;
        case 5:
		    strcpy(ingressos[idIngresso].tipoIngresso, meiaEntrada);
            break;
        default:
            strcpy(ingressos[idIngresso].tipoIngresso, erro);
            break;

    }
}

void retornaTipoPagamento(int tipoPag, ingresso ingressos[], int idIngresso)
{
    char PIX[50] = "PIX";
    char credito[50] = "C/ Crédito";
    char debito[50] = "C/ Débito";
    char saldoConta[50] = "Saldo da conta";
    char erro[50] = "Erro";

    switch(tipoPag)
    {
        case 1:
            strcpy(ingressos[idIngresso].pagamento, PIX);
            break;
        case 2:
            strcpy(ingressos[idIngresso].pagamento, saldoConta);
            break;
		case 3:
		    strcpy(ingressos[idIngresso].pagamento, credito);
            break;
        case 4:
		    strcpy(ingressos[idIngresso].pagamento, debito);
            break;
        default:
            strcpy(ingressos[idIngresso].tipoIngresso, erro);
            break;

    }
}

void validadorIngressos(ingresso ingressos[], int i, int ingressoValido)
{
    char valido[50] = "Válido";
    char invalido[50] = "Inválido";
    char erro[10] = "Erro";

    switch(ingressoValido)
    {
        case 0:
            strcpy(ingressos[i].validaIngresso, invalido);
            break;
        case 1:
            strcpy(ingressos[i].validaIngresso, valido);
            break;
        default:
            strcpy(ingressos[i].validaIngresso, erro);
            break;
    }

}

void converteIngressoCSV(ingresso ingressos[])
{

    FILE *arquivoCSV = fopen("ingressos.csv", "w");
    if (arquivoCSV == NULL)
    {
        perror("Erro ao abrir o arquivo CSV");
    }

    for(int i = 0; i <= contadorCriaIngresso; i++){
        fprintf(arquivoCSV,"%d, %s, %s, %s, %d, %s \n ", ingressos[i].id, ingressos[i].obra, ingressos[i].tipoIngresso,
                ingressos[i].dono, ingressos[i].idDono, ingressos[i].validaIngresso);
    }

    fclose(arquivoCSV);
}

void converteUsuarioCSV(usuario usuarios[])
{

    FILE *arquivoCSV = fopen("usuarios.csv", "w");
    if (arquivoCSV == NULL)
    {
        perror("Erro ao abrir o arquivo CSV");
    }

    for(int i = 0; i < contador; i++){
        fprintf(arquivoCSV,"%d, %s, %d, %s, %s, %s, %s,", usuarios[i].id, usuarios[i].nome, usuarios[i].idade,
                usuarios[i].email, usuarios[i].senha, usuarios[i].cpf, usuarios[i].data_nascimento);
    }

    fclose(arquivoCSV);
}


