#include "Tarea.h"

Tarea::Tarea(int id, string nombre, string descripcion, int duracionEstimada, tm fechaVencimiento,
    Prioridad prioridad, Estado estado, Categoria categoria, string responsable)
    : id(id), nombre(nombre), descripcion(descripcion), duracionEstimada(duracionEstimada),
    fechaVencimiento(fechaVencimiento), prioridad(prioridad), estado(estado),
    categoria(categoria), responsable(responsable) {
    time_t now = time(0);
    localtime_s(&fechaUltimaModificacion, &now);
}

void Tarea::agregarSubtarea(const Tarea& subtarea) {
    subtareas.push_back(subtarea);
    actualizarFechaModificacion();
}

void Tarea::actualizarFechaModificacion() {
    time_t now = time(0);
    localtime_s(&fechaUltimaModificacion, &now);
}

void Tarea::mostrarTarea() const {
    char buffer[26];
    asctime_s(buffer, sizeof(buffer), &fechaVencimiento);
    string fechaVencimientoStr(buffer);

    asctime_s(buffer, sizeof(buffer), &fechaUltimaModificacion);
    string fechaUltimaModificacionStr(buffer);

    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Descripción: " << descripcion << endl;
    cout << "Duración Estimada: " << duracionEstimada << " minutos" << endl;
    cout << "Fecha de Vencimiento: " << fechaVencimientoStr;
    cout << "Prioridad: " << prioridadToString() << endl;
    cout << "Estado: " << estadoToString() << endl;
    cout << "Categoría: " << categoriaToString() << endl;
    cout << "Responsable: " << responsable << endl;
    cout << "Fecha Última Modificación: " << fechaUltimaModificacionStr;
    cout << "Subtareas: " << subtareas.size() << endl;
    for (const auto& subtarea : subtareas) {
        subtarea.mostrarTarea();
    }
}

string Tarea::prioridadToString() const {
    switch (prioridad) {
    case ALTA: return "Alta";
    case MEDIA: return "Media";
    case BAJA: return "Baja";
    }
    return "";
}

string Tarea::estadoToString() const {
    switch (estado) {
    case COMPLETA: return "Completa";
    case EN_PROGRESO: return "En progreso";
    case PENDIENTE: return "Pendiente";
    }
    return "";
}

string Tarea::categoriaToString() const {
    switch (categoria) {
    case TRABAJO: return "Trabajo";
    case HOGAR: return "Hogar";
    case ESTUDIO: return "Estudio";
    }
    return "";
}
