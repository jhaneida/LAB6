#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

enum Prioridad { ALTA, MEDIA, BAJA };
enum Estado { COMPLETA, EN_PROGRESO, PENDIENTE };
enum Categoria { TRABAJO, HOGAR, ESTUDIO };

class Tarea {
private:
    int id;
    string nombre;
    string descripcion;
    int duracionEstimada;
    tm fechaVencimiento;
    Prioridad prioridad;
    Estado estado;
    Categoria categoria;
    string responsable;
    vector<Tarea> subtareas;
    tm fechaUltimaModificacion;

    string prioridadToString() const;
    string estadoToString() const;
    string categoriaToString() const;

public:
    Tarea(int id, string nombre, string descripcion, int duracionEstimada, tm fechaVencimiento,
        Prioridad prioridad, Estado estado, Categoria categoria, string responsable);

    void agregarSubtarea(const Tarea& subtarea);
    void actualizarFechaModificacion();
    void mostrarTarea() const;
};

#endif // TAREA_H
