#include "ECUControl.h"

ECUControl::ECUControl(){
    estadoActual = EstadoECU::INIT;    
    
}

void ECUControl::diagnosticar(const ECUGateway& gateway) {
    if (!gateway.obtenerSensor("Temperatura").esRangoValido() ||
        !gateway.obtenerSensor("Presion de aceite").esRangoValido()) {
        estadoActual = EstadoECU::SAFE_STATE;
    }

    else if (!gateway.obtenerSensor("Voltaje de bateria").esRangoValido() ||
             !gateway.obtenerSensor("RPM").esRangoValido() ||
             !gateway.obtenerSensor("Velocidad").esRangoValido()) {
        estadoActual = EstadoECU::DEGRADED;
    }

    else{
        estadoActual = EstadoECU::OPERATIONAL;
    }
}

EstadoECU ECUControl::getEstadoActual() const{
    return estadoActual;
}
