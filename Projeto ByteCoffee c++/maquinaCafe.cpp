//Programa: maquina de café
//autor: Martim Pereira Nº17 E Martim Bernardo Nº18
//Data: 16/03/2026

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    string descricoes[10] = {"Cafe Expresso", "Cafe Longo", "Cappuccino", "Chocolate Quente", "Cha", "-", "-", "-", "-", "-"};
    float precos[10] = {1.00, 1.20, 1.80, 2.00, 1.50, 0, 0, 0, 0, 0};
    int stock[10] = {12, 12, 12, 12, 12, 0, 0, 0, 0, 0};
    int vendas[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float totalDinheiro = 0.0;

    int escolha;
    int pin = 1234;
    int tentativaPin;
    float pagamento, moeda, preco;
    string produto;

    do {
        for (int i = 0; i < 20; i++) cout << endl;

        cout << "==================================" << endl;
        cout << "      Bem-vindo a Maquina Cafe!   " << endl;
        cout << "==================================" << endl;

        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << left << setw(18) << descricoes[i];

            if (stock[i] <= 0) {
                cout << "ESGOTADO" << endl;
            } else {
                cout << fixed << setprecision(2) << precos[i] << "€" << endl;
            }
        }

        cout << "0. Sair" << endl;
        cout << "-99. Menu de Gestao (Admin)" << endl;
        cout << "==================================" << endl;

        cout << "Escolha uma opcao: ";
        cin >> escolha;

        // MENU ADMIN
        if (escolha == -99) {
            cout << "Introduza o PIN: ";
            cin >> tentativaPin;

            if (tentativaPin == pin) {
                int opGestao;

                cout << "\n1. Mudar Nomes" << endl;
                cout << "2. Mudar Precos" << endl;
                cout << "3. Repor Stock" << endl;
                cout << "4. Ver Movimentos (Vendas)" << endl;
                cout << "Opcao: ";
                cin >> opGestao;

                if (opGestao == 4) {
                    cout << "\n--- RELATORIO DE VENDAS ---" << endl;
                    for (int i = 0; i < 10; i++) {
                        if (descricoes[i] != "-") {
                            cout << descricoes[i] << ": " << vendas[i] << " unidades" << endl;
                        }
                    }
                    cout << "---------------------------" << endl;
                    cout << "TOTAL EM CAIXA: " << fixed << setprecision(2) << totalDinheiro << "€" << endl;
                }

                else if (opGestao == 1) {
                    int item;
                    cout << "Qual item (1-10)? ";
                    cin >> item;

                    if (item < 1 || item > 10) {
                        cout << "Item invalido!" << endl;
                    } else {
                        cout << "Novo nome: ";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, descricoes[item - 1]);
                    }
                }

                else if (opGestao == 2) {
                    int item;
                    cout << "Qual item (1-10)? ";
                    cin >> item;

                    if (item < 1 || item > 10) {
                        cout << "Item invalido!" << endl;
                    } else {
                        cout << "Novo preco: ";
                        cin >> precos[item - 1];
                    }
                }

                else if (opGestao == 3) {
                    int item;
                    cout << "Qual item deseja repor o stock (1-10)? ";
                    cin >> item;

                    if (item < 1 || item > 10) {
                        cout << "Numero invalido!" << endl;
                    } else {
                        int qtd;
                        cout << "Stock atual: " << stock[item - 1];
                        cout << ". Adicionar quanto? ";
                        cin >> qtd;

                        if (stock[item - 1] + qtd <= 12) {
                            stock[item - 1] += qtd;
                            cout << "Stock atualizado!" << endl;
                        } else {
                            cout << "Erro: O limite de stock e 12 unidades!" << endl;
                        }
                    }
                }

            } else {
                cout << "PIN INCORRETO!" << endl;
            }

            cout << "Pressione Enter para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

        // CLIENTE
        else if (escolha >= 1 && escolha <= 5) {
            if (stock[escolha - 1] <= 0) {
                cout << "Lamentamos, produto ESGOTADO!" << endl;
                cin.ignore();
                cin.get();
            } else {
                preco = precos[escolha - 1];
                produto = descricoes[escolha - 1];
                pagamento = 0;

                cout << "\nSelecionou: " << produto << " | Preco: " << preco << "€" << endl;

                while (pagamento < preco) {
                    cout << "Insira moeda (0 para cancelar): ";
                    cin >> moeda;

                    if (moeda == 0) {
                        cout << "Devolvendo moedas: " << pagamento << "€" << endl;
                        pagamento = -1;
                        break;
                    }

                    if (moeda == 0.05 || moeda == 0.10 || moeda == 0.20 || moeda == 0.50 || moeda == 1 || moeda == 2) {
                        pagamento += moeda;

                        if (pagamento < preco) {
                            cout << "Falta: " << fixed << setprecision(2) << (preco - pagamento) << "€" << endl;
                        }
                    } else {
                        cout << "Moeda nao aceite!" << endl;
                    }
                }

                if (pagamento >= preco) {
                    stock[escolha - 1]--;
                    vendas[escolha - 1]++;
                    totalDinheiro += preco;

                    char t;
                    cout << "Deseja imprimir talao? (s/n): ";
                    cin >> t;

                    if (t == 's' || t == 'S') {
                        cout << "\n--- TALAO DE COMPRA ---" << endl;
                        cout << "Produto: " << produto << endl;
                        cout << "Pago: " << pagamento << "€" << endl;
                        cout << "Troco: " << fixed << setprecision(2) << (pagamento - preco) << "€" << endl;
                        cout << "-----------------------" << endl;
                    }

                    cout << "Retire o seu produto. Obrigado!" << endl;
                    cin.ignore();
                    cin.get();
                }
            }
        }

    } while (escolha != 0);

    return 0;
}