#include "Equipo.h"

struct EquipoSt {
    Seleccion seleccion;
    string nombre;
    string grupo;
};
/*
    INV.REP: 
     sea EquipoSt{ s n g} una representacion de un EquipoSt:
        ->n es el nombre del equipo 
        ->g es el grupo en el cual participa.  
        ->s es la seleccion del equipo. (representa al pais)
*/

Equipo crearEquipo(Seleccion s, string grupo) {
    Equipo e     = new EquipoSt;
    e->seleccion = s;
    e->nombre    = nombreDeSeleccion(s);
    e->grupo     = grupo;
    return e;
}

string nombreDeSeleccion(Seleccion s) {
    string selecciones[32];
    selecciones[ESTADOSUNIDOS] = "Estados Unidos";
    selecciones[COSTARICA]     = "Costa Rica";
    selecciones[COLOMBIA]      = "Colombia";
    selecciones[PARAGUAY]      = "Paraguay";
    selecciones[HAITI]         = "Haiti";
    selecciones[PERU]          = "Peru";
    selecciones[BRASIL]        = "Brasil";
    selecciones[ECUADOR]       = "Ecuador";
    selecciones[VENEZUELA]     = "Venezuela";
    selecciones[MEXICO]        = "Mexico";
    selecciones[URUGUAY]       = "Uruguay";
    selecciones[JAMAICA]       = "Jamaica";
    selecciones[ARGENTINA]     = "Argentina";
    selecciones[BOLIVIA]       = "Bolivia";
    selecciones[CHILE]         = "Chile";
    selecciones[PANAMA]        = "Panama";
    selecciones[FRANCIA]       = "Francia"; // EUROPEAS
    selecciones[ESPAÑA]        = "España";
    selecciones[ALEMANIA]      = "Alemania";
    selecciones[ITALIA]        = "Italia";
    selecciones[CROACIA]       = "Croacia";
    selecciones[ESLOVENIA]     = "Eslovenia";
    selecciones[ESTONIA]       = "Estonia";
    selecciones[LETONIA]       = "Letonia";
    selecciones[POLONIA]       = "Polonia";
    selecciones[PORTUGAL]      = "Portugal";
    selecciones[HOLANDA]       = "Holanda";
    selecciones[SUECIA]        = "Suecia";
    selecciones[NORUEGA]       = "Noruega";
    selecciones[AUSTRIA]       = "Austria";
    selecciones[SUIZA]         = "Suiza";
    selecciones[BELGICA]       = "Belgica";
    return selecciones[s];
}

Seleccion seleccionEquipo(Equipo e) {
    return e->seleccion;
}

string nombreEquipo(Equipo e) {
    return e->nombre;
}

string grupoEquipo(Equipo e) {
    return e->grupo;
}
