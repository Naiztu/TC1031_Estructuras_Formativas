#ifndef SORTS_H
#define SORTS_H

//
// sorts.h
//
//  Created on: 25/08/2021
//      Author: Angel Rico
//

class Sorts{
	public:
		funciones(){}
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


#endif
