#ifndef FUNCIONES_H
#define FUNCIONES_H

//
// funciones.h
//
//  Created on: 25/08/2021
//      Author: Angel Rico
//

class Funciones{
	public:
		Funciones(){}
		int sumaIterativa(int);
		int sumaRecursiva(int);
		int sumaDirecta(int);
};


/**
 * sumaDirecta()
 * 
 * Usando el metodo de Gauss, se calcula el valor de la sumatoria desde el uno al numero enviado como parametro
 * @param int limite de la sumatoria
 * @return int valor de la sumatoria
 *
 */
 int Funciones::sumaDirecta(int n){
	return ((n*(n+1))/2);
}

/*
 * sumaIterativa
 * 
 * Usando un metodo iterativo, se calcula el valor de la sumatoria desde el uno al numero enviado como parametro
 * @param int limite de la sumatoria
 * @return int valor de la sumatoria
 *
 */
int Funciones::sumaIterativa(int n){
	int S=0;
	for(int i=1; i<=n; i++){
		S+=i;
	}
	return S;
}

/**
 * sumaIterativa
 * 
 * Usando un metodo recursivo, se calcula el valor de la sumatoria desde el uno al numero enviado como parametro
 * @param int limite de la sumatoria
 * @return int valor de la sumatoria
 *
 */
int Funciones::sumaRecursiva(int n){
	if(n==0) return 0;
	return n + sumaRecursiva(n-1);
}

#endif
