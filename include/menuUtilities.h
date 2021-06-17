/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Auxiliary functions declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef MENUUTILITIES
#define MENUUTILITIES 

#include <string>
using std::string;

namespace menuUtilities{
    void cls();
    void clinput();
    void pkey();
    void funcionSecreta(string);
    void ptitle();
    void reprintln();
    int takeInputRange(int min,int max);
    bool boolSelect();
}

#endif
