#include "/home/luis/Documentos/Academia Tech/Proyecto_ECU_Gateway/include/ECUControl.h"

ECUControl::ECUControl(){
    estadoActual = EstadoECU::INIT;
}

EstadoECU ECUControl::getEstadoActual() const{
    return estadoActual;
}

void ECUControl::setEstadoActual(EstadoECU nuevoEstado){
    estadoActual = nuevoEstado;
}