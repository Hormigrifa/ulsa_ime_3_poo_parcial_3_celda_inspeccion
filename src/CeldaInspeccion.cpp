#include "CeldaInspeccion.h"

#include <iostream>

#include "Calibrable.h"

namespace calidad {

void CeldaInspeccion::agregarDispositivo(
    Dispositivo* d
) {
    dispositivos_.push_back(d);
}

void CeldaInspeccion::iniciarTurno() {

    std::cout << "=== Inicio de turno ===\n";

    for (Dispositivo* d : dispositivos_) {

        if (Calibrable* c =
                dynamic_cast<Calibrable*>(d))
        {
            std::cout
                << "Calibrando "
                << d->id()
                << " ("
                << d->descripcion()
                << ") ... "
                << (c->calibrar()
             