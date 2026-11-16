#pragma once

#include <string>

class Sensor{

    private:
        std::string nombre;        
        std::string unidadDeMedida;

        double valor;
        double minimo;
        double maximo;

        bool valido = true;

        int ciclosSinActualizar;

    public:

        //Constructor    
        Sensor(const std::string &nombre, const std::string &unidadDeMedida, double minimo, double maximo);
        
        //Getters
        std::string getNombre() const;
        std::string getUnidadDeMedida() const;
        double getValor() const;   
        double getMinimo() const;
        double getMaximo() const;

        //Setters
        void setNombre(const std::string &nombre);
        void setUnidadDeMedida(const std::string &unidadDeMedida);      
        void setValor(double valor);
        void setMinimo(double minimo);
        void setMaximo(double maximo);
        void setValido(bool valido);

        bool esRangoValido() const;
        
        void registrarCicloSinActualizar();
};
