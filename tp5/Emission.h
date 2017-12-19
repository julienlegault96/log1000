#ifndef Emission_H
#define Emission_H

#include <string>
#include "Chaine.h"

using namespace std;
        
// Cette classe représente un Emission
class Emission {
public:
    // Constructeurs
    Emission ();
    Emission(string, string, string, string, string);
    
    // Setters
    void setTitre(string);
    void setAnimateur(string);    
    void associerChaine(Chaine*);
    
    // Getters
    string getTitre();
    string getAnimateur();    
    Chaine* getChaine();
    
    // Enregistrer l'Emission
    void saveEmission(string);
    // Afficher l'Emission
    void afficher();

    
    // Chercher un Emission dans une base de données par titre
	string trouverInfo(string line, int& index);
    Emission* trouverEmission(string, string);
    
private:
    // Information sur l'emission
    string titre;		
    string animateur;
	Chaine* chaine;  
    
};

#endif 
