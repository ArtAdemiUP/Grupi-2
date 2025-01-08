#include <iostream>
#include <vector>
#include "functions.h"

int main() {
    std::vector<Shpenzim> shpenzimet; 
    int zgjedhja;
    
    do {
        std::cout << "\nMirësevini në Tracker-in e Shpenzimeve\n";
        std::cout << "1. Shto Shpenzim\n";
        std::cout << "2. Shiko Shpenzimet\n";
        std::cout << "3. Llogarit Totali i Shpenzimeve\n";
        std::cout << "4. Shiko Shpenzimet sipas Kategorisë\n";
        std::cout << "5. Fshi Shpenzim\n";
        std::cout << "6. Dalje\n";
        std::cout << "Shkruaj zgjedhjen tuaj: ";
        std::cin >> zgjedhja;
        
        switch (zgjedhja) {
            case 1:
                shtoShpenzim(shpenzimet);
                break;
            case 2:
                shikoShpenzimet(shpenzimet);
                break;
            case 3:
                std::cout << "Totali i Shpenzimeve: $" << llogaritTotali(shpenzimet) << std::endl;
                break;
            case 4: {
                std::string kategoria;
                std::cout << "Shkruaj kategorinë (Ushqim/Transport/Argëtim): ";
                std::cin >> kategoria;
                llogaritNgaKategoria(shpenzimet, kategoria);
                break;
            }
            case 5: {
                int id;
                std::cout << "Shkruaj ID-në e shpenzimit që dëshiron të fshish: ";
                std::cin >> id;
                fshiShpenzim(shpenzimet, id);
                break;
            }
            case 6:
                std::cout << "Duke dalë nga programi...\n";
                break;
            default:
                std::cout << "Zgjedhje e pavlefshme. Ju lutem provoni përsëri.\n";
        }
    } while (zgjedhja != 6);
    
    return 0;
}
