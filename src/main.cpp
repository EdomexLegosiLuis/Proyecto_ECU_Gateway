#include <iostream>

#include "../include/ECUControl.h"
#include "../include/VehicleSimulator.h"
#include "../include/Dashboard.h"
#include "../include/ECUGateway.h"

#include <chrono>
#include <thread>
int main() {

    VehicleSimulator simulador(12345);
    ECUGateway gateway;
    ECUControl control;
    Dashboard dashboard;

    while (true) {
        simulador.actualizar();

        gateway.actualizarSeñalesSensores(
            simulador.obtenerVelocidad(),
            simulador.obtenerRPM(),
            simulador.obtenerTemperatura(),
            simulador.obtenerVoltajeBateria(),
            simulador.obtenerPresionAceite()
        );

        control.diagnosticar(gateway);
        dashboard.mostrar(control, gateway);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}