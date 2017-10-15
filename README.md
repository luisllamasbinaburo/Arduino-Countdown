# Librería Arduino Countdown
Librería para Arduino implementa un contador simple. Aparte de para emplear un contador simple, como por ejemplo un contador de vueltas o un encoder, el interés principal de la librería es emplear la función de Callback para liberar de parte del código al flujo principal del programa. 

Finalmente, la funcionalidad de la librería es más interesante si la combinamos con otras librerías como AsyncTask, MultiTask, StateMachine o PetriNet.

Más información https://www.luisllamas.es/libreria-arduino-countdown/

## Instrucciones de uso
El contador se inicializa a un cierto valor mediante la variable `StartValue`. El valor actual del contador se guarda en la variable Value.

El contador dispone del método `Tick()`, que reduce el valor de Value hasta llegar a cero. También dispone del método `Reset()`, que reinicia `Value` al valor `StartValue`.

Opcionalmente, se dispone de una función de callback denominada `OnFinish`, que dispara cuando el contador llega a cero.

Por ejemplo, podemos usar el contador para ignorar los N primeros ciclos de una señal para esperar a que se estabilice, o para lanzar una función cada N ocurrencias de un evento.

### Constructor
La clase Countdown se instancia a través de uno de sus constructores.
```c++
Countdown(uint16_t startValue);
Countdown(uint16_t startValue, CountdownAction OnFinish);
```

### Usar Countdown
```c++
// Valor inicial del contador
int16_t StartValue;

// Valor actual del contador
uint16_t Value;

// Disminuye el valor de Value y lanza OnFinish si Value == 0
void Tick();

// Reinicia el valor de Value a StartValue
void Reset();

// Función de callback lanzada cuando Value == 0
CountdownAction OnFinish;
```

## Ejemplos
La librería Countdown incluye los siguientes ejemplos para ilustrar su uso.
* Countdown: Ejemplo de uso de la clase Countdown.

```c++
#include "CountdownLib.h"

#define DEBUG(A) Serial.println(A);

Countdown countDown(10, []() {
	DEBUG("Finish");
	countDown.Reset();
});

void setup()
{
	Serial.begin(115200);
}

void loop() 
{
	DEBUG(countDown.Value);
	countDown.Tick();
	delay(1000);
}
```
