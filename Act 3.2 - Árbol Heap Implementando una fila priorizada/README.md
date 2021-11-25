# Análisis de complejidad ⚙️ 
Para determinar la complejidad del main necesitamos saber que complejidad tienen las funciones que hace uso de ellas:


## Método push
El algoritmo empleado en esta función tiene una complejidad de O(log(n)), pues se usa la función heapify(). Esto quiere decir que en el peor de los casos, cada vez que insertas un valor, puede que hagas un swap en cada nivel para mantener la propiedad de un árbol heap.

## Método pop
El algoritmo empleado en esta función tiene una complejidad de O(log(n)), pues se usa la función heapify(). Esto quiere decir que en el peor de los casos, cada vez que insertas un valor, puede que hagas un swap en cada nivel para mantener la propiedad de un árbol heap.

Pop y Push pueden llegar a ser 
## Método top
El algoritmo empleado en esta función, solo necesita ejecutar la operaciones constantes. Por lo tanto es de O(1).

## Método empty
El algoritmo empleado en esta función, solo necesita ejecutar la operaciones constantes. Por lo tanto es de O(1).

## Método size
El algoritmo empleado en esta función, solo necesita ejecutar la operaciones constantes. Por lo tanto es de O(1).
