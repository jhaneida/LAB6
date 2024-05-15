#ifndef MULTILISTA_H
#define MULTILISTA_H

#include <vector>
#include "Tarea.h"

class Multilista {
private:
    std::vector<Tarea> tareas;

public:
    void agregarTarea(const Tarea& tarea);
    void listarTareas() const;
};

#endif // MULTILISTA_H

