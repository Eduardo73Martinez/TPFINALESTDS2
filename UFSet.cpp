#include "UFSet.h"
   /*
      INV.REP: 
         sea UFNode{e r p} una representación de UFNode:
         -> e es un elemento perteneciente al conjunto sin importar cual es la relación.
         -> r es la cantidad de nodos de la rama más larga de un arbol que contiene como padre al nodo actual.
         -> p es el nodo padre del nodo actual. 
         -> si UfNode es el elemento distinguido del conjunto entonces p es NULL (en realidad apunta a NULL).

         
      Observacion:
        Definimos como nodo padre al nodo que se encuentra en el siguiente
        nodo más cercano a la raiz.
        Definimos como elemento distinguido de un conjunto a la raiz de un árbol.
        UFNode* representa  un elemento de un UFSet o  al conjunto en su totalidad, si el nodo es la raíz del arbol.
   */
struct UFNode {
   ELEM_TYPE element;
   int rango;              
   UFSet nodoPadre;
};


UFSet createUFS(ELEM_TYPE value) {
    /*
   Proposito: 
      describe un conjunto UFSet con el elemento value dado. 
   Precondicion: 
      ninguna.
   */

   UFSet nodo = new UFNode;
   nodo->nodoPadre = NULL;
   nodo->element= value;
   nodo->rango=0;
   return nodo;
}

ELEM_TYPE elemUFS(UFSet ufset) {
   /*
      Propósito: describe el elemento del conjunto dado. 
      Precondición:niguna.
   */
   return ufset->element;
}

UFSet findUFS(UFSet elem) {
   /*
   Proposito: 
      describe el elemento distinguido para el conjunto UFSet dado. 

   Precondicion: 
      ->la rama del àrbol a la cual pertenece el elemento dado tiene una cantidad menor de nodos que el rango 
        del elemento distinguido. Esto sucede porque no conocemos las otras ramas de la raiz, de no ser 
        así deberiamos actualizar el rango cuando optimizamos.
      ->si el rango y la cantidad de nodos de la rama del elemento dado son iguales entonces existe almenos otra rama 
        con igual cantidad de nodos que tienen como nodo padre a ese nodo.
   */
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

void unionUFS(UFSet ufset1, UFSet ufset2) {
   /*
      Propósito: describe la unión entre los conjuntos ufset1 y ufset2. 
      Precondición:niguna.
   */
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
