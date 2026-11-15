
#include <iostream>
#include <stdexcept>
using namespace std;

// Exception montant invalide
class MontantInvalideException : public runtime_error {
public:
    MontantInvalideException()
        : runtime_error("Montant invalide !") {}
};

// Exception solde insuffisant
class SoldeInsuffisantException : public runtime_error {
public:
    SoldeInsuffisantException()
        : runtime_error("Solde insuffisant pour effectuer le retrait !") {}
};

// Classe Compte
class Compte {
private:
    int solde;

public:
    // Constructeur
    Compte(int s) {
        solde = s;
    }

    // Methode deposer
    void deposer(int montant) {

        if (montant <= 0) {
            throw MontantInvalideException();
        }

        solde += montant;

        cout << "Depot effectue avec succes !" << endl;
        cout << "Montant depose : " << montant << endl;
        cout << "Nouveau solde : " << solde << endl;
    }

    // Methode retirer
    void retirer(int montant) {

        if (montant <= 0) {
            throw MontantInvalideException();
        }

        if (montant > solde) {
            throw SoldeInsuffisantException();
        }

        solde -= montant;

        cout << "Retrait effectue avec succes !" << endl;
        cout << "Montant retire : " << montant << endl;
        cout << "Nouveau solde : " << solde << endl;
    }

    // Afficher le solde
    void afficherSolde() const {
        cout << "Solde actuel : " << solde << endl;
    }
};

int main() {

    cout << "===== SIMULATION BANCAIRE =====" << endl;

    // Creation du compte
    Compte compte(1000);

    compte.afficherSolde();

    // Premier test : depot valide
    cout << "\n--- Depot valide ---" << endl;

    try {
        compte.deposer(500);
    }
    catch (const MontantInvalideException& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    // Deuxieme test : depot invalide
    cout << "\n--- Depot invalide ---" << endl;

    try {
        compte.deposer(-200);
    }
    catch (const MontantInvalideException& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    // Troisieme test : retrait valide
    cout << "\n--- Retrait valide ---" << endl;

    try {
        compte.retirer(300);
    }
    catch (const MontantInvalideException& e) {
        cout << "Erreur : " << e.what() << endl;
    }
    catch (const SoldeInsuffisantException& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    // Quatrieme test : solde insuffisant
    cout << "\n--- Retrait avec solde insuffisant ---" << endl;

    try {
        compte.retirer(2000);
    }
    catch (const MontantInvalideException& e) {
        cout << "Erreur : " << e.what() << endl;
    }
    catch (const SoldeInsuffisantException& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    // Solde final
    cout << "\n--- Solde final ---" << endl;
    compte.afficherSolde();

    cout << "\nFin du programme." << endl;

    return 0;
}
