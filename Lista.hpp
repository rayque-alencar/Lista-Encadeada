#ifndef LISTA_HPP
#define LISTA_HPP
#include "No.hpp"
#include "iostream"

using namespace std;

    typedef struct {
        No *inicio, *fim;
        int tam;
    } Lista;

    void inserirInicio(Lista *lista, int valor);
    void inserirFim(Lista *lista, int valor);
    void inserirMeioLista(Lista *lista, int posicao, int valor);
    void imprimir(Lista *lista);
    int tamanhoLista(Lista *lista);
    void remover(Lista *lista, int valor);
    No* removerPrimeiroNO(Lista *lista);
    int elemento(Lista *lista, int posicao);
    int posicao(Lista *lista, int valor);


#endif