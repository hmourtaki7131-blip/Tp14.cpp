
#include <iostream>
#include <stdexcept>
using namespace std;

// Fonction diviser
int diviser(int a, int b) {

    if (b == 0) {
        throw runtime_error("Erreur : division par zero impossible !");
    }

    return a / b;
}

int main() {

    cout << "===== DIVISION SECURISEE =====" << endl;

    // Premier test
    try {
        cout << "10 / 2 = " << diviser(10, 2) << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    // Deuxieme test
    try {
        cout << "7 / 0 = " << diviser(7, 0) << endl;
    }
    catch (const exception& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    // Troisieme test
    try {
        cout << "9 / 3 = " << diviser(9, 3) << endl;
    }
    catch (const exception& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    cout << "\nFin du programme." << endl;

    return 0;
}
