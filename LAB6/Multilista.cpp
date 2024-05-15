#include "Multilista.h"
#include <iostream>

void Multilista::agregarTarea(const Tarea& tarea) {
    tareas.push_back(tarea);
}

void Multilista::listarTareas() const {
    for (const auto& tarea : tareas) {
        tarea.mostrarTarea();
        std::cout << "---------------------------------" << std::endl;
    }
}
