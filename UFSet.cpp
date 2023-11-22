#include "UFSet.h"

/*
 * UFSet.cpp contiene la implementación de la interfaz para UFSet declarada en UFSet.h. 
 * Deben implementarse las operaciones de acuerdo a la representación elegida para el tipo UFSet.
 */

/* El tipo UFNode* representa:
 *  1. un elemento de un UFSet (o sea, un nodo del árbol que contiene a todos los elementos del conjunto)
 *  2. al conjunto en su totalidad, si el nodo es la raíz del arbol
 *
 *  El nodo tiene un puntero a su elemento asociado en el campo element. 
 *  Deberán agregarse los campos necesarios para completar la representación.
 */
struct UFNode {
   ELEM_TYPE element;
   int rango;              
   UFSet nodoPadre;
};

/* 
 * Inicializa el UFSet ufset, cuyo valor asociado será value 
 */
UFSet createUFS(ELEM_TYPE value) {
   // COMPLETAR
   UFSet nodo = new UFNode;
   nodo->nodoPadre = NULL;
   nodo->element= value;
   nodo->rango=0;
   return nodo;
}

ELEM_TYPE elemUFS(UFSet ufset) {
   // COMPLETAR
   return ufset->element;
}

/*
 * Encuentra el elemento distinguido para el UFSet dado. 
 * Esta operación puede ser optimizada con la técnica de compresión de camino.
 */
UFSet findUFS(UFSet elem) {
   // COMPLETAR
   // find optimizado no modifica el rango.

   UFSet nodoRaiz = elem;
   while (nodoRaiz->nodoPadre != NULL)   {
      nodoRaiz = nodoRaiz->nodoPadre;
   }
   //return nodoRaiz; // esto esto sólo devuelve la raiz sin comprimir la estructura.

   // a partir de acá es la version optimizada.
   UFSet nodoActual = elem;
   UFSet nodoSiguiente = elem;
   for(int i= 0; nodoSiguiente != NULL && i < nodoRaiz->rango ; i++){
      nodoSiguiente = nodoActual ->nodoPadre;
      nodoActual->nodoPadre = nodoRaiz;
      nodoActual =nodoSiguiente;
   }

   return nodoRaiz;
}


/*
 * Calcula la unión entre los conjuntos ufset1 y ufset2. 
 * Esta operación puede ser optimizada con la técnica de unión por rango.
 */ 
void unionUFS(UFSet ufset1, UFSet ufset2) {
   // COMPLETAR
   // tengo que buscar las raices de ambos nodos

   UFSet nodoRaiz1 = findUFS(ufset1);
   UFSet nodoRaiz2 = findUFS (ufset2); 
   /*UFSet nodoRaiz1= ufset1;
   while (nodoRaiz1->nodoPadre != NULL )   {
      //nodoRaiz1 = nodoRaiz1->nodoPadre; // busco la raiz de usfset1
   }

   UFSet nodoRaiz2 = ufset2;
   while (nodoRaiz1->nodoPadre != NULL )   {
      nodoRaiz2 = nodoRaiz2->nodoPadre; // busco la raiz de usfset2
   }*/

   //asigno el nodo padre según el rango 
   if (nodoRaiz1->rango > nodoRaiz2->rango)   {
      nodoRaiz2->nodoPadre = nodoRaiz1; 
   }
   if (nodoRaiz1->rango < nodoRaiz2->rango){
      nodoRaiz1->nodoPadre = nodoRaiz2; 
   }
   if (nodoRaiz1->rango = nodoRaiz2->rango){
      nodoRaiz2->nodoPadre = nodoRaiz1;
      nodoRaiz1->rango++;
   }
   
}
