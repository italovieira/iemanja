#ifndef FILA_H
#define FILA_H

#include "lista_duplamente_encadeada.h"

template <typename T>
class Fila {
private:
    LinkedList<T> *lista;
public:
    Fila();
    ~Fila();
    T front();
    void enqueue(T item);
    T dequeue();

    bool is_empty();
    int size();
};

template <typename T>
Fila<T>::Fila() {
    lista = new LinkedList<T>;
}

template <typename T>
Fila<T>::~Fila() {}

template <typename T>
void Fila<T>::enqueue(T item) {
    lista->push_front(item);
}

template <typename T>
T Fila<T>::dequeue() {
    int indice = lista->length() - 1;
    T valor = lista->get_element(indice);
    lista->remove(indice);

    return valor;
}

template <typename T>
T Fila<T>::front() {
    return lista->get_element(lista->length() - 1);
}

template <typename T>
bool Fila<T>::is_empty() {
    return lista->is_empty();
}

template <typename T>
int Fila<T>::size() {
    return lista->length();
}

#endif
