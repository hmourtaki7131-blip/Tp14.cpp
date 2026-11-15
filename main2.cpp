
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Exception personnalisee
class StockInsuffisantException : public runtime_error {
public:
    StockInsuffisantException()
        : runtime_error("Stock insuffisant pour effectuer cette vente !") {}
};

// Classe Produit
class Produit {
private:
    string nom;
    int stock;

public:
    // Constructeur
    Produit(string n, int s) {
        nom = n;
        stock = s;
    }

    // Methode vendre
    void vendre(int quantite) {

        if (quantite <= 0) {
            throw invalid_argument("Quantite invalide !");
        }

        if (quantite > stock) {
            throw StockInsuffisantException();
        }

        stock = stock - quantite;

        cout << "Vente effectuee avec succes !" << endl;
        cout << "Quantite vendue : " << quantite << endl;
        cout << "Stock restant : " << stock << endl;
    }

    // Afficher les informations
    void afficher() const {
        cout << "Produit : " << nom << endl;
        cout << "Stock disponible : " << stock << endl;
    }
};

int main() {

    cout << "===== GESTION DU STOCK =====" << endl;

    // Creation du produit
    Produit p("Ordinateur", 10);

    p.afficher();

    // Premier test : vente reussie
    cout << "\n--- Premiere vente ---" << endl;

    try {
        p.vendre(3);
    }
    catch (const StockInsuffisantException& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    // Deuxieme test : stock insuffisant
    cout << "\n--- Deuxieme vente ---" << endl;

    try {
        p.vendre(15);
    }
    catch (const StockInsuffisantException& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    // Afficher le stock final
    cout << "\n--- Stock final ---" << endl;
    p.afficher();

    return 0;
}
