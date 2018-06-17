#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <typename T>
struct node {
    T content;
    struct node * next;
    struct node * prev;
};

// List with head
template <typename T>
class LinkedList {
    struct node<T> * head;
    struct node<T> * tail;
    int size;

    public:
    LinkedList();
    ~LinkedList();

    void push_back(T content);
    void push_front(T content);
    int  search(T content);
    T    get_element(int index);
    void remove(int index);
    void erase();
    int  length();
    bool is_empty();
    void print();
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = new struct node<T>;
    head->next = nullptr;
    head->prev = nullptr;

    tail = new struct node<T>;
    tail->next = nullptr;
    tail->prev = nullptr;

    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    this->erase();
}

template <typename T>
bool LinkedList<T>::is_empty() {
    return size == 0;
}

template <typename T>
void LinkedList<T>::push_front(T content) {
    struct node<T> * newNode = new struct node<T>;
    newNode->content = content;
    newNode->next = head->next;
    newNode->prev = head;

    if(is_empty()) {
        tail->next = newNode;
    } else {
        head->next->prev = newNode;
    }

    head->next = newNode;

    size++;
}

template <typename T>
void LinkedList<T>::push_back(T content) {
    struct node<T> * newNode = new struct node<T>;
    newNode->content = content;
    newNode->next = nullptr;

    if(!is_empty()) {
        tail->next->next = newNode;
    }

    newNode->prev = tail->next;
    tail->next = newNode;

    if(is_empty()) {
        head->next = newNode;
    }

    size++;
}

template <typename T>
void LinkedList<T>::print() {
    struct node<T> * aux = head->next;

    while(aux != nullptr) {
        std::cout << aux->content << " ";
        aux = aux->next;
    }

    std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::remove(int index) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Não existe elemento com este índice na lista.");
    }

    struct node<T> * aux = head;

    while (index-- && aux->next) {
        aux = aux->next;
    }

    auto deleted = aux->next;
    aux->next = aux->next->next;
    delete deleted;

    // Se o item removido foi o último da lista
    if (aux->next == nullptr) {
        tail->next = aux;
    } else {
        aux->next->prev = aux;
    }

    size--;
}

template <typename T>
void LinkedList<T>::erase() {
    while (size) {
        this->remove(0);
    }
}

template <typename T>
int LinkedList<T>::length() {
    return size;
}

template <typename T>
T LinkedList<T>::get_element(int index) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Não existe elemento com este índice na lista.");
    }

    struct node<T> * aux = head;

    while (index-- && aux->next) {
        aux = aux->next;
    }

    return aux->next->content;
}

#endif
