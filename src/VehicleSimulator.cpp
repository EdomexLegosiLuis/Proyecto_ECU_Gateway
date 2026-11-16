#include "VehicleSimulator.h"

#include <algorithm>

VehicleSimulator::VehicleSimulator(unsigned int semilla)
:
generador(semilla),
ruido(0.0, 1.0),
velocidad(0.0),
rpm(800.0),
temperatura(25.0),
voltajeBateria(12.6),
presionAceite(1.5),
acelerador(0.0)
{
}

void VehicleSimulator::actualizar()
{
    std::uniform_real_distribution<double> cambioAcelerador(-8.0, 8.0);

    acelerador += cambioAcelerador(generador);

    acelerador = std::clamp(acelerador, 0.0, 100.0);

    // Velocidad

    //double velocidadObjetivo = acelerador * 1.8;

    //velocidad += (velocidadObjetivo - velocidad) * 0.05;    // Kp 

    //velocidad += ruido(generador) * 0.3;

    //velocidad = std::max(0.0, velocidad);

    // RPM

    rpm = 800.0 + velocidad * 22.0 + acelerador * 18.0 + ruido(generador) * 50.0;

    rpm = std::clamp(rpm, 700.0, 7000.0);

    // Temperatura

    double temperaturaObjetivo = 85.0 + acelerador * 0.08;

    temperatura += (temperaturaObjetivo - temperatura) * 0.01;   // Kp

    temperatura += ruido(generador) * 0.05;

    // Voltaje

    voltajeBateria = 13.8 + ruido(generador) * 0.08;

    // Presion Aceite

    presionAceite = 1.0 + rpm/2000.0 + ruido(generador) * 0.05;

    presionAceite = std::max(0.0, presionAceite);

}


double VehicleSimulator::obtenerVelocidad() const
{
    return velocidad;
}

double VehicleSimulator::obtenerRPM() const
{
    return rpm;
}

double VehicleSimulator::obtenerTemperatura() const
{
    return temperatura;
}

double VehicleSimulator::obtenerVoltajeBateria() const
{
    return voltajeBateria;
}

double VehicleSimulator::obtenerPresionAceite() const
{
    return presionAceite;
}

double VehicleSimulator::obtenerAcelerador() const
{
    return acelerador;
}


/*

static std::mt19937 generador(42);

double generarNumeroAleatorio(double minimo, double maximo){
    std::uniform_real_distribution<double> distribucion(minimo, maximo);

    return distribucion(generador);
}

DatosVehiculo generarDatosIniciales(){
    DatosVehiculo datos;

    datos.velocidad = 0.0;
    datos.rpm = 800;
    datos.temperatura = 25.0;
    datos.voltajeBateria = 12.5;
    datos.presionAceite = 2.5;

    return datos;
}

DatosVehiculo actualizarSimulacion(const DatosVehiculo& datosActuales){
    DatosVehiculo datosNuevos = datosActuales;

    datosNuevos.velocidad += generarNumeroAleatorio(-2.0, 4.0);

    if (datosNuevos.velocidad < 0){
        datosNuevos.velocidad = 0;
    }

    if (datosNuevos.velocidad > 180.0){
        datosNuevos.velocidad = 180.0;
    }

    datosNuevos.rpm = 800 + static_cast<int>(datosNuevos.velocidad * 30.0) + static_cast<int>(generarNumeroAleatorio(-150, 150));

    if (datosNuevos.rpm < 750){
        datosNuevos.rpm = 750;
    }

    if (datosNuevos.rpm > 6500){
        datosNuevos.rpm = 6500;
    }

    if(datosNuevos.temperatura < 90.0){
        datosNuevos.temperatura += generarNumeroAleatorio(0.1, 0.6);
    }

    else
    {
        datosNuevos.temperatura += generarNumeroAleatorio(-0.2, 0.2);
    }

    datosNuevos.voltajeBateria = 13.8 + generarNumeroAleatorio(-0.15, 0.15);

    datosNuevos.presionAceite = 1.5 + datosNuevos.rpm/2000.0 + generarNumeroAleatorio(-0.15, 0.15);

    return datosNuevos;
}

*/







