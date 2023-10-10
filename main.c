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
};

typedef struct ingresso ingresso;


void telaUsuarioLogado(usuario usuaarios[], int i);
void usuarioLogado(usuario usuarios[], int idLogado, ingresso ingressos[]);
void compraIngressos(usuario usuarios[], int idLogado, ingresso ingressos[]);
void criaIngresso(ingresso ingressos[], usuario usuarios[], int idLogado, int qnt, int opcaoObra, int tipoIngresso);

int idIngresso = 0, contadorCriaIngresso = 0;

int main()
{
    setlocale(LC_ALL, "Portuguese");
 //   int qntU = 1, qntI = 1;
    usuario usuarios[100];
    ingresso ingressos[100];

    int opcao, contador = 0, id = 0, mudarTela = 0;
    char emailValidar[50];
    char senhaValidar[15];
    int logado = 0;
    int compEmail, compSenha;
    int idLogado = 0;
    char cadastrarNovamente;
    int validaNovamente = 0;
    char sim[3] = "sim";
    char nao = 'n';

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
            printf("Obrigado por acessar o nosso sistema");
            break;
        case 1:

            do
            {
                for (int i = contador; i < 100; i++)
                {
                    puts("Tela cadastro");
                    id++;
                    usuarios[i].id = id;
                    fflush(stdin);
                    puts("Insira seu nome: ");
                    scanf("%100[^\n]s", &usuarios[i].nome);
                    fflush(stdin);
                    puts("Insira sua idade: ");
                    scanf("%d", &usuarios[i].idade);
                    fflush(stdin);
                    puts("Insira seu email: ");
                    scanf("%50[^\n]s", &usuarios[i].email);
                    fflush(stdin);
                    puts("Insira sua senha: ");
                    scanf("%15[^\n]s", &usuarios[i].senha);
                    fflush(stdin);
                    contador++;
                    break;
                }
                system("cls");
                printf("Cliente cadastrado com sucesso! \n");
                for (int i = id  - 1; i < contador; i++)
                {
                    printf("Id: %d \n", usuarios[i].id);
                    printf("Nome: %s \n", usuarios[i].nome);
                    printf("Idade: %d \n", usuarios[i].idade);
                }

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

            } while (validaNovamente != 1);

            break;
        case 2:
            mudarTela = 1;
            if (mudarTela)
            {
                telaCompraIngresso();
                int opcaoCompraIngresso;
                scanf("%d", &opcaoCompraIngresso);

                if (opcaoCompraIngresso != NULL)
                {
                    system("cls");
                }

                switch (opcaoCompraIngresso)
                {
                case 0:
                    mudarTela = 0;
                    system("cls");
                    break;
                case 1:
                    printf("Vc comprou ingresso completo!");
                    break;
                case 2:
                    printf("Vc comprou meio ingresso");
                    break;
                default:
                    printf("Opção invalida");
                    break;
                }
            }

            break;
        case 3:

            fflush(stdin);
            printf("Informe seu email ou CPF: \n");
            scanf("%50[^\n]s", &emailValidar);
            fflush(stdin);
            printf("Informe sua senha: \n");
            scanf("%15[^\n]s", &senhaValidar);
            fflush(stdin);

            for (int i = 0; i <= contador; i++)
            {

                compEmail = strcmp(usuarios[i].email, emailValidar);
                compSenha = strcmp(usuarios[i].senha, senhaValidar);

                if (compEmail == 0 && compSenha == 0)
                {
                    logado = 1;
                    idLogado = i;
                    break;
                }
                else
                {
                    logado = 0;
                }
            }

            if (logado)
            {
                printf("Vc esta logado!\n");
                usuarioLogado(usuarios, idLogado, ingressos);
            }
            else
            {
                printf("Email ou senha inválidos \n");
                system("cls");
            }

            break;
        default:
            printf("Opção invalida \n");
            break;
        }
    } while (opcao != 0);
}




void usuarioLogado(usuario usuarios[], int idLogado, ingresso ingressos[])
{
    int opcao, comparador;
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
            printf("Saindo");
            break;
        case 1:
            compraIngressos(usuarios, idLogado, ingressos);
            break;
        case 2:
            printf("Viu apresentação");
            break;
        case 3:
            printf("Insira o valor a ser depositado: ");
            scanf("%f", &saldo);

            usuarios[idLogado].saldo = saldo;

            if (usuarios[idLogado].saldo >= saldo)
            {
                printf("Tigrinho pagou \n");
            }
            else
            {
                printf("Tigrinho não pagou \n");
            }
            break;
        case 4:
            puts("Seus ingressos: ");

            for(int i = 0; i < contadorCriaIngresso; i++){

                comparador = strcmp(ingressos[i].dono, usuarios[idLogado].nome);

                if(comparador == 0)
                {
                    printf("ID Ingresso: %d\n", ingressos[i].id);
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
    int opcaoCompra, tipoIngresso, opcaoObra, qnt;
    float total;
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

        puts("Ingresso Interiro valor: R$ 15,00");

        telaObras();
        scanf("%d", &opcaoObra);

        puts("Você deseja continuar com a compra ? (s/n)");
        fflush(stdin);
        scanf("%c", &sn);

        if (sn == 's')
        {
            usuarios[idLogado].saldo = usuarios[idLogado].saldo - 15.00;
            criaIngresso(ingressos, usuarios, idLogado, qnt, opcaoObra, tipoIngresso);

        }else if(usuarios[idLogado].saldo >= 15.00)
        {
            puts("Seu saldo é insulficiente para comprar esse ingresso");
        }else
        {
            system("cls");
        }

        break;
    case 2:
        tipoIngresso = 5;

        telaObras();
        scanf("%d", &opcaoObra);

        puts("Meio Ingresso valor: R$ 7,50");
        puts("Quantos ingressos você deseja comprar ?");
        scanf("%d", &qnt);

        total = 7.50 * qnt;

        printf("Total: %.2f \n", total);
        puts("Você deseja continuar com a compra ? (s/n)");
        fflush(stdin);
        scanf("%c", &sn);

        if (sn == 's')
        {
            puts("Saiba que ao adquirir este ingresso, você terá que comprovar o motivo da meia entrada");
            usuarios[idLogado].saldo = usuarios[idLogado].saldo - total;

            criaIngresso(ingressos, usuarios, idLogado, qnt, opcaoObra, tipoIngresso);
        }
        else if(usuarios[idLogado].saldo < total)
        {
            puts("Seu saldo é insulficiente para comprar esse ingresso");
        }
        else
        {
            system("cls");
        }
        break;
    case 3:
        telaIsento();
        scanf("%d", &tipoIngresso);

        criaIngresso(ingressos, usuarios, idLogado, qnt, opcaoObra, tipoIngresso);



    default:
        printf("Opção inválida");
    }
}

void criaIngresso(ingresso ingressos[], usuario usuarios[], int idLogado, int qnt, int opcaoObra, int tipoIngresso)
{
    int comparador;


    for(int q = 0; q < qnt; q++)
    {
        for(int i = contadorCriaIngresso; i < 100; i++)
        {
            idIngresso++;
            ingressos[i].id = idIngresso;
            strcpy(ingressos[i].dono, usuarios[idLogado].nome);
            retornaObra(opcaoObra, ingressos, i);
            retornaTipoIngresso(tipoIngresso, ingressos, i);
            contadorCriaIngresso++;
            break;
        }
    }


    for(int i = 0; i < contadorCriaIngresso; i++)
    {

        comparador = strcmp(ingressos[i].dono, usuarios[idLogado].nome);

        if(comparador == 0)
        {
            printf("ID Ingresso: %d\n", ingressos[i].id);
            printf("Dono Ingresso: %s\n", ingressos[i].dono);
            printf("Obra: %s\n", ingressos[i].obra);
            printf("Tipo Ingresso: %s\n", ingressos[i].tipoIngresso);
            printf("---------------------------------");
        }

    }
}

void retornaObra(int opcaoObra, ingresso ingressos[], int idIngresso)
{
    char obra1[50] = "Obra 1";
    char obra2[50] = "Obra 2";
    char obra3[50] = "Obra 3";
    char obra4[50] = "Obra 4";
    char obra5[50] = "Obra 5";
    char obra6[50] = "Obra 6";
    char obra7[50] = "Obra 7";
    char obra8[50] = "Obra 8";
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
    char pdc[50] = "PDC";
    char mais60[50] = "+60";
    char campanha[50] = "Campanha";
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


