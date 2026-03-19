//Autores : Martim Pereira Nº17 Martim Bernardo Nº18
//Turma : 10ºF

#include <stdio.h>
#include <windows.h>
#include <locale.h>

//constante
#define PASSWORD 94561231

//variáveis globais
int totalExpresso = 0, totalLongo = 0, totalDesCurto = 0, totalDesLongo = 0, totalGalao = 0, totalCap= 0;
float totalFaturado = 0, totalFatExpresso = 0, totalFatLongo = 0, totalFatDesCurto = 0, totalFatDesLongo = 0, totalFatGalao = 0, totalFatCap = 0;

//criação de funções
int menuCafes()
{
    int opcao;
    printf("                      __  __ \n");
    printf("                     / _|/_/ \n");
    printf("            ___ __ _| |_ ___ \n");
    printf("           / __/ _ |  _/ _ \\ \n");
    printf("          | (_| (_| | ||  __/ \n");
    printf("           \\___\\___|_| \\___| \n\n");
    printf("\033[93m====== Tipo de café =========== Preços =========\033[0m\n");
    printf("\033[33m1 - Café expresso             0,70 euros\033[0m\n");
    printf("\033[33m2 - Café longo                0,70 euros\033[0m\n");
    printf("\033[33m3 - Descafeinado curto        0,70 euros\033[0m\n");
    printf("\033[33m4 - Descafeinado longo        0,70 euros\033[0m\n");
    printf("\033[33m5 - Galão                     0,80 euros\033[0m\n");
    printf("\033[33m6 - Capuccino com chocolate   0,80 euros\033[0m\n");
    printf("\033[93m================================================\033[0m\n");

    printf("0 - Sair\n");
    do
    {
        printf("Qual opção deseja selecionar: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');
    }
    while ((opcao < 0 || opcao > 6) && opcao != -99);

    return opcao;
}

int obterTotalCafes(int a, int b, int c, int d, int e, int f)
{
    return a + b + c + d + e + f;
}

float totalFaturadoCafes(float a, float b, float c, float d, float e, float f)
{
    return a + b + c + d + e + f;
}

int menuTotalCafes()
{
    int sairFabricante = 0;
    puts("==== Total Cafés ====");
    printf("Total de cafes expresso: %d \n", totalExpresso);
    printf("Total de cafes longo: %d\n", totalLongo);
    printf("Total de cafes Descafeinados Curtos: %d\n", totalDesCurto);
    printf("Total de cafes Descafeinados Longos: %d\n", totalDesLongo);
    printf("Total de Galões: %d\n", totalGalao);
    printf("Total de capuccino com chocolate: %d\n\n", totalCap);
    printf("Total de cafes: %d\n", obterTotalCafes(totalExpresso,totalLongo, totalDesCurto,totalDesLongo, totalGalao,totalCap  ));
    puts("=====================");
    printf("Pressione ENTER para voltar ao menu:");
    getchar();
    //getchar();

    return sairFabricante;
}

int menuTotalFaturacao()
{
    int sairFabricante = 0;
    puts("==== Total Faturado ====");
    printf("Total faturado de cafes expresso: %.2f \n", totalFatExpresso);
    printf("Total faturado de cafes longo: %.2f\n", totalFatLongo);
    printf("Total faturado de cafes Descafeinados Curtos: %.2f\n", totalFatDesCurto);
    printf("Total faturado de cafes Descafeinados Longos: %.2f\n", totalFatDesLongo);
    printf("Total faturado de Galões: %.2f\n", totalFatGalao);
    printf("Total faturado de capuccino com chocolate: %.2f\n\n", totalFatCap);
    printf("Total faturado de cafes: %.2f\n", totalFaturadoCafes(totalFatExpresso, totalFatLongo, totalFatDesCurto, totalFatDesLongo, totalFatGalao, totalFatCap));
    puts("=====================");
    printf("Pressione ENTER para voltar ao menu:");
    getchar();
    return sairFabricante;
}

int menuEntrarModoFabricante()
{
    int tentativaPassword;
    printf("===== Modo Fabricante =====\n");
    printf("Digite a password:");
    scanf("%d", &tentativaPassword);
    while (getchar() != '\n');

    return tentativaPassword;
}

int menuModoFabricante()
{
    int opcaoFabricante;
    puts("======= Menu fabricante =======");
    printf("1 - Total de cafés\n");
    printf("2 - Total faturado\n");
    puts("===============================");
    printf("3 - Sair do Modo Fabricante\n");
    printf("Opcao -> ");
    scanf("%d", &opcaoFabricante);
    while (getchar() != '\n');

    return opcaoFabricante;
}

int menuQuantidadeAcucar( int acucar)
{
    int escolhaAcucar;
    printf("\033[38;5;223m\n==== Ajustar quantidade de açúcar ====\033[0m\n");
    printf("Açúcar atual: %d colheres\n", acucar);
    printf("1 - Adicionar açúcar\n");
    printf("2 - Remover açúcar\n");
    printf("3 - Confirmar\n");
    printf("Escolha: ");
    scanf("%d", &escolhaAcucar);
    while (getchar() != '\n');

    return escolhaAcucar;
}

int menuEscolherMetodoPagamento()
{
    int opcaoPagamento;
    printf("Deseja pagar com cartão (1) ou dinheiro (2): ");
    scanf("%d", &opcaoPagamento);
    while (getchar() != '\n');

    return opcaoPagamento;
}

int menuInserirPin()
{
    int pin;
    printf("\nDigite o PIN (4 dígitos): ");
    scanf("%d", &pin);
    while (getchar() != '\n');

    return pin;
}

void mostrarFimCompra()
{
    printf("\nSeu café está pronto! Bom apetite!\n\n\n");

    printf("    (  )   (   )  )\n");
    printf("     ) (   )  (  (\n");
    printf("     ( )  (    ) )\n");
    printf("     _____________\n");
    printf("    <_____________> ___\n");
    printf("    |             |/ _ \\\n");
    printf("    |               | | |\n");
    printf("    |               |_| |\n");
    printf(" ___|             |\\___/\n");
    printf("/    \\___________/    \\\n");
    printf("\\_____________________/\n");
}

//função main
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opcao = -1, opcaoPagamento, opcaoFabricante, pagamentoCartao;
    int acucar = 0;
    int escolhaAcucar;
    float precoCafe = 0, dinheiroInserido = 0, moedas;
    int tentativaPassword;
    int cafeAtual;

    do //exibir o menu até apertar 0
    {
        acucar = 0;
        opcao = menuCafes();

        if(opcao == -99) // verificar se o utilizador digitou -99 para entrar no modo fabricante
        {
            tentativaPassword = menuEntrarModoFabricante();
            system("cls");


            if(tentativaPassword == PASSWORD ) //verificar se a password está correta
            {
                do
                {
                    system("cls");
                    opcaoFabricante = menuModoFabricante();

                    switch(opcaoFabricante)
                    {
                    case 1:
                        system("cls");
                        menuTotalCafes();
                        break;
                    case 2:

                        system("cls");
                        menuTotalFaturacao();
                        break;
                    case 3:
                        printf("Saindo do modo Fabricante...");
                        Sleep(1000);
                        break;

                    }
                }
                while(opcaoFabricante != 3);

            }
            else
            {
                printf("Não é o fabricante desta máquina");
            }
            system("cls");
            continue;
        }


        if (opcao < 0 || opcao > 6)
        {
            printf("Opção inválida! Escolha uma opção etre 0 e 6.\n");

        }

        switch (opcao)
        {
        case 1 :
            printf("Café expresso selecionado\n");
            precoCafe = 0.70;
            break;
        case 2:
            printf("Café longo selecionado\n");
            precoCafe = 0.70;
            break;
        case 3:
            printf("Descafeinado curto selecionado\n");
            precoCafe = 0.70;
            break;
        case 4:
            printf("Descafeinado longo selecionado\n");
            precoCafe = 0.70;

            break;
        case 5:
            printf("Galão selecionado\n");

            precoCafe = 0.80;
            break;
        case 6:
            printf("Capuccino com chocolate selecionado\n");
            precoCafe = 0.80;
            break;
        case 0:

            printf("Saindo da máquina...\n");
            Sleep(2000);
            system("cls");
            printf("Obrigado!\n");
            Sleep(2000);
            return 0;

        }

        Sleep(1000);
        system("cls");

        // Loop responsável por permitir ao utilizador ajustar a quantidade de açúcar que repete até escolher opção 3

        do
        {
            escolhaAcucar = menuQuantidadeAcucar(acucar);

            switch (escolhaAcucar)
            {
            case 1:
                system("cls");
                if (acucar < 5)//verificar se o açucar não é maior que 5
                {
                    acucar++; //incrementar açucar
                }
                else printf("Máximo de açúcar (5 colheres).\n");
                break;

            case 2:
                system("cls");
                if (acucar > 0)//verificar se o açucar não é menor que 0
                {
                    acucar--; //decrementar açucar
                }
                else
                {
                    printf("O mínimo é 0 colheres.\n");
                }

                break;

            case 3:
                break;

            default:
                system("cls");
                printf("Escolha inválida! Apenas 1, 2 ou 3.\n");

            }
        }
        while (escolhaAcucar != 3);

        system("cls");

        //mostra o resultado da compra exibindo o tipo de café e a quantidade de açucar

        printf("\033[38;5;120m======= Pagamento =======\033[0m\n");
        printf("Tipo de café: %d\n", opcao);
        printf("Quantidade de açúcar: %d\n", acucar);
        printf("\033[95mPreço: %.2f euros\033[0m\n", precoCafe);


        do
        {
            opcaoPagamento = menuEscolherMetodoPagamento();

            if(opcaoPagamento != 1 && opcaoPagamento != 2)
            {
                printf("\nDigite uma opção válida (1 ou 2)\n");
            }

        }
        while (opcaoPagamento != 1 && opcaoPagamento != 2);

        int pagamentoConfirmado = 1;

        system("cls");

        switch (opcaoPagamento)
        {
        case 1:  // Escolheu pagar em cartão
            printf("==== PAGAMENTO POR CARTÃO ====\n");
            printf("Preço: %.2f euros\n", precoCafe);

            do //Loop responsavel por exibir uma mensagem de erro caso o utilizador não seleciona a opção 1 ou 2
            {
                printf("1 - Continuar\n2 - Cancelar pagamento\nEscolha: ");
                scanf("%d", &pagamentoCartao);
                while (getchar() != '\n');

                if (pagamentoCartao != 1 && pagamentoCartao != 2) //mensagem de erro se o utilizador não escolher uma opção válida
                {
                    printf("Opção inválida! Digite 1 ou 2.\n");
                    Sleep(1000);
                    system("cls");
                    printf("==== PAGAMENTO POR CARTÃO ====\n");
                    printf("Preço: %.2f euros\n", precoCafe);
                }
            }
            while (pagamentoCartao != 1 && pagamentoCartao != 2);

            if (pagamentoCartao == 2) //se o utilizador cancelar o pagamento
            {
                printf("Pagamento cancelado!\n");
                Sleep(2000);
                system("cls");
                pagamentoConfirmado = 0;
                break;
            }
            // PIN
            int pin, pinValido = 0;



            do//Loop de mensagem de erro enquanto o utilizador não digita o pin correto
            {
                pin = menuInserirPin();

                // Verifica se tem 4 dígitos
                if (pin >= 1000 && pin <= 9999)
                {
                    pinValido = 1;
                }
                else
                {
                    printf("PIN inválido!\n");
                }
            }
            while (!pinValido);



            // Só vai chegar aqui se escolheu a opção 1 de continuar com o pagamento
            system("cls");
            printf("\033[93m[***           ] pagamento pendente...\033[0m\n");
            Sleep(1500);

            // Aprovação do pagamento com som
            system("cls");
            printf("\033[92m[**************] Pagamento aprovado!\033[0m\n");

            Beep(1200, 200);
            Beep(1500, 200);
            Beep(1800, 250);

            Sleep(1500);
            break;

        case 2:  // Escolheu pagar com dinheiro
            printf("----------------------------------------\n");
            printf("           PAGAMENTO EM DINHEIRO        \n");
            printf("----------------------------------------\n");
            printf("Preço do café: %.2f euros", precoCafe);
            dinheiroInserido = 0;


            printf("\nInsira moedas válidas (0.05 | 0.10 | 0.20 | 0.50 | 1.00 | 2.00) \n");

            while (dinheiroInserido < precoCafe)
            {
                printf("Insira moeda: ");
                scanf("%f", &moedas);
                while (getchar() != '\n');

                // Verificação da moeda
                if (moedas == 0.05f || moedas == 0.10f || moedas == 0.20f || moedas == 0.50f || moedas == 1.00f || moedas == 2.00f )
                {
                    dinheiroInserido += moedas;
                    printf("Total de dinheiro inserido: %.2f euros\n", dinheiroInserido);
                }
                else
                {
                    printf("Moeda inválida! Tente novamente.\n");
                    continue;
                }

                if (dinheiroInserido < precoCafe)
                    printf("Falta: %.2f euros\n", precoCafe - dinheiroInserido);
            }

            if (dinheiroInserido > precoCafe)
                printf("Troco: %.2f euros\n", dinheiroInserido - precoCafe); //mostra o troco em euros
            else
                printf("Pagamento concluido! Obrigado.\n");

            Sleep(1500);
            dinheiroInserido = 0;
            system("cls");
            break;
        }
        acucar = 0;

        if (pagamentoConfirmado == 0)
        {
            continue;  // Volta diretamente para o menu de seleção do produto
        }
        cafeAtual = opcao; //Validar se foi concluida a compra

        switch(cafeAtual) //Acumular a quantidade do café e o preço do café para o menu do fabricante
        {
        case 1 :
            totalExpresso++;
            totalFatExpresso += precoCafe ;
            break;
        case 2:
            totalLongo++;
            totalFatLongo += precoCafe;
            break;
        case 3:
            totalDesCurto++;
            totalFatDesCurto += precoCafe;
            break;
        case 4:
            totalDesLongo++;
            totalFatDesLongo += precoCafe;
            break;
        case 5:
            totalGalao++;
            totalFatGalao += precoCafe;
            break;
        case 6:
            totalCap++;
            totalFatCap += precoCafe;
            break;
        }


        system("cls");

        printf("\nPreparando o seu café...\n");
        for (int i = 0; i <= 50; i++)
        {
            printf("\rO seu café está a sair! Aguarde: [");
            for (int j = 0; j < i; j++) printf("*");
            for (int j = i; j < 50; j++) printf(" ");
            printf("] %3d%%", i * 2);
            fflush(stdout);
            Beep(800 + i * 5, 20);
            Sleep(50);
        }

        Beep(1200, 150);
        Beep(1400, 150);
        Beep(1600, 200);

        mostrarFimCompra();

        Sleep(2000);
        system("cls");
    }
    while (opcao != 0 );

    return 0;
}
