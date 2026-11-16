#include "Dashboard.h"

#include <iostream>  // Se usa para impresión básica
#include <iomanip>  // Se usa para comandos de escape o fix para formato 
#include <cstdlib>  // Nos permite hacer operaciones referentes al sistema y su terminal


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

    std::cout << "                    ECU GATEWAYzz DASHBOARD\n";

    std::cout << "=============================================================\n";

    std::cout << "Estado ECU        : " << estadoATexto(ecuControl.getEstadoActual()) << "\n\n";

    std::cout << std::fixed << std::setprecision(2);

    std::cout << std::left << std::setw(18) 
              << ecuGateway.obtenerSensor("Velocidad").getNombre() << " : "           
              << ecuGateway.obtenerSensor("Velocidad").getValor()
              << std::right << std::setw(6) 
              << ecuGateway.obtenerSensor("Velocidad").getUnidadDeMedida() << "\n";

    std::cout << std::left << std::setw(18) 
              << ecuGateway.obtenerSensor("RPM").getNombre() << " : "     
              << ecuGateway.obtenerSensor("RPM").getValor() 
              << std::right << std::setw(6) 
              << ecuGateway.obtenerSensor("RPM").getUnidadDeMedida() << "\n";
    
    std::cout << std::left << std::setw(18) 
              << ecuGateway.obtenerSensor("Temperatura").getNombre() << " : " 
              << ecuGateway.obtenerSensor("Temperatura").getValor() 
              << std::right << std::setw(6)
              << ecuGateway.obtenerSensor("Temperatura").getUnidadDeMedida() << "\n";

    std::cout << std::left << std::setw(18) 
              << ecuGateway.obtenerSensor("Voltaje de bateria").getNombre() << " : " 
              << ecuGateway.obtenerSensor("Voltaje de bateria").getValor() 
              << std::right << std::setw(6) 
              << ecuGateway.obtenerSensor("Voltaje de bateria").getUnidadDeMedida() <<"\n";

    std::cout << std::left << std::setw(18) 
              << ecuGateway.obtenerSensor("Presion de aceite").getNombre() << " : " 
              << ecuGateway.obtenerSensor("Presion de aceite").getValor() 
              << std::right << std::setw(6) 
              << ecuGateway.obtenerSensor("Presion de aceite").getUnidadDeMedida() << "\n";

    std::cout << "=============================================================\n";

}
