#pragma once

#include "ECUControl.h"
#include "ECUGateway.h"

#include <string>

class Dashboard
{
    private:

        const std::string estadoATexto(EstadoECU estado) const; 

    public:

        void mostrar(const ECUControl& ecuControl, const ECUGateway& ecuGateway) const;

};