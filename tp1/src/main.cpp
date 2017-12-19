/* 
 * File:   main.cpp
 * Author: bram
 *
 * Created on November 8, 2015, 8:39 PM
 */

#include <iostream>
#include "HashMap.h"
#include <fstream>

using namespace std;

/* Pari lit le fichier et retourne le mot qui apparait le plus de fois */
int main(int argc, char** argv) {

	HashMap map;
    HashMap myMap;
    string nomDeFichier = argv[1];
    ifstream file;
    file.open(nomDeFichier.c_str());
    std::string word;
    while ( file >> word )
    {
	map.compteur(word);
	cout<< word <<endl;
    }
 
 
  //utilisation normale
  HashMap hmap;
  hmap.put("v1",1);
  hmap.put("v3",1);
  hmap.put("v11",1);
  hmap.put("v13",13);
  
  int value;
  bool res = hmap.get("v13", value);
  if (res)
    cout << value << endl;
  
  hmap.remove("v1");
  res = hmap.get("v1", value);
  if (res)
    cout << "ERROR: " << value << endl;

  std::vector<std::string> keys=hmap.getKeys();
  for(unsigned int i=0;i<keys.size();i++){
    cout << keys[i] << endl;
  }
  
  return 0;
}

