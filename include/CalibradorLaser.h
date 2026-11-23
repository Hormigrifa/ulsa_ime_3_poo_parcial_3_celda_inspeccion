#pragma once

#include <string>

#include "Dispositivo.h"
#include "Calibrable.h"

namespace calidad {

class CalibradorLaser final
    : public Dispositivo,
      public Calibrable {

private:
    double desfase_;

public:
    explicit CalibradorLaser(
        const std::string& id
    );

    bool inspeccionar(
        const Pieza& pieza
    ) const override;

    std::string descripcion()
        const override;

    bool calibrar() override;
};

}
