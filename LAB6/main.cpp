#include <iostream>
#include "Tarea.h"
#include "Multilista.h"

int main() {
    Multilista multilista;

    // Crear una tarea de ejemplo
    tm fechaVencimiento;
    time_t now = time(0);
    localtime_s(&fechaVencimiento, &now);
    fechaVencimiento.tm_mday += 7; // Fecha de vencimiento una semana después

    Tarea tarea1(1, "Tarea de ejemplo", "Descripción de la tarea", 120, fechaVencimiento, ALTA, PENDIENTE, TRABAJO, "Juan Perez");

    // Agregar una subtarea a la tarea
    Tarea subtarea1(2, "Subtarea de ejemplo", "Descripción de la subtarea", 60, fechaVencimiento, MEDIA, PENDIENTE, TRABAJO, "Maria Gomez");
    tarea1.agregarSubtarea(subtarea1);

    // Agregar la tarea a la multilista
    multilista.agregarTarea(tarea1);

    // Listar todas las tareas
    multilista.listarTareas();

    return 0;
}
