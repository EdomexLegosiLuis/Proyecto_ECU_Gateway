#pragma once

#include "Sensor.h"

#include <optional>
#include <string>
#include <vector>

class ECUGateway {

    private:
        std::vector<Sensor> sensores;

    public:
        ECUGateway();

        // std::nullopt significa que esa señal NO llegó en este ciclo
        void actualizarSenales(
            std::optional<double> velocidad,
            std::optional<double> rpm,
            std::optional<double> temperatura,
            std::optional<double> voltajeBateria,
            std::optional<double> presionAceite
        );

        const Sensor& obtenerSensor(const std::string& nombre) const;
};