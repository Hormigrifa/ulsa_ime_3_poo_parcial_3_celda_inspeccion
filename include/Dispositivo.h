#pragma once

#include <string>
#include "Pieza.h"

namespace calidad {

class Dispositivo {
private:
    std::string id_;

public:
    explicit Dispositivo(const std::string& id)
        : id_(id) {}

    const std::string& id() const {
        return id_;
    }

    virtual bool inspeccionar(const Pieza& pieza) const = 0;

    virtual std::string descripcion() const = 0;

    virtual ~Dispositivo() = default;
};

}

