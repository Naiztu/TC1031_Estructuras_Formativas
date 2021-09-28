/*
 * dlist.h
 *
 *  Created on: 10/08/2015
 *      Author: pperezm
 */

#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>

template <class T> class DList;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList {
public:
	DList();
	DList(const DList<T>&);
	~DList();

	void insertion(T);
    int search(T);
    void update(int, T);
    T deleteAt(int);
    std::string toStringForward() const;
    std::string toStringBackward() const;

private:
	DLink<T> *head;
	DLink<T> *tail;
	int 	 size;

    bool empty() const;
    int length() const;
    void clear();
};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
	clear();
}

template <class T>
bool DList<T>::empty() const {
	return (head == 0 && tail == 0);
}

template <class T>
int DList<T>::length() const {
	return size;
}

template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}


template <class T>
void DList<T>::insertion(T val){
	DLink<T> *newLink;

	newLink = new DLink<T>(val);

	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		tail->next = newLink;
		newLink->previous = tail;
		tail = newLink;
	}
	size++;
}

template <class T>
int DList<T>::search(T val) {
	int pos;
	DLink<T> *p;

	p = head;
	pos = 0;
	while (p != 0) {
		if (p->value == val){
            return pos;
        }
        p = p->next;
		pos++;
	}

	return -1;
}
template <class T>
void DList<T>::update(int index, T val){
    int pos;
    T aux;
	DLink<T> *p;

    if (index > 0 && index < size) {
        if (index == 0) {
            head->value = val;
        }else if (index == size-1){
            tail->value = val;
        } else{
            p = head;
            pos = 0;
            while (pos != index) {
                p = p->next;
                pos++;
            }
            p->value = val;
        }
	}	
}

template <class T>
T DList<T>::deleteAt(int index){
    int pos;
    T aux;
	DLink<T> *p;

	if (index < 0 || index >= size) {
		return 0;
	}

	if (index == 0) {
		p = head;
        head = p->next;
        p->next->previous = 0;
	}else if (index == size-1){
        p = tail;
        tail = p->previous;
        p->previous->next = 0;
    } else{
        p = head;
        pos = 0;
        while (pos != index) {
            p = p->next;
            pos++;
        }

        p->next->previous = p->previous;
        p->previous->next = p->next;
    }
    aux = p->value;
    delete p;
    return aux;
}


template <class T>
std::string DList<T>::toStringForward() const {
	std::stringstream aux;
	DLink<T> *p;

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

template <class T>
std::string DList<T>::toStringBackward() const {
	std::stringstream aux;
	DLink<T> *p;

	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}

#endif