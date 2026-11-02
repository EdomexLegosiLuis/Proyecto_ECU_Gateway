#include "/home/luis/Documentos/Academia Tech/Proyecto_ECU_Gateway/include/Sensor.h"

Sensor::Sensor(
    const std::string &nombre,
    const std::string &unidadDeMedida, 
    int valor, //porque no se agregaba valor al constructor
    int minimo, 
    int maximo){

    this->nombre = nombre;
    this->unidadDeMedida = unidadDeMedida;
    this->valor = valor;
    this->minimo = minimo;
    this->maximo = maximo; 
    }

    
        std::string Sensor::getNombre() const{
            return nombre;
        }

        std::string Sensor::getUnidadDeMedida() const{
            return unidadDeMedida;
        }

        int Sensor::getValor() const{
            return valor;
        } 

        int Sensor::getMinimo() const{
            return minimo;
        }

        int Sensor::getMaximo() const{
            return maximo;
        }

        void Sensor::setNombre(const std::string &nombre){
            this->nombre = nombre;
        }

        void Sensor::setUnidadDeMedida(const std::string &unidadDeMedida){
            this->unidadDeMedida = unidadDeMedida;
        }

        void Sensor::setValor(int valor){
            this->valor = valor;
        }

        void Sensor::setMinimo(int minimo){
            this->minimo = minimo;
        }

        void Sensor::setMaximo(int maximo){
            this->maximo = maximo;
        }

        bool Sensor::esValorValido() const{
            return valor >= minimo && valor <= maximo;
        }

        void Sensor::registrarCicloSinActualizar() {
            ciclosSinActualizar++;

            if (ciclosSinActualizar > 5) {
                valido = false;
            }
        }