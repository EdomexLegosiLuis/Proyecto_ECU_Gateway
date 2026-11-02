#pragma once

#include <vector>
#include "Sensor.h"

enum class EstadoECU {
    INIT,
    OPERATIONAL,
    DEGRADED,
    SAFE_STATE
};

class ECUControl {
    
    private:
        EstadoECU estadoActual;
        std::vector<Sensor> sensores; // Vector para almacenar los sensores asociados a la ECU


    public:
        ECUControl();
        
        EstadoECU getEstadoActual() const;
        void setEstadoActual(EstadoECU nuevoEstado);
};