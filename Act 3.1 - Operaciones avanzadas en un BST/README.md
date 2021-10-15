# Análisis de complejidad ⚙️ 
Para determinar la complejidad del main necesitamos saber que complejidad tienen las funciones que hace uso de ellas:


## Método visit
El algoritmo empleado en esta función(inoder, preorder, postorde, levelbylevel), solo necesita ejecutar la operaciones constantes, pero n veces segun el tamaño del arbol. Por lo tanto es de O(n).

## Método Ancestors
El algoritmo empleado en esta función, solo necesita ejecutar la operaciones constantes, pero n veces segun el tamaño del arbol. Por lo tanto es de O(n).

## Método ancestors
El algoritmo empleado en esta función, solo necesita ejecutar la operaciones constantes, pero cada vez disminuye los pasos segun el tamaño del arbol. Por lo tanto es de O(log(n)).

## Método whatlevelamI
El algoritmo empleado en esta función, solo necesita ejecutar la operaciones constantes, pero n veces segun el tamaño del arbol. Por lo tanto es de O(n).
