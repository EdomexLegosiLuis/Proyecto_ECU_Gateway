#pragma once

#include "Sensor.h"

#include <vector>

class ECUGateway {
    
    private:
        std::vector<Sensor> sensores;

    public:
        ECUGateway();
        
        void validarSeñalesSensores();
        void actualizarSeñalesSensores(
            double velocidad,
            double rpm,
            double temperatura,
            double voltajeBateria,
            double presionAceite
        );
        const Sensor& obtenerSensor(const std::string& nombre) const; 
};