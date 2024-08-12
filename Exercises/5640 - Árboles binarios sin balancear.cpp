// https://omegaup.com/arena/problem/Arboles-binarios-sin-balancear/#problems

#include <stdio.h>
#include <stdlib.h>

#define Nodo struct nodo

Nodo {
    int dato;
    Nodo *izq;
    Nodo *der;
};

Nodo *raiz = NULL;

int insertarArbol(int dato);

int main() {
    int N, x, i;

    scanf("%i", &N);

    for (i = 0; i < N; i++) {
        scanf("%i", &x);
        printf("%i\n", insertarArbol(x));
    }

    return 0;
}

int insertarArbol(int dato) {
    int cont = 0;

    Nodo *aux = raiz;
    Nodo *ant = NULL;
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));

    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    while (aux != NULL) {
        ant = aux;
        if (nuevo->dato > aux->dato) {
            aux = aux->der;
        } else {
            aux = aux->izq;
        }
        cont++;
    }

    if (ant == NULL) {
        raiz = nuevo;
    } else if (nuevo->dato > ant->dato) {
        ant->der = nuevo;
    } else {
        ant->izq = nuevo;
    }

    return cont;
}
