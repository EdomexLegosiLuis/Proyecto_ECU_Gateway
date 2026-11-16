#pragma once

#include <random>

class VehicleSimulator 
{
    private:

        std::mt19937 generador;

        std::normal_distribution<double> ruido;

        double velocidad;
        double rpm;
        double temperatura;
        double voltajeBateria;
        double presionAceite;

        double acelerador;

    public:

        VehicleSimulator(unsigned int semilla);

        void actualizar();

        double obtenerVelocidad() const;
        double obtenerRPM() const;
        double obtenerTemperatura() const;
        double obtenerVoltajeBateria() const;
        double obtenerPresionAceite() const;

        double obtenerAcelerador() const;

};


/*
DatosVehiculo generarDatosIniciales();

DatosVehiculo actualizarSimulacion(const DatosVehiculo& datosActuales);
*/