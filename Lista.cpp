#include "No.hpp"
#include "Lista.hPP"


void inserirInicio(Lista *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No)); // cria um novo nó
    novo->valor = valor;

    if(lista->inicio == NULL) { // a lista está vazia
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    } else { // a lista não está vazia
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    lista->tam++;
}

void inserirFim(Lista *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No)); // cria um novo nó
    novo->valor = valor;
    novo->proximo = NULL;

    if(lista->inicio == NULL) { // lista vazia
        lista->inicio = novo;
        lista->fim = novo;
    } else { // lista não vazia
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tam++;
}

void inserirMeioLista(Lista *lista, int posicao, int valor){

    No* novo = (No*) malloc(sizeof(No));
    int cont = 1;

    novo->valor = valor;

    No* aux;

    aux = lista->inicio;

    while((cont < posicao - 1) && (aux != NULL)){
        aux = aux->proximo;
        cont++;
    }
    
    novo->proximo = aux->proximo;
    aux->proximo = novo;
    lista->tam++;
}

void imprimir(Lista *lista) {
    No *inicio = lista->inicio;
    cout << "Tamanho da lista: " << lista->tam << endl;
    while(inicio != NULL) {
        cout << inicio->valor << endl;
        inicio = inicio->proximo;
    }
}

int tamanhoLista(Lista *lista){

    return lista->tam;
}

void remover(Lista *lista, int valor){
    No *inicio = lista->inicio; // ponteiro para o início da lista
    No * noARemover = NULL; // ponteiro para o nó a ser removido

    if(inicio != NULL && lista->inicio->valor == valor) { // remover 1º elemento
        noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;
        if(lista->inicio == NULL)
            lista->fim = NULL;
    } else { // remoção no meio ou no final
        while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor) {
            inicio = inicio->proximo;
        }
        if(inicio != NULL && inicio->proximo != NULL) {
            noARemover = inicio->proximo;
            inicio->proximo = noARemover->proximo;
            if(inicio->proximo == NULL) // se o último elemento for removido
                lista->fim = inicio;
        }
    }
    if(noARemover) {
        free(noARemover); // libera a memória do nó
        lista->tam--; // decrementa o tamanho da lista
    }
}

No* removerPrimeiroNO(Lista *lista) {
    if(lista->inicio != NULL) {
        No *no = lista->inicio;
        lista->inicio = no->proximo;
        lista->tam--;
        if(lista->inicio == NULL)
            lista->fim = NULL;
        return no;
    } else
        return NULL;
}

int elemento(Lista *lista, int posicao){
    No * aux;
    aux = lista->inicio;
    int cont = 1;
   
    
    if(lista == NULL){
        return 0;
    }

    if((posicao < 1) || (posicao > lista->tam)){
        return -1;
    }

    while(cont < posicao){
        aux = aux->proximo;
        cont++;
    }

    return aux->valor;
}

int posicao(Lista *lista, int valor){
    int cont = 1;
    No * aux;

    if(lista == NULL){
        return 0;
    }

    aux = lista->inicio;

    while(aux != NULL){
        if(aux->valor == valor)
            return cont;
        aux = aux->proximo;
        cont++;
    }
    return -1;

}