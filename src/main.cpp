#include <iostream>

#include "../include/ECUControl.h"
#include "../include/VehicleSimulator.h"
#include "../include/Dashboard.h"
#include "../include/ECUGateway.h"

#include <chrono>
#include <optional>
#include <thread>

int main() {

    VehicleSimulator simulador(12345);
    ECUGateway gateway;
    ECUControl control;
    Dashboard dashboard;

    // int ciclo = 0;   // <-- PRUEBA TEMPORAL (descomentar para probar validez temporal)

    while (true) {
        simulador.actualizar();

        std::optional<double> temperatura = simulador.obtenerTemperatura();

        // PRUEBA TEMPORAL: la temperatura deja de llegar después de 20 ciclos
        // if (++ciclo > 20) {
        //     temperatura = std::nullopt;
        // }

        gateway.actualizarSenales(
            simulador.obtenerVelocidad(),
            simulador.obtenerRPM(),
            temperatura,
            simulador.obtenerVoltajeBateria(),
            simulador.obtenerPresionAceite()
        );

        control.diagnosticar(gateway);
        dashboard.mostrar(control, gateway);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}