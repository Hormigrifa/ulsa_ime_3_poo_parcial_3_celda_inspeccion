#include <iostream>

#include "Bascula.h"
#include "CalibradorLaser.h"
#include "CamaraVision.h"
#include "SensorTemperatura.h"

#include "CeldaInspeccion.h"
#include "DatosTurno.h"
#include "ReporteTurno.h"

using namespace calidad;

int main() {

    // Dispositivos
    Bascula bascula("B-01");
    CalibradorLaser laser("L-01");
    CamaraVision camara("V-01");
    SensorTemperatura sensor("T-01");

    // Celda
    CeldaInspeccion celda;

    // Agregación
    celda.agregarDispositivo(&bascula);
    
