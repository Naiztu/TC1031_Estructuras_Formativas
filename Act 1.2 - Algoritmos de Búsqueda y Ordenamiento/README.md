# Análisis de complejidad ⚙️ 
Para determinar la complejidad del main necesitamos saber que complejidad tienen las funciones que hace uso de ellas:


## Método Selection 
El algoritmo empleado en esta función, solo necesita ejecutar una operación booleana para obtener el resultado esperado, sin embargo, lo realiza dentro de dos ciclos, por lo cual su complejidad es de O(n^2)


## Método Bubble
El algoritmo empleado en esta función, solo necesita ejecutar una operación booleana para obtener el resultado esperado, sin embargo, lo realiza dentro de dos ciclos, por lo cual su complejidad es de O(n^2)


## Método Merge
El algoritmo empleado en esta función, se apoya con un vector auxiliar, y al pasar el resultado de uno a otro, crea una complejidad de O(n), mientras que en otra parte va haciendo operaciones donde los pasos se reducen a la mitad conforme se acomoda, lo que genera una complejidad d O(Log(n)). Juntando estos dos casos, identificamos que la complejidad es de O(n Log(n))


## Búsqueda Secuencial
El algoritmo empleado en esta función, solo necesita ejecutar una operación booleana para obtener el resultado esperado, una n cantidad de veces, por lo cual su complejidad es de O(n)


## Búsqueda Binaria
El algoritmo empleado en esta función, necesita encontrar a un valor requerido, después de cada operación, los pasos se reducen a la mitad conforme se acerca al valor, por eso se denomina con complejidad O(Log(n))
