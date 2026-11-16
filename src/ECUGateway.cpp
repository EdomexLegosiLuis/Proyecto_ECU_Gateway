#include "ECUGateway.h"

#include <algorithm>
#include <array>
#include <stdexcept>

ECUGateway::ECUGateway() {
    sensores = {
        Sensor("Velocidad", "km/h", 0.0, 220.0),
        Sensor("RPM", "rpm", 600.0, 7000.0),
        Sensor("Temperatura", "°C", 0.0, 110.0),
        Sensor("Voltaje de bateria", "V", 11.5, 15.0),
        Sensor("Presion de aceite", "bar", 0.8, 6.0)
    };
}

void ECUGateway::actualizarSenales(
    std::optional<double> velocidad,
    std::optional<double> rpm,
    std::optional<double> temperatura,
    std::optional<double> voltajeBateria,
    std::optional<double> presionAceite
) {
    // Mismo orden que el vector del constructor
    const std::array<std::optional<double>, 5> entradas = {
        velocidad, rpm, temperatura, voltajeBateria, presionAceite
    };

    for (std::size_t i = 0; i < sensores.size(); ++i) {
        if (entradas[i].has_value()) {
            sensores[i].actualizar(*entradas[i]);
        } else {
            sensores[i].registrarCicloSinActualizar();
        }
    }
}

const Sensor& ECUGateway::obtenerSensor(const std::string& nombre) const {
    auto it = std::find_if(sensores.begin(), sensores.end(),
        [&](const Sensor& sensor) {
            return sensor.getNombre() == nombre;
        });

    if (it == sensores.end()) {
        throw std::runtime_error("Sensor no encontrado: " + nombre);
    }

    return *it;
}