#include "Emission.h"

#include <fstream>
#include <iostream>

// Constructeur
Emission::Emission(){
    titre = "";
    animateur = "";
    chaine = new Chaine();
}

Emission::Emission (string titre,
                  string animateur,
                  string chaineName,
                  string chaineCodePostal,
                  string chaineAddress) {
    // Emission information
    this->titre = titre;
    this->animateur = animateur;
	this->chaine = new Chaine (chaineName, chaineCodePostal, chaineAddress);      
}

// Setters
void Emission::setTitre(string titre) {
    this->titre = titre;
}

void Emission::setAnimateur(string animateur) {
    this->animateur = animateur;
}


// Associer une Chaine à l'Emission
void Emission::associerChaine (Chaine* chaine) {
    this -> chaine = chaine;
}

// Getters
string Emission::getTitre() {
    return this->titre;
}
string Emission::getAnimateur() {
    return this->animateur;
}

Chaine* Emission::getChaine(){
    return chaine;
}

// Enregistrer l'Emission dans un fichier
void Emission::saveEmission (string fileName) {

    ofstream outfile (fileName.c_str(), std::ofstream::binary | std::fstream::app);
    // write to outfile
    outfile<<this->titre <<","
                   <<this->animateur <<"\n";
    outfile.close();
}

string Emission::trouverInfo(string line, int& index) {

	if (index != 0)
		index++;
	string info;
	for (index; index < line.length(); index++) {
		if (line[index] != ',') {
			info += line[index];
		}
		else {
			break;
		}
	}
	return info;
}

// Trouver un Emission avec son nom dans la base de données DB
Emission* Emission::trouverEmission(string DB, string titre) {

	ifstream fichier(DB.c_str(), ios::in); // Ouvrir le fichier "DB.txt"
	Emission*tmp = NULL;

	if (fichier)
	{
		string line;
		// Lire les Emissions, un Emission par ligne dans la base de données (DB.txt)
		while (getline(fichier, line)) {

			// Récupérer le nom de l'Emission	
			int i = 0;
			string titreDB = trouverInfo(line, i);

			// Si l'Emission qu'on lit actuellement est celui qu'on cherche
			if (titreDB == titre) {

				// Récupérer le nom de l'animateur
				string  animateurDB = trouverInfo(line, i);

				//  Récupérer le nom de l'éditeur
				string  chaineNameDB = trouverInfo(line, i);

				// Récupérer le code postale de l'éditeur
				string  chaineCodePostalDB = trouverInfo(line, i);

				// Récupérer l'addresse de l'éditeur
				string  chaineAddressDB = trouverInfo(line, i);

				// Créer un objet de type Emission avec les informations récupérées
				Emission *a = new Emission(titreDB, animateurDB, chaineNameDB, chaineCodePostalDB, chaineAddressDB);

				// Fermer la base de données
				fichier.close();
				// Retourner l'Emission sélectionné
				return a;
			}
		}
		// Fermer la base de données
		fichier.close();
	}
	// Si l'Emission est innexistant, on retourne NULL
	return NULL;
}

// Afficher l'Emission
void Emission::afficher() {
    std::cout << "Titre : " << this->titre << std::endl;
    std::cout << "Animateur : " << this->animateur << std::endl;
    std::cout << "Chaine name : " << (this->chaine)->getChaineName() << std::endl;
    std::cout << "Chaine code postale : " << (this->chaine)->getChaineCodePostal() << std::endl;
    std::cout << "Chaine address : " << (this->chaine)->getChaineAddress() << std::endl;
}



