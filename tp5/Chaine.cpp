#include "Chaine.h"

#include <fstream>
#include <iostream>

// Constructeurs

Chaine::Chaine(){
    this->chaineName = "";
    this->chaineCodePostal = "";
    this->chaineAddress = "";    
}

Chaine::Chaine (string chaineName,
                  string chaineCodePostal,
                  string chaineAddress) {    
    this->chaineName = chaineName;
    this->chaineCodePostal = chaineCodePostal;
    this->chaineAddress = chaineAddress;    
}

// Getters

string Chaine::getChaineName(){
    return this->chaineName;
}

string Chaine::getChaineCodePostal() {
    return this->chaineCodePostal;
}

string Chaine::getChaineAddress(){
    return this->chaineAddress;
}



