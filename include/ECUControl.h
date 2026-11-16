#pragma once

#include "ECUGateway.h"

enum class EstadoECU {
    INIT,
    OPERATIONAL,
    DEGRADED,
    SAFE_STATE
};

class ECUControl {
    
    private:
        EstadoECU estadoActual;

    public:
        ECUControl();
        
        void diagnosticar(const ECUGateway& gateway);

        EstadoECU getEstadoActual() const;
};