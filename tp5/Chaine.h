#ifndef Chaine_H
#define Chaine_H

#include <string>

using namespace std;
        
// Cette classe représente une chaine 
class Chaine {
public:
    // Constructeurs
    Chaine ();
    Chaine(string, string,string);
    
    
    // Getters
        
    string getChaineName();
    string getChaineCodePostal();
    string getChaineAddress();
   

   
private:  
    
    // Informations sur la chaine 
    string chaineName;
    string chaineCodePostal;
    string chaineAddress;
    
};

#endif 
