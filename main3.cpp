
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

// Fonction de lecture du fichier
void lireFichier(string nomFichier) {

    ifstream fichier(nomFichier);

    // Verifier si le fichier est ouvert
    if (!fichier.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier : " + nomFichier);
    }

    string ligne;

    cout << "Contenu du fichier :" << endl;

    // Lire le fichier ligne par ligne
    while (getline(fichier, ligne)) {
        cout << ligne << endl;
    }

    fichier.close();
}

int main() {

    cout << "===== LECTURE D'UN FICHIER =====" << endl;

    // Premier test : fichier existant
    try {
        lireFichier("texte.txt");
    }
    catch (const exception& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    // Deuxieme test : fichier inexistant
    cout << "\n===== TEST FICHIER INTROUVABLE =====" << endl;

    try {
        lireFichier("fichier_inexistant.txt");
    }
    catch (const exception& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    cout << "\nFin du programme." << endl;

    return 0;
}
