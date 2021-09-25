#ifndef LIST_H
#define LIST_H

#include <vector>
#include <iostream>

//
// list.h
//
//  Created on: 24/09/2021
//      Author: Angel Rico
//

#include <string>
#include <sstream>

template <class T> class List;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

template <class T>
class List {
public:
	List();
	~List();

	void first(T);
	void insertion(T);
    int search(T);
    void update(int, T);
    void deleteAt(int);
	bool empty() const;
	void clear();
	std::string toString() const;

private:
	Link<T> *head;
	int 	size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
void List<T>::first(T val){
	Link<T> *newLink;

	newLink = new Link<T>(val);
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::insertion(T val){
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);
	if (empty()) {
		first(val);
		return;
	}

	p = head;
	while (p->next != 0) {
		p = p->next;
	}

	newLink->next = 0;
	p->next = newLink;
	size++;
}

template <class T>
int List<T>::search(T val){
	Link<T> *p;
	int i;

	if (empty()){
        return -1;
	}

    p = head;
    i = 0;
    while (p != 0){
        if (p->value == val){
            return i;
        }
        i++;
        p = p -> next;
    }
    return -1;
}

template <class T>
void List<T>::update(int index, T val){
    Link<T> *p;
	int i;

    p = head;
    i = 0;
    while (p != 0){
        if(i == index){
            p->value = val;
        }
        i++;
        p = p -> next;
    }
}

template <class T>
void List<T>::deleteAt(int index){
    Link<T> *p, *aux;
	int i;

    p = head;
    i = 0;
    if (index == 0){
        aux = p;
        head = p -> next;

        delete aux;
        size--;
    }else if(index == size-1){
         while (i != size-2){
            i++;
            p = p -> next;
        }
        aux = p -> next;
        p -> next = 0;
        delete aux;
        size--;

    }else{
        while (p != 0){
            if((i == index-1)&&(i != size-1)){
                aux = p -> next;
                p-> next = p -> next -> next;
                delete aux;
                size--;
            }
            i++;
            p = p -> next;
        }
    }



   
}



template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0){
		q = p -> next;
		delete p;
		p = q;
	}

	head = 0;
	size = 0;

}


template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

#endif