# ECU Gateway + ECU de Control

Proyecto de Programación C++ (Hito Rango IV): simulación de un vehículo cuyas señales
son recibidas y validadas por una **ECU Gateway** y analizadas por una **ECU de Control**
que ejecuta una **máquina de estados**. Todo se muestra en un **Dashboard** en terminal.

## Descripción

El sistema simula un vehículo de forma automática (acelerador, RPM, velocidad,
temperatura, voltaje de batería y presión de aceite, con ruido)

1. El simulador genera nuevas señales.
2. La Gateway las recibe, las almacena y valida su **rango** y su **actualización temporal**.
3. La ECU de Control consulta las señales ya validadas y ejecuta la máquina de estados.
4. El Dashboard muestra el estado de cada señal y el estado de la ECU de Control.

## Arquitectura general

```
VehicleSimulator  ->  ECUGateway  ->  ECUControl  ->  Dashboard
 (genera señales)    (valida señales)  (ejecuta FSM)   (muestra todo)
```

| Clase | Responsabilidad |
|-------|-----------------|
| `Sensor` | Guarda nombre, unidad, valor, rango, validez y ciclos sin actualizar. |
| `VehicleSimulator` | Genera señales relacionadas entre sí (Acelerador → RPM → Velocidad) con ruido y semilla fija. |
| `ECUGateway` | Almacena los sensores, valida rango y actualización, marca cada señal como válida/inválida. **No** decide estados. |
| `ECUControl` | Interpreta la validez de las señales y ejecuta la máquina de estados. |
| `Dashboard` | Muestra el estado de las señales y de la ECU de Control. |
| `main.cpp` | Solo coordina el ciclo; no contiene lógica de validación ni diagnóstico. |

## Estructura de archivos

```
Proyecto_ECU_Gateway/
├── README.md
├── include/
│   ├── Sensor.h
│   ├── VehicleSimulator.h
│   ├── ECUGateway.h
│   ├── ECUControl.h
│   └── Dashboard.h
└── src/
    ├── main.cpp
    ├── Sensor.cpp
    ├── VehicleSimulator.cpp
    ├── ECUGateway.cpp
    ├── ECUControl.cpp
    └── Dashboard.cpp
```

## Señales implementadas

| Señal | Unidad | Mínimo | Máximo | Crítica |
|-------|--------|--------|--------|---------|
| Velocidad | km/h | 0.0 | 220.0 | No |
| RPM | rpm | 600.0 | 7000.0 | No |
| Temperatura | °C | 0.0 | 110.0 | **Sí** |
| Voltaje de batería | V | 11.5 | 15.0 | No |
| Presión de aceite | bar | 0.8 | 6.0 | **Sí** |

## Criterios de validez

Una señal es **VÁLIDA** únicamente si cumple ambas condiciones:

1. **Rango:** `minimo <= valor <= maximo`.
2. **Actualización:** no ha superado el límite de ciclos sin actualizarse.

Una señal es **INVÁLIDA** si sale de rango o si deja de actualizarse. La señal nunca
se elimina del vector: solo cambia su estado de validez. Si vuelve a recibir un dato
correcto, se recupera como válida.

## Estados de la ECU de Control

| Estado | Condición |
|--------|-----------|
| `INIT` | Estado inicial, antes del primer diagnóstico. |
| `OPERATIONAL` | Todas las señales son válidas. |
| `DEGRADED` | Una señal **no crítica** es inválida (Voltaje de batería, RPM o Velocidad). Operación limitada. |
| `SAFE_STATE` | Una señal **crítica** es inválida (Temperatura o Presión de aceite). Tiene prioridad sobre DEGRADED. |

## Instrucciones de compilación

g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude   src/main.cpp src/VehicleSimulator.cpp src/ECUGateway.cpp   src/ECUControl.cpp src/Dashboard.cpp src/Sensor.cpp   -o proyecto_ecu_gateway

## Instrucciones de ejecución

```bash
./proyecto_ecu_gateway
```

El Dashboard se refresca cada 500 ms (usa `clear`, por lo que requiere terminal Linux/macOS).
Detener con `Ctrl + C`.