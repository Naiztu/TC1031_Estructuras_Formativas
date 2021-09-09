#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <iostream>

//
// sorts.h
//
//  Created on: 01/09/2021
//      Author: Angel Rico
//

template <class T>
class Sorts{
	private:
		int bin_aux(std::vector<T>, int, int, int);
		void copyArray(std::vector<T>&, std::vector<T>&, int, int);
		void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
		void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
		void swap(std::vector<T>&, int, int);
	public:
		Sorts(){}
		void ordenaSeleccion(std::vector<T>&);
		void ordenaBurbuja(std::vector<T>&);
		void ordenaMerge(std::vector<T> &v){
			std::vector<T> aux(v.size());
			mergeSplit(v,aux, 0, v.size() - 1);}
		int busqSecuencial(std::vector<T>&,int);
		int busqBinaria(std::vector<T> &v,int num){ return bin_aux(v, 0, v.size() - 1, num);};
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &v){
	int pos;

	for (int i = v.size() - 1; i > 0; i--) {
		pos = 0;
		for (int j = 1; j <= i; j++) {
			if (v[j] > v[pos]) {
				pos = j;
			}
		}

		if (pos != i) {
			swap(v, i, pos);
		}
	}
}

template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T> &v){
	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
			}
		}
	}
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) A[i] = B[i];
}
template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid &&j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}
template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

template <class T>
int Sorts<T>::busqSecuencial(std::vector<T> &v, int num){
	for (int i = 0; i < v.size() ; i++) { 
		if (num == v[i]) return i; 
	}
	return -1; 
}

template <class T>
int Sorts<T>::bin_aux(std::vector<T> v, int low, int high, int num) {
	int mid;
	if (low <= high) {
		mid = (high + low) / 2;
		if (num == v[mid]) {
			return mid;     
		} else if (num < v[mid]) { 
			return bin_aux(v, low, mid - 1, num); 
		} else if (num > v[mid]) {
			return bin_aux(v, mid + 1, high, num); 
		}
	}
	return -1; 
}

#endif
