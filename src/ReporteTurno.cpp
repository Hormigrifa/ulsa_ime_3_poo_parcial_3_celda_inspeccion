#include "ReporteTurno.h"

namespace calidad {

ReporteTurno::ReporteTurno()
    : inspeccionadas_(0),
      aceptadas_(0) {
}

ReporteTurno::ReporteTurno(
    int inspeccionadas,
    int aceptadas,
    const std::map<std::string, int>& rechazos
)
    : inspeccionadas_(inspeccionadas),
      aceptadas_(aceptadas),
      rechazos_(rechazos) {
}

void ReporteTurno::registrarPieza(
    bool aceptada
) {
    ++inspeccionadas_;

    if (aceptada) {
        ++aceptadas_;
    }
}

void ReporteTurno::registrarRechazo(
    const std::string& idDispositivo
) {
    ++rechazos_[idDispositivo];
}

int ReporteTurno::inspeccionadas() const {
    return inspeccionadas_;
}

int ReporteTurno::aceptadas() const {
    return aceptadas_;
}

int ReporteTurno::rechazadas() const {
    return inspeccionadas_ - aceptadas_;
}

bool ReporteTurno::operator==(
    const ReporteTurno& otro
) const {

    return inspeccionadas_ ==
               otro.inspeccionadas_
        && aceptadas_ ==
               otro.aceptadas_
        && rechazos_ ==
               otro.rechazos_;
}

std::ostream& operator<<(
    std::ostream& os,
    const ReporteTurno& r
) {

    os << "=== Reporte de turno ===\n";

    os << "Inspeccionadas: "
       << r.inspeccionadas_
       << '\n';

    os << "Aceptadas: "
       << r.aceptadas_
       << '\n';

    os << "Rechazadas: "
       << r.rechazadas()
       << '\n';

    os << "Rechazos por dispositivo:\n";

    for (const auto& rechazo : r.rechazos_) {

        os << "  "
           << rechazo.first
           << ": "
           << rechazo.second
           << '\n';
    }

    return os;
}

} // namespace calidad