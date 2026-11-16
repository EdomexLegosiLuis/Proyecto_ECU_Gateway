#include "Sensor.h"

Sensor::Sensor(
    const std::string &nombre,
    const std::string &unidadDeMedida, 
    double minimo, 
    double maximo){

    this->nombre = nombre;
    this->unidadDeMedida = unidadDeMedida;    
    this->minimo = minimo;
    this->maximo = maximo; 
    this->valor = minimo;
    this->ciclosSinActualizar = 0;
}

    
        std::string Sensor::getNombre() const{
            return nombre;
        }

        std::string Sensor::getUnidadDeMedida() const{
            return unidadDeMedida;
        }

        double Sensor::getValor() const{
            return valor;
        } 

        double Sensor::getMinimo() const{
            return minimo;
        }

        double Sensor::getMaximo() const{
            return maximo;
        }

        void Sensor::setNombre(const std::string &nombre){
            this->nombre = nombre;
        }

        void Sensor::setUnidadDeMedida(const std::string &unidadDeMedida){
            this->unidadDeMedida = unidadDeMedida;
        }

        void Sensor::setValor(double valor){
            this->valor = valor;
            ciclosSinActualizar = 0;
        }

        void Sensor::setMinimo(double minimo){
            this->minimo = minimo;
        }

        void Sensor::setMaximo(double maximo){
            this->maximo = maximo;
        }

        void Sensor::setValido(bool valido) {
            this->valido = valido;
        }

        bool Sensor::esRangoValido() const{
            return valido && valor >= minimo && valor <= maximo;
        }

        void Sensor::registrarCicloSinActualizar() {
            ciclosSinActualizar++;

            if (ciclosSinActualizar > 5) {
                valido = false;
            }
        }