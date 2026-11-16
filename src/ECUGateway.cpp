#include "ECUGateway.h"

#include <stdexcept>

ECUGateway::ECUGateway() {
    sensores = {
        Sensor("Velocidad", "km/h", 0.0, 220.0),
        Sensor("RPM", "rpm", 600.0, 7000.0),
        Sensor("Temperatura", "°C", 0.0, 110.0),
        Sensor("Voltaje de bateria", "V", 11.5, 15.0),
        Sensor("Presion de aceite", "psi", 0.8, 6.0)
    };
}

void ECUGateway::validarSeñalesSensores() {
    for (auto& sensor : sensores) {
        const bool enRango =
            sensor.getValor() >= sensor.getMinimo() &&
            sensor.getValor() <= sensor.getMaximo();
        sensor.setValido(enRango);
    }
}

void ECUGateway::actualizarSeñalesSensores(
    double velocidad,
    double rpm,
    double temperatura,
    double voltajeBateria,
    double presionAceite
) {
    sensores[0].setValor(velocidad);
    sensores[1].setValor(rpm);
    sensores[2].setValor(temperatura);
    sensores[3].setValor(voltajeBateria);
    sensores[4].setValor(presionAceite);

    validarSeñalesSensores();
}

const Sensor& ECUGateway::obtenerSensor(const std::string& nombre) const {
    for (const auto& sensor : sensores) {
        if (sensor.getNombre() == nombre) {
            return sensor;
        }
    }
    throw std::runtime_error("Sensor no encontrado: " + nombre);
}
