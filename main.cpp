#include "iostream"
#include <stdio.h>
#include "Lista.hpp"
#include "No.hpp"

using namespace std;

int main() {
    Lista lista; // criação de Lista
    // criando Lista Vazia
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tam = 0;

    int opcao, valor;

    do { // menu de opções
        cout << "\n|--------------------------------------------|" << endl;
        cout << "| 1 - Adicionar elemento                     |"   << endl;
        cout << "| 2 - Tamanho da Lista                       |"   << endl;
        cout << "| 3 - Remover elemento da lista              |"   << endl;
        cout << "| 4 - Visualizar elemento com a posicao      |"   << endl;
        cout << "| 5 - Visualizar posicao do elemento         |"   << endl;
        cout << "| 6 - Exibir lista                           |"   << endl;
        cout << "| 0 - Finalizar                              |"   << endl;
        cout << "|--------------------------------------------|\n" << endl;
        cout << "Digite a opcao desejada: " << endl;
        cin >> opcao;
        system("clear||cls");

        switch(opcao) {
        case 1:

            cout << "Adicionar o elemento na lista no: " << endl;
            cout << "1 - Inicio " << endl;
            cout << "2 - Meio " << endl;
            cout << "3 - Fim " << endl;
            int aux;
            cin >> aux;

            if(aux == 1) {
            cout << "Digite um valor a ser inserido: " << endl;
            cin  >> valor;
            inserirInicio(&lista, valor);
            }else if (aux == 2){
            int posicao, valor;
            cout << "Digite a posicao: " << endl;
            cin >> posicao;
            cout << "Digite o valor: " << endl;
            cin >> valor;
            inserirMeioLista(&lista, posicao, valor);
            }else if(aux == 3){
            cout << "Digite um valor a ser inserido: " << endl;
            cin  >> valor;
            inserirFim(&lista, valor);
            }
            break;

        case 2:
            cout << tamanhoLista(&lista) << endl;
            break;

        case 3:
            cout << "Digite um valor a ser removido: " << endl;
            cin >> valor;
            remover(&lista, valor);
            break;
        case 4:
            int posicaoElemento;
            cout << "Qual a posicao do elemento que voce quer visualizar: " << endl;
            cin >> posicaoElemento;
            cout << elemento(&lista, posicaoElemento) << endl;
            break;

        case 5:
            cout << "Digite um valor a ser pesquisado: " << endl;
            cin >> valor;
            cout <<"Elemento na posicao : " << posicao(&lista, valor) << endl;
            break;

        case 6:
            cout << "Lista: " << endl;
            imprimir(&lista);
            break;

        case 0:
            cout << "Finalizando..." << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
        }
    } while(opcao != 0);

    return 0;
}
