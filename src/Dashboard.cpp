#include "Dashboard.h"

#include <iostream>  // Impresión básica
#include <iomanip>   // Formato de salida (setw, setprecision)
#include <cstdlib>   // system("clear")

namespace {

void imprimirSensor(const Sensor& sensor)
{
    std::cout << std::left  << std::setw(20) << sensor.getNombre() << ": "
              << std::right << std::setw(10) << sensor.getValor() << " "
              << std::left  << std::setw(6)  << sensor.getUnidadDeMedida()
              << (sensor.esRangoValido() ? "VALIDA" : "INVALIDA") << "\n";
}

}

const std::string Dashboard::estadoATexto(EstadoECU estado) const
{
    switch(estado)
    {
        case EstadoECU::INIT:
            return "INIT";

        case EstadoECU::OPERATIONAL:
            return "OPERATIONAL";

        case EstadoECU::DEGRADED:
            return "DEGRADED";

        case EstadoECU::SAFE_STATE:
            return "SAFE_STATE";
    }

    return "DESCONOCIDO";
}

void Dashboard::mostrar(const ECUControl& ecuControl, const ECUGateway& ecuGateway) const
{
    system("clear");

    std::cout << "=============================================================\n";
    std::cout << "                    ECU GATEWAY / CONTROL\n";
    std::cout << "=============================================================\n";

    std::cout << std::fixed << std::setprecision(2);

    imprimirSensor(ecuGateway.obtenerSensor("Velocidad"));
    imprimirSensor(ecuGateway.obtenerSensor("RPM"));
    imprimirSensor(ecuGateway.obtenerSensor("Temperatura"));
    imprimirSensor(ecuGateway.obtenerSensor("Voltaje de bateria"));
    imprimirSensor(ecuGateway.obtenerSensor("Presion de aceite"));

    std::cout << "-------------------------------------------------------------\n";
    std::cout << "ECU CONTROL: " << estadoATexto(ecuControl.getEstadoActual()) << "\n";
    std::cout << "=============================================================\n";
}