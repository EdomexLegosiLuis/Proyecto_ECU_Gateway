#pragma once

#include <string>

class Sensor{

    private:
        std::string nombre;        
        std::string unidadDeMedida;

        int valor;
        int minimo;
        int maximo;

        bool valido;
        
        int ciclosSinActualizar;

    public:

        //Constructor    
        Sensor(const std::string &nombre, const std::string &unidadDeMedida, int valor, int minimo, int maximo);
        
        //Getters
        std::string getNombre() const;
        std::string getUnidadDeMedida() const;
        int getValor() const;   
        int getMinimo() const;
        int getMaximo() const;

        //Setters
        void setNombre(const std::string &nombre);
        void setUnidadDeMedida(const std::string &unidadDeMedida);      
        void setValor(int valor);
        void setMinimo(int minimo);
        void setMaximo(int maximo);

        bool esValorValido() const;
        
        void registrarCicloSinActualizar();
};
