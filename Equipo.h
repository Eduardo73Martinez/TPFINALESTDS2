#ifndef _EQUIPO_H
#define _EQUIPO_H

#include <iostream>

#define CANTIDAD_SELECCIONES 16

using namespace std;

struct EquipoSt;
typedef EquipoSt* Equipo;

enum Seleccion {
    ESTADOSUNIDOS,
    COSTARICA,
    COLOMBIA,
    PARAGUAY,
    HAITI,
    PERU,
    BRASIL,
    ECUADOR,
    VENEZUELA,
    MEXICO,
    URUGUAY,
    JAMAICA,
    ARGENTINA,
    BOLIVIA,
    CHILE,
    PANAMA,
    //agrego otras 16 selecciones 
    FRANCIA,
    ESPAÑA,
    SUIZA,
    BELGICA,
    CROACIA,
    PORTUGAL,
    ITALIA, 
    ALEMANIA,
    AUSTRIA,
    ESLOVENIA,
    NORUEGA,
    SUECIA, 
    ESTONIA,
    LETONIA,
    POLONIA,
    HOLANDA
};

Equipo crearEquipo(Seleccion seleccion, string grupo);

string nombreEquipo(Equipo e);

string grupoEquipo(Equipo e);

Seleccion seleccionEquipo(Equipo e);

string nombreDeSeleccion(Seleccion s);

#endif
