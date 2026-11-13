# proyecto_04_11_26
codigo estudiantil: 104626011496

Preguntas:

1. Por que no se puede crear un objeto de Vehiculo directamente?
Porque Vehiculo tiene sus metodos virtuales puros que son: getTipo()=0 y cobrar()=0, por eso seria una clase abstracta.
El compilador no deja hacer new Vehiculo, solo deja new Carro, Moto, Bus o Camion que si lo implementan.

2. Por que el destructor de vehiculo es virtual?
Porque los vehiculos se guardan como Vehiculo* y se borran con delete sobre ese puntero.
Pero con destructor virtual se llama el de la clase real como carro, moto y asi y luego el de la base, si no solo al puntero.

3. Que hace el programa si se registra un paso con un puntero nulo?
En Caseta::regitrarPaso lanza DatosInvalidos, pasa que no crea el registro y no cambia el recaudo.
Lo decide asi porque con un punturo nulo no hay placa ni valor que cobrar, y el main es el que muestra el mensaje.