# Análisis de complejidad ⚙️ 
Para determinar la complejidad del main necesitamos saber que complejidad tienen las funciones que hace uso de ellas:


## Método add
El algoritmo empleado en esta función, solo necesita ejecutar las operaciones por la cantidad de datos en el árbol. Pero al usar las condiciones y recursión los pasos se disminuyen a cambio de una lista, por lo tanto, es de O(log(n)).

## Método remove
El algoritmo empleado en esta función, solo necesita ejecutar las operaciones por la cantidad de datos en el árbol. Pero al usar las condiciones y recursión los pasos se disminuyen a cambio de una lista, y después se hace un loop por n cantidad de veces, por lo tanto, es de O(log(n)*n).

## Método find
El algoritmo empleado en esta función, solo necesita ejecutar las operaciones por la cantidad de datos en el árbol. Pero al usar las condiciones y recursión los pasos se disminuyen a cambio de una lista, por lo tanto, es de O(log(n)).

## Método size
El algoritmo empleado en esta función, solo necesita ejecutar las operaciones con recursividad. Por lo tanto, es de O(n).

## Método play
El algoritmo empleado en esta función, solo necesita ejecutar las operaciones por cierta cantidad de datos en el árbol.  Por lo tanto, es de O(n).


